#ifndef LCD_H
#define LCD_H

#include "stm32f4xx_hal.h"

#define SET GPIO_PIN_SET
#define RESET GPIO_PIN_RESET

#define lcdPort  GPIOE
#define rsPin  GPIO_PIN_7
#define rwPin  GPIO_PIN_10
#define enPin  GPIO_PIN_11
#define dh4Pin  GPIO_PIN_12
#define dh5Pin  GPIO_PIN_13
#define dh6Pin  GPIO_PIN_14
#define dh7Pin  GPIO_PIN_15

#define RS(X) HAL_GPIO_WritePin(lcdPort, rsPin, X);
#define RW(X) HAL_GPIO_WritePin(lcdPort, rwPin, X);
#define EN(X) HAL_GPIO_WritePin(lcdPort, enPin, X);
#define DH4(X) HAL_GPIO_WritePin(lcdPort, dh4Pin, X);
#define DH5(X) HAL_GPIO_WritePin(lcdPort, dh5Pin, X);
#define DH6(X) HAL_GPIO_WritePin(lcdPort, dh6Pin, X);
#define DH7(X) HAL_GPIO_WritePin(lcdPort, dh7Pin, X);

void initLCD(void);
void lcdSend(uint8_t, uint8_t);
void lcdCommand(uint8_t);
void lcdChar(const char);
void lcdUNumber(uint32_t);
void lcdNumber(int32_t);
void lcdString(char*);
void setCursor(uint8_t, uint8_t);
void parametrsToggle(uint8_t, uint8_t, uint8_t);
void shiftToggle(uint8_t, uint8_t);
void scrollRight(void);
void scrollLeft(void);
void clear(void);
void home(void);

#endif //LCD_H
