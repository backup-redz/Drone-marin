void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    char charac = Serial.read();
    recep(charac);
    //Serial.print(charac);
  }
  gps.flush();
}
