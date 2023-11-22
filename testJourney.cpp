#include "catalog.h"
#include "compositeJourney.h"
#include "journey.h"
#include "journeys.h"
#include "simpleJourney.h"
#include <cstring>
#include <iostream>

using namespace std;

int main() {
  char start[100], end[100], transport[100];

  cout << "===========Test Journey Start===========" << endl;

  // cin >> start >> end;
  strcpy(start, "Paris");
  strcpy(end, "Tianjin");

  Journey journey1;
  Journey journey2(start, end);

  cout << journey1 << endl << journey2 << endl;
  cout << "===========Test Journey End===========" << endl;
  cout << endl << endl;

  cout << "===========Test SimpleJourney Start===========" << endl;

  // cin >> start >> end >> transport;
  strcpy(start, "Villeurbanne");
  strcpy(end, "Saint-Etienne");
  strcpy(transport, "car");

  SimpleJourney simpleJourney1;
  SimpleJourney simpleJourney2(start, end, transport);

  cout << simpleJourney1 << endl << simpleJourney2 << endl;

  cout << "===========Test SimpleJourney End===========" << endl;
  cout << endl << endl;

  cout << "===========Test Journeys Start===========" << endl;

  Journeys journeys;
  cout << journeys << endl;
  journeys.add(new SimpleJourney("Nanjing", "Beijing", "train"));
  cout << journeys << endl;
  journeys.add(new SimpleJourney("Lyon", "Tokyo", "plane"));
  cout << journeys << endl;
  cout << "===========Test Journeys End===========" << endl;

  cout << endl << endl;

  cout << "===========Test CompositeJourney Start===========" << endl;

  CompositeJourney compositeJourney;
  cout << compositeJourney << endl;
  compositeJourney.add(new SimpleJourney("Guangzhou", "Shenzhen", "bus"));
  cout << compositeJourney << endl;
  compositeJourney.add(new SimpleJourney("Shenzhen", "Honkong", "boat"));
  cout << compositeJourney << endl;
  compositeJourney.add(new SimpleJourney("Macao", "Taiwan", "boat"));
  cout << compositeJourney << endl;

  cout << "===========Test CompositeJourney End===========" << endl;
  cout << endl << endl;

  cout << "===========Test Catalog Start===========" << endl;

  Catalog catalog;
  cout << catalog << endl << endl;
  catalog.add(new Journey("Guangzhou", "Shenzhen"));
  cout << catalog << endl << endl;
  catalog.add(new SimpleJourney("Shenzhen", "Honkong", "boat"));
  cout << catalog << endl << endl;
  CompositeJourney *pcompositeJourney = new CompositeJourney;
  pcompositeJourney->add(new SimpleJourney("Wuhan", "Xiamen", "train"));
  pcompositeJourney->add(new SimpleJourney("Xiamen", "Fuzhou", "metro"));

  catalog.add(pcompositeJourney);
  cout << catalog << endl << endl;

  catalog.add(new SimpleJourney("Macao", "Taiwan", "boat"));
  cout << catalog << endl << endl;

  cout << "===========Test Catalog End===========" << endl;
  cout << endl << endl;

  return 0;
}