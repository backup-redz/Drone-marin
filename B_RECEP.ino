void recep (char lettre) { // Serial
  
  if (lettre != 'B') {
     //debug(String(lettre)); 
     //Serial.print("on recoit ");
     //Serial.println(lettre);
  }
  
  delay(10);
  switch (lettre) {
    case 'A': // autonomous mode
      {
        String cekejeresoi = "";
        char localCharac;
        while (Serial.available() > 0 ) {
          delay(8); // etre sur de recevoir le prochain char
          localCharac = Serial.read();
          if (localCharac == '$') {
            break;
          }
          cekejeresoi.concat(localCharac);
        }
        targetY = getStringPartByNr(cekejeresoi, ',', 1).toDouble();
        targetX = getStringPartByNr(cekejeresoi, ',', 1).toDouble();
        autonomous = ENABLED;
        updateGPS();
        avant();
      }
    break;
    case 'z':
      avant();
    break;
    case 's':
      arriere();
    break;
    case 'q':
      droite();
    break;
    case 'd':
      gauche();
    break;
    case 'K':
      Stop();
      autonomous = DISABLED;
    break;
    case 'P': // get GPS position
      updateGPS();
    break;
    case 'B':
    {
      while (true) {
        delay(10);
        char test = Serial.read();
        if (test == '$') {
          break;
        }
      }
    }
  }
}
