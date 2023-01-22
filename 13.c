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
char deger[6];
unsigned int timess=0;
void interrupt(){
CCP1IF_bit = 0;
portb.b7=!portb.b7;
}

void main() {
     TRISB=0;
     TRISC.B0 = 1;
      T1CON = 0x01;
      CCP1CON = 0x0B;
      GIE_bit=1; // Global Int. izin
      PEIE_bit=1; //Periph. Int. izin
      CCP1IE_bit = 1; //CCP1 Int. izin
      TMR1L = 0x00;
      TMR1H = 0x00;

      CCPR1L = 0xD0;
      CCPR1H = 0x07;
      portb.B7=0;
      
      Lcd_Init();
      while(1){
         timess=TMR1H;
         timess=timess<<8;
         timess+=TMR1L;
         WordToStr(timess,deger);

         Lcd_Out(1,1,deger)  ;
      }
}