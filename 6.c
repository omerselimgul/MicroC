# define start_tus PORTB.B2
sbit LCD_RS at RB4_bit;
sbit LCD_EN at RB5_bit;
sbit LCD_D4 at RB0_bit;
sbit LCD_D5 at RB1_bit;
sbit LCD_D6 at RB2_bit;
sbit LCD_D7 at RB3_bit;
sbit LCD_RS_Direction at TRISB4_bit;
sbit LCD_EN_Direction at TRISB5_bit;
sbit LCD_D4_Direction at TRISB0_bit;
sbit LCD_D5_Direction at TRISB1_bit;
sbit LCD_D6_Direction at TRISB2_bit;
sbit LCD_D7_Direction at TRISB3_bit;

char text[6];
unsigned short sayac=1;
unsigned short clik=0;
int kontrol=0;

void interrupt()
{ 
  if(CCP1IF_bit){
  CCP1IF_bit = 0; //int. flag reset
  sayac++;; // bandý durdur
  kontrol=1;
  while(PORTC.B0==0);
  }
}

void main() {
  Lcd_Init();
  TRISB=0;
  TRISC = 1; // T1CKI pin giri
  Lcd_Cmd(_LCD_CURSOR_OFF);
  
  T1CON = 0x03;
  /*
  CCP1CON = 0x05;

  
  CCP1IE_bit = 1; //CCP1 Int. izin
  CCPR1L = 0x06;
  CCPR1H = 0x00;
  */
  TMR1L = 0x00;
  TMR1H = 0x00;
    GIE_bit=1; // Global Int. izin
  PEIE_bit=1; //Periph. Int. izin
  while(1){
      clik=TMR1L;
      ShortToStr(clik,text);
      Lcd_Out(2,5,text);
      
       Delay_ms(100);
       while(PORTC.B0==0);
             
      /*
     if(PORTC.B0==0){
      clik+=1;
      ShortToStr(clik,text);
      Lcd_Out(2,5,text);
      while(PORTC.B0==0);
      Delay_ms(100);
      }
       */

      /*
     if(kontrol){
       IntToStr(sayac,text);
       Lcd_Out(1,1,text);

       kontrol=0;
     }
      */
  }
}