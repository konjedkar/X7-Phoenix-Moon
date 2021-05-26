//It MUST be RUN at begin of the Program
//Select default values from A/B/C and load them in RAM
void load_initial_values(void)
{ 
unsigned char liv0=0,liv1;          
unsigned int  liv2,liv3;   

   liv1= EE_DefaultSet;
   if(liv1 =='B' || liv1=='D')DefaultSet = liv1;
   else EE_DefaultSet = DefaultSet;  
   
   /*liv1= EE_EncType;
   if(liv1=='4' || liv1 =='2')EncType = liv1;
   else EE_EncType = EncType; */       
   
   liv2= EE_DoorWidth;
   if(liv2>299 && liv2<3000)DoorWidth = liv2;
   else EE_DoorWidth = DoorWidth;    
   
   liv2 = DoorWidth;
   liv2 = liv2 * 10;
   liv2 = liv2 / 19;
   //if(EncType=='4') liv2 = liv2 * 2;   
   DoorWidth_pulses = liv2; 
 
   liv1= EE_DoorDirection;
   if(liv1=='f' || liv1 =='r')DoorDirection = liv1;
   else EE_DoorDirection = DoorDirection;   

   liv1= EE_InputCtrl;
   if(liv1=='1' || liv1 =='2')InputCtrl = liv1;
   else EE_InputCtrl = InputCtrl;   
   

   liv1 = EE_DemoDelay;
   if(liv1<1 || liv1>200)EE_DemoDelay=DemoDelay;      
   
 
      //////semi-auto DOOR     
      liv1 = EE_DoorType[0];
      if(liv1!='a' && liv1!='c')EE_DoorType[0]='a';      
   
      liv2 = EE_OpMaxSp[0];
      if(liv2<10 || liv2>500)EE_OpMaxSp[0]=160;   
      liv2 = EE_ClMaxSp[0];
      if(liv2<10 || liv2>500)EE_ClMaxSp[0]=140;  
      
      liv2 = EE_OpMinSp[0];
      if(liv2<10 || liv2>500)EE_OpMinSp[0]=40;  
      liv2 = EE_ClMinSp[0];
      if(liv2<10 || liv2>500)EE_ClMinSp[0]=50;    
      
      liv1 = EE_OpTorque[0];
      if(liv1<7 || liv1>100)EE_OpTorque[0]=25;                         
      liv1 = EE_ClTorque[0];
      if(liv1<7 || liv1>100)EE_ClTorque[0]=20;    
      
      liv1 = EE_OpDecel[0];
      if(liv1<10 || liv1>100)EE_OpDecel[0]=70;                         
      liv1 = EE_ClDecel[0];
      if(liv1<10 || liv1>100)EE_ClDecel[0]=80;        
      
      liv2 = EE_OpBrakePos[0];
      if(liv2<40 || liv2>700)EE_OpBrakePos[0]=150;   
      liv2 = EE_ClBrakePos[0];
      if(liv2<40 || liv2>700)EE_ClBrakePos[0]=150;  
      
      liv2 = EE_OpLockSp[0];
      if(liv2<10 || liv2>100)EE_OpLockSp[0]=40; 
      liv1 = EE_OpLockTq[0];
      if(liv1<7 || liv1>100)EE_OpLockTq[0]=30; 
      liv1 = EE_OpLockPos[0];
      if(liv1<30 || liv1>200)EE_OpLockPos[0]=85;                               

      liv2 = EE_ClLockSp[0];
      if(liv2<10 || liv2>100)EE_ClLockSp[0]=40;       
      liv1 = EE_ClLockTq[0];
      if(liv1<7 || liv1>100)EE_ClLockTq[0]=30;     
      liv1 = EE_ClLockPos[0];
      if(liv1<30 || liv1>200)EE_ClLockPos[0]=85;        
                  
      liv1 = EE_KPOnOff[0];
      if(liv1!='y' && liv1!='n')EE_KPOnOff[0]='n';     
      liv1 = EE_KPTime[0];
      if(liv1<1 || liv1>60)EE_KPTime[0]=20;    
       
      liv1 = EE_OpParkEn[0];
      if(liv1!='y' && liv1!='n')EE_OpParkEn[0]='y'; 

      liv1 = EE_OpParkTq[0];
      if(liv1<7 || liv1>100)EE_OpParkTq[0]=15;       
      
      liv1 = EE_ClParkEn[0];
      if(liv1!='y' && liv1!='n')EE_ClParkEn[0]='y';   

      liv1 = EE_ClParkTq[0];
      if(liv1<7 || liv1>100)EE_ClParkTq[0]=10;   
      
                          
      
      liv1 = EE_DoorType[1];
      if(liv1!='a' && liv1!='c')EE_DoorType[1]='c';      
   
      liv2 = EE_OpMaxSp[1];
      if(liv2<10 || liv2>500)EE_OpMaxSp[1]=140;   
      liv2 = EE_ClMaxSp[1];
      if(liv2<10 || liv2>500)EE_ClMaxSp[1]=120;  
      
      liv2 = EE_OpMinSp[1];
      if(liv2<10 || liv2>500)EE_OpMinSp[1]=40;  
      liv2 = EE_ClMinSp[1];
      if(liv2<10 || liv2>500)EE_ClMinSp[1]=30;    
      
      liv1 = EE_OpTorque[1];
      if(liv1<7 || liv1>100)EE_OpTorque[1]=30;                         
      liv1 = EE_ClTorque[1];
      if(liv1<7 || liv1>100)EE_ClTorque[1]=20;    
      
      liv1 = EE_OpDecel[1];
      if(liv1<10 || liv1>100)EE_OpDecel[1]=45;                         
      liv1 = EE_ClDecel[1];
      if(liv1<10 || liv1>100)EE_ClDecel[1]=50;         
      
      liv2 = EE_OpBrakePos[1];
      if(liv2<40 || liv2>700)EE_OpBrakePos[1]=150;   
      liv2 = EE_ClBrakePos[1];
      if(liv2<40 || liv2>700)EE_ClBrakePos[1]=125;  
      
      liv2 = EE_OpLockSp[1];
      if(liv2<10 || liv2>100)EE_OpLockSp[1]=40; 
      liv1 = EE_OpLockTq[1];
      if(liv1<7 || liv1>100)EE_OpLockTq[1]=30; 
      liv1 = EE_OpLockPos[1];
      if(liv1<30 || liv1>200)EE_OpLockPos[1]=85;                               

      liv2 = EE_ClLockSp[1];
      if(liv2<10 || liv2>100)EE_ClLockSp[1]=30;       
      liv1 = EE_ClLockTq[1];
      if(liv1<7 || liv1>100)EE_ClLockTq[1]=35;     
      liv1 = EE_ClLockPos[1];
      if(liv1<30 || liv1>200)EE_ClLockPos[1]=85;        
                  
      liv1 = EE_KPOnOff[1];
      if(liv1!='y' && liv1!='n')EE_KPOnOff[1]='n';     
      liv1 = EE_KPTime[1];
      if(liv1<1 || liv1>60)EE_KPTime[1]=20;    
       
      liv1 = EE_OpParkEn[1];
      if(liv1!='y' && liv1!='n')EE_OpParkEn[1]='y'; 

      liv1 = EE_OpParkTq[1];
      if(liv1<7 || liv1>100)EE_OpParkTq[1]=15;       
      
      liv1 = EE_ClParkEn[1];
      if(liv1!='y' && liv1!='n')EE_ClParkEn[1]='y';   

      liv1 = EE_ClParkTq[1];
      if(liv1<7 || liv1>100)EE_ClParkTq[1]=10;       
   
   
   
   
   liv0=0;
   if(DefaultSet=='B')liv0=0;
   if(DefaultSet=='D')liv0=1; 
   
   DoorType = EE_DoorType[liv0];

   OpMaxSp = EE_OpMaxSp[liv0];
   ClMaxSp = EE_ClMaxSp[liv0];
  
   OpMinSp = EE_OpMinSp[liv0];
   ClMinSp = EE_ClMinSp[liv0];   
   
   OpTorque = EE_OpTorque[liv0];
   ClTorque = EE_ClTorque[liv0];
   
   OpDecel = EE_OpDecel[liv0];
   ClDecel = EE_ClDecel[liv0];   
      
   OpBrakePos = EE_OpBrakePos[liv0];
   ClBrakePos = EE_ClBrakePos[liv0]; 
   
   OpLockSp = EE_OpLockSp[liv0];
   OpLockTq = EE_OpLockTq[liv0];
   OpLockPos = EE_OpLockPos[liv0];  
   ClLockSp = EE_ClLockSp[liv0];
   ClLockTq = EE_ClLockTq[liv0];
   ClLockPos = EE_ClLockPos[liv0];
   
   KPTime = EE_KPTime[liv0];
   KPOnOff = EE_KPOnOff[liv0];      
      
   OpParkEn = EE_OpParkEn[liv0];   
   OpParkTime = EE_OpParkTime[liv0];  
   OpParkTq = EE_OpParkTq[liv0]; 
    
   ClParkEn = EE_ClParkEn[liv0];   
   ClParkTime = EE_ClParkTime[liv0];  
   ClParkTq = EE_ClParkTq[liv0];   

   calculate_close_ramp_pos_sp();
   calculate_open_ramp_pos_sp();

} 


//Load Default Values in EEPROM 'A' 'B' 'C'  when press 'A' 'b' 'c'
void load_from_eeprom_values_in_RAM(unsigned char values_set)
 { 
 unsigned char ledsv1;  
 
   if(values_set=='B')ledsv1=0;
   else 
   if(values_set=='D')ledsv1=1; 
   else return;

   DoorType = EE_DoorType[ledsv1];   
   
   OpMaxSp = EE_OpMaxSp[ledsv1];
   ClMaxSp = EE_ClMaxSp[ledsv1];
  
   OpMinSp = EE_OpMinSp[ledsv1];
   ClMinSp = EE_ClMinSp[ledsv1];   
   
   OpTorque = EE_OpTorque[ledsv1];
   ClTorque = EE_ClTorque[ledsv1];  
   
   OpDecel = EE_OpDecel[ledsv1];
   ClDecel = EE_ClDecel[ledsv1];   
      
   OpBrakePos = EE_OpBrakePos[ledsv1];
   ClBrakePos = EE_ClBrakePos[ledsv1]; 
   
   OpLockSp = EE_OpLockSp[ledsv1];
   OpLockTq = EE_OpLockTq[ledsv1];
   OpLockPos = EE_OpLockPos[ledsv1];  
   ClLockSp = EE_ClLockSp[ledsv1];
   ClLockTq = EE_ClLockTq[ledsv1];
   ClLockPos = EE_ClLockPos[ledsv1];
   
   KPTime = EE_KPTime[ledsv1];
   KPOnOff = EE_KPOnOff[ledsv1];      
      
   OpParkEn = EE_OpParkEn[ledsv1];   
   OpParkTime = EE_OpParkTime[ledsv1];  
   OpParkTq = EE_OpParkTq[ledsv1]; 
    
   ClParkEn = EE_ClParkEn[ledsv1];   
   ClParkTime = EE_ClParkTime[ledsv1];  
   ClParkTq = EE_ClParkTq[ledsv1]; 

   calculate_close_ramp_pos_sp();  
   calculate_open_ramp_pos_sp();
 
 }  
 
 
//Save changed value of parameters in RAM at EEPROM  'A' 'B' 'C'  when press 'ok?' at 11.factor set
void save_changed_values_in_eeprom(void)
 { 
 unsigned char scvte1;  
 

   if(DefaultSet=='B')scvte1=0;
   else 
   if(DefaultSet=='D')scvte1=1; 
   else return;

     EE_DoorType[scvte1] = DoorType;
     
     EE_OpMaxSp[scvte1] = OpMaxSp;
     EE_ClMaxSp[scvte1] = ClMaxSp;
  
     EE_OpMinSp[scvte1] = OpMinSp;
     EE_ClMinSp[scvte1] = ClMinSp;   
     
     EE_OpTorque[scvte1] = OpTorque;
     EE_ClTorque[scvte1] = ClTorque;
     
     EE_OpDecel[scvte1] = OpDecel;
     EE_ClDecel[scvte1] = ClDecel;      
      
     EE_OpBrakePos[scvte1] = OpBrakePos;
     EE_ClBrakePos[scvte1] = ClBrakePos; 
   
     EE_OpLockSp[scvte1] = OpLockSp;
     EE_OpLockTq[scvte1] = OpLockTq;
     EE_OpLockPos[scvte1] = OpLockPos;  
     EE_ClLockSp[scvte1] = ClLockSp;
     EE_ClLockTq[scvte1] = ClLockTq;
     EE_ClLockPos[scvte1] = ClLockPos;
   
     EE_KPTime[scvte1] = KPTime;
     EE_KPOnOff[scvte1] = KPOnOff;      
      
     EE_OpParkEn[scvte1] = OpParkEn;   
     EE_OpParkTime[scvte1] = OpParkTime;  
     EE_OpParkTq[scvte1] = OpParkTq; 
    
     EE_ClParkEn[scvte1] = ClParkEn;   
     EE_ClParkTime[scvte1] = ClParkTime; 
     EE_ClParkTq[scvte1] = ClParkTq;      
   
 
 }  
 
 
//Save changed value of parameters in RAM at EEPROM  'B' 'D'  when press 'ok?' at 11.factor set
void load_original_values_to_eeprom(void)
 { 
 if(DefaultSet=='B')
  {
     EE_DoorType[0] = 'a';
     
     EE_OpMaxSp[0] = 140;
     EE_ClMaxSp[0] = 140;
  
     EE_OpMinSp[0] = 40;
     EE_ClMinSp[0] = 50;   
     
     EE_OpTorque[0] = 25;
     EE_ClTorque[0] = 25;
     
     EE_OpDecel[0] = 70;
     EE_ClDecel[0] = 80;     
      
     EE_OpBrakePos[0] = 200;
     EE_ClBrakePos[0] = 175; 
   
     EE_OpLockSp[0] = 40;
     EE_OpLockTq[0] = 30;
     EE_OpLockPos[0] = 70;  
     EE_ClLockSp[0] = 30;
     EE_ClLockTq[0] = 30;
     EE_ClLockPos[0] = 70;
   
     EE_KPOnOff[0] = 'n';
     EE_KPTime[0] = 20;
      
     EE_OpParkEn[0] = 'y';   
     EE_OpParkTime[0] = 0xFF;  
     EE_OpParkTq[0] = 15; 
    
     EE_ClParkEn[0] = 'y';   
     EE_ClParkTime[0] = 0xFF; 
     EE_ClParkTq[0] = 10;       

  }
 else 
 if(DefaultSet=='D')
  {
     EE_DoorType[1] = 'c';
   
     EE_OpMaxSp[1] = 140;
     EE_ClMaxSp[1] = 100;
  
     EE_OpMinSp[1] = 40;
     EE_ClMinSp[1] = 30;   
     
     EE_OpTorque[1] = 25;
     EE_ClTorque[1] = 25;
     
     EE_OpDecel[1] = 45;
     EE_ClDecel[1] = 50;     
      
     EE_OpBrakePos[1] = 200;
     EE_ClBrakePos[1] = 150; 
   
     EE_OpLockSp[1] = 40;
     EE_OpLockTq[1] = 30;
     EE_OpLockPos[1] = 70;  
     EE_ClLockSp[1] = 30;
     EE_ClLockTq[1] = 35;
     EE_ClLockPos[1] = 70;
   
     EE_KPOnOff[1] = 'n';
     EE_KPTime[1] = 20;
      
     EE_OpParkEn[1] = 'y';   
     EE_OpParkTime[1] = 0xFF;  
     EE_OpParkTq[1] = 15; 
    
     EE_ClParkEn[1] = 'y';   
     EE_ClParkTime[1] = 0xFF; 
     EE_ClParkTq[1] = 10;       
 
  }
 else return;
 
 }   
 


void initial(void)
{

// Input/Output Ports initialization
// Port A initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=Out Func1=Out Func0=Out 
// State7=T State6=P State5=P State4=P State3=P State2=1 State1=1 State0=1 
PORTA=0x7F;
DDRA=0x07;

// Port B initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=Out Func1=Out Func0=Out 
// State7=T State6=T State5=P State4=P State3=T State2=0 State1=0 State0=0 
PORTB=0x30;
DDRB=0x07;

// Port C initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTC=0x00;
DDRC=0x00;

// Port D initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTD=0x00;
DDRD=0x00;

// Port E initialization
// Func7=In Func6=In Func5=Out Func4=Out Func3=Out Func2=Out Func1=In Func0=In 
// State7=T State6=T State5=0 State4=0 State3=0 State2=0 State1=T State0=T 
PORTE=0x00;

#ifdef IRAMS
EN_MOTOR = 1;       //disable motor 
#else                               
EN_MOTOR = 0;       //disable motor 
#endif

U_PHASE  = 0; 
V_PHASE  = 0;         
W_PHASE  = 0;   

DDRE=0x3C;

// Port F initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=Out Func1=In Func0=Out 
// State7=T State6=T State5=P State4=P State3=P State2=1 State1=P State0=1 
PORTF=0x3F;
DDRF=0x05;

// Port G initialization
// Func4=In Func3=In Func2=In Func1=In Func0=In 
// State4=T State3=T State2=T State1=T State0=T 
PORTG=0x00;
DDRG=0x00;   
   
   

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: 8000.000 kHz
// Mode: Normal top=FFh
// OC0 output: Disconnected
ASSR=0x00;
TCCR0=0x00;
TCNT0=0x00;
OCR0=0x00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: 62.500 kHz
// Mode: Normal top=FFFFh
// OC1A output: Discon.
// OC1B output: Discon.
// OC1C output: Discon.
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer 1 Overflow Interrupt: On
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
// Compare C Match Interrupt: Off
TCCR1A=0x00;
TCCR1B=0x04;
TCNT1H=0xFD;
TCNT1L=0x8F;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;
OCR1CH=0x00;
OCR1CL=0x00;



// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: 3.906 kHz
// Mode: Normal top=FFh
// OC2 output: Disconnected
ASSR=0x00;
TCCR2=0x00;
TCNT2=0x00;
OCR2=0x00;
OCR2=0x00;    

// Timer/Counter 3 initialization
// Clock source: System Clock
// Clock value: 8000.000 kHz
// Mode: Ph. correct PWM top=00FFh
// Noise Canceler: Off
// Input Capture on Falling Edge
// OC3A output: Non-Inv.
// OC3B output: Non-Inv.
// OC3C output: Non-Inv.
// Timer 3 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
// Compare C Match Interrupt: Off
TCCR3A=0x00;//TCCR3A=0xA9;
TCCR3B=0x00;//TCCR3B=0x01;
TCNT3H=0x00;
TCNT3L=0x00;
ICR3H=0x00;
ICR3L=0x00;
OCR3AH=0x00;
OCR3AL=0x00;
OCR3BH=0x00;
OCR3BL=0x00;
OCR3CH=0x00;
OCR3CL=0x00;


// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
// INT2: Off
MCUCR=0x00;
MCUCSR=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=0x04;                             //enable timer1 ovf   public for 10ms
ETIMSK=0x00;
TIMSK|=0x40;                            //ENABLE INTERRUPT 2  for ENC debounce
//TIMSK|=0x01;                            //ENABLE INTERRUPT 0  for angle++


// Analog Comparator initialization
// Analog Comparator: Off
// Analog Comparator Input Capture by Timer/Counter 1: Off
ACSR=0x80;
SFIOR=0x00;


// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
// INT2: Off
// INT3: Off
// INT4: Off
// INT5: Off
// INT6: On
// INT6 Mode: Falling Edge
// INT7: Off
/*EICRA=0x00;
EICRB=0x20;
EIMSK=0x40;  
EIFR=0x40; */ 
EICRA=0x00;
EICRB=0x00;
EIMSK=0x00;  
EIFR=0x00;


// SPI initialization
// SPI Type: Master
// SPI Clock Rate: 2000.000 kHz
// SPI Clock Phase: Cycle Half
// SPI Clock Polarity: High
// SPI Data Order: MSB First
SPCR=0x58;
SPSR=0x00;



// Watchdog Timer initialization
// Watchdog Timer Prescaler: OSC/2048k
#pragma optsize-
WDTCR=0x1F;
WDTCR=0x0F;
#ifdef _OPTIMIZE_SIZE_
#pragma optsize+
#endif

#asm("SEI")

}  
    

void calculate_close_ramp_pos_sp(void)
{
 
 unsigned int ccrps1,ccrps2,ccrps3,ccrps4;
 
 unsigned long int ccrps5;
             
  ccrps3 = ClLockPos;
  ccrps3 = ccrps3 * 10;
  ccrps3 = ccrps3 / 19;   //ccrps3 is cllocksp pulses  
  ccrps3 += 5;  
  FirstofLockPos =  DoorWidth_pulses  - ccrps3; 
  
  ccrps4 = FirstofLockPos;
  ccrps4 *= 9;
 
  
  ccrps1 = ClBrakePos;

  if(ClDecel<20)ccrps5=20; 
   else ccrps5 = ClDecel;  
  ccrps5 = 100 + ccrps5; 
  
  ccrps5 = ccrps5 * ccrps1;
  ccrps5 = ccrps5 / 10;
  ccrps1 = ccrps5;           // ccrps1 is 1st point of decel * 10
  
  if(ccrps1>ccrps4)ccrps1=ccrps4;        //if 1st point is greater than 0.9 DoorWidth_pulses            
  
  ccrps2 = ClBrakePos;
  
  if(ClDecel>80)ccrps5=80; 
  else
  if(ClDecel<20)ccrps5=20; 
  else ccrps5 = ClDecel;  
  ccrps5 = 100 - ccrps5;
  
  ccrps5 = ccrps5 * ccrps2;
  ccrps5 = ccrps5 / 10;
  ccrps2 = ccrps5;             // ccrps2 is last point of decel * 10
  
  
  ccrps1 = ccrps1 - ccrps2;   //length of brake ClBrakePos   1pulse = 1.9mm
  
  ccrps1 = ccrps1 / 19;       //change mm to pulse number
  ccrps1++;                  //escape from critiacak value of zero
  

  ccrps2 = ccrps2 / 19;       //change mm to pulse number
                           
  close_ramp_pos[9] = DoorWidth_pulses  - ccrps2;  
  close_ramp_pos[9] -= ccrps3;   
  
  ccrps1+=5;        //rounding
  ccrps1 = ccrps1 / 10;
  
  close_ramp_pos[8] = close_ramp_pos[9] - ccrps1;
  close_ramp_pos[7] = close_ramp_pos[8] - ccrps1;
  close_ramp_pos[6] = close_ramp_pos[7] - ccrps1;
  close_ramp_pos[5] = close_ramp_pos[6] - ccrps1;
  close_ramp_pos[4] = close_ramp_pos[5] - ccrps1;
  close_ramp_pos[3] = close_ramp_pos[4] - ccrps1;
  close_ramp_pos[2] = close_ramp_pos[3] - ccrps1;
  close_ramp_pos[1] = close_ramp_pos[2] - ccrps1;
  close_ramp_pos[0] = close_ramp_pos[1] - ccrps1;  
  
  ccrps1 = ClMaxSp;
  ccrps2 = ClMinSp;
  if(ClMinSp<ClMaxSp)ccrps1 = ccrps1 - ccrps2;   
  else  ccrps1 = ccrps2 - ccrps1;   
  
  ccrps1 = ccrps1 / 9;      
  
  close_ramp_sp[9] = ClMinSp;
  close_ramp_sp[8] = close_ramp_sp[9] + ccrps1;
  close_ramp_sp[7] = close_ramp_sp[8] + ccrps1;
  close_ramp_sp[6] = close_ramp_sp[7] + ccrps1;
  close_ramp_sp[5] = close_ramp_sp[6] + ccrps1;
  close_ramp_sp[4] = close_ramp_sp[5] + ccrps1;
  close_ramp_sp[3] = close_ramp_sp[4] + ccrps1;
  close_ramp_sp[2] = close_ramp_sp[3] + ccrps1;
  close_ramp_sp[1] = close_ramp_sp[2] + ccrps1;
  close_ramp_sp[0] = ClMaxSp;  
}
    

void calculate_open_ramp_pos_sp(void)
{
 
 unsigned int ccrps1,ccrps2,ccrps3,ccrps4;
 
 unsigned long int ccrps5;
 
  
  ccrps4 = DoorWidth_pulses;
  ccrps4 *= 9;
 
  ccrps1 = OpBrakePos;
  
  if(OpDecel<20)ccrps5=20; 
   else ccrps5 = ClDecel;  
  ccrps5 = 100 + ccrps5; 
  
  ccrps5 = ccrps5 * ccrps1;
  ccrps5 = ccrps5 / 10;
  ccrps1 = ccrps5;           // ccrps1 is 1st point of decel * 10   
  
  if(ccrps1>ccrps4)ccrps1=ccrps4;        //if 1st point is greater than 0.9 DoorWidth_pulses  

  ccrps2 = OpBrakePos;
  
  if(OpDecel>80)ccrps5=80; 
  else
  if(OpDecel<20)ccrps5=20; 
  else ccrps5 = OpDecel;  
  ccrps5 = 100 - ccrps5;
  
  ccrps5 = ccrps5 * ccrps2;
  ccrps5 = ccrps5 / 10;
  ccrps2 = ccrps5;             // ccrps2 is last point of decel * 10
  
  
  ccrps1 = ccrps1 - ccrps2;   //length of brake ClBrakePos   1pulse = 1.9mm
  
  ccrps1 = ccrps1 / 19;       //change mm to pulse number
  ccrps1++;                  //escape from critiacak value of zero 
  ccrps1+=5;        //rounding
  ccrps1 = ccrps1 / 10;  
  

  ccrps2 = ccrps2 / 19;       //change mm to pulse number

  open_ramp_pos[9] = ccrps2; 
  
  open_ramp_pos[9] = open_ramp_pos[9] + ccrps1;
  open_ramp_pos[8] = open_ramp_pos[9] + ccrps1;
  open_ramp_pos[7] = open_ramp_pos[8] + ccrps1;
  open_ramp_pos[6] = open_ramp_pos[7] + ccrps1;
  open_ramp_pos[5] = open_ramp_pos[6] + ccrps1;
  open_ramp_pos[4] = open_ramp_pos[5] + ccrps1;
  open_ramp_pos[3] = open_ramp_pos[4] + ccrps1;
  open_ramp_pos[2] = open_ramp_pos[3] + ccrps1;
  open_ramp_pos[1] = open_ramp_pos[2] + ccrps1;
  open_ramp_pos[0] = open_ramp_pos[1] + ccrps1;    
  
  ccrps1 = OpMaxSp;
  ccrps2 = OpMinSp;
  ccrps1 = ccrps1 - ccrps2;   //1.5time of ClBrakePos   
  
  ccrps1 = ccrps1 / 9;      //0.15time is step 
  
  open_ramp_sp[9] = OpMinSp;
  open_ramp_sp[8] = open_ramp_sp[9] + ccrps1;
  open_ramp_sp[7] = open_ramp_sp[8] + ccrps1;
  open_ramp_sp[6] = open_ramp_sp[7] + ccrps1;
  open_ramp_sp[5] = open_ramp_sp[6] + ccrps1;
  open_ramp_sp[4] = open_ramp_sp[5] + ccrps1;
  open_ramp_sp[3] = open_ramp_sp[4] + ccrps1;
  open_ramp_sp[2] = open_ramp_sp[3] + ccrps1;
  open_ramp_sp[1] = open_ramp_sp[2] + ccrps1;
  open_ramp_sp[0] = OpMaxSp;  
}
         


void key_navigation(unsigned char key_code)
{  
unsigned char kn2;

//--------------page==0---------- 
   if(page==0)
    {
      if(key_code=='M')
        {
          page=10;
          menu_item=1;
          select_item=0; 
          display_en=1;  
        }
      
    }    
    
//--------------page==1---------- 
   else
   if(page==1)
    {
      if(key_code=='U')
        {
          if(manual_mode)command='c';
          else
          if(page_1_state==0)page_1_state=1;
          else                             
          if(page_1_state==1)page_1_state=2;    
          else                             
          if(page_1_state==2)page_1_state=0;                 
           
        }   
      if(key_code=='D')
        {
          if(manual_mode)command='o';
          else          
          if(page_1_state==0)page_1_state=2;
          else                             
          if(page_1_state==1)page_1_state=0;    
          else                             
          if(page_1_state==2)page_1_state=1;         
        }         
      if(key_code=='M')
        {
          page=10;
          menu_item=1;
          select_item=0; 
          if(demo_mode_en)
           {
             demo_mode_en=0;   //exit from demo mode   
             demo_mode_timer=0;
           }
          if(manual_mode)manual_mode=0;
                     
        }  
              
      display_en=1; 
    }  

//--------------page==10----------  MAIN MENU    
   else
   if(page==10)
    {       
      if(key_code=='M')
        {
          page=1;
        }    
      if(key_code=='U')
        {
          if(menu_item>1)menu_item--;
           else  menu_item=5;
        }    
      if(key_code=='D')
        {
          if(menu_item<5)menu_item++;
           else  menu_item=1;
        }  
      if(key_code=='E')
        {
          if(menu_item==1)
            {                                   //1.CLOSE
              page=20;
              select_item=1;
            }
          else           
          if(menu_item==2)                      //2.OPEN
           {
              page=20;
              select_item=1;
           }
          else
          if(menu_item==3)                     //3.dir F
           {
         /*    if(DoorDirection=='f')DoorDirection='r';
             else DoorDirection='f';
             EE_DoorDirection = DoorDirection; */
             get_value_temp_i1=DoorDirection;   
             blink_value_on=1; 
             page=34;
           /*  kn2=direction;  
             direction=STP;
             motor_command(kn2,speed);    */        
           }
          else
          if(menu_item==4)                    //4.INP 1
           {
            /* if(InputCtrl=='1')InputCtrl='2';
             else InputCtrl='1';
             EE_InputCtrl = InputCtrl; */
             get_value_temp_i1=InputCtrl;   
             blink_value_on=1; 
             page=35;                                 
           } 
          else          
          if(menu_item==5)                    //5.SETpl
           {
             get_value_temp_i1=DoorWidth; 
             blink_value_on=1;
             page=31;  
           }            
        
        
        }   //end of key_code=='e'           
        display_en=1;
    }  //end of page==10 
    
  else
   if(page==20)
    {       
      if(key_code=='M')
        {
          page=10;
        }
        
      if(key_code=='U')
        {
          if(select_item>1)select_item--;
           else  select_item=9;
        }    
      if(key_code=='D')
        {
          if(select_item<9)select_item++;
           else  select_item=1;
        }      
        
      if(key_code=='E')
        {
          if(menu_item==1)
           { 
             blink_value_on=BLINK_VALUE_ON_TIME;
             if(select_item==1){page=32;get_value_temp_i1=ClMaxSp;}
             if(select_item==2){page=32;get_value_temp_i1=ClMinSp;}
             if(select_item==3){page=32;get_value_temp_i1=ClBrakePos;}  
             if(select_item==4){page=31;get_value_temp_i1=ClTorque;}
             if(select_item==5){page=40;sub_select_item=1;}   
             if(select_item==6){page=50;sub_select_item=1;}
             if(select_item==7){page=31;get_value_temp_i1=ClDecel;}
             if(select_item==8){page=33;get_value_temp_i1=KPOnOff;}          
             if(select_item==9){page=32;get_value_temp_i1=KPTime;}
             
           } 
          else
          if(menu_item==2)
           { 
             blink_value_on=BLINK_VALUE_ON_TIME;
             if(select_item==1){page=32;get_value_temp_i1=OpMaxSp;}
             if(select_item==2){page=32;get_value_temp_i1=OpMinSp;}
             if(select_item==3){page=32;get_value_temp_i1=OpBrakePos;}  
             if(select_item==4){page=31;get_value_temp_i1=OpTorque;}
             if(select_item==5){page=40;sub_select_item=1;}   
             if(select_item==6){page=50;sub_select_item=1;}
             if(select_item==7){page=31;get_value_temp_i1=OpDecel;}
             if(select_item==8)blink_value_on=0;
             if(select_item==9)blink_value_on=0; //{page=32;get_value_temp_i1=OPTout;}   
             
           }           

        }        
                
        display_en=1;
    }  //end of page==20    
    
//-----------------------page=40 menu_item==5 LIST of PARK MENU    
   else
   if(page==40)
    {       
      if(key_code=='M')
        {
          page=20;
        }
        
      if(key_code=='U')
        {
          if(sub_select_item>1)sub_select_item--;
           else  sub_select_item=3;
        }    
      if(key_code=='D')
        {
          if(sub_select_item<3)sub_select_item++;
           else  sub_select_item=1;
        }      
        
      if(key_code=='E')
        {
          if(menu_item==1)
           { 
             blink_value_on=BLINK_VALUE_ON_TIME;
             if(sub_select_item==1){page=32;get_value_temp_i1=ClLockSp;}
             if(sub_select_item==2){page=31;get_value_temp_i1=ClLockTq;}
             if(sub_select_item==3){page=32;get_value_temp_i1=ClLockPos;}  
           } 
          else
          if(menu_item==2)
           { 
             blink_value_on=BLINK_VALUE_ON_TIME;
             if(sub_select_item==1){page=32;get_value_temp_i1=OpLockSp;}
             if(sub_select_item==2){page=31;get_value_temp_i1=OpLockTq;}
             if(sub_select_item==3){page=32;get_value_temp_i1=OpLockPos;} 
           }           

        }        
                
        display_en=1;
    }  //end of page==20      
         
//-----------------------page=50 menu_item==6 LIST of PARK MENU    
   else
   if(page==50)
    {       
      if(key_code=='M')
        {
          page=20;
        }
        
      if(key_code=='U')
        {
          if(sub_select_item>1)sub_select_item--;
           else  sub_select_item=3;
        }    
      if(key_code=='D')
        {
          if(sub_select_item<3)sub_select_item++;
           else  sub_select_item=1;
        }      
        
      if(key_code=='E')
        {
          if(menu_item==1)
           { 
             blink_value_on=BLINK_VALUE_ON_TIME;
             if(sub_select_item==1){page=33;get_value_temp_i1=ClParkEn;}
             if(sub_select_item==2){page=31;get_value_temp_i1=ClParkTime;}
             if(sub_select_item==3){page=31;get_value_temp_i1=ClParkTq;}  
           } 
          else
          if(menu_item==2)
           { 
             blink_value_on=BLINK_VALUE_ON_TIME;
             if(sub_select_item==1){page=33;get_value_temp_i1=OpParkEn;}
             if(sub_select_item==2){page=31;get_value_temp_i1=OpParkTime;}
             if(sub_select_item==3){page=31;get_value_temp_i1=OpParkTq;} 
           }           

        }        
                
        display_en=1;
    }  //end of page==20        
    
    
//--------------page==21----------        PLEASE WAIT 0000mm
   else
   if(page==21)
    {   
      if(key_code=='M')
        {
          page=1; 
          detection_mode_en=0;    
          position=0xffff; 
          page_1_state=0;
        }
        
    }       

   else
   if(page==31)
    {
      if(menu_item==5)   //in 5.SETPL menu
       {
         if(key_code=='M'){page=10;}
         if(key_code=='U'){get_value_temp_i1+=10;if(get_value_temp_i1>3000)get_value_temp_i1=3000;}
         if(key_code=='D'){if(get_value_temp_i1>300)get_value_temp_i1-=10;}
         if(key_code=='E')
           {
             page=10;

             DoorWidth = get_value_temp_i1;

             get_value_temp_i1 = get_value_temp_i1 * 10; 
             get_value_temp_i1 = get_value_temp_i1 / 19;             
                     
             DoorWidth_pulses = get_value_temp_i1;
             blink_value_on=0;
             blink_value_off=0;  

             EE_DoorWidth = DoorWidth;  
             calculate_close_ramp_pos_sp();   
             calculate_open_ramp_pos_sp();
             dispaly_done_cntr=10;
           }
       }    
 
     else
     if(menu_item==1)
      {       
         if(select_item==4)  //4.TORQ
           {
              if(key_code=='M'){page=20;}
              if(key_code=='U'){get_value_temp_i1+=1;if(get_value_temp_i1>100)get_value_temp_i1=100;}    
              if(key_code=='D'){if(get_value_temp_i1>7)get_value_temp_i1-=1;} 
              if(key_code=='E')
                    {
                        page=20;dispaly_done_cntr=10;
                        blink_value_on=0;blink_value_off=0;
                        ClTorque=get_value_temp_i1; 
                    }             
           } 
         else  
         if(select_item==5)  //5.Loc
           { 
            if(sub_select_item==2) //2.LC Tq          
             {
                if(key_code=='M'){page=40;}
                if(key_code=='U'){get_value_temp_i1+=1;if(get_value_temp_i1>100)get_value_temp_i1=100;}    
                if(key_code=='D'){if(get_value_temp_i1>7)get_value_temp_i1-=1;} 
                if(key_code=='E')
                    {
                        page=40;dispaly_done_cntr=10;
                        blink_value_on=0;blink_value_off=0;
                        ClLockTq=get_value_temp_i1; 
                    }  
             }                  
           } 
         else          
         if(select_item==6)  //6.PAR --> sub_select_item
           {
             if(sub_select_item==2)  //2.PAR T
              {
               if(key_code=='M'){page=50;}
               if(key_code=='U')
                  {
                    if(get_value_temp_i1<120)get_value_temp_i1+=1;
                    else
                    if(get_value_temp_i1<240)get_value_temp_i1+=10; 
                    else get_value_temp_i1=0xFE;
                  }    
               if(key_code=='D')
                  {
                    if(get_value_temp_i1>240)get_value_temp_i1=240;
                    else
                    if(get_value_temp_i1>120)get_value_temp_i1-=10; 
                    else 
                    if(get_value_temp_i1>1)get_value_temp_i1-=1;
                  }  
               if(key_code=='E')
                    {
                        page=50;dispaly_done_cntr=10;
                        blink_value_on=0;blink_value_off=0;
                        ClParkTime=get_value_temp_i1;
                    }             
              } //if(sub_select_item==2)
            else   
            if(sub_select_item==3)  //3.PR TQ
              {
                 if(key_code=='M'){page=20;}
                 if(key_code=='U'){get_value_temp_i1+=1;if(get_value_temp_i1>100)get_value_temp_i1=100;}    
                 if(key_code=='D'){if(get_value_temp_i1>7)get_value_temp_i1-=1;} 
                 if(key_code=='E')
                    {
                        page=50;dispaly_done_cntr=10;
                        blink_value_on=0;blink_value_off=0;
                        ClParkTq=get_value_temp_i1;  
                    }             
               }                
                   
           } 
         else
         if(select_item==7)  //7.DEC
           {
              if(key_code=='M'){page=20;}
              if(key_code=='U'){get_value_temp_i1+=5;if(get_value_temp_i1>100)get_value_temp_i1=100;}    
              if(key_code=='D'){if(get_value_temp_i1>10)get_value_temp_i1-=5;} 
              if(key_code=='E')
                    {
                        page=20;dispaly_done_cntr=10;
                        blink_value_on=0;blink_value_off=0;ClDecel=get_value_temp_i1;calculate_close_ramp_pos_sp();
                    }             
           }          
                                          
      }
     else
     if(menu_item==2)   // 2.OPEN
       {  
         if(select_item==4)  //4.TORQ
           {
              if(key_code=='M'){page=20;}
              if(key_code=='U'){get_value_temp_i1+=1;if(get_value_temp_i1>100)get_value_temp_i1=100;}    
              if(key_code=='D'){if(get_value_temp_i1>7)get_value_temp_i1-=1;} 
              if(key_code=='E')
                    {
                        page=20;dispaly_done_cntr=10;
                        blink_value_on=0;blink_value_off=0;
                        OpTorque=get_value_temp_i1; 
                    }             
           }   
         else  
         if(select_item==5)  //5.Loc
           { 
            if(sub_select_item==2) //2.LC Tq          
             {
                if(key_code=='M'){page=40;}
                if(key_code=='U'){get_value_temp_i1+=1;if(get_value_temp_i1>100)get_value_temp_i1=100;}    
                if(key_code=='D'){if(get_value_temp_i1>7)get_value_temp_i1-=1;} 
                if(key_code=='E')
                    {
                        page=40;dispaly_done_cntr=10;
                        blink_value_on=0;blink_value_off=0;
                        OpLockTq=get_value_temp_i1; 
                    }  
             }                  
           }            
         else  
         if(select_item==6)  //6.PAR --> sub_select_item
           {
             if(sub_select_item==2)     //2.PAR T
              {
               if(key_code=='M'){page=50;}
               if(key_code=='U')
                  {
                    if(get_value_temp_i1<120)get_value_temp_i1+=1;
                    else
                    if(get_value_temp_i1<240)get_value_temp_i1+=10; 
                    else get_value_temp_i1=0xFE;
                  }    
               if(key_code=='D')
                  {
                    if(get_value_temp_i1>240)get_value_temp_i1=240;
                    else
                    if(get_value_temp_i1>120)get_value_temp_i1-=10; 
                    else 
                    if(get_value_temp_i1>1)get_value_temp_i1-=1;
                  }  
               if(key_code=='E')
                    {
                        page=50;dispaly_done_cntr=10;
                        blink_value_on=0;blink_value_off=0;
                        OpParkTime=get_value_temp_i1;
                    }             
              } 
            else     
            if(sub_select_item==3)  //3.PR TQ
              {
                 if(key_code=='M'){page=50;}
                 if(key_code=='U'){get_value_temp_i1+=1;if(get_value_temp_i1>100)get_value_temp_i1=100;}    
                 if(key_code=='D'){if(get_value_temp_i1>7)get_value_temp_i1-=1;} 
                 if(key_code=='E')
                    {
                        page=50;dispaly_done_cntr=10;
                        blink_value_on=0;blink_value_off=0;
                        OpParkTq=get_value_temp_i1;
                    }             
               }               
                 
           } //if(select_item==6) 
         else
         if(select_item==7)  //7.DEC
           {
              if(key_code=='M'){page=20;}
              if(key_code=='U'){get_value_temp_i1+=5;if(get_value_temp_i1>100)get_value_temp_i1=100;}    
              if(key_code=='D'){if(get_value_temp_i1>10)get_value_temp_i1-=5;} 
              if(key_code=='E')
                    {
                        page=20;dispaly_done_cntr=10;
                        blink_value_on=0;blink_value_off=0;OpDecel=get_value_temp_i1;calculate_open_ramp_pos_sp();
                    }             
           }                
                                 
        } 
      display_en=1;     
    }        //if(page==31) 
  
///------------------------------menus with 3 digits and one point  ##.# 
   else
   if(page==32)
    {   

     if(menu_item==1)   //in 1.CLOSE
       {  
         if(select_item==1)  //1.HI SP
           {
              if(key_code=='M'){page=20;}
              if(key_code=='U'){get_value_temp_i1+=5;if(get_value_temp_i1>300)get_value_temp_i1=300;}    
              if(key_code=='D'){if(get_value_temp_i1>30)get_value_temp_i1-=5;} 
              if(key_code=='E')
                    {
                        page=20;dispaly_done_cntr=10;
                        blink_value_on=0;blink_value_off=0;
                        ClMaxSp=get_value_temp_i1;  
                        calculate_close_ramp_pos_sp();
                    }             
           }    
         if(select_item==2)  //2.LO SP
           {
              if(key_code=='M'){page=20;}
              if(key_code=='U')
                        {
                           get_value_temp_i1+=5;
                           if(get_value_temp_i1>ClMaxSp)get_value_temp_i1=ClMaxSp;
                         }    
              if(key_code=='D'){if(get_value_temp_i1>30)get_value_temp_i1-=5;} 
              if(key_code=='E')
                    {
                        page=20;dispaly_done_cntr=10;
                        blink_value_on=0;blink_value_off=0;
                        ClMinSp=get_value_temp_i1;
                        calculate_close_ramp_pos_sp();
                    }  
           }       
         if(select_item==3)  //3.POS
           {
              if(key_code=='M'){page=20;}
              if(key_code=='U'){get_value_temp_i1+=5;if(get_value_temp_i1>700)get_value_temp_i1=700;}    
              if(key_code=='D'){if(get_value_temp_i1>40)get_value_temp_i1-=5;} 
              if(key_code=='E')
                    {
                        page=20;dispaly_done_cntr=10;
                        blink_value_on=0;blink_value_off=0;
                        ClBrakePos=get_value_temp_i1; 
                        calculate_close_ramp_pos_sp();
                    }             
           }  
         if(select_item==5)  //5.LOC
           {
            if(sub_select_item==1)   //1.LC SP
             {
               if(key_code=='M'){page=40;}
               if(key_code=='U'){get_value_temp_i1+=5;if(get_value_temp_i1>100)get_value_temp_i1=100;}    
               if(key_code=='D'){if(get_value_temp_i1>10)get_value_temp_i1-=5;} 
               if(key_code=='E')
                    {
                        page=40;dispaly_done_cntr=10;
                        blink_value_on=0;blink_value_off=0;
                        ClLockSp=get_value_temp_i1;
                    }             
             }         
            else 
            if(sub_select_item==3)   //3.LC PO 
             {
               if(key_code=='M'){page=40;}
               if(key_code=='U'){get_value_temp_i1+=5;if(get_value_temp_i1>200)get_value_temp_i1=200;}    
               if(key_code=='D'){if(get_value_temp_i1>30)get_value_temp_i1-=5;} 
               if(key_code=='E')
                    {
                        page=40;dispaly_done_cntr=10;
                        blink_value_on=0;blink_value_off=0;
                        ClLockPos=get_value_temp_i1;    
                        calculate_close_ramp_pos_sp();
                    }             
             }                       
           } 
         if(select_item==9)  //9.OBS T  (close)
           {
              if(key_code=='M'){page=20;}
              if(key_code=='U'){if(get_value_temp_i1<100)get_value_temp_i1+=1;}    
              if(key_code=='D'){if(get_value_temp_i1>2)get_value_temp_i1-=1;} 
              if(key_code=='E')
                    {
                        page=20;dispaly_done_cntr=10;
                        blink_value_on=0;blink_value_off=0;KPTime=get_value_temp_i1;
                    }             
           }  
                       
       }  
     else
     if(menu_item==2)   //in 2.OPEN
       {   
         if(select_item==1)  //1.HI SP
           {
              if(key_code=='M'){page=20;}
              if(key_code=='U'){get_value_temp_i1+=5;if(get_value_temp_i1>300)get_value_temp_i1=300;}    
              if(key_code=='D'){if(get_value_temp_i1>30)get_value_temp_i1-=5;} 
              if(key_code=='E')
                    {
                        page=20;dispaly_done_cntr=10;
                        blink_value_on=0;blink_value_off=0;
                        OpMaxSp=get_value_temp_i1;
                        calculate_open_ramp_pos_sp();
                    }             
           }    
         if(select_item==2)  //2.LO SP
           {
              if(key_code=='M'){page=20;}
              if(key_code=='U')
                        {
                         get_value_temp_i1+=5;
                         if(get_value_temp_i1>OpMaxSp)get_value_temp_i1=OpMaxSp;
                        }    
              if(key_code=='D'){if(get_value_temp_i1>30)get_value_temp_i1-=5;} 
              if(key_code=='E')
                    {
                        page=20;dispaly_done_cntr=10;
                        blink_value_on=0;blink_value_off=0;
                        OpMinSp=get_value_temp_i1;
                        calculate_open_ramp_pos_sp();
                    }  
           }        
         if(select_item==3)  //3.POS
           {
              if(key_code=='M'){page=20;}
              if(key_code=='U'){get_value_temp_i1+=5;if(get_value_temp_i1>700)get_value_temp_i1=700;}    
              if(key_code=='D'){if(get_value_temp_i1>40)get_value_temp_i1-=5;} 
              if(key_code=='E')
                    {
                        page=20;dispaly_done_cntr=10;
                        blink_value_on=0;blink_value_off=0;OpBrakePos=get_value_temp_i1;calculate_open_ramp_pos_sp();
                    }             
           }  
         if(select_item==5)  //5.LOC
           {
            if(sub_select_item==1)   //1.LC SP
             {
               if(key_code=='M'){page=40;}
               if(key_code=='U'){get_value_temp_i1+=5;if(get_value_temp_i1>100)get_value_temp_i1=100;}    
               if(key_code=='D'){if(get_value_temp_i1>10)get_value_temp_i1-=5;} 
               if(key_code=='E')
                    {
                        page=40;dispaly_done_cntr=10;
                        blink_value_on=0;blink_value_off=0;
                        OpLockSp=get_value_temp_i1;
                    }             
             }         
            else 
            if(sub_select_item==3)   //3.LC PO 
             {
               if(key_code=='M'){page=40;}
               if(key_code=='U'){get_value_temp_i1+=5;if(get_value_temp_i1>200)get_value_temp_i1=200;}    
               if(key_code=='D'){if(get_value_temp_i1>30)get_value_temp_i1-=5;} 
               if(key_code=='E')
                    {
                        page=40;dispaly_done_cntr=10;
                        blink_value_on=0;blink_value_off=0;
                        OpLockPos=get_value_temp_i1;
                    }             
             }                       
           } 
         if(select_item==8)  //9.OBS T
           {
              if(key_code=='M'){page=20;}
              if(key_code=='U'){if(get_value_temp_i1<250)get_value_temp_i1+=10;}    
              if(key_code=='D'){if(get_value_temp_i1>30)get_value_temp_i1-=10;} 
              if(key_code=='E')
                    {
                        page=20;dispaly_done_cntr=10;
                        blink_value_on=0;blink_value_off=0;OPTout=get_value_temp_i1;
                    }             
           }               
       }

         
   display_en=1;     
  }        //if(page==32)
    
   else
   if(page==33)
    {
              if(key_code=='M')
               {
                if(select_item==8 && menu_item==1)page=20;
                else
                if(select_item==6 && sub_select_item==1)page=50;
               }
              if(key_code=='U' || key_code=='D'){if(get_value_temp_i1=='y')get_value_temp_i1='n'; else get_value_temp_i1='y';}    
              if(key_code=='E')
                    {
                        dispaly_done_cntr=10;
                        blink_value_on=0;blink_value_off=0;
                        if(select_item==8 && menu_item==1){KPOnOff=get_value_temp_i1;page=20;}
                        else
                        if(select_item==6 && sub_select_item==1)
                         {
                           if(menu_item==1)ClParkEn=get_value_temp_i1;
                           else
                           if(menu_item==2)OpParkEn=get_value_temp_i1;  
                           page=50;
                         }                      
                        
                    }              
  
       
   display_en=1;     
  }        //if(page==33)       
  
   else
   if(page==34)
    {
        if(key_code=='M'){page=10;menu_item=3;}
        if(key_code=='U' || key_code=='D'){if(get_value_temp_i1=='f')get_value_temp_i1='r'; else get_value_temp_i1='f';}    
        if(key_code=='E')
                    {
                        page=10;dispaly_done_cntr=10;menu_item=3;
                        blink_value_on=0;blink_value_off=0;
                        DoorDirection=get_value_temp_i1; 
                        EE_DoorDirection = DoorDirection;
                        
                        kn2=direction_ref;  
                        direction=STP;
                        //motor_command(kn2,speed); 
                        place_command_in_queue('d',kn2);
                        place_command_in_queue('s',actual_speed);  
                                               
                    }              

       
       display_en=1;     
  }        //if(page==34)     
  
   else
   if(page==35)
    {
        if(key_code=='M'){page=10;menu_item=4;}
        if(key_code=='U' || key_code=='D'){if(get_value_temp_i1=='1')get_value_temp_i1='2'; else get_value_temp_i1='1';}    
        if(key_code=='E')
                    {
                        page=10;dispaly_done_cntr=10;menu_item=4;
                        blink_value_on=0;blink_value_off=0;InputCtrl=get_value_temp_i1;     
                        EE_InputCtrl = InputCtrl;
                    }              

       
       display_en=1;     
  }        //if(page==34) 
                   
    
   
   

}




void display(void)
{    
 
  unsigned int disp1,disp2;    

  if(dispaly_lfr_cntr)
    {
        point=0;
        sprintf(text_7seg,"SET %c ",DefaultSet);
        sseg_puts();          
        return; 
    }    
    
  if(dispaly_save_cntr)
    {
        point=0;
        sprintf(text_7seg," SAVE ");
        sseg_puts();  
        return; 
    }   

  if(dispaly_enc_cntr)
    {
        point=0;
        sprintf(text_7seg,"ER ENC");
        sseg_puts();
        return; 
    }   
    
  if(dispaly_done_cntr)                 
    {
        point=0;
        sprintf(text_7seg," DONE ");
        sseg_puts();
        return; 
    }     
    
  if(page==0)
   {
        point=5;
        sprintf(text_7seg,VERSION);
        sseg_puts();       
   }    
  else
  if(page==1)
   {
        if(KP_mode_en)
         {point=0;sprintf(text_7seg,"OBS   ");}  
        else
        if(demo_mode_en)
         {

           
        disp1 = position;
        disp1 *= 2;
        disp2 = position / 10;
        disp1 -= disp2;
       // if(EncType=='4') disp1 = disp1 * 2;           
                   
           point=0;              
           sprintf(text_7seg,"DE %03d",disp1/10);         
         }  
        else    
        if(manual_mode)
         {
           point=0;   
           disp1 = command - 0x20;
           sprintf(text_7seg,"TEST %c",disp1);   //0x20 for CAPITALIZE   
         }  
        else          
        if(page_1_state==0)
          {
            point=0; 
            if(position==0xffff)sprintf(text_7seg,"D=----");
            else
             {   
                disp1 = position;
                disp1 *= 2;
                disp2 = position / 10;
                disp1 -= disp2;
               // if(EncType=='4') disp1 = disp1 * 2;                
                point=5;              
                sprintf(text_7seg,"D=%04d",disp1);
             }
          } 
        else  
        if(page_1_state==1)
          {                                                         
            point=4;       
            if(direction_ref==RVS)disp1='-'; else disp1=' ';
            sprintf(text_7seg,"%c %2d%dH",disp1,actual_speed/10,actual_speed%10);
          }  
        else  
        if(page_1_state==2)
          {
            point=0;    
            sprintf(text_7seg,"TQ=%2d",torque);
           // sprintf(text_7seg,"A=%3d",M_char);
          }           
      
        
        sseg_puts(); 
           
   }  

  else
  if(page==2)
   {
      
        if(QC_test_mode==101)                
         {
           point=5;   
          /* disp1= DC_bus;
           disp1 = disp1>>1;  */        
           sprintf(text_7seg,"V=%4d",disp1);         
         }  
        else                  
         {
           if(A_KEY)
            {
              point=5;   
              /*disp1= DC_bus;
              disp1 = disp1>>1;          
              sprintf(text_7seg,"V=%4d",disp1);  */  
            }
           else 
            {
              point=3;    
             /* disp1 = Imotor;
              disp1 = disp1 % 45;  
              disp1 = disp1 * 100; 
              disp1 = disp1 /45;  
              sprintf(text_7seg,"I=%01d%02dA",Imotor/45,disp1);   */       
            }  
         }                
        sseg_puts();          
   }
   
  else  
  if(page==10)
   {                                           
        point=1;
        switch(menu_item)
         {                                          
           case 1:
              sprintf(text_7seg,"1CLOSE");
           break;   
           case 2:
              sprintf(text_7seg,"2OPEN ");
           break;                                               
           case 3:
              sprintf(text_7seg,"3DIR %c",DoorDirection-32);
           break;  
           case 4:
              sprintf(text_7seg,"41NPT%c",InputCtrl);
           break;   
           case 5:
              sprintf(text_7seg,"5SETCO");
           break;                                   
         }    
       sseg_puts();    
   }   
   
   
  else 
  if(page==20)                 
   {                                           
        point=1;
        switch(select_item)         //select item is used in page=20
         {
           case 1:
              sprintf(text_7seg,"1HI SP"); 
           break;   
           case 2:
              sprintf(text_7seg,"2LO SP");
           break;  
           case 3:
              sprintf(text_7seg,"3POS  ");
           break;  
           case 4:
              sprintf(text_7seg,"4TORQ ");
           break;  
           case 5:
              sprintf(text_7seg,"5LOC  ");
           break;    
           case 6:
              sprintf(text_7seg,"6PAR  ");
           break;  
           case 7:
              sprintf(text_7seg,"7DEC  ");
           break;             
           case 8:
              sprintf(text_7seg,"8OBS  ");
           break;    
           case 9:
              sprintf(text_7seg,"9OBS T");
           break;                                                    
         }    
       sseg_puts();        
   }     
   
  else 
  if(page==40)                 
   {                                           
        point=1;
        switch(sub_select_item)         //select item is used in page=50
         {
           case 1:
              sprintf(text_7seg,"1LC SP"); 
           break;   
           case 2:
              sprintf(text_7seg,"2LC TQ");
           break;  
           case 3:
              sprintf(text_7seg,"3LC PO");
           break;  
                                              
         }    
       sseg_puts();        
   }        
   
  else 
  if(page==50)                 
   {                                           
        point=1;
        switch(sub_select_item)         //select item is used in page=50
         {
           case 1:
              sprintf(text_7seg,"1PR EN"); 
           break;   
           case 2:
              sprintf(text_7seg,"2PR TI");
           break;  
           case 3:
              sprintf(text_7seg,"3PR TQ");
           break;  
                                              
         }    
       sseg_puts();        
   }      
   
  else
  if(page==21)
   {
        point=4;     
        disp1 = position;
        disp1 *= 2;
        disp2 = position / 10;
        disp1 -= disp2;
       // if(EncType=='4') disp1 = disp1 * 2;        
            
        sprintf(text_7seg,"(%04d)",disp1);
        sseg_puts(); 
   }   
   
   
  else                         //4digits
  if(page==31)
   { 
        point=0;              
        
        if(blink_value_on)
          {
           sprintf(text_7seg," %4d ",get_value_temp_i1);
           if(select_item==6 && sub_select_item==2 && get_value_temp_i1>=0xFE)sprintf(text_7seg,"  1NF ",get_value_temp_i1);
          }         
        else sprintf(text_7seg,"      ");  
        sseg_puts();          
   }     
   
  else                         //3digits + 1float point
  if(page==32)
   { 
        point=4;   
        if(blink_value_on)sprintf(text_7seg,"  %03d ",get_value_temp_i1);           
        else sprintf(text_7seg,"      ");
        sseg_puts();           
   }    
   
  else                        
  if(page==33)
   { 
        point=0;              
        if(blink_value_on)
          {
           if(get_value_temp_i1=='y')sprintf(text_7seg,"  YES ");
             else sprintf(text_7seg,"   NO ");
          }
        else sprintf(text_7seg,"      ");
        sseg_puts();           
   }       
  else                        
  if(page==34)
   { 
        point=0;   
        sprintf(text_7seg,"      ");           
        if(blink_value_on)
          {
           if(get_value_temp_i1=='f')text_7seg[4]='F';
             else text_7seg[4]='R';
          }

        sseg_puts();           
   } 
  else                        
  if(page==35)
   { 
        point=0;   
        sprintf(text_7seg,"      ");           
        if(blink_value_on)
          {
           if(get_value_temp_i1=='1')text_7seg[4]='1';
             else text_7seg[4]='2';
          }

        sseg_puts();           
   }       
   

}


unsigned char place_command_in_queue(unsigned char com_type,unsigned int com_para)
 {
   unsigned char pciq1=0;    
   
   if(com_type==0 && com_para==0)
    {
      com_type_q[9]=0;
      com_para_q[9]=0;
      for(pciq1=0;pciq1<9;pciq1++)
       {
         com_type_q[pciq1] = com_type_q[pciq1+1];
         com_para_q[pciq1] = com_para_q[pciq1+1];       
       }
      return 1;
    }
   
   while(com_type_q[pciq1])
     {
       pciq1++; 
       if(pciq1>9)return 0;  //unsuccessful placement
     }
   
   if(pciq1>0)  //***\\
    {
      if(com_type_q[pciq1]!=com_type_q[pciq1-1] || com_para_q[pciq1]!=com_para_q[pciq1-1])   //COMMAND is NOT previous command
       {
           com_type_q[pciq1] =  com_type;
           com_para_q[pciq1] =  com_para;         
       }
    } 
   else
    {                                      //Only ONE command in LIST
       com_type_q[pciq1] =  com_type;
       com_para_q[pciq1] =  com_para;  
    }                                         //***\\
    
//  com_type_q[pciq1] =  com_type;
//  com_para_q[pciq1] =  com_para;      
   
   if(com_type=='s')speed=com_para;
  
   return 1;
 } 


void motor_command_queue(void)
 {
   unsigned int mcq1,mcq2;
   
   if(com_type_q[0]==0)return;    
   //if(tx_rd_index1)return;
   
   switch(com_type_q[0])
    {
        case 's':               //speed command   
         if(com_para_q[0]<MIN_SPEED)com_para_q[0]=MIN_SPEED;
         if(com_para_q[0]>MAX_SPEED)com_para_q[0]=MAX_SPEED; 
         
         Speed_ref = com_para_q[0];
         
      //   if(Speed_ref==0)actual_speed=0;
         
         if(actual_speed)    //motor is already running
          {
             if(Speed_ref>actual_speed)
              {
                ramp_up_cntr=1;
                ramp_down_cntr=0;
              }   
             else  
             if(Speed_ref<actual_speed)
              {
                ramp_up_cntr=0;
                ramp_down_cntr=1;
              }                
             else break;  
          }
        break; 
        case 'a':               //accel command
         
         mcq1 = com_para_q[0];
         
         if(mcq1==0xFF)mcq1=0xFF;
         else
         if(mcq1>10)mcq1=1;  
         else mcq1=10 - mcq1;
         
         acceleration=mcq1;
         deceleration=mcq1;
         
        break;   
        case 'b':               //Vboost command

        torque = com_para_q[0];
        mcq1 = torque;
        mcq1 = (mcq1<<8);
        mcq1 = mcq1 / 100;
        Vboost = mcq1;
        
        new_vboost = 1;
        
        break;               
        case 'd':               //direction command 
          
          if(com_para_q[0]==FWD)
             {
               if(DoorDirection=='f')mcq1=FWD;
               else mcq1=RVS;
             } 
          else   
          if(com_para_q[0]==RVS)
             {
               if(DoorDirection=='f')mcq1=RVS;
               else mcq1=FWD;
             } 
          else   
          if(com_para_q[0]==STP)mcq1=STP;
          
          //mcq1 is final direction according to door
          
          if(mcq1==STP)         //stop command
           {
              start_motor=0;
              stop_motor=1;  
              direction=STP;
           }
          else 
          if(actual_speed==0 || direction==STP)
           {
              start_motor=1; 
              ramp_up_cntr=0;
              ramp_down_cntr=0;  
              actual_speed=MIN_SPEED;
              
              if(Speed_ref)
               {
                 ramp_up_cntr=1;
               }
              else Speed_ref=MIN_SPEED; 
              
              direction=mcq1;
           }
          else
           {
             direction=mcq1; 
           } 

      
        break; 
    }
   
   place_command_in_queue(0,0);         //erase command place in queue  
   return;
 }



