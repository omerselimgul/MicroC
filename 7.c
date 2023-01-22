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

unsigned short sayac=0;
unsigned short check=0;
char text[6];
void interrupt()
{ CCP1IF_bit = 0;
  sayac++;
  check=1;
  TMR1L = 0x00;
TMR1H = 0x00;
}

void main() {

     TRISB = 0;
     TRISC.B0=1;
     Lcd_Init();
     Lcd_Cmd(_LCD_CURSOR_OFF) ;
     T1CON = 0x03;
      CCP1CON = 0x0B;
      GIE_bit=1;
      PEIE_bit=1;
      CCP1IE_bit = 1;
      CCPR1L = 0x05;
      CCPR1H = 0x00;

TRISC.B0 = 1;
TMR1L = 0x00;
TMR1H = 0x00;
while(1)
{
if( check == 1)
{
  IntToStr(sayac,text);
  Lcd_Out(1,4,text);
  Lcd_Out(1,1,"test");
  check=0;
}

}


     
}