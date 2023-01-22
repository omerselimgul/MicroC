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
unsigned int sayma;
float frekans;
char cevir[6];

void interrupt()
{ 
if (CCP1IF_bit) // flag kontrol
  {
    CCP1IF_bit = 0;
    TMR1L=0;
    TMR1H=0;
    sayma=CCPR1H;
    sayma=sayma<<8;
    sayma=sayma+CCPR1L;
  }
if(TMR1IF_bit){
TMR1IF_bit=0;
sayma=46;
}
}
void main() {
sayma=0;
  TRISB=0;
  Lcd_Init();
  Lcd_Cmd(_LCD_CLEAR);
  Lcd_Cmd(_LCD_CURSOR_OFF);
  TRISC=0xff;
  T1CON = 0x31;
  CCP1CON = 0x05;
  CCPR1L = 0x00; // ilk deðer
  CCPR1H = 0x00; // ilk deðer
  INTCON.GIE =1; // GIE enable
  INTCON.PEIE=1; // PEIE enable
  TMR1IE_bit=1;
  CCP1IE_bit= 1; // CCP1 enable
  TMR1L = 0x00;
  TMR1H = 0x00; // Timer 1 ilk reset
  while(1){
    while(POrtC.B2==0);
    WordToStr(sayma,cevir);
    Lcd_Out(1,1,cevir);
  }
}