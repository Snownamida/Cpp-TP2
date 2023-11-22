#ifndef JOURNEYS_H_
#define JOURNEYS_H_

#include "journey.h"

struct NodeJourney {
  Journey *pjourney;
  NodeJourney *next;
};

class Journeys {
public:
  void show(const char sep = '|') const;
  friend std::ostream &operator<<(std::ostream &os, const Journeys &journeys);
  void add(Journey *pjourney); // important:should pass a new Journey* object,
                               // Journeys will make the GC for it

  virtual ~Journeys();

protected:
  NodeJourney *_first = nullptr;
  NodeJourney *_last = nullptr;
};

#endif
