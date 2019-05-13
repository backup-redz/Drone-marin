void recep_slave (char lettre) { // commun
  Serial.println("on recoit du commun");
  delay(10);
  switch (lettre) {
    case 'Q':
      Blt.print('Q');
      while (commun.available() > 0 ) {
        delay(8); // etre sur de recevoir le prochain char
        char localCharac = commun.read();
        Blt.print(localCharac);
        if (localCharac == '$') {
          break;
        }
      }
    break;
  }
}
