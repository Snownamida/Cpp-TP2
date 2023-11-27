#include "catalog.h"
#include "compositeJourney.h"
#include "simpleJourney.h"
#include <iostream>
#include <ostream>

using namespace std;

int main()
{

  cout << "\n   ______      __        __           \n  / ____/___ _/ /_____ _/ /___  ____ _\n / /   / __ `/ __/ __ `/ / __ \\/ __ `/\n/ /___/ /_/ / /_/ /_/ / / /_/ / /_/ / \n\\____/\\__,_/\\__/\\__,_/_/\\____/\\__, /  \n                             /____/   \n"
       << endl; // Just an ASCII art.
  Catalog catalog;

  while (true)
  {
    cout << "------- Select an action number: -------" << endl;
    cout << " ______________________________________ " << endl;
    cout << "|                                      |" << endl;
    cout << "| Insert a Simple Journey............1 |" << endl;
    cout << "| Insert a Composite Journey.........2 |" << endl;
    cout << "| Show catalog.......................3 |" << endl;
    cout << "| Search path........................4 |" << endl;
    cout << "| Quit...............................5 |" << endl;
    cout << "|______________________________________|" << endl;

    char actionNumber;
    cin >> actionNumber;

    char start[100], end[100], transportMethod[100];

    switch (actionNumber)
    {

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

    case '2':
    {
      cout << "Insert the Composite Journey step by step." << endl;
      CompositeJourney *pcompositeJourney = new CompositeJourney;

      do
      {

        cout << "start: ";
        cin >> start;

        cout << "end: ";
        cin >> end;

        cout << "transportMethod: ";
        cin >> transportMethod;

        pcompositeJourney->add(new SimpleJourney(start, end, transportMethod));

        cout << endl;
        cout << "Would you like to input another segment of the journey? (Y/n) :";
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

      cout << endl
           << endl;
      break;

    case '5':

      return 0;

    default:

      cout << "Error: Please select a correct number." << endl;
    }
  }
  return 0;
}
