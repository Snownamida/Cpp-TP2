#include "journeys.h"
#include <iostream>
#include <ostream>

void Journeys::show(const char sep) const {
  NodeJourney *nodeJourney = _first;
  unsigned int i = 0;
  while (nodeJourney) {
    i++;
    if (sep == '\n')
      std::cout << i << '.';
    std::cout << *nodeJourney->pjourney;
    nodeJourney = nodeJourney->next;
    if (nodeJourney)
      std::cout << sep;
  }
}

std::ostream &operator<<(std::ostream &os, const Journeys &journeys) {
  journeys.show();
  return os;
}

void Journeys::add(Journey *pjourney) {
  NodeJourney *nodeJourney = new NodeJourney{pjourney, nullptr};
  if (!_first)
    _first = _last = nodeJourney;
  else
    _last = _last->next = nodeJourney;
}

Journeys::~Journeys() {
  while (_first) {
    _last = _first; // from here on, _last is only used as a temp var
    _first = _first->next;
    delete _last->pjourney;
    delete _last;
  }
}