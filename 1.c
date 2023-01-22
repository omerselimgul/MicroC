#define disp0 PORTC.B0
// Sol display kontrol pin
#define disp1 PORTC.B1
// Sa� display kontrol pin
unsigned char birler,onlar, sayac=0;
unsigned int display[ ]= {0x3F, 0x06, 0x5B, 0x4F, 0x66,
0x6D, 0x7D, 0x07, 0x7F, 0x6F};

void main()
{
TRISC = 0; // Port C ��k��
TRISB = 0; // Port B ��k��
disp0= 0; // 1.Display pasif
disp1= 0; // 2..Display pasif
while(1)
{
  onlar=sayac/10; //tamsay� b�lme ile sol digit de�eri bul
  PORTB=display[onlar]; //display verisini Port�a yaz
  disp1= 1; //Sol display aktifle
  delay_ms(10); // 10ms bekle
  disp1= 0; //Sol display pasif
  birler=sayac%10; //Mod(10) kalan� verir, Sayac de�eri sa�digit bul,
  PORTB=display[birler]; // Display kodunu Port�a yaz
  disp0= 1; //Sa� displayi aktifle
   disp1= 1; //Sol display aktifle
  delay_ms(10); // 10ms bekle
  disp1= 0; //Sol display pasif
  birler=sayac%10; //Mod(10) kalan� verir, Sayac de�eri sa� digit bul,
  PORTB=display[birler];  // Display kodunu Port�a yaz
  disp0= 1;  //Sa� displayi aktifle

  delay_ms(10); // display 10ms aktif
  disp0= 0; // Sa� display pasif
  sayac++;
  if (sayac>99) {
     sayac=0;
    delay_ms(300); // Sayac de�i�im h�z�
  }
}
}



