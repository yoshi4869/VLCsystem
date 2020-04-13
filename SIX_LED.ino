#define LED 8
#define H HIGH
#define L LOW
  int val = 20;//200もいい
//{0 1}={0001000 0011100}の２値で明暗を表現
//1bit = 5 times t
void pwm0(int led,float t){//00100=LLHLL
  digitalWrite(led,L);
  delayMicroseconds(t);
   digitalWrite(led,L);
  delayMicroseconds(t);
  digitalWrite(led,H);
  delayMicroseconds(t);
  digitalWrite(led,L);
  delayMicroseconds(t);
  digitalWrite(led,L);
  delayMicroseconds(t);
}
void pwm1(int led,float t){//01110=LHHHL
  digitalWrite(led,L);
  delayMicroseconds(t);
  digitalWrite(led,H);
  delayMicroseconds(t);
  digitalWrite(led,H);
  delayMicroseconds(t);
  digitalWrite(led,H);
  delayMicroseconds(t);
  digitalWrite(led,L);
  delayMicroseconds(t);
}

void head(int led,float t){//00000
  digitalWrite(led,L);
  delayMicroseconds(t);
  digitalWrite(led,L);
  delayMicroseconds(t);
  digitalWrite(led,L);
  delayMicroseconds(t);
  digitalWrite(led,L);
  delayMicroseconds(t);
  digitalWrite(led,L);
  delayMicroseconds(t);
}

void A(int led, float t){//7ビットで変換可能
  pwm1(led,t);
  pwm0(led,t);
  pwm0(led,t);
  pwm0(led,t);
  pwm0(led,t);
  pwm0(led,t);
  pwm1(led,t);
 // pwm0(led,t);//頭のビットは不要
  head(led,t);
}
//void data(int led,float t){
//  //送信情報は画面下から順に走査されるので，符号はすべて逆になる
//   //A
//A(led,t);
//A(led,t);
//A(led,t);
//A(led,t);
//}

void setup(){
  int pin = 8;
//  Serial.begin(9600);

  for(int i=pin;i < pin + 6;i++){
  pinMode(i,OUTPUT);
  }
}

void loop(){
  //rad = 23.5にたいして
   A(8,val);
   A(9,val);
   A(10,val);
   A(11,val);
   A(12,val);
   A(13,val);
}


