unsigned char make_data(unsigned char CH,unsigned char dotst)    //0b (dp C A E D F G B) data order //0->ON and 1->OFF
{
 unsigned char md1=0xFF;
   
 if(CH=='0')md1 = 0b10000010;
 if(CH=='1')md1 = 0b10111110;
 if(CH=='2')md1 = 0b11000100;
 if(CH=='3')md1 = 0b10010100;
 if(CH=='4')md1 = 0b10111000;
 if(CH=='5')md1 = 0b10010001;
 if(CH=='6')md1 = 0b10000001;
 if(CH=='7')md1 = 0b10011110;
 if(CH=='8')md1 = 0b10000000;
 if(CH=='9')md1 = 0b10010000;
 if(CH=='A')md1 = 0b10001000;
 if(CH=='B')md1 = 0b10100001;
 if(CH=='C')md1 = 0b11000011;
 if(CH=='D')md1 = 0b10100100;             
 if(CH=='E')md1 = 0b11000001;
 if(CH=='F')md1 = 0b11001001;
 if(CH=='G')md1 = 0b10000011;
 if(CH=='H')md1 = 0b10101000;
 if(CH=='I')md1 = 0b11101011;
 if(CH=='J')md1 = 0b10100110;
 if(CH=='K')md1 = 0b10101000;
 if(CH=='L')md1 = 0b11100011;
 if(CH=='M')md1 = 0b10001111;
 if(CH=='N')md1 = 0b10101101;
 if(CH=='O')md1 = 0b10100101;
 if(CH=='P')md1 = 0b11001000;
 if(CH=='Q')md1 = 0b10011000;
 if(CH=='R')md1 = 0b11101101;
 if(CH=='S')md1 = 0b10010001;
 if(CH=='T')md1 = 0b11100001;
 if(CH=='U')md1 = 0b10100010;
 if(CH=='V')md1 = 0b10100111;
 if(CH=='W')md1 = 0b10000111;
 if(CH=='X')md1 = 0b10101000;
 if(CH=='Y')md1 = 0b10110000;
 if(CH=='Z')md1 = 0b11000100;
 if(CH=='.')md1 = 0b01111111;
 if(CH=='=')md1 = 0b11110101;
 if(CH==' ')md1 = 0b11111111; 
 if(CH=='(')md1 = 0b11000011;
 if(CH==')')md1 = 0b10010110; 
 if(CH=='-')md1 = 0b11111101; 
 
 if(dotst)md1 &= 0b01111111;
 return md1;
}    


// write the string str located in SRAM to the LCD
void sseg_puts(void)
{
  
   SPI_RCK=0;  
   
   if(point==6)spi(make_data(text_7seg[5],1)); else spi(make_data(text_7seg[5],0));
   if(point==5)spi(make_data(text_7seg[4],1)); else spi(make_data(text_7seg[4],0));
   if(point==4)spi(make_data(text_7seg[3],1)); else spi(make_data(text_7seg[3],0));
   if(point==3)spi(make_data(text_7seg[2],1)); else spi(make_data(text_7seg[2],0));
   if(point==2)spi(make_data(text_7seg[1],1)); else spi(make_data(text_7seg[1],0));
   if(point==1)spi(make_data(text_7seg[0],1)); else spi(make_data(text_7seg[0],0));
   

 // delay_us(PROPAG_DELAY_US); 
  SPI_RCK=1;
 // delay_us(PROPAG_DELAY_US);
 // delay_us(PROPAG_DELAY_US); 
  SPI_RCK=0;   

}

