#include "catalog.h"
#include "compositeJourney.h"
#include "simpleJourney.h"
#include <iostream>
#include <ostream>

using namespace std;

int main() {
  Catalog catalog;
  while (true) {
    cout << "Select an action number:" << endl;
    cout << "1. Insert a Simple Journey" << endl;
    cout << "2. Insert a Composite Journey" << endl;
    cout << "3. Show catalog" << endl;
    cout << "4. Search path" << endl;
    cout << "5. Quit" << endl;

    char actionNumber;
    cin >> actionNumber;

    char start[100], end[100], transportMethod[100];
    switch (actionNumber) {
    case '1':

      cout << "start: ";
      cin >> start;

      cout << "end: ";
      cin >> end;

      cout << "transportMethod: ";
      cin >> transportMethod;

      catalog.add(new SimpleJourney(start, end, transportMethod));
      cout << endl;
      break;
    case '2': {
      CompositeJourney *pcompositeJourney = new CompositeJourney;
      do {

        cout << "start: ";
        cin >> start;

        cout << "end: ";
        cin >> end;

        cout << "transportMethod: ";
        cin >> transportMethod;

        pcompositeJourney->add(new SimpleJourney(start, end, transportMethod));
        cout << endl;
        cout << "Would you like to input another segment of the journey? (Y/n) "
                ":";
        cin >> start;
      } while (start[0] == 'Y' || start[0] == 'y');
      catalog.add(pcompositeJourney);
    }
      cout << endl;
      break;
    case '3':
      cout << catalog << endl;
      cout << endl;
      break;
    case '4':

      cout << "start: ";
      cin >> start;

      cout << "end: ";
      cin >> end;
      catalog.search(start, end);
      cout << endl << endl;
      break;
    case '5':
      return 0;
    default:
      cout << "Error: Please select a correct number." << endl;
    }
  }

  return 0;
}
