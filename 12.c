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

float tempdata=0.00;
char cevir[6];
void main() {
     trisA=0xff;
     trisB=0;
     trisC=0;
     Lcd_Init();
     Lcd_Cmd(_LCD_CURSOR_OFF);
     
     ADCON1=0x80;
     ADC_Init();
     Portc=0;
     while(1){
     tempdata=adc_read(3);
     tempdata=tempdata*5/1023;
     if(tempdata<2.5){
      portc.B0=1;
      Portc.B1=0;
     }else if(tempdata>=2.5 && tempdata<=3.5){
      portc.B0=0;
      Portc.B1=1;
     }
     else if(tempdata>3.5){
      portc.B0=1;
      Portc.B1=1;
     }
     FloatToStr(tempdata,cevir);
     Lcd_Out(1,1,cevir);
     Delay_ms(50);
     }
     

}