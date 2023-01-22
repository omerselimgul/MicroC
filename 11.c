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
unsigned int okunan;
char cevir[6];
void main() {

    TRISB=0;
    TRISA=0xFF;
    TRISC=0;
    PORTB.B7=1;
    Lcd_Init();
    Lcd_Cmd(_LCD_CURSOR_OFF);
    ADC_Init();
    // Timerla ilgili alan

    okunan=EEPROM_Read(0x4A);
    
    gelen=ADC_Read(3);
    WordToStr(okunan,cevir);
    Lcd_Out(2,1,"Before");
    Lcd_Out(2,7,cevir);

    while(1){
        gelen=ADC_Read(3);
        gelen=gelen/4;
        WordToStr(gelen,cevir);
        Lcd_Out(1,1,cevir);

        EEPROM_Write(0x4A,gelen);
        Delay_ms(50);
    }
}