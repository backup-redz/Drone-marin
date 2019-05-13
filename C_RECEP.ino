void recep (char lettre) { // bluetooth
  Serial.println("on recoit du blt");
  Serial.println(lettre);
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
    case'K':
    Stop();
    break;
    
    case 'E':
    {
      char localCharac;
      commun.print('E');
      while (Blt.available() > 0 ) {
        delay(8); // etre sur de recevoir le prochain char
        localCharac = Blt.read();
        Serial.print(localCharac);
        commun.print(localCharac);
        if (localCharac == '$') {
          break;
        }
      }
    }
    break;
    case 'G':
    {
      Serial.println("on va recevoir les pos gps");
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
        Serial.print("Lat : ");
        Serial.println(positionsGPS[i*2]);
        Serial.print("Long : ");
        Serial.println(positionsGPS[i*2+1]);
      }
    }
    break;
    case 'Q':
      Serial.println("Q sent");
      commun.print('Q');
    break;
    case '+':
    Serial.println("On recoit ss ok");
      while (Blt.read() != 'K') {
        delay(10);
      }
      delay(10);
      Blt.read();
    break;
  }
}
