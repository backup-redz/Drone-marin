#include <SoftwareSerial.h>

SoftwareSerial commun (13, 4);
SoftwareSerial gps (7,8);
SoftwareSerial Blt (11, 12);

float latitude = 0.0;
float longitude = 0.0;
float route = 0.0;

char charac;
char charac2;
int vitesse = 250;
int vitesseR = 250;
int IN1 = 9;
int IN2 = 10;
int IN3 = 2;
int IN4 = 6;
int ENA = 3;
int ENB = 5;

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
