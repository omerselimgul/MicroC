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
int deger=250;
void main() {
      TRISB=0;
      TRISC.B0 = 1;
      Trisc.B2=0;
      trisc.B6=1;
      trisc.b7=1;
      PWM1_Init(1000);
      PWM1_Start();
      PWM1_Set_Duty(deger);


      while(1){
           if(portc.b6==0){
             deger=deger+50;
             PWM1_Set_Duty(deger);
             
             while(portc.b6==0);
           }
           else if(PORTc.B7==0){
             deger=deger-50;
             PWM1_Set_Duty(deger);
             while(PORTc.B7==0);
           }
      }
}