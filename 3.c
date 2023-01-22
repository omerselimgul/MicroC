#define input1 PORTA.B3
#define output1 PORTC.B2
unsigned short Ton=0;

void main(){
  PWM1_Init(1000);
  PWM1_Start();
  ADCON1=0;
  input1=1;
  output1=0;
  while(1){
    unsigned long readData=ADC_Read(3);
    Ton=(int)(readData/4);
    PWM1_Set_Duty(Ton);
    Delay_ms(500);
  }
}