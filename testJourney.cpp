#include "journey.h"
#include <iostream>

using namespace std;

int main() {
  char start[100], end[100];
  cin >> start >> end;

  Journey journey1;
  Journey journey2(start, end);

  cout << journey1 << endl << journey2 << endl;

  return 0;
}