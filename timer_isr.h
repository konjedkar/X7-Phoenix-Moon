  
 // Timer 2 overflow interrupt service routine
interrupt [TIM2_OVF] void timer2_ovf_isr(void)
{   

TCNT2=TCNT2_value;    

if(!calcualte_new_angle_val)
{
OCR3AH  = U_Phase_value_H; 
OCR3AL  = U_Phase_value_L; 

OCR3BH  = V_Phase_value_H; 
OCR3BL  = V_Phase_value_L;

OCR3CH  = W_Phase_value_H; 
OCR3CL  = W_Phase_value_L;
}

if(Frequency_H)
 {
   if(Counter_for_H==0xFF)              //Counter_for_H i
    {
     Counter_for_H = Frequency_H; 
     Counter_for_H--;
     TCNT2_value=0x00; 
    }
   else  
   if(Counter_for_H)
    {
     Counter_for_H--; 
     TCNT2_value=0x00;
     return;
    }
   else 
    {
      TCNT2_value=Frequency_L;  
      Counter_for_H=0xFF;
      return;
    }
 }
else TCNT2_value=Frequency_L; 


calcualte_new_angle_val=1;
   
         

angle++;
angle++;            //step=2

        
}  


// Timer 0 overflow interrupt service routine
interrupt [TIM0_OVF] void timer0_ovf_isr(void)
{
  TCCR0=0x00;  

  
   /*
      no_pulse_detect_flag=0;
      check_encoder_cntr=0;   
  

      if(detection_mode_en>2)
       {
        position++;
       }
      else
      if(position!=0xFFFF && detection_mode_en==0)   //run if calibrated
       {
          if(direction_ref!=RVS)
            {   
             if(position<DoorWidth_pulses)position++;
            }
          if(direction_ref!=FWD)  
           {
             if(position>0)position--;
           }
       }   

 
      if(demo_mode_en)display_en=1;
      if(page==21)display_en=1;             
      if(page==1){if(page_1_state==0)display_en=1;}   */ 

  /*if(EICRB==0x20) EICRB=0x30;
  else EICRB=0x20; */

  EIMSK=0x40;    ///re-enable INT6

}  

// External Interrupt 6 service routine
interrupt [EXT_INT6] void ext_int6_isr(void)
{
  
  
  if(EICRB==0x20)   //FALLING
    {
      if(ENC_A)return;  
      #asm("NOP")
      if(ENC_A)return; 
      EICRB=0x30;
    }
  else 
    {
     if(ENC_A==0)return;
     #asm("NOP")
     if(ENC_A==0)return; 
     EICRB=0x20; 
    }   
        
   enc_pulse_counter++; 

   EIMSK=0x00;        //disable interrupts  
  
  // Clock source: System Clock
  // Clock value: 15.625 kHz
       TCNT0=0xE0;    //for enable int6 after 2ms by t0 overflow isr
       TCCR0=0x07;    
        
}


// Timer 1 overflow interrupt service routine
interrupt [TIM1_OVF] void timer1_ovf_isr(void)
{
// Reinitialize Timer 1 value     //ISR run in every 10ms
TCNT1H=0xFD;
TCNT1L=0x8F;

loop_delay_flag=0;

/*
if(ramp_up_cntr)
 {
  if(start_motor==0)
  { 
    if(acceleration==0xFF)
      {
             actual_speed=Speed_ref;
             ramp_up_cntr=0;   
             new_freq=1;           
           
           /* if(actual_speed<Speed_ref && Speed_ref>=MIN_SPEED)
              {
               actual_speed+=10;
               if(actual_speed>Speed_ref)actual_speed=Speed_ref; 
               new_freq=1;
              }
            else
             {
               actual_speed=Speed_ref;
               ramp_up_cntr=0;   
               new_freq=1;
             }
      }
    else
      {
        ramp_up_cntr++;
        if(ramp_up_cntr>acceleration) 
         {
            ramp_up_cntr=1; 
            if(actual_speed<Speed_ref && Speed_ref>=MIN_SPEED)
             {
               actual_speed++;
               new_freq=1;
             }
            else
             {
               actual_speed=Speed_ref;
               ramp_up_cntr=0;   
               new_freq=1;
             }
         }

      } 
   } 
 
 }   
 
if(ramp_down_cntr)
 {
  if(start_motor==0)
  { 
    if(deceleration==0xFF)
      {
               actual_speed=Speed_ref;
               ramp_down_cntr=0;   
               new_freq=1;          
           /* if(actual_speed>Speed_ref && Speed_ref>=MIN_SPEED)
              {
               if(actual_speed>10)actual_speed-=10;
               if(actual_speed<Speed_ref || actual_speed<=MIN_SPEED)actual_speed=Speed_ref; 
               new_freq=1;
              }
            else
             {
               actual_speed=Speed_ref;
               ramp_down_cntr=0;   
               new_freq=1;
             }    
      }
    else
      {
        ramp_down_cntr++;
        if(ramp_down_cntr>deceleration) 
         {
            ramp_down_cntr=1; 
            if(actual_speed>Speed_ref && Speed_ref>=MIN_SPEED)
             {
               actual_speed--;
               new_freq=1;
             }
            else 
             {
               actual_speed=Speed_ref;
               ramp_down_cntr=0;   
               new_freq=1;
             }
         }

      } 
   } 
 
 }   
 

 if(new_freq)
         {
            new_freq=0;       
            TCCR2=0x00;
            Frequency_L = angle_step_L[actual_speed];   
            Frequency_H = angle_step_H[actual_speed];
            Counter_for_H = Frequency_H; 
            
            if(Counter_for_H)
             {
               Counter_for_H--;
               TCNT0=0x00;
             }
            else TCNT0=Frequency_L;   
            TCCR2=0x04;                 //62.5KHz
            
            if(page==1){if(page_1_state==1)display_en=1;}
            new_vboost=1;     
            
         } 
         
 if(new_vboost)      // Vboost normalize in 0~255 range
         {
            new_vboost=0;
            
             M=(((255-Vboost)*(unsigned long)(actual_speed-SPEED_BOOST))/(SPEED_BASE-SPEED_BOOST))+Vboost;  
             
             M = M + A_BOOST_MIN; 
             if(M>255)M=255;  
             

             M_char = M;
             
             if(page==1){if(page_1_state==2)display_en=1;}
     
         }  
         
 if(start_motor==1)
       {
         angle=0; 
         //calcualte_new_angle_val=0;  
         
         TCCR3A = 0x00;
         TCCR3B = 0x00;  //STOP TIMER 3
         TCCR2  = 0x00;   //STOP TIMER 0
       
        
         TCCR2  = 0x00;      //STOP TIMER2
         
         OCR3AH =0; OCR3AL =0;   //U
         OCR3BH =0; OCR3BL =0;   //V
         OCR3CH =0; OCR3CL =0;   //W       
         EN_MOTOR=1;    //Enable MOTOR
         U_PHASE=0;
         V_PHASE=0;
         W_PHASE=0;
       } 
 else       
 if(start_motor>10)
       {
         start_motor=0;
         
         new_freq = 1; 
         
         TCCR3A = 0xAA;
         TCCR3B = 0x01;    
       }  
 if(start_motor)start_motor++;  
 
 
 if(stop_motor)
       {
         stop_motor=0;
         angle=0; 
        // calcualte_new_angle_val=0;  
         
         TCCR3A = 0x00;
         TCCR3B = 0x00;  //STOP TIMER 3
         TCCR2 = 0x00;   //STOP TIMER 0
       
        
         TCCR2=0x00;      //STOP TIMER 0
         
         OCR3AH =0;OCR3AL =0;   //U
         OCR3BH =0;OCR3BL =0;   //V
         OCR3CH =0;OCR3CL =0;   //W        
         EN_MOTOR=0;    //disable MOTOR
         U_PHASE=0;
         V_PHASE=0;
         W_PHASE=0;
       }  
         


  

if(++timer1_cntr_5<5)return;   
timer1_cntr_5=0;                   //50ms      

if(OP_cmd_cntr)OP_cmd_cntr++; 
if(CL_cmd_cntr)CL_cmd_cntr++; 
if(NO_cmd_cntr)NO_cmd_cntr++;        


if(close_state==11){if(close_pre_ramp_cntr)close_pre_ramp_cntr++;} 
if(open_state==11){if(open_pre_ramp_cntr)open_pre_ramp_cntr++;}  
if(open_state==9){if(open_first_lck_cntr)open_first_lck_cntr++;}

if(close_state==12 || close_state==50){if(close_timer_in_no_enc_mode_cntr)close_timer_in_no_enc_mode_cntr++;}
if(open_state==12 || open_state==40){if(open_timer_in_no_enc_mode_cntr)open_timer_in_no_enc_mode_cntr++;}  

if(++timer1_cntr<2)return;   
timer1_cntr=0;                   //100ms         demo_mode_en

if(demo_mode_timer)demo_mode_timer--;     
if(test_mode_timer)test_mode_timer--;   

if(close_brake_cntr)close_brake_cntr++;
if(open_brake_cntr)open_brake_cntr++;

check_encoder_cntr++;                  

if(travelling_time)travelling_time++;

if(dispaly_lfr_cntr)    
 {dispaly_lfr_cntr--; 
  if(!dispaly_lfr_cntr)display_en=1;}     //display reset factory default setting for 2 sec 
  

if(dispaly_save_cntr)    
 {dispaly_save_cntr--; 
  if(!dispaly_save_cntr)display_en=1;}    //display reset factory default setting for 2 sec     

if(dispaly_enc_cntr)    
 {dispaly_enc_cntr--; 
  if(!dispaly_enc_cntr)display_en=1;}  
  
if(dispaly_done_cntr)    
 {dispaly_done_cntr--; 
  if(!dispaly_done_cntr)display_en=1;}     
  

if(pl_key_cntr)if(pl_key_cntr<100)pl_key_cntr++;   
if(mn_key_cntr)if(mn_key_cntr<100)mn_key_cntr++;    
if(en_key_cntr)if(en_key_cntr<100)en_key_cntr++; 
if(b_key_cntr)if(b_key_cntr<100)b_key_cntr++;
if(d_key_cntr)if(d_key_cntr<100)d_key_cntr++;  
if(up_dn_key_cntr)if(up_dn_key_cntr<100)up_dn_key_cntr++;


if(blink_value_on)
 {
   blink_value_on--;   
   if(blink_value_on==0)
    {blink_value_off=5;
     display_en=1;}
 } 
if(blink_value_off)
 {
   blink_value_off--;
   if(blink_value_off==0)
     {blink_value_on=20;
      display_en=1;}
 } 
 
if(command=='c')
 {
   blink_led_test++; 
   if(blink_led_test>4)blink_led_test=0;  
   if(blink_led_test>2)DIR_LED=0;else DIR_LED=1;
 }
else  
if(command=='o')
 {  
    DIR_LED=0;
 }
else
 {
    DIR_LED=1;
 } 
 
if(++timer1_cntr_10<10)return;   
timer1_cntr_10=0;     

if(open_park_cntr)open_park_cntr++;
if(close_park_cntr)close_park_cntr++; 

if(page==1)display_en=1;                //REFRESH EVERY 1 SECOND
if(demo_mode_en)display_en=1;           //REFRESH EVERY 1 SECOND
 */
}

