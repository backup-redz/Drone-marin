void loop() {
  // put your main code here, to run repeatedly:
  
  if (Serial.available() > 0) {
    char charac = Serial.read();
    recep(charac);
  }
  
  while (gps.available() > 0) {
    //Serial.print(gps.peek());
    if (gps.read() == '$') {
      if (getGPSPos(&latitude, &longitude) == GPS_SUCCES) {
        break; // si on a obtenu une nouvelle pos GPS alors on quitte la boucle
      }
    }
    delay(15);    
  }
}
