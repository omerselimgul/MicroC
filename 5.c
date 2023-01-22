unsigned short tuskod,sayac;
char txt[6];
char keypadPort at PORTD;

//LCD Baðlantý

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


void main() {
  Lcd_Init();
  Lcd_Cmd(_LCD_CLEAR);
  Lcd_Cmd(_LCD_CURSOR_OFF);
  Lcd_Out(1, 1, "Aktif Tus:"); // lcd’ye mesaj yaz
  Lcd_Out(2, 1, "ASCII kod:");
  do{
     tuskod=0;
     do
       tuskod=Keypad_Key_Press();
     while(!tuskod);
     switch (tuskod)
     {
      case 1: tuskod = 49; break; // 1. buton (1)
      case 2: tuskod = 50; break; // 2. buton (2)
      case 3: tuskod = 51; break; // 3. buton (3)
      case 4: tuskod = 65; break; // 4. buton (A)
      case 5: tuskod = 52; break; // 5. buton (4)
      case 6: tuskod = 53; break; // 6. buton (5)
      case 7: tuskod = 54; break; // 7. buton (6)
      case 8: tuskod = 66; break; // 8. buton (B)
      case 9: tuskod = 55; break; // 9. buton (7)
      case 10: tuskod = 56; break; // 10. buton (8)
      case 11: tuskod = 57; break; // 11. buton (9)
      case 12: tuskod = 67; break; // 12. buton (C)
      case 13: tuskod = 42; break; // 13. buton (*)
      case 14: tuskod = 48; break; // 14. buton (0)
      case 15: tuskod = 35; break; // 15. buton (#)
      case 16: tuskod = 68; break; // 16. buton (D)
      }
      Lcd_Chr(1, 12, tuskod);
      byteToStr(tuskod, txt);
      Lcd_Out(2, 12, txt);

  }while(1);
}