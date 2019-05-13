void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  commun.begin(9600);
  gps.begin(9600);
  Blt.begin(9600);

  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);

  avant();
  Serial.println("avant");
  delay(500);
  Serial.println("arriere");
  arriere();
  delay(500);
  Serial.println("droite");
  droite();
  delay(500);
  Serial.println("stop");
  Stop();
  Serial.println("Le programme se lance !");
}
