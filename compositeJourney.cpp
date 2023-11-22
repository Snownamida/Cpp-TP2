#include "compositeJourney.h"
#include <cstdlib>
#include <cstring>

int CompositeJourney::add(Journey *pjourney) {
  if (!_first) {
    Journeys::add(pjourney);
    free((char *)_from);
    free((char *)_to);
    _from = strdup(pjourney->getFrom());
    _to = strdup(pjourney->getTo());
    return 0;
  }

  if (std::strcmp(_last->pjourney->getTo(), pjourney->getFrom())) {
    delete pjourney;
    return -1;
  }
  Journeys::add(pjourney);
  free((char *)_to);
  _to = strdup(pjourney->getTo());
  return 0;
}

std::ostream &operator<<(std::ostream &os,
                         const CompositeJourney &compositeJourney) {
  compositeJourney.Journeys::show();
  return os;
}