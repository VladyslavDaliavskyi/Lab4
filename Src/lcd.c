#include "lcd.h"
void DelayMs(uint32_t time){
	HAL_Delay(time);
}

void initLCD(void){
	DelayMs(40);
	lcdCommand(0x02); 
	DelayMs(1);
	lcdCommand(0x28); 
	DelayMs(1);
	lcdCommand(0x28); 
	DelayMs(1);
	parametrsToggle(1,0,0);
	DelayMs(1);
	clear();
	shiftToggle(1,0);
	
}

void lcdSend(uint8_t isCommand, uint8_t data) {
    if(isCommand==1) RS(RESET) else RS(SET);
    DelayMs(1);

    if(((data >> 7) & 1)==1) DH7(SET) else DH7(RESET);
    if(((data >> 6) & 1)==1) DH6(SET) else DH6(RESET);
    if(((data >> 5) & 1)==1) DH5(SET) else DH5(RESET);
    if(((data >> 4) & 1)==1) DH4(SET) else DH4(RESET);

    EN(SET);
    DelayMs(1);
		EN(RESET);

    if(((data >> 3) & 1)==1) DH7(SET) else DH7(RESET);
    if(((data >> 2) & 1)==1) DH6(SET) else DH6(RESET);
    if(((data >> 1) & 1)==1) DH5(SET) else DH5(RESET);
    if(((data >> 0) & 1)==1) DH4(SET) else DH4(RESET);

    EN(SET);
    DelayMs(1);
		EN(RESET);
}

void lcdCommand(uint8_t cmd) {
    lcdSend(1, cmd);
}

void lcdChar(const char chr) {
    lcdSend(0, (uint8_t)chr);
}

void lcdString(char* str){
	for(uint8_t i=0;str[i]!='\0';i++){
		lcdChar(str[i]);
	}
}

void setCursor(uint8_t col, uint8_t row)
{
	lcdSend(1,0x80 | (col | row*0x40));
}

void parametrsToggle(uint8_t display,uint8_t cursor,uint8_t blink){
	uint8_t comm = 0x08;
	if(display)comm|=0x04;
	if(cursor)comm|=0x02;
	if(blink)comm|=0x01;
	lcdCommand(comm);
}

void shiftToggle(uint8_t rightShift,uint8_t scrollInc){
	uint8_t comm = 0x04;
	if(rightShift)comm|=0x02;
	if(scrollInc)comm|=0x01;
	lcdCommand(comm);
}

void scrollRight(void){
	lcdCommand(0x10|0x08|0x00);
}

void scrollLeft(void){
	lcdCommand(0x10|0x08|0x04);
}

void clear(void)
{
	lcdCommand(0x01);
	DelayMs(2);
}

void home(void)
{
	lcdCommand(0x02);
	DelayMs(2);
}

static void printNumber(uint8_t* arr,int count,uint8_t isNegative){
    if(isNegative) lcdChar('-');
    for(int i=count;i>=0;i--){
        lcdChar(48+arr[i]);
    }
}

void lcdUNumber(uint32_t val){
    uint8_t arr[10];
    int i=0;
    while(val>9){
        arr[i++]=val%10;
        val/=10;
        
    }
    arr[i]=val;
    printNumber(arr,i,0);
}

void lcdNumber(int32_t val){
    uint8_t isNegative = 0;
    if(val<0){
        isNegative=1;
        val=-val;
    }
    uint8_t arr[10];
    int i=0;
    while(val>9){
        arr[i++]=val%10;
        val/=10;
    }
    arr[i]=val;
    printNumber(arr,i,isNegative);
}
