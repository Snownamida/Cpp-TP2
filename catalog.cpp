#include "catalog.h"
#include <cstring>
#include <ostream>

std::ostream &operator<<(std::ostream &os, const Catalog &catalog) {
  catalog.show('\n');
  return os;
}

PathNode *Catalog::search(const char *const from, const char *const to,
                          PathNode *pathNode) {
  if (!strcmp(from, to)) {
    LinkedList<Journey> path;

    while (pathNode->pjourney) {
      path.add(pathNode->pjourney, false);
      pathNode = pathNode->lastPathNode;
    }

    for (auto nodeJourney = path.getFirst(); nodeJourney;
         nodeJourney = nodeJourney->next) {
      std::cout << *(nodeJourney->pdata) << std::endl;
    }

    std::cout << std::endl;
    return nullptr;
  }
  if (!pathNode)
    pathNode = new PathNode{nullptr, nullptr};

  for (auto nodeJourney = journeyLinkedList.getFirst(); nodeJourney;
       nodeJourney = nodeJourney->next) {
    if (!strcmp(nodeJourney->pdata->getFrom(), from)) {
      auto nextPathNode = new PathNode{nodeJourney->pdata, pathNode};
      pathNode->nextPathNodes.add(nextPathNode);
      search(nodeJourney->pdata->getTo(), to, nextPathNode);
    }
  }

  // std::cout << *(pathHead.pathNodes.getFirst()->pdata->pjourney);
  return pathNode;
}
