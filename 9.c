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
unsigned int gelen;
char cevir[6];

void interrupt(){
     if(CCP1IF_bit){
        CCP1IF_bit=0;
        PORTB.B7=!PORTB.B7;
     }
     
}
void main() {

    TRISB=0;
    TRISA=0xFF;
    TRISC=0;
    PORTB.B7=1;
    Lcd_Init();
    Lcd_Cmd(_LCD_CURSOR_OFF);
    ADC_Init();
    // Timerla ilgili alan

    CCP1CON = 0x0B;
    T1CON=0x01;
    GIE_bit=1;
    PEIE_bit=1;
    CCP1IE_bit=1;

    gelen=ADC_Read(3);
    gelen=gelen*64;

    CCPR1L=gelen;
    CCPR1H=gelen>>8;
    TMR1H=0x00;
    TMR1L=0x00;
    while(1){
        gelen=ADC_Read(3);

        gelen=gelen*64;
        CCPR1L=gelen;
        CCPR1H=gelen>>8;

        WordToStr(gelen,cevir);
        Lcd_Out(1,1,cevir);
    }
}