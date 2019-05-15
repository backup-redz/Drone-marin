void loop() {
  // put your main code here, to run repeatedly:
        
  while (Blt.available() > 0) {
    charac = Blt.read();
    recep(charac);
  }
  commun.listen();
  if (commun.available() > 0) {
    charac2 = commun.read();
    recep_slave(charac2);
  }
  while (gps.available() > 0) {
    Serial.print(gps.peek());
    if (gps.read() == '$') {
      if (getGPSPos(&latitude, &longitude) == GPS_SUCCES) {
        break; // si on a obtenu une nouvelle pos GPS alors on quitte la boucle
      }
    }
    delay(5);
  }
  if (Serial.available() > 0) {
    commun.write(Serial.read());
  }
}
