#define tus1 PORTB.B1
#define tus2 PORTB.B2
unsigned char Ton;
void main() {
     TRISB=255;
     TRISC=0;
     PWM1_Init(1000);
     Ton=16;
     PWM1_Start();
     PWM1_Set_Duty(Ton);
     while(1){
              if(tus1==0){
                Ton=Ton+16;
                if(Ton >= 255) Ton=255;
                PWM1_Set_Duty(Ton);
                while(tus1==0);
                Delay_ms(200);
              }
              if(tus2==0){
                Ton=Ton-16;
                if(Ton <= 0) Ton=0;
                while(tus2==0);
                PWM1_Set_Duty(Ton);
                Delay_ms(200);
              }
     
     }
     
}