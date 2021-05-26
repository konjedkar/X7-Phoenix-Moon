
//#define IRAMS             1         //Remark for using Discrete  

#define A_KEY            ((PINF&0x08)==0)
#define B_KEY            ((PINF&0x10)==0)
#define C_KEY             (PINE.7==0)
#define D_KEY            ((PINF&0x02)==0) 


#define PL_KEY           ((PINF & 0x20) ==0)
#define EN_KEY            (PINA.3==0)
#define DN_KEY            (PINA.4==0)
#define UP_KEY            (PINA.5==0)
#define MN_KEY            (PINA.6==0)

#define A_LED             PORTA.1
#define B_LED             PORTA.0
#define C_LED             (0b00000001)//PORTF.0
#define D_LED             (0b00000100)//PORTF.2
#define DIR_LED           PORTA.2

#define CL_cmd           (PINB.4==0)         ///input close command pin
#define OP_cmd           (PINB.5==0)         ///input open command pin 

#define MC3_RESET         PORTD.7

#define ENC_A             PINE.6            ///encoder pulse A pin    

#define EN_MOTOR          PORTE.2
#define U_PHASE           PORTE.3
#define V_PHASE           PORTE.4
#define W_PHASE           PORTE.5

#define SPI_RCK           PORTB.0
#define SPI_SCK           PORTB.1
#define SPI_SI            PORTB.2


#define STP    0x00
#define FWD    0x01
#define RVS    0x02     


#define CMD_INPUT_DEBOUNCE  10          //in 50ms for input debounce
#define TRAVELLING_TIME     200   

#define PROPAG_DELAY_US     20   //propagation time in uS   

#define DEMO_DELAY          100         //in 0.1sec     

#define BLINK_VALUE_ON_TIME   20
#define BLINK_VALUE_OFF_TIME  5   

#define UNDEF_POS_TIMER       15

#define DETECTION_TIME_OUT    15


//PWM motor command
#define FREQ_BASE       50U     // 50Hz
#define SPEED_BASE      (FREQ_BASE * 10U -5U)
#define SPEED_BOOST     1U//1U
#define A_BOOST_MIN     11U //7U 
#define MIN_SPEED       10  
#define MAX_SPEED       300    

//eeprom parameters
eeprom unsigned char EE_osccal=0xFF;

eeprom unsigned char EE_DefaultSet = 'B';

eeprom unsigned int  EE_DoorWidth = 770;
eeprom unsigned char EE_DoorDirection = 'f';   
eeprom unsigned char EE_InputCtrl = '1';
eeprom unsigned char EE_EncType = '2';
eeprom unsigned char EE_DemoDelay = 10;  

eeprom unsigned char EE_DoorType[2] ={'a','c'};

eeprom unsigned int  EE_OpMaxSp[2] = {160,140};
eeprom unsigned int  EE_ClMaxSp[2] = {140,120};

eeprom unsigned int  EE_OpMinSp[2] = {40,40};
eeprom unsigned int  EE_ClMinSp[2] = {50,30};        

eeprom unsigned int   EE_OpBrakePos[2] =  {150,150};
eeprom unsigned int   EE_ClBrakePos[2] =  {150,125};

eeprom unsigned char  EE_OpTorque[2] = {25,30};
eeprom unsigned char  EE_ClTorque[2] = {20,20}; 

eeprom unsigned int   EE_OpLockSp[2] = {40,40};  
eeprom unsigned char  EE_OpLockTq[2] = {30,30};   
eeprom unsigned char  EE_OpLockPos[2] = {85,85};

eeprom unsigned int   EE_ClLockSp[2] = {30,30};
eeprom unsigned char  EE_ClLockTq[2] = {30,35};
eeprom unsigned char  EE_ClLockPos[2] = {85,85};     

eeprom unsigned char  EE_OpDecel[2] = {70,45};
eeprom unsigned char  EE_ClDecel[2] = {80,50};

eeprom unsigned char  EE_KPOnOff[2] = {'n','n'};
eeprom unsigned char  EE_KPTime[2] = {20,20};  

eeprom unsigned char  EE_OpParkEn[2] = {'y','y'};       
eeprom unsigned char  EE_OpParkTime[2] = {0xFF,0xFF};  
eeprom unsigned char  EE_OpParkTq[2] = {15,15};

eeprom unsigned char  EE_ClParkEn[2] = {'y','y'};
eeprom unsigned char  EE_ClParkTime[2] = {0xFF,0xFF};
eeprom unsigned char  EE_ClParkTq[2] = {10,10};


//REGISTERS for fast calcualating
 unsigned char U_Phase_value_L=0,V_Phase_value_L=0,W_Phase_value_L=0;    
 unsigned char U_Phase_value_H=0,V_Phase_value_H=0,W_Phase_value_H=0;  
 
 unsigned long M=0;                                                                                
 unsigned char M_char=0,angle=0; 
 
 
 unsigned char Frequency_H,Frequency_L=0;
//end of REGISTERS for fast calcualating

 
 unsigned char Counter_for_H=0,Vboost=0,TCNT2_value=0;  


unsigned char  text_7seg[7],point=0;   


//parameters
unsigned char DefaultSet = 'B';

unsigned int  DoorWidth = 770;
unsigned char DoorDirection = 'f';   //'f' or 'r'
unsigned char InputCtrl = '1';
unsigned char EncType = '2';  
unsigned char DemoDelay = 10;  

unsigned char DoorType ='a';

unsigned int  OpMaxSp = 140;
unsigned int  ClMaxSp = 140;

unsigned int  OpMinSp = 40;
unsigned int  ClMinSp = 50;

unsigned char  OpTorque = 25;
unsigned char  ClTorque = 25;   

unsigned char  OpDecel = 80;
unsigned char  ClDecel = 80;

unsigned int   OpBrakePos =  200;
unsigned int   ClBrakePos =  175;

unsigned int   OpLockSp = 40;
unsigned char  OpLockTq = 30;
unsigned char  OpLockPos = 70; 

unsigned int   ClLockSp = 30;
unsigned char  ClLockTq = 30;
unsigned char  ClLockPos = 70;

unsigned char KPOnOff = 'n';
unsigned char KPTime = 20;  

unsigned char OpParkEn = 'y';
unsigned char OpParkTime = 0xFF;
unsigned char OpParkTq = 15;

unsigned char ClParkEn = 'y';
unsigned char ClParkTime = 0xFF;
unsigned char ClParkTq = 10;

unsigned char OPTout = 30;


unsigned int   DoorWidth_pulses,FirstofLockPos;
unsigned int   get_value_temp_i1,get_value_temp_i2,get_value_temp_i3,get_value_temp_i4;
unsigned char  get_value_temp_c1,get_value_temp_c2,menu_item=0,select_item=0,sub_select_item=0;

unsigned char  close_state=0,open_state=0;
unsigned char  no_pulse_detect_flag=0;      //shows how long no pulse has been detected
unsigned int   demo_mode_timer=0,test_mode_timer=0;
unsigned char  blink_led_test=0;
unsigned char  demo_mode_en=0,detection_mode_en=0,test_mode_en=0,KP_mode_en=0,manual_mode=0;
unsigned int   position=0xFFFF,kp_cntr=0;;
unsigned char  speed=0,direction=STP,direction_ref=STP,torque=0;    
unsigned char  command='s'; 


unsigned char  travelling_time=0,init_counter=0,encoder_state=0;
unsigned char  close_undefined_pos_cntr=0,open_undefined_pos_cntr=0;
unsigned char  close_park_cntr=0,open_park_cntr=0,check_encoder_cntr=0,open_first_lck_cntr=0;
unsigned char  close_pre_ramp_cntr=0,open_pre_ramp_cntr=0,close_timer_in_no_enc_mode_cntr=0,open_timer_in_no_enc_mode_cntr=0,QC_test_mode;
unsigned char  OP_cmd_cntr=0,CL_cmd_cntr=0,NO_cmd_cntr=0,close_brake_cntr=0,open_brake_cntr=0;
unsigned char  timer1_cntr=0,timer1_cntr_5=0,timer1_cntr_10=0;
unsigned char  pl_key_cntr=0,b_key_cntr=0,d_key_cntr=0,en_key_cntr=0,mn_key_cntr=0,up_dn_key_cntr=0;
unsigned char  dispaly_enc_cntr=0,dispaly_lfr_cntr=0,dispaly_save_cntr=0;
unsigned char  detection_mode_start_cntr=0,open_state_12_cntr=0,disp_dist=0,dispaly_done_cntr=0;
unsigned char  page=0,page_1_state=0,display_en=0,key_release=0,key_buf=0,blink_value_on=0,blink_value_off=0;   

unsigned int   close_ramp_pos[10];
unsigned int   close_ramp_sp[10]; 
unsigned int   open_ramp_pos[10];
unsigned int   open_ramp_sp[10];  

unsigned char  com_type_q[10]; 
unsigned int   com_para_q[10];



void calculate_close_ramp_pos_sp(void);
void calculate_open_ramp_pos_sp(void);


//Motor PWM variables

 unsigned char start_motor=0,ramp_up_cntr=0,ramp_down_cntr=0,deceleration=0,acceleration=0,stop_motor=0;
 
 
 
 unsigned int actual_speed=0,Speed_ref=0;    
 

 
 unsigned char enc_pulse_counter=0;
 
 bit new_freq=0,new_vboost=0,loop_delay_flag=1,calcualte_new_angle_val=0;
 
 
unsigned char place_command_in_queue(unsigned char ,unsigned int );
 
 
/*
unsigned char a_calc(unsigned char sine)
{
 unsigned int sine_temp;
 unsigned char sine1;   
 

 sine1=((sine<128)?~sine:sine);
 sine_temp=(((unsigned int)sine1)<<1);
 sine_temp-=255;
 sine_temp*=M;
 sine_temp>>=8;
 sine_temp+=255;
 sine_temp>>=1;
 sine_temp++;  
 sine1=(unsigned char)sine_temp;
 if (sine<128) sine1=~sine1;
 return sine1;
} */


