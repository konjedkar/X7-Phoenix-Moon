#define  VERSION   "ASR 15"

#include <mega64.h>  
#include <delay.h>  
#include <stdio.h>  

#include <spi.h>  


#include "tables.h"
#include "defines.h"
#include "sevenseg.h"  
#include "timer_isr.h"
#include "funcs.h"

// Declare your global variables here

void main(void)
{    

unsigned int  tempi=0;        

initial();  

SPI_SI=0;
SPI_RCK=0;
SPI_SCK=0;

point=0;
sprintf(text_7seg,"------");
sseg_puts();   

command=0;

#asm("WDR") 
delay_ms(500);       //delay 500ms      
#asm("WDR") 
delay_ms(500);       //delay 500ms
#asm("WDR") 


A_LED=1;
B_LED=1;
PORTF|=C_LED;   //C_LED=0;
PORTF|=D_LED;   //D_LED=0;  

#asm("WDR") 
delay_ms(100);       //delay 100ms

load_initial_values();       //Load default values in EEPROM

if(DefaultSet=='B')B_LED=0;
else if(DefaultSet=='D')PORTF&=(~D_LED); //D_LED=0;

enc_pulse_counter=0;
page=0; 
display_en=0;  

if(InputCtrl=='2')command='o';      
 
if(ENC_A){encoder_state=1;TCCR0=0x07;} 
  else {encoder_state=0;TCCR0=0x00;} 
                                       
loop_delay_flag=1;  
while(1)
{      

  if(encoder_state==0)
   {
     if(ENC_A)
      { 
         encoder_state=1; 
     
         TCNT0=0x00;    //for enable int6 after 2ms by t0 overflow isr
         TCCR0=0x07;        
      }
   } 
  else
  if(encoder_state==1)
   {
     if(ENC_A==0)TCNT0=0;  
     
     if(TCNT0>15)      //at least 2ms  ENC_A==1
      {
        encoder_state=2; 
        TCCR0=0;
        enc_pulse_counter++;
      }
   }  
  else 
  if(encoder_state==2)
   {
     if(!ENC_A)
      {      
          encoder_state=3;  
          TCNT0=0x00;    //for enable int6 after 2ms by t0 overflow isr
          TCCR0=0x07;         
      }
   }  
  else 
  if(encoder_state==3)
   {
     if(ENC_A)TCNT0=0;  
     
     if(TCNT0>15)      //at least 2ms  ENC_A==0
      {
        encoder_state=0; 
        TCCR0=0;
        enc_pulse_counter++;
      }
   }     
  
  
  
  if(enc_pulse_counter)
   {
      //no_pulse_detect_flag=0;
      if(no_pulse_detect_flag)no_pulse_detect_flag--;
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
      if(page==1){if(page_1_state==0)display_en=1;}    
      
      enc_pulse_counter--;
   }
   
if(calcualte_new_angle_val)
 {
  if(direction==RVS)
    {    
         if(sine_H[angle])
          {
            U_Phase_value_H=1;  
            U_Phase_value_L = sine_L_3rdH[angle];
            U_Phase_value_L * M_char;                  //MUL in assemly
            #asm    
              MOV _U_Phase_value_L,R1
            #endasm
          }
         else
          {
            U_Phase_value_H=0;  
            U_Phase_value_L = ~sine_L_3rdH[angle];
            U_Phase_value_L * M_char;    
            #asm  
              COM  R1
              MOV  _U_Phase_value_L,R1
            #endasm       
          }    
          
         if(sine_85_H[angle])
          {
            W_Phase_value_H=1;  
            W_Phase_value_L = sine_85_L_3rdH[angle];
            W_Phase_value_L * M_char;    
            #asm
              MOV  _W_Phase_value_L,R1
            #endasm
          }
         else
          {
            W_Phase_value_H=0;  
            W_Phase_value_L = ~sine_85_L_3rdH[angle];
            W_Phase_value_L * M_char;    
            #asm  
              COM  R1
              MOV  _W_Phase_value_L,R1
            #endasm       
          }   
          
          
         if(sine_171_H[angle])
          {
            V_Phase_value_H=1;  
            V_Phase_value_L = sine_171_L_3rdH[angle];
            V_Phase_value_L * M_char;    
            #asm
              MOV  _V_Phase_value_L,R1
            #endasm
          }
         else
          {
            V_Phase_value_H=0;  
            V_Phase_value_L = ~sine_171_L_3rdH[angle];
            V_Phase_value_L * M_char;    
            #asm  
              COM  R1
              MOV  _V_Phase_value_L,R1
            #endasm       
          }           

    } 
else    
if(direction==FWD)
    {    
         if(sine_H[angle])
          {
            U_Phase_value_H=1;  
            U_Phase_value_L = sine_L_3rdH[angle];
            U_Phase_value_L * M_char;    
            #asm
              MOV  _U_Phase_value_L,R1
            #endasm
          }
         else
          {
            U_Phase_value_H=0;  
            U_Phase_value_L = ~sine_L_3rdH[angle];
            U_Phase_value_L * M_char;    
            #asm  
              COM  R1
              MOV  _U_Phase_value_L,R1
            #endasm       
          }    
          
         if(sine_171_H[angle])
          {
            W_Phase_value_H=1;  
            W_Phase_value_L = sine_171_L_3rdH[angle];
            W_Phase_value_L * M_char;    
            #asm
              MOV  _W_Phase_value_L,R1
            #endasm
          }
         else
          {
            W_Phase_value_H=0;  
            W_Phase_value_L = ~sine_171_L_3rdH[angle];
            W_Phase_value_L * M_char;    
            #asm  
              COM  R1
              MOV  _W_Phase_value_L,R1
            #endasm       
          }   
          
          
         if(sine_85_H[angle])
          {
            V_Phase_value_H=1;  
            V_Phase_value_L = sine_85_L_3rdH[angle];
            V_Phase_value_L * M_char;    
            #asm
              MOV  _V_Phase_value_L,R1
            #endasm
          }
         else
          {
            V_Phase_value_H=0;  
            V_Phase_value_L = ~sine_85_L_3rdH[angle];
            V_Phase_value_L * M_char;    
            #asm  
              COM  R1
              MOV  _V_Phase_value_L,R1
            #endasm       
          }         
 
    }
else
   {      
   
            U_Phase_value_L = 0;
            V_Phase_value_L = 0;
            W_Phase_value_L = 0;
   }  
   
   calcualte_new_angle_val=0;   
 
 }
          
    
   if(loop_delay_flag)continue;     //10ms stay and repeat above part of program  
   loop_delay_flag=1;
   
   #asm("WDR")      
   
   
   
//****** timer1 isr body shift here entirely  *********************************************

while(1)
 {
    if(ramp_up_cntr)
     {
      if(start_motor==0)
      {     
        if(acceleration==0xFF)
          {
             actual_speed=Speed_ref;
             ramp_up_cntr=0;   
             new_freq=1;           
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
                   actual_speed++;  
                   if(actual_speed>Speed_ref)actual_speed= Speed_ref;
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
                   actual_speed--;
                   if(actual_speed<Speed_ref)actual_speed=Speed_ref;
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
         
         U_PHASE=0;
         V_PHASE=0;
         W_PHASE=0; 
      
       } 
     else  
     if(start_motor==2)
       {
         #ifdef IRAMS
         EN_MOTOR = 0;        //Enable MOTOR 
         #else                               
         EN_MOTOR = 1;       //Enable MOTOR 
         #endif          
       }
     else            
     if(start_motor>20)
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
          
         #ifdef IRAMS
          EN_MOTOR = 1;        //disable MOTOR 
         #else                               
          EN_MOTOR = 0;       //disable MOTOR 
         #endif       
         U_PHASE=0;
         V_PHASE=0;
         W_PHASE=0;
       } 
       

    if(OP_cmd_cntr)OP_cmd_cntr++; 
    if(CL_cmd_cntr)CL_cmd_cntr++; 
    if(NO_cmd_cntr)NO_cmd_cntr++;           

    if(++timer1_cntr_5<5)break;   
    timer1_cntr_5=0;                   //50ms      

    if(close_state==11){if(close_pre_ramp_cntr)close_pre_ramp_cntr++;} 
    if(open_state==11){if(open_pre_ramp_cntr)open_pre_ramp_cntr++;}  
    if(open_state==9){if(open_first_lck_cntr)open_first_lck_cntr++;}

    if(close_state==12 || close_state==50){if(close_timer_in_no_enc_mode_cntr)close_timer_in_no_enc_mode_cntr++;}
    if(open_state==12 || open_state==40){if(open_timer_in_no_enc_mode_cntr)open_timer_in_no_enc_mode_cntr++;}  

    if(++timer1_cntr<2)break;   
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
 
    if(++timer1_cntr_10<10)break;   
    timer1_cntr_10=0;   
    
    if(open_undefined_pos_cntr)
     {
      open_undefined_pos_cntr++;  
      if(open_undefined_pos_cntr>UNDEF_POS_TIMER)
       {
        open_undefined_pos_cntr=0;
        if(command=='o')place_command_in_queue('b',OpParkTq);
       }
      }
                   
    if(close_undefined_pos_cntr)
     {
      close_undefined_pos_cntr++;  
      if(close_undefined_pos_cntr>UNDEF_POS_TIMER)
       {
        close_undefined_pos_cntr=0;
        if(command=='c')place_command_in_queue('b',ClParkTq);
       }
      }      
     
    
    if(detection_mode_start_cntr)
     { 
       if(detection_mode_en==2 || detection_mode_en==3)detection_mode_start_cntr++;
     }
            

    if(open_park_cntr)open_park_cntr++;
    if(close_park_cntr)close_park_cntr++; 

    if(page==1)display_en=1;                //REFRESH EVERY 1 SECOND
    if(demo_mode_en)display_en=1;           //REFRESH EVERY 1 SECOND

   
    break;
  }
//****** timer1   *********timer1********************timer1***************timer1*****************************timer1***************** 




 
  motor_command_queue();                    //checkfor a command to execute  
          
  if(detection_mode_en)
     {
        if(detection_mode_en==1)           //opon until no pulse is detected
          {
            position=0;
            command='c';
            detection_mode_en=2;
            check_encoder_cntr=0;
            detection_mode_start_cntr=1; 
            display_en=1;
          }   
        if(detection_mode_en==2)
          {
            if(check_encoder_cntr>10 || detection_mode_start_cntr>DETECTION_TIME_OUT)       //close until no pulse is detected
              {
                 position=0;    
                 command='o';                 
                 detection_mode_en=3; 
                 check_encoder_cntr=0; 
                 detection_mode_start_cntr=1;
                 display_en=1;
              }
          }
          
        if(detection_mode_en==3)
          {
            if(check_encoder_cntr>10 || detection_mode_start_cntr>=DETECTION_TIME_OUT)
              {
                 tempi = position;
                 if(position>100 && detection_mode_start_cntr<DETECTION_TIME_OUT)               //succesful detection process is DONE!
                   {
                         tempi = tempi * 19;
                         tempi = tempi / 10; 
                         DoorWidth = tempi;
                         EE_DoorWidth = DoorWidth;
                         DoorWidth_pulses = position;   
                         calculate_close_ramp_pos_sp();
                         calculate_open_ramp_pos_sp(); 
                         position=0;

                   }                     
                 else position=0xffff;
                 
                 detection_mode_en = 0;        //cancel detection mode
                 page =0; 
                 display_en=1; 
                 open_state=0;
                 close_state=0;  
              }
          }          
     }
   else
   if(KP_mode_en) 
    {
        if(check_encoder_cntr>30)
          {
            KP_mode_en=0;
            check_encoder_cntr=0;
            if(page==1)display_en=1;
          }
    }  
   else
   if(demo_mode_en)               //Fulfill Commands from DEMO mode
    {
       if(demo_mode_timer==0)
        {
          if(command !='c')command='c';
          else if(command !='o')command='o'; 
          demo_mode_timer =  DEMO_DELAY;
        }
    }
   else
   if(test_mode_en) 
    {
        if(test_mode_timer==0)
         {
          if(InputCtrl=='1')test_mode_en=0;
          else  
          if(command =='c')                      //in input cntrl==2 it must open the DOOR
           {
            command='o';
            test_mode_timer =  DEMO_DELAY; 
           }
          else test_mode_en=0;   
         }        
    }   
   else  
   if(manual_mode)
    {
           //do nothing!!
    }    
   else
    {
        if(InputCtrl=='1')
          {
            if(command!='c')
              {
                if(CL_cmd)
                   {
                     if(!CL_cmd_cntr)CL_cmd_cntr=1; 
                     if(CL_cmd_cntr>CMD_INPUT_DEBOUNCE)command='c';
                   }  
                else CL_cmd_cntr=0;
              } 
            if(command!='o')
              {
                if(!CL_cmd)
                   {
                     if(!OP_cmd_cntr)OP_cmd_cntr=1; 
                     if(OP_cmd_cntr>CMD_INPUT_DEBOUNCE)command='o';
                   }  
                else OP_cmd_cntr=0;
              }              
          }
        else
        if(InputCtrl=='2')
          {
           
            if(command!='c')
              {
                if(CL_cmd && !OP_cmd)
                   {
                     if(!CL_cmd_cntr)CL_cmd_cntr=1; 
                     if(CL_cmd_cntr>CMD_INPUT_DEBOUNCE)command='c';
                   }  
                else CL_cmd_cntr=0;
              } 
            if(command!='o')
              {
                if(OP_cmd && !CL_cmd)
                   {
                     if(!OP_cmd_cntr)OP_cmd_cntr=1; 
                     if(OP_cmd_cntr>CMD_INPUT_DEBOUNCE)command='o';
                   }  
                else OP_cmd_cntr=0;
              }     
            if(command=='c')   //if(command!='s')
              {
                if(!CL_cmd && !OP_cmd)
                   {
                     if(!NO_cmd_cntr)NO_cmd_cntr=1; 
                     if(NO_cmd_cntr>CMD_INPUT_DEBOUNCE)command='s';
                   }  
                else NO_cmd_cntr=0;
              }   
                                      
          }        
    }
    
    
   if(position==0xffff && !detection_mode_en)   // calibration
     { 
       if(direction_ref==FWD)
         {
           if(check_encoder_cntr>20)
            {
             close_state=0xFF;
             close_park_cntr=1;             
             position=DoorWidth_pulses;
             display_en=1;   
             
             //if(page==0){page=1;page_1_state=0;} 
             
            }
         }
       if(direction_ref==RVS)
         {
           if(check_encoder_cntr>20)
            {
             open_state=0xFF;
             open_park_cntr=1;             
             position=0;
             display_en=1;   
             
             //if(page==0){page=1;page_1_state=0;} 
             
            }
         }         
     } 
    
     
  if(detection_mode_en || position==0xffff)
    {   
        if(direction_ref!=FWD && command=='c')
              {
              //   place_command_in_queue('d',STP); 
                 place_command_in_queue('d',FWD);         //place command direction in queue       
                 
                 place_command_in_queue('a',5);
                 place_command_in_queue('b',ClLockTq);
                 place_command_in_queue('s',50);
                       
                 direction_ref = FWD;       
                 check_encoder_cntr=0;
                 
                 open_undefined_pos_cntr=0;
                 close_undefined_pos_cntr=1;
              }
        if(direction_ref!=RVS && command=='o')
              {
               //   place_command_in_queue('d',STP); 
                  place_command_in_queue('d',RVS); 
                  
                  place_command_in_queue('a',5);  
                  place_command_in_queue('b',OpLockTq);                
                  place_command_in_queue('s',60);                   
                      
                  direction_ref = RVS; 
                  check_encoder_cntr=0;
                  
                  open_undefined_pos_cntr=1;
                  close_undefined_pos_cntr=0;
              }
        if(direction_ref!=STP && command=='s')
              {
                  place_command_in_queue('a',5);
                  place_command_in_queue('s',0);
                  place_command_in_queue('d',STP);
                  direction_ref = STP;   
                  check_encoder_cntr=0;
              }
    }   
  else
  {       
 
  if(KPOnOff=='y')
     {
            if(close_state>10 && close_state<30 && KP_mode_en==0)
             { 
              
               if(check_encoder_cntr>KPTime) 
                  {                                                                    //is received and encoder may be works correctly
                       KP_mode_en=1;
                       command='o'; 
                       close_state=0;  
                       place_command_in_queue('a',0xFF);
                       place_command_in_queue('s',0);
                       place_command_in_queue('d',STP);   
                      //direction = STP;
                       direction_ref=STP;                   
                  } 
                else kp_cntr=0;  
             }
            else kp_cntr=0; 
     }     

  
    if(direction_ref!=STP && command=='s')
     {
       place_command_in_queue('a',20);
       place_command_in_queue('s',0);
       place_command_in_queue('d',STP);

       //direction=STP;
       direction_ref=STP;       
       close_state=0;
       open_state=0;
     } 
    
    if(close_state)
      {
        if(close_state<10)close_state++;
      }  
    
    if(direction_ref!=FWD && command=='c' && close_state==0)
     {
       close_state=1;
       open_state=0;
       close_brake_cntr=0;  
       
       open_undefined_pos_cntr=0;      
       
       if(direction==STP)
        {
             place_command_in_queue('d',FWD);         //place command direction in queue
             place_command_in_queue('s',MIN_SPEED);
             direction_ref=FWD;             
        }   
       else
        {
             place_command_in_queue('a',0xFF);
             place_command_in_queue('s',MIN_SPEED); 
        } 
       
    //   place_command_in_queue('a',0xFF);
    //   place_command_in_queue('s',0); 
    //   place_command_in_queue('d',FWD);         //place command direction in queue    
    //   direction = FWD;
    
       
       
       check_encoder_cntr=0; 
       close_timer_in_no_enc_mode_cntr=0;     
       travelling_time=1;
     }                                            
                     
     
    if(close_state==10)                         
     {
      if(actual_speed==MIN_SPEED)                   //***\\
      {                                                     //***\\
        if(direction_ref!=FWD){place_command_in_queue('d',FWD);direction_ref=FWD;}  //***\\
        else                                                 //***\\
        if(position<close_ramp_pos[0])
         {
           place_command_in_queue('b',ClTorque);  //start with CLMaxSp/4 in high speed area  
           place_command_in_queue('s',ClMaxSp/4);
                           
           close_state=11;      
           no_pulse_detect_flag=5;               //set flag for checking encoder 1 sec later to receive 5 pulses
           close_pre_ramp_cntr=1;                //start increasing speed ramp counter
         }
        else 
         {

           place_command_in_queue('b',ClLockTq); 
           place_command_in_queue('s',ClMinSp);
                    
           close_state=30;                     //start with minimum speed in low speed area
           close_brake_cntr=1;
         }  
       }  
     }   
 
   
   if(close_state==11) 
     {
       if(close_pre_ramp_cntr>10)               //stay in clmaxsp/4 for 1 second
        {
           close_pre_ramp_cntr=0;  
           close_state=12;    
           close_timer_in_no_enc_mode_cntr=1;      
           
           place_command_in_queue('a',20);
           place_command_in_queue('s',ClMaxSp);
        }
     }    
   
   if(close_state==12) 
     {  
        if(close_timer_in_no_enc_mode_cntr>10)    //1 sec for receiving a pulse
         {
            if(no_pulse_detect_flag)             //if no pulse received after arrive in high speed
             {
                  dispaly_enc_cntr=10;          //display OPEN MODE MESSAGE for 3 sec
                  display_en=1;  
                  close_state=50;               //go to timing state instead encoder
                  position=DoorWidth_pulses;       
             }  
         }          

         
     }   
   
   
   if(close_state>10 && close_state<20)
     {
       if(position>close_ramp_pos[0] && no_pulse_detect_flag==0)close_state=20;    //exit from accel-ramp if door was arrived in decel-ramp  
     }        
     
  
   if(close_state>19 && close_state<30)                 //ramp from state=20 to state=29
     {
      if(position>close_ramp_pos[close_state-20])
       {
         if(close_state==20)place_command_in_queue('a',0xFF);            //apply maximium accelerate for the last step

         place_command_in_queue('s',close_ramp_sp[close_state-20]); 
        
         close_state++;
       }
     }   

   if(close_state==30)   
    {
      if(position>FirstofLockPos)
       {
         close_state = 40;   
         place_command_in_queue('b',ClLockTq);
         place_command_in_queue('s',ClLockSp); 
       } 
    }    

   if(close_state==40)   
    {
         if(check_encoder_cntr>20)
          {     
            if(ClParkEn=='y')place_command_in_queue('b',ClParkTq);
            close_state=0xFF;
            close_brake_cntr=0;   
            close_park_cntr=1;         
          } 
    } 

   if(close_state==50)                                  //Deceleration by timer instead of ENCODER
    {                                                   //It's run in Check ENCODER MODE
      tempi = DoorWidth;
      tempi = tempi / 30;                                  //estimate decel time from DoorWidth parameter
      
      tempi = tempi * 140;
      tempi = tempi / ClMaxSp;
      
      if(close_timer_in_no_enc_mode_cntr>tempi)         //BRAKE after 1.0 sec in CHECK ENCODER MODE
             {                                          //this time can chage in menu
                     place_command_in_queue('b',ClLockTq);
                     place_command_in_queue('s',ClMinSp);                
                     close_timer_in_no_enc_mode_cntr=0;
                     close_state=0xFF;   
                     check_encoder_cntr=0;   
                     close_brake_cntr=0;   
                     close_park_cntr=1;    
                     
                     close_undefined_pos_cntr=1;                                     
                                                          //reset for reduce to park force after 4.0 seconds in park state => close_state=30
             }    
    }    
    
   if(close_state==0xFF)
    {
      if(close_park_cntr>ClParkTime && ClParkEn=='y')
         {
          place_command_in_queue('s',0); 
          place_command_in_queue('d',STP);
          
          close_park_cntr=0;
         }
    } 
    
  if(close_state)
    {
      if(close_state<30)
        {
          if(travelling_time>TRAVELLING_TIME)
            {
              travelling_time=0;
              close_state=30;
            }
        }
    }        
    
     
  ///-----------------OPENING CONTROL SECTION -----------------

   if(open_state>1 && open_state<30 && KP_mode_en==0)
             { 
                if(check_encoder_cntr>OPTout && no_pulse_detect_flag==0)  //no_pulse_detect_flag==0 means at least 1 pulse 
                  {                                          
                    KP_mode_en=1;
                    close_state=0; 
                   // motor_command(STP,0); 
                    place_command_in_queue('s',0); 
                    place_command_in_queue('d',STP);         //place command direction in queue  
                    command='o';
                    //direction=RVS;  //cancel any open command until we have close command input
                    direction_ref=RVS; 
                  } 
             }  

    if(open_state){if(open_state<8)open_state++;}   
    
    if(direction_ref!=RVS && command=='o' && open_state==0)
     {
       open_state=1;
       close_state=0;  
       open_brake_cntr=0; 
       
       close_undefined_pos_cntr=0;    
       
       if(direction==STP)
        {
             place_command_in_queue('d',RVS);         //place command direction in queue
             place_command_in_queue('s',MIN_SPEED);
             direction_ref=RVS;             
        }   
       else
        {
             place_command_in_queue('a',0xFF);
             place_command_in_queue('s',MIN_SPEED); 
        }        
       

      /// place_command_in_queue('a',0xFF);
      // place_command_in_queue('s',0); 
      // place_command_in_queue('d',RVS);         //place command direction in queue    
      // direction = RVS;    
    
       check_encoder_cntr=0;    
       open_timer_in_no_enc_mode_cntr=0;   
       travelling_time=1;
     }    

           
    if(open_state==8)                         
     {  
      if(actual_speed==MIN_SPEED)                   //***\\
      {                                                     //***\\
        if(direction_ref!=RVS){place_command_in_queue('d',RVS);direction_ref=RVS;}  //***\\
        else               
        if(position>FirstofLockPos)
         {
            place_command_in_queue('b',OpLockTq); 
            place_command_in_queue('s',OpLockSp);  
            no_pulse_detect_flag=5;               //set flag for checking encoder 1 sec later 
            open_first_lck_cntr=1;   
            open_state=9;
         } 
        else open_state=10;   
      }     
     }  
     
   if(open_state==9) 
     {
       
       if(open_first_lck_cntr>20)        //stay in OpLockSp for 2 second
        {  
          if(no_pulse_detect_flag)open_state=10;
        }            
        
       if(position<FirstofLockPos)open_state=10; 

     }
     
    if(open_state==10)                         
     {
      if(position>open_ramp_pos[0] || no_pulse_detect_flag)  
        {
          place_command_in_queue('b',OpTorque);      //start with CLMaxSp/4 in high speed area  
          place_command_in_queue('s',OpMaxSp/4);
                           
          open_state=11;      
          no_pulse_detect_flag=5;               //set flag for checking encoder 1 sec later
          open_pre_ramp_cntr=1;                //start increasing speed ramp counter
        }
      else 
        {
          place_command_in_queue('b',OpTorque); 
          place_command_in_queue('s',OpMinSp);
                    
          open_state=30;                     //start with minimum speed in low speed area
          open_brake_cntr=1;
        }  
     }      
     
   if(open_state==11) 
     {
       if(open_pre_ramp_cntr>10)        //stay in opmaxsp/4 for 1 second
        {
           open_pre_ramp_cntr=0;
           open_state=12;
           open_state_12_cntr=0; 
           open_timer_in_no_enc_mode_cntr=1;   
           place_command_in_queue('a',20);
           place_command_in_queue('s',OpMaxSp);
           
        }  
     }      
   
   if(open_state==12) 
     {  

        if(open_timer_in_no_enc_mode_cntr>10)    //0.5 sec for receiving a pulse
         {
            if(no_pulse_detect_flag)             //if no pulse received after arrive in high speed
             {
                  dispaly_enc_cntr=10;          //display OPEN MODE MESSAGE for 1 sec
                  display_en=1;  
                  open_state=40;               //go to timing state instead encoder
                  position=0;   
               
             }  
         }   

     }

   if(open_state>10 && open_state<20)
     {
       if(position<open_ramp_pos[0] && no_pulse_detect_flag==0)open_state=20;      
     }       
  
   if(open_state>19 && open_state<30)   
     {
      if(position<open_ramp_pos[open_state-20])
       {
         if(open_state==20)place_command_in_queue('a',0xFF);            //apply maximium accelerate for the last step
         
         place_command_in_queue('s',open_ramp_sp[open_state-20]);
         open_state++;
       }
     }   
   
   if(open_state==30)   
    {
         if(check_encoder_cntr>20)
          {     
            if(OpParkEn=='y')place_command_in_queue('b',OpParkTq);
            open_state=0xFF;
            open_brake_cntr=0;       
            open_park_cntr=1;     
          } 
    } 
    
    
   if(open_state==40)   
    {
      tempi = DoorWidth;
      tempi = tempi/30;                                  //estimate decel time from DoorWidth parameter
     
      tempi = tempi * 140;
      tempi = tempi / OpMaxSp;      
      
      if(open_timer_in_no_enc_mode_cntr>tempi)             //BRAKE after 1.0 sec in CHECK ENCODER MODE
             {                                              //this time can chage in menu
                        place_command_in_queue('s',OpMinSp);
                        open_timer_in_no_enc_mode_cntr=0;
                        open_state=0xFF;   
                        check_encoder_cntr=0;                   //reset counter for reduce to park force   
                        open_brake_cntr=0;   
                        open_park_cntr=1;       
                        
                        open_undefined_pos_cntr=1;                     

             }                                          //after 4.0 seconds in park state => open_state=30
    }       
    
      
   if(open_state==0xFF)
    {
      if(open_park_cntr>OpParkTime && OpParkEn=='y')
       {
          place_command_in_queue('s',0); 
          place_command_in_queue('d',STP);       
         open_park_cntr=0;
       }
    } 
        
    
   if(open_state)
    {
      if(open_state<30)
        {
          if(travelling_time>TRAVELLING_TIME)
            {
              travelling_time=0;
              open_state=30;
            }
        }
    }     
    

  }    


     


   
   
//--------------------- KEY SCANNING  ------------------------------  
  if(dispaly_lfr_cntr)continue;
  if(dispaly_save_cntr)continue;

  if(pl_key_cntr)
   {
     if(PL_KEY)
       {
         if(pl_key_cntr==30)      //HOLD 3SEC FOR CAL   
          {                       //Detection MODE  
            pl_key_cntr=0xFF;             //disable auto-incr by t0-isr  
            if(page==0 || page==1)
             {
               page=21;      
               detection_mode_en=1;
               display_en=1;
             }
          }                 
       }   
     else
          {
            if(pl_key_cntr<30)
             {
                if(!demo_mode_en && !detection_mode_en && !manual_mode && !KP_mode_en && command!='c')
                  {
                     test_mode_en=1;
                     tempi = DemoDelay;
                     test_mode_timer =  tempi * 10;                     
                     command='c';                  
                  }
             }      //Test Mode 
            pl_key_cntr=0;          
          }     
   } 
   
  if(mn_key_cntr)
   {
     if(MN_KEY)
       {
         if(mn_key_cntr==30)      //HOLD 3SEC FOR CAL   
          {                       //Detection MODE  
            mn_key_cntr=0xFF;             //disable auto-incr by t0-isr  
            if(!detection_mode_en && !demo_mode_en)
               {
                manual_mode=1;
                test_mode_en=0;  
                page=1;
               }
            display_en=1;
          }                 
       }
      else mn_key_cntr=0; 
   }  
   
  if(en_key_cntr)
   {
     if(EN_KEY)
       {
         if(en_key_cntr==30)      //HOLD 3SEC FOR CAL   
          {                       //Detection MODE  
            en_key_cntr=0xFF;             //disable auto-incr by t0-isr  
            dispaly_save_cntr=20;
            save_changed_values_in_eeprom();       //SAVE  ALL PRESENT PARAMETERS IN A/B/C
            display_en=1;
          }                 
       }
     else 
      {
       if(en_key_cntr==0xFF){en_key_cntr=0;continue;}
       en_key_cntr=0;     
       if(key_buf==0)key_buf='E';    
       key_navigation(key_buf);
       key_release=0;       
      }
   }             
   
         

  if(b_key_cntr)
   {
     if(B_KEY)
      {
       if(b_key_cntr==30)
         {   
           if(DefaultSet!='B')
            {         
              DefaultSet='B';EE_DefaultSet='B';B_LED=0;PORTF|=D_LED;//D_LED=1;   //B set factory defaults   
              load_from_eeprom_values_in_RAM('B');
            }   
           else 
            {
               load_original_values_to_eeprom();             //clear all modified values in eeprom
               load_from_eeprom_values_in_RAM('B');            //load original new values of eeprom in RAM
            }            
            
           b_key_cntr=0xFF;            //disable auto-incr by t0-isr    
           dispaly_lfr_cntr=40;                 //display msg factory reset for 2 sec
           display_en=1;
         }  
      }
     else b_key_cntr=0;      
   }      
   
  if(d_key_cntr)
   {
     if(D_KEY)
      {
       if(d_key_cntr==30)
         {  
           if(DefaultSet!='D')
            {         
               DefaultSet='D';EE_DefaultSet='D';B_LED=1;PORTF&=(~D_LED);//D_LED=0;      
               load_from_eeprom_values_in_RAM('D');
            }   
           else 
            {
               load_original_values_to_eeprom();             //clear all modified values in eeprom
               load_from_eeprom_values_in_RAM('D');            //load original new values of eeprom in RAM
            }            

           d_key_cntr=0xFF;            //disable auto-incr by t0-isr
           dispaly_lfr_cntr=40;                 //display msg factory reset for 2 sec
           display_en=1;
         }  
      }
     else d_key_cntr=0;      
   } 
   
  if(UP_KEY && DN_KEY)
    {
      if(up_dn_key_cntr==0)up_dn_key_cntr=1;
      if(up_dn_key_cntr==30)
       {
         up_dn_key_cntr=0xFF;
         demo_mode_en=1;     //GO TO DEMO MODE after 3 sec holding up and down keys
         demo_mode_timer=1;
         command='s';
         page=1;        
         display_en=1;
       }
    }
  else up_dn_key_cntr=0;            
   

  if(key_buf==0)
     {
       if(PL_KEY)if(!pl_key_cntr)pl_key_cntr=1; //play
       if(MN_KEY)if(!mn_key_cntr)mn_key_cntr=1; //menu   
       if(EN_KEY)if(!en_key_cntr)en_key_cntr=1; //menu   
       if(B_KEY)if(!b_key_cntr)b_key_cntr=1; //B
       if(D_KEY)if(!d_key_cntr)d_key_cntr=1; //C
 
       if(MN_KEY)key_buf='M';  //menu   
       else 
       if(UP_KEY)key_buf='U';  //up
       else
       if(DN_KEY)key_buf='D'; //down
 
             
       if(key_buf)
         {
           key_navigation(key_buf);
           key_release=0;
         } 
     } 
   else
     {
       if(!(MN_KEY || UP_KEY || DN_KEY || EN_KEY))
          {
           key_release++;
           if(key_release>10)
            {
             key_release=0;
             key_buf=0;
            }
          }
     }    
//--------------------- End of KEY SCANNING  --------------------------     

   
   if(display_en)
     { 
       display_en=0;
       display();
     }







  

}
  

}
