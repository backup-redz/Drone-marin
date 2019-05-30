void setup() {
  // put your setup code here, to run once:
  
  pinMode(MOTOR_A1_PIN, OUTPUT);
  pinMode(MOTOR_B1_PIN, OUTPUT);

  pinMode(MOTOR_A2_PIN, OUTPUT);
  pinMode(MOTOR_B2_PIN, OUTPUT);

  pinMode(PWM_MOTOR_1, OUTPUT);
  pinMode(PWM_MOTOR_2, OUTPUT);

  pinMode(CURRENT_SEN_1, OUTPUT);
  pinMode(CURRENT_SEN_2, OUTPUT);

  pinMode(EN_PIN_1, OUTPUT);
  pinMode(EN_PIN_2, OUTPUT);

  Serial.begin(9600);
  gps.begin(9600);

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
