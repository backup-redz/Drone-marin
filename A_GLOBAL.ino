#include <SoftwareSerial.h>

SoftwareSerial commun (6, 13);
SoftwareSerial gps (7, 8);
SoftwareSerial Blt (11, 12);

float latitude = 0.0;
float longitude = 0.0;
float route = 0.0;

char charac;
char charac2;
int vitesse = 250;
int vitesseR = 250;
byte IN1 = 9;
byte IN2 = 10;
byte IN3 = 2;
byte IN4 = 6;
byte ENA = 3;
byte ENB = 5;

double positionsGPS[10];

enum GPS_CODES {
  GPS_SUCCES,
  GPS_FAILURE
};

// functions prototypes
int isGPRMC(String trameGPS);
float parseLat(String latrame);
float parseLong(String latrame);
float parseRoute(String latrame);
int getGPSPos (float *lati, float *longi);

String getStringPartByNr(String data, char separator, int index);

void avant();
void arriere();
void droite();
void gauche();
void Stop();
void recep (char lettre);
void emptyBuffer ();
