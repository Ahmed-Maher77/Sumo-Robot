#include <AFMotor.h>    // AFMotor kutubxonasini yuklab oling!!!
AF_DCMotor motor1(1);     
AF_DCMotor motor2(2);

int trigPin = 9;
int echoPin = 10;
int davomiylik, sm;

void plusUltra() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPin, LOW);
  davomiylik = pulseIn(echoPin, HIGH);
  sm = davomiylik / 58;
}

void setup() {
  //Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  delay(5000);             // 5 Sekund kutib turish
  motor1.setSpeed(255);    // Tezlik 0 dan 255 gacha o'zgartirish mumkin
  motor1.run(RELEASE);     
  motor2.setSpeed(255);    // Tezlik 2- Motor uchun
  motor2.run(RELEASE);    

}

void loop() {
plusUltra();
  //Serial.println(sm);
  if (sm > 1 && sm < 50) { //Agar 50 sm masofada biror raqib ko'rinsa 
    motor1.run(FORWARD);   //Oldinga yuri
    motor2.run(FORWARD);
    delay(300);
  } else {                 //Raqib ko'rinmasa 
    motor1.run(BACKWARD);  //O'nga burilib raqibni qidir
    motor2.run(FORWARD);
    delay(10);
  }
}
