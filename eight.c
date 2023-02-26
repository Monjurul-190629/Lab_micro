int input();
void delay(int x);
void display(int num);
unsigned char hexvalue[10] = {
  0x3F,
  0x06,
  0x5B,
  0x4F,
  0x66,
  0x6D,
  0x7D,
  0x07,
  0x7F,
  0x6F
};
int i=0,m,ii,kk;
int start=0,end=0;
void main() {
     TRISB=0x00;
     TRISC=0x00;
     TRISD=0xff;
     start=input();
     i=start+1;
     end=input();
     while(1){
         for(ii=start;ii<=end;ii++){
             display(ii);

         }
     }

}
// input from user
int input(){
while(1){
         // for display digit
         portb=hexvalue[(i/10)%10];
         portc.f0=0;
         delay_ms(1);
         portc.f0=1;

         portb=hexvalue[i%10];
         portc.f1=0;
         delay_ms(1);
         portc.f1=1;
          // for increase button
         if(portd.f0==1){
             delay_ms(200);
             if(portd.f0==1){
                 i++;
                 if(i>99){
                     i=0;
                 }
             }
         }
         //for decrease button
         if(portd.f1==1){
             delay_ms(200);
             if(portd.f1==1){
                 i--;
                 if(i<0){
                     i=0;
                 }
             }
         }
         // for ok button
         if(portd.f2==1){
             delay_ms(200);
             if(portd.f2==1){
                 return i;
             }
         }
     }
}
// for delay
void delay(int x){
    for(m=0;m<x;m++){
        delay_ms(1000);
    }
}

void display(int num){
 // for display digit
      for(kk=0;kk<160*5;kk++){
         portb=hexvalue[(num/10)%10];
         portc.f0=0;
         delay_ms(1);
         portc.f0=1;

         portb=hexvalue[num%10];
         portc.f1=0;
         delay_ms(1);
         portc.f1=1;

    }
}