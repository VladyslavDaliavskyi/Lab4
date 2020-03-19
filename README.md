# Lab Work "Work with can bus on STM32f407VG"

Can bus init in loop mode with silence.
On LCD display the user can see how many messages are in the queue to receive.
If the user clicks SW3-button on GL-ESK, the microcontroller sends one pack of data by can bus
If the user clicks SW2-button, the microcontroller receives one pack from the queue if it exists.