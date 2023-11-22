#include "journey.h"
#include "journeys.h"
#include "simpleJourney.h"
#include <cstring>
#include <iostream>

using namespace std;

int main() {
  char start[100], end[100], transport[100];
  // cin >> start >> end;
  strcpy(start, "Paris");
  strcpy(end, "Tianjin");

  Journey journey1;
  Journey journey2(start, end);

  cout << journey1 << endl << journey2 << endl;

  // cin >> start >> end >> transport;
  strcpy(start, "Villeurbanne");
  strcpy(end, "Saint-Etienne");
  strcpy(transport, "car");

  SimpleJourney simpleJourney1;
  SimpleJourney simpleJourney2(start, end, transport);

  cout << simpleJourney1 << endl << simpleJourney2 << endl;

  Journeys journeys;
  cout << journeys << endl;
  journeys.add(new SimpleJourney("Nanjing", "Beijing", "train"));
  cout << journeys << endl;
  journeys.add(new SimpleJourney("Lyon", "Tokyo", "plane"));
  cout << journeys << endl;

  return 0;
}