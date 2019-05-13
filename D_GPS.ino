// to know if the trame is GPRMC
int isGPRMC(String trameGPS) {
  if(trameGPS[0] == '$' && trameGPS[1] == 'G' && trameGPS[2] == 'P' && trameGPS[3] == 'R' && trameGPS[4] == 'M' && trameGPS[5] == 'C')
    return 1;
  else
    return 0;
}

// to get Latitude from GPRMC trame
float parseLat(String latrame) {
  String fLat = getStringPartByNr(latrame, ',', 3);
  String part1 = String(fLat.charAt(0))+String(fLat.charAt(1));
  String part2 = "";
  if (part1 != "") {
    for (int a = 2; a < fLat.length();a++) {
      part2 = part2 + fLat.charAt(a);
    }
    float npart2 = part2.toFloat();
    float npart1 = part1.toFloat();
    float calcul = npart1 + npart2/60;
    return calcul;
  } else return 0.0;
}

float parseLong(String latrame) {
  String fLong = getStringPartByNr(latrame, ',', 5);
  String part1 = String(fLong.charAt(0))+String(fLong.charAt(1))+String(fLong.charAt(2));
  String part2 = "";
  if (part1 != "") {
    for (int a = 3; a < fLong.length();a++) {
      part2 = part2 + fLong.charAt(a);
    }
    float npart2 = part2.toFloat();
    float npart1 = part1.toFloat();
    float calcul = npart1 + npart2/60;
    return calcul;
  } else {
    return 0.0;
  }
}

float parseRoute(String latrame) {
  String routeStr = getStringPartByNr(latrame, ',', 8);
  return routeStr.toFloat();
}

int getGPSPos (float *lati, float *longi) {
  
  String trame = "$";
  byte trameLength = 1;
  delay(10);
  while (gps.available() > 0 && gps.peek() != '$' && gps.peek() != '*') {
    delay(7);
    Serial.print(gps.peek());
    trame.concat(gps.read());
    trameLength++;
    if (trameLength > 147) {
      trameLength = 0;
      break;
    }
    delay(10);
  }
  if (trameLength != 0) { // si tout c'est bien passe
    trameLength = 0;
    if (isGPRMC(trame)) {
      latitude = parseLat(trame);
      longitude = parseLong(trame);
      route = parseRoute(trame);
      Serial.println("pos updated :");
      Serial.print(latitude, 5); Serial.print(",");
      Serial.println(longitude, 5);
      return GPS_SUCCES;
    }
  }
  Serial.println("gps Failure");
  return GPS_FAILURE;
}
