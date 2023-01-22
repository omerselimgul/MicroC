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
unsigned int deger;
unsigned int pwmDeger=0;
char cevir[6];
void main() {
  TRISA=0xff;
  TRISB=0;
  TRISC=0;
  PORTC=0;
  Lcd_Init();
  Lcd_Cmd(_LCD_CLEAR);
  Lcd_Cmd(_LCD_CURSOR_OFF);
  ADC_Init();

  deger=ADC_Read(3);
  pwmDeger=deger/4;
  WordToStr(deger,cevir);
  Lcd_Out(1,1,cevir);
  PWM1_Init(1000);
  PWM1_Start();
  PWM1_Set_Duty(pwmDeger);
  
  while(1){
  deger=ADC_Read(3);
  pwmDeger=deger/4;
  PWM1_Set_Duty(pwmDeger);
  WordToStr(deger,cevir);
  Lcd_Out(1,1,cevir);

  }
}