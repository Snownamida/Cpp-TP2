#include "journeys.h"
#include <iostream>

void Journeys::show() const {
  NodeJourney *nodeJourney = _first;
  while (nodeJourney) {
    std::cout << nodeJourney->journey;
    nodeJourney = nodeJourney->next;
    if (nodeJourney)
      std::cout << " | ";
  }
}

std::ostream &operator<<(std::ostream &os, const Journeys &journeys) {
  journeys.show();
  return os;
}

void Journeys::add(Journey *journey) {
  _last = _last->next = new NodeJourney{journey, nullptr};
  if (!_first)
    _first = _last;
}

Journeys::~Journeys() {
  while (_first) {
    _last = _first; // from here on, _last is only used as a temp var
    _first = _first->next;
    delete _last->journey;
    delete _last;
  }
}