void recep (char lettre) {
  delay(10);
  switch (lettre) {
    case'z':
    avant();
    break;
    case's':
    arriere();
    break;
    case'q':
    droite();
    break;
    case'd':
    gauche();
    break;
    case'S':
    Stop();
    break;
    
    case 'E':
    {
      char localCharac;
      Serial.print('E');
      while (Blt.available() > 0 ) {
        delay(8); // etre sur de recevoir le prochain char
        localCharac = Blt.read();
        Serial.print(localCharac);
        if (localCharac == '$') {
          break;
        }
      }
    }
    break;
    case 'G':
    {
      String cekejeresoi = "";
      char localCharac;
      while (Blt.available() > 0 ) {
        delay(8); // etre sur de recevoir le prochain char
        localCharac = Blt.read();
        if (localCharac == '$') {
          break;
        }
        cekejeresoi.concat(localCharac);
      }
      for (int i = 0; i < 5; i++) {
        positionsGPS[i*2] = getStringPartByNr(getStringPartByNr(cekejeresoi, ';', i), ',', 0).toDouble();
        positionsGPS[i*2+1] = getStringPartByNr(getStringPartByNr(cekejeresoi, ';', i), ',', 1).toDouble();
      }
    }
    break;
    case 'I':
      Serial.print('I');
    break;
  }
}
