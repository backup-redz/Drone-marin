void recep (char lettre) { // Serial
  
  if (lettre == ' ') {
    return;
  }
  if (lettre != 'B') {
     debug(String(lettre)); 
  }
  
  delay(10);
  switch (lettre) {
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
