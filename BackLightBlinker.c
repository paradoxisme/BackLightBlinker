/* 
   BackLightBlinker V0.1 is a simple program for beginner and it use 
   micro controler PIC16F88 (but it can to be compatible with little 
   modificatifation for other reference).
   I use it for my back light of my bike.

   Copyright (C) 2014 Damien PIQUET

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>
   Created on 17 octobre 2014, 19:04
 */

#include <pic16f88.h>

unsigned int __at _CONFIG1 configword1 =  _CP_OFF & _DEBUG_OFF & _WRT_PROTECT_OFF & _CPD_OFF & _LVP_OFF & _BODEN_OFF & _MCLR_OFF & _PWRTE_OFF & _WDT_ON & _INTRC_IO;


void main() {

  //use internal oscillator to 1MHz
  OSCCON=0x40;
  
  //configure PORTB to output 
  TRISB=0;
  while(1)
    {
      //clear PORTB
      PORTB=0;

      //set time of sleep with configuring prescaler of watchog
      //Watchdog will wake up the system and will continue where it is sleeping
      //use a big prescaler for having a big time
      OPTION_REG=0x0D;
      //go to sleep
      __asm SLEEP 
	__endasm;
      //wake up
      PORTB=255;
      //use a smaller perscaler for having a little time
      OPTION_REG=0x0A;
      __asm SLEEP 
	__endasm;
      PORTB=0;
      OPTION_REG=0x0A;
      __asm SLEEP 
	__endasm;
      PORTB=255;
      OPTION_REG=0x0A;
      __asm SLEEP 
	__endasm;
      PORTB=0;
      OPTION_REG=0x0A;
      __asm SLEEP 
	__endasm;
      PORTB=255;
      OPTION_REG=0x0A;
      __asm SLEEP 
	__endasm;
      PORTB=0;
      OPTION_REG=0x0A;
      __asm SLEEP 
	__endasm;
    }   
}

