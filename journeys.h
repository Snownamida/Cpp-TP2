#ifndef JOURNEYS_H_
#define JOURNEYS_H_

#include "journey.h"
#include "linkedList.h"

class Journeys {
public:
  friend std::ostream &operator<<(std::ostream &os, const Journeys &journeys);

  // important:should pass a new Journey* object,
  // Journeys will make the GC for it
  void Add(Journey *pjourney) { journeyLinkedList.Add(pjourney); }
  unsigned int refCount = 0;

protected:
  LinkedList<Journey> journeyLinkedList;
  void show(const char sep = '|') const;
};

#endif
