void loop() {
  // put your main code here, to run repeatedly:
        
  while (Blt.available() > 0) {
    charac = Blt.read();
    recep(charac);
  }
  while (commun.available() > 0) {
    charac2 = commun.read();
    recep_slave(charac);
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
}
