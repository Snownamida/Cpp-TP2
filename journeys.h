#ifndef JOURNEYS_H_
#define JOURNEYS_H_

#include "journey.h"

struct NodeJourney {
  Journey *pjourney;
  NodeJourney *next;
};

class Journeys {
public:
  void show() const;
  friend std::ostream &operator<<(std::ostream &os, const Journeys &journeys);
  void add(Journey *pjourney);
  virtual ~Journeys();

protected:
  NodeJourney *_first = nullptr;
  NodeJourney *_last = nullptr;
};

#endif
