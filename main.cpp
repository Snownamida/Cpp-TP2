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
    cout << "\n------- Select an action number --------" << endl;
    cout << " ______________________________________ " << endl;
    cout << "|                                      |" << endl;
    cout << "| Insert a Simple Journey............1 |" << endl;
    cout << "| Insert a Composite Journey.........2 |" << endl;
    cout << "| Show catalog.......................3 |" << endl;
    cout << "| Search path........................4 |" << endl;
    cout << "| Quit...............................5 |" << endl;
    cout << "|______________________________________|\n" << endl;

    char actionNumber;
    cout << ">     Input : ";
    cin >> actionNumber;

    char start[100], end[100], transportMethod[100];

    switch (actionNumber)
    {

    case '1':

      cout << "\n>     Start : ";
      cin >> start;

      cout << ">       End : ";
      cin >> end;

      cout << "> Transport : ";
      cin >> transportMethod;

        catalog.Add(new SimpleJourney(start, end, transportMethod));
        cout << endl;
        break;

    case '2':
    {
      cout << "\nInsert the Composite Journey step by step." << endl;
      CompositeJourney *pcompositeJourney = new CompositeJourney;

      do
      {

        cout << "\n>     Start : ";
        cin >> start;

        cout << ">       End : ";
        cin >> end;

        cout << "> Transport : ";
        cin >> transportMethod;

        pcompositeJourney->Add(new SimpleJourney(start, end, transportMethod));

        cout << "\nWould you like to input another segment of the journey? (y/n) : ";
        cin >> start;

      } while (start[0] == 'Y' || start[0] == 'y');

        catalog.Add(pcompositeJourney);
    }
      cout << endl;
      break;

    case '3':

      cout << "\n=---------------Catalog---------------= \n" << endl;
      cout << catalog << endl;
      cout << "\n=-------------------------------------= " << endl;
      break;

    case '4':

      cout << "\n>     Start : ";
      cin >> start;

      cout << ">       End : ";
      cin >> end;

      cout << "\n=-----------Result (" << start << " to " << end << ")-----------= \n" << endl;
      catalog.Search(start, end);
      cout << "=-------------------------------------= " << endl;

      cout << endl;
      break;

    case '5':

      return 0;

    default:

      cout << "Error: Please select a correct number." << endl;
    }
  }
  return 0;
}
