#include "compositeJourney.h"
#include <cstdlib>
#include <cstring>

int CompositeJourney::Add(Journey *pjourney, bool check) {
  if (!journeyLinkedList.getFirst()) {
    Journeys::Add(pjourney);
    free((char *)_from);
    free((char *)_to);
    _from = strdup(pjourney->GetFrom());
    _to = strdup(pjourney->GetTo());
    return 0;
  }

  if (check && std::strcmp(journeyLinkedList.getLast()->pdata->GetTo(),
                           pjourney->GetFrom())) {
    delete pjourney;
    return -1;
  }
  Journeys::Add(pjourney);
  free((char *)_to);
  _to = strdup(pjourney->GetTo());
  return 0;
}

void CompositeJourney::show(void) const { Journeys::show(); };

std::ostream &operator<<(std::ostream &os,
                         const CompositeJourney &compositeJourney) {
  compositeJourney.show();
  return os;
}