/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
© Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 2/22/2016
Author  : 
Company : 
Comments: 


Chip type               : ATmega32L
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 512
*******************************************************/

#include <mega32.h>
#asm
    .equ __w1_port=0x12
    .equ __w1_bit=6
#endasm
#include <string.h>
#include <ds18b20.h>
#include <stdbool.h>
#include <stdlib.h>
#include <1wire.h>
#include <stdio.h>
#include <Defines.h>

#define REG_SIZE 16
#define TimerN 16
#define TRANS_RESEND_TIMER 1
#include <Tirax.h>
#include <1wire.h>
#include <ds18b20.h>
void Get_Temp();
void init_Temp_Sens();
void init_LPG();
void TEC_Drive();
void Read_Press_SW();
void Machine_S (char);
void cryo(char);
void LPG_Modes(char);
void LPG();
void Reset_All();


bit t;
unsigned char addr[Num_of_Sens][9];
#include <init.c>
int resolution = 3;
 
void main(void)
{
// Declare your local variables here

// Input/Output Ports initialization
// Port A initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRA=(0<<DDA7) | (0<<DDA6) | (0<<DDA5) | (0<<DDA4) | (0<<DDA3) | (0<<DDA2) | (0<<DDA1) | (0<<DDA0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTA=(0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (0<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) | (0<<PORTA0);

// Port B initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRB=(0<<DDB7) | (1<<DDB6) | (1<<DDB5) | (0<<DDB4) | (0<<DDB3) | (0<<DDB2) | (0<<DDB1) | (0<<DDB0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (0<<PORTB0);

// Port C initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRC=(0<<DDC7) | (0<<DDC6) | (0<<DDC5) | (0<<DDC4) | (0<<DDC3) | (0<<DDC2) | (0<<DDC1) | (0<<DDC0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0);

// Port D initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRD=(0<<DDD7) | (0<<DDD6) | (0<<DDD5) | (0<<DDD4) | (0<<DDD3) | (0<<DDD2) | (0<<DDD1) | (0<<DDD0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTD=(0<<PORTD7) | (0<<PORTD6) | (0<<PORTD5) | (0<<PORTD4) | (0<<PORTD3) | (0<<PORTD2) | (0<<PORTD1) | (0<<PORTD0);


// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: Timer1 Stopped
// Mode: Normal top=0xFFFF
// OC1A output: Disconnected
// OC1B output: Disconnected
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=(0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (0<<WGM10);
TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (0<<WGM12) | (0<<CS12) | (0<<CS11) | (0<<CS10);
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: Timer2 Stopped
// Mode: Normal top=0xFF
// OC2 output: Disconnected
ASSR=0<<AS2;
TCCR2=(0<<PWM2) | (0<<COM21) | (0<<COM20) | (0<<CTC2) | (0<<CS22) | (0<<CS21) | (0<<CS20);
TCNT2=0x00;
OCR2=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1) | (0<<OCIE0) | (0<<TOIE0);

// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
// INT2: Off
MCUCR=(0<<ISC11) | (0<<ISC10) | (0<<ISC01) | (0<<ISC00);
MCUCSR=(0<<ISC2);


// Analog Comparator initialization
// Analog Comparator: Off
// The Analog Comparator's positive input is
// connected to the AIN0 pin
// The Analog Comparator's negative input is
// connected to the AIN1 pin
ACSR=(1<<ACD) | (0<<ACBG) | (0<<ACO) | (0<<ACI) | (0<<ACIE) | (0<<ACIC) | (0<<ACIS1) | (0<<ACIS0);
SFIOR=(0<<ACME);

// ADC initialization
// ADC disabled
ADCSRA=(0<<ADEN) | (0<<ADSC) | (0<<ADATE) | (0<<ADIF) | (0<<ADIE) | (0<<ADPS2) | (0<<ADPS1) | (0<<ADPS0);

// SPI initialization
// SPI disabled
SPCR=(0<<SPIE) | (0<<SPE) | (0<<DORD) | (0<<MSTR) | (0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);

// TWI initialization
// TWI disabled
TWCR=(0<<TWEA) | (0<<TWSTA) | (0<<TWSTO) | (0<<TWEN) | (0<<TWIE);

// Global enable interrupts

initTirax();
SetBitReg(15,First_run);
init_Temp_Sens();
Sen_Add_init();
setInterrupt(Machine_State,Machine_S);

#asm("sei")
while (1)
      {
      RunTirax(); 
      }
}

void Get_Temp ()
{
    int i;
    for(i=0;i<Num_of_Sens;i++)
    {
        syReg[i]=ds18b20_temperature_phase2(addr[i],resolution)+30;
    }                                        
    for(i=0;i<Num_of_Sens;i++)
    {
      ds18b20_temperature_phase1(addr[i]);
    }
}

void init_Temp_Sens ()
{
  int i;
  for(i=0;i<Num_of_Sens;i++)
  {
    ds18b20_temperature_phase1(addr[i]);
  }
}

void init_LPG()
{
    Reg_1=0;
    Vacum_valve=1;    
}

void TEC_Drive()
{
    if(Sen_1_Temp > Ref_Temp_1)
    {
        TEC1=1;
    } 
    else
    {
        TEC1=0;
    }   
    if(Sen_2_Temp > Ref_Temp_2)
    {
        TEC2=1;
    } 
    else
    {
        TEC2=0;
    } 
    if(Sen_3_Temp > Ref_Temp_3)
    {
        TEC3_4=1;
    } 
    else
    {
        TEC3_4=0;
    }    
        if(Sen_4_Temp > Ref_Temp_4)
    {
        TEC5_6=1;
    } 
    else
    {
        TEC5_6=0;
    }
}

void Read_Press_SW()
{
    if(SW_Press_up==1)  
    {
        while(!SW_Press_up){}
        Press_State++;
    }
    if(SW_Press_down==1)  
    {
        while(!SW_Press_down){}
        Press_State--;
    }
}

void Machine_S (char a)
{
    if((a&(1<<On_Off))==0x00)    
    {
        Reset_All(); 
        StopTimer(Get_Temp_Timer);
        StopTimer(TEC_Drive_Timer);
        StopTimer(Press_SW_Timer);   
        StopTimer(LPG_Timer);
        Water_Pump=0;
        Vacum_Pump=0;
        LED1=0;
        LED2=0;
    }
    else
    {
        if((a&(1<<LPG_Cryo))==1<<LPG_Cryo)  
        {                          
            LED1=1;
            LED2=0;
            StopTimer(LPG_Timer);
            Vacum_Pump=1;                                      
            cryo(Press_State); 
            StartJob(Get_Temp_Timer,Time_Delay_Read_Temp,Get_Temp); 
            Water_Pump=1;
            StartJob(TEC_Drive_Timer,Time_Delay_TEC_Drive,TEC_Drive);
            StartJob(Press_SW_Timer,Time_Delay_Press_SW,Read_Press_SW);
            setInterrupt(Press_State,cryo);
        }
        else if((a&(1<<LPG_Cryo))==0x00)  
        {
            Water_Pump=0;                  
            LED1=0;
            LED2=1;
            init_LPG();  
            StopTimer(Get_Temp_Timer);
            StopTimer(TEC_Drive_Timer);
            StopTimer(Press_SW_Timer);
            Vacum_Pump=1;  
            StartJob(LPG_Timer,T_LPG,LPG);   
            setInterrupt(T_LPG,LPG_Modes);
        }
    }
}

void cryo(char a)
{
    
    switch (a) {
    case 0:{    Vacum_valve=0;Cryo_shir=0; }break;
    case 1:{    Vacum_valve=1;Reg_1=1;Reg_2=1;Reg_3=1;Cryo_shir=1;}break;
    case 2:{    Vacum_valve=1;Reg_1=0;Reg_2=1;Reg_3=1;Cryo_shir=1;}break;
    case 3:{    Vacum_valve=1;Reg_1=0;Reg_2=0;Reg_3=1;Cryo_shir=1;}break;
    case 4:{    Vacum_valve=1;Reg_1=0;Reg_2=0;Reg_3=0;Cryo_shir=1;}
    break;
    }; 
    
}

void LPG_Modes(char a)
{
     StartJob(LPG_Timer,a,LPG);     
}

void LPG()
{
    LPG_shir=1;
    Reg_1=~Reg_1;
    Vacum_valve=~Vacum_valve;
}

void Reset_All()
{
    Tri0=0;Tri1=0;Tri2=0;Tri3=0;Tri4=0;Tri5=0;Tri6=0;Tri7=0;
    Mos1=0;Mos2=0;Mos3=0;Mos4=0;Mos5=0;Mos6=0;Mos7=0;Mos8=0;
    LED1=0;LED2=0;    
}