void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  gps.begin(9600);

  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);

  avant();
  debug("avant");
  delay(500);
  debug("arriere");
  arriere();
  delay(500);
  debug("droite");
  droite();
  delay(500);
  debug("gauche");
  gauche();
  delay(500);
  debug("STOP");
  Stop();
  debug("Le programme se lance !");  
}
