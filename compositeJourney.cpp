#include "compositeJourney.h"
#include <cstdlib>
#include <cstring>

int CompositeJourney::add(Journey *pjourney, bool check) {
  if (!journeyLinkedList.getFirst()) {
    Journeys::add(pjourney);
    //Using free instead of delete because the string was created with strdup(), which require a free
    free((char *)_from); 
    free((char *)_to);
    _from = strdup(pjourney->getFrom());
    _to = strdup(pjourney->getTo());
    return 0;
  }

  if (check && std::strcmp(journeyLinkedList.getLast()->pdata->getTo(),
                           pjourney->getFrom())) {
    delete pjourney;
    return -1;
  }
  Journeys::add(pjourney);
  //Using free instead of delete because the string was created with strdup(), which require a free
  free((char *)_to);
  _to = strdup(pjourney->getTo());
  return 0;
}

void CompositeJourney::show(void) const { Journeys::show(); };

std::ostream &operator<<(std::ostream &os,
                         const CompositeJourney &compositeJourney) {
  compositeJourney.show();
  return os;
}