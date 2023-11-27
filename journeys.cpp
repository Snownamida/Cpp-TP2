#include "journeys.h"
#include <ostream>

void Journeys::show(const char sep) const
{
  Node<Journey> *nodeJourney = journeyLinkedList.getFirst();

  for (unsigned int i = 1; nodeJourney; i++)
  {
    if (sep == '\n')
      std::cout << i << ". ";

    std::cout << *nodeJourney->pdata;
    nodeJourney = nodeJourney->next;

    if (nodeJourney)
      std::cout << sep;
  }
}

std::ostream &operator<<(std::ostream &os, const Journeys &journeys)
{
  journeys.show();
  return os;
}
