#define Tri0 PORTC.0
#define Tri1 PORTC.1
#define Tri2 PORTC.2
#define Tri3 PORTC.3
#define Tri4 PORTC.7
#define Tri5 PORTC.6
#define Tri6 PORTC.5
#define Tri7 PORTC.4
#define Vacum_valve Tri0
#define Reg_1 Tri1 //Regulator shir
#define Reg_2 Tri2
#define LPG_shir Tri3
#define Reg_3 Tri4
#define Cryo_shir Tri5
#define Vacum_Pump Tri6
#define Water_Pump Tri7

#define Mos1 PORTA.0    //1 for first hand,2 for second hand,3-4 for third hand (3 right side,4 for left side)
#define Mos2 PORTA.1
#define Mos3 PORTA.2
#define Mos4 PORTB.4
#define Mos5 PORTB.3
#define Mos6 PORTB.2
#define Mos7 PORTB.1
#define Mos8 PORTB.0
#define TEC1 Mos1
#define TEC2 Mos2
#define TEC3_4 Mos3
#define TEC5_6 Mos4

#define LED1 PORTB.5
#define LED2 PORTB.6
#define Num_of_Sens 8
#define SW_Press_up PORTD.2 //J1 in PCB
#define SW_Press_down PORTD.3 //J1 in PCB

//Define Timers

#define Time_Delay_Read_Temp 3000 //time delay for reading sensors
#define Get_Temp_Timer 1
#define Time_Delay_TEC_Drive 1000 //time delay for driving TEC
#define TEC_Drive_Timer 2
#define Time_Delay_Press_SW 500 //time delay for driving TEC
#define Press_SW_Timer 3
#define LPG_Timer 4


//Define Registers


#define Sen_1_Temp syReg[0]       // 1-4 Sensors are installed on low side, 4 install on left hand,3 install on right hand, 1-2 install on Pressure hand (2 on right side and 1 on left side)
#define Sen_2_Temp syReg[1]
#define Sen_3_Temp syReg[2]
#define Sen_4_Temp syReg[3]
#define Sen_5_Temp syReg[4]
#define Sen_6_Temp syReg[5]
#define Sen_7_Temp syReg[6]
#define Sen_8_Temp syReg[7]
#define Ref_Temp_1 syReg[8]       //for  first hand
#define Ref_Temp_2 syReg[9]       //for second hand
#define Ref_Temp_3 syReg[10]       //for third hand right side
#define Ref_Temp_4 syReg[11]      //for third hand left side
#define Max_Temp syReg[12]
#define Press_State syReg[13] //State of Pressure  0:0% , 1:25% , 2:50% , 3:75% , 4:100%
#define T_LPG syReg[14]////On_Off Delay for LPG Mode
#define Machine_State syReg[15] // bit: 7:On/Off  6:LPG/Cryo  5:First run
#define On_Off 7
#define LPG_Cryo 6 
#define First_run 5


//Define Sensor Adresses
#define S0 0
#define S1 1
#define S2 2
#define S3 3
#define S4 4
#define S5 5
#define S6 6
#define S7 7