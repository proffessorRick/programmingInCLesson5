///////////////////////////////////////////////////////////////////////////////////////////////////////
//// INCLUDE OTHER FILES //////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
#include "common.h"
#include "main.h"
#include "mathFunc.h"

float get_angle(int x1, int y1, int x2, int y2, SDL_Texture *txtr) {
  // We Make Sure We Have Our Variables //
  double pythagoras, sinusRule, arcTangus = 0;
  int h = 0;

  // We Want To Know Where Blorp Is //
  SDL_QueryTexture(txtr, NULL, NULL, NULL, &h);

  // Just To Keep Everything A Bit Organized //
  double answerA, answerB;
  
  // We Use Pyhtagaros To Calculate A Diagonal Distance Between Blorp And Mouse //
  answerA = pow((x2 - x1), 2);
  answerB = pow((y2 - y1), 2);
  pythagoras = sqrt(answerA + answerB);

  // After That We Use pythagoras And The Sinus Rule To Calulate Our Degree //
  answerA = h / 3.75;
  answerB = sin(90) / pythagoras;
  sinusRule = asin(answerA * answerB);

  // Now We Calculte It's Opposite //
  answerA = y2 - y1;
  answerB = x2 - x1;
  arcTangus = atan2(answerA, answerB);

  // We Calculate All Our Results And Transform It Into Degrees //
  answerA = arcTangus - sinusRule;
  answerB = 180 / PI;

  return (float)(answerA * answerB);
}
