#include "journey.h"
#include "simpleJourney.h"
#include <iostream>

using namespace std;

int main() {
  char start[100], end[100], transport[100];
  cin >> start >> end;

  Journey journey1;
  Journey journey2(start, end);

  cout << journey1 << endl << journey2 << endl;

  cin >> start >> end >> transport;

  SimpleJourney simpleJourney1;
  SimpleJourney simpleJourney2(start, end, transport);

  cout << simpleJourney1 << endl << simpleJourney2 << endl;

  return 0;
}