#ifndef CATALOG_H_
#define CATALOG_H_

#include "journeys.h"

struct PathNode
{
  Journey *pjourney;
  PathNode *lastPathNode;
  LinkedList<PathNode> nextPathNodes;
  unsigned int refCount = 0;
};

class Catalog : public Journeys
{
protected:
  PathNode pathRoot{nullptr, nullptr};

public:
  friend std::ostream &operator<<(std::ostream &os, const Catalog &Catalog);
  void Search(const char *const from, const char *const to,
              PathNode *pathHead = nullptr);
};

#endif
