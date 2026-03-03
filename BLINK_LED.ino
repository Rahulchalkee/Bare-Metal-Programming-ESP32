#include <stdio.h>
#include <stdint.h>


//#define GPIO_OUT_W1TS_REG     0x0008 + 0x6000_4000  = 0x6000_4008   OFFSET + GPIO BASE ADDRESS = MEMORY ADDRESS OF THIS REGISTER
#define GPIO_OUT_W1TS_REG       0x60004008
//#define GPIO_OUT_W1TC_REG     0x000C + 0x6000_4000  = 0x6000_400C   OFFSET + GPIO BASE ADDRESS = MEMORY ADDRESS OF THIS REGISTER
#define GPIO_OUT_W1TC_REG       0x6000400C
//#define GPIO_ENABLE_W1TS_REG  0x0024 + 0x6000_4000  = 0x6000_4024   OFFSET + GPIO BASE ADDRESS = MEMORY ADDRESS OF THIS REGISTER
#define GPIO_ENABLE_W1TS_REG    0x60004024
#define GPIO4                   4 
//#define GPIO_MASK             0001 0000               1 << 4        SETTING SET BIT TO GPIO PIN 4
#define GPIO_MASK               16                                    //HEX VALUE PUTTINH INTO THOSE REGISTER FOR THERE CONFIGURATIONS

void setup() {
*(volatile uint32_t *)GPIO_ENABLE_W1TS_REG = GPIO_MASK;
//*(volatile uint32_t *)0x60004024 MEANS Go to memory location 0x60004024.
//GPIO_MASK It writes into that "GPIO_ENABLE_W1TS_REG" register.
}

void loop() {
*(volatile uint32_t *)GPIO_OUT_W1TS_REG   = GPIO_MASK;
delay(200);
*(volatile uint32_t *)GPIO_OUT_W1TC_REG   = GPIO_MASK;
delay(200); 
}
