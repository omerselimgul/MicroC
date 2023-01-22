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

char cevir[6];
char gerilim[12];
unsigned int veri10bit;
float volt;
void bekle(){ Delay_ms(100);}
void main(){
  Lcd_Init();
  Lcd_Cmd(_LCD_CLEAR);
  Lcd_Cmd(_LCD_CURSOR_OFF);
  Delay_ms(100);
  TRISA=0x255;
  ADCON1=0x80;
  ADC_Init();
  do{
    veri10bit= ADC_Read(2);
    WordToStr(veri10bit,cevir);
    Lcd_Out(1,2,"Data=");
    Lcd_Out(1,7,cevir);
    volt=veri10bit*5;
    volt=volt/1024;
    FloatToStr(volt,gerilim);
    Lcd_Out(2,2,gerilim);
    Lcd_Out(2,12,"V");
    Delay_ms(200);
    Lcd_Cmd(_LCD_CLEAR);
  }while(1);


}