#include <stdio.h>
#include <stdint.h>

//--------------------OUTPUT----------------------------
//#define GPIO_OUT_W1TS_REG     0x0008 + 0x6000_4000  = 0x6000_4008   OFFSET + GPIO BASE ADDRESS = MEMORY ADDRESS OF THIS REGISTER
#define GPIO_OUT_W1TS_REG       0x60004008
//#define GPIO_OUT_W1TC_REG     0x000C + 0x6000_4000  = 0x6000_400C   OFFSET + GPIO BASE ADDRESS = MEMORY ADDRESS OF THIS REGISTER
#define GPIO_OUT_W1TC_REG       0x6000400C
//#define GPIO_ENABLE_W1TS_REG  0x0024 + 0x6000_4000  = 0x6000_4024   OFFSET + GPIO BASE ADDRESS = MEMORY ADDRESS OF THIS REGISTER
#define GPIO_ENABLE_W1TS_REG    0x60004024
//-------------------INPUT-----------------------------
//#define GPIO_IN_REG             0x003C + 0x6000_4000 = 0x6000403C 
#define GPIO_IN_REG             0x6000403C

//#define GPIO_IN_REG_MASK        0x6001403C //(1 << 5) 
//----------------------------------------------------
#define GPIO4                   4
//#define GPIO_MASK             0001 0000               1 << 4        SETTING SET BIT TO GPIO PIN 4
#define GPIO_MASK               16                                    //HEX VALUE PUTTINH INTO THOSE REGISTER FOR THERE CONFIGURATIONS

#define GPIO5                   5 //pushubutton 0010 0000
#define GPIO_BUTTON_MASK        (1 << GPIO5)

void setup() {
  Serial.begin(9600);
  Serial.print("setup");
*(volatile uint32_t *)GPIO_ENABLE_W1TS_REG = GPIO_MASK;
pinMode(5, INPUT_PULLUP);
//*(volatile uint32_t *)0x60004024 MEANS Go to memory location 0x60004024.
//GPIO_MASK It writes into that "GPIO_ENABLE_W1TS_REG" register.
}
void loop() {
if (*(volatile uint32_t *)GPIO_IN_REG & GPIO_BUTTON_MASK) {
  //Serial.print("here");

*(volatile uint32_t *)GPIO_OUT_W1TC_REG   = GPIO_MASK;
//delay(2000);
}
else{
*(volatile uint32_t *)GPIO_OUT_W1TS_REG   = GPIO_MASK;
//delay(2000); 
}
}

