#ifndef CATALOG_H_
#define CATALOG_H_

#include "journeys.h"

struct PathNode {
  Journey *pjourney;
  Journey *plastJourney;
  LinkedList<PathNode> pathNodes;
  unsigned int refCount = 0;
};

class Catalog : public Journeys {
protected:
public:
  friend std::ostream &operator<<(std::ostream &os, const Catalog &Catalog);
  void search(const char *from, const char *to,
              PathNode pathHead = {nullptr, nullptr});
};

#endif
