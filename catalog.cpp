#include "catalog.h"
#include <cstring>
#include <ostream>

std::ostream &operator<<(std::ostream &os, const Catalog &catalog) {
  catalog.show('\n');
  return os;
}

void Catalog::search(const char *const from, const char *const to,
                     PathNode *pathNode) {
  if (!strcmp(from, to)) {
    LinkedList<Journey> path;

    while (pathNode && pathNode->pjourney) {
      path.add(pathNode->pjourney, false);
      pathNode = pathNode->lastPathNode;
    }

    for (Node<Journey> *nodeJourney = path.getFirst(); nodeJourney;
         nodeJourney = nodeJourney->next) {
      std::cout << *(nodeJourney->pdata) << std::endl;
    }

    std::cout << std::endl;
    return;
  }

  if (!pathNode) {
    pathNode = &pathRoot;
  }

  for (Node<Journey> *nodeJourney = journeyLinkedList.getFirst(); nodeJourney;
       nodeJourney = nodeJourney->next) {

    if (!strcmp(nodeJourney->pdata->getFrom(), from)) {

      PathNode *checkPathNode = pathNode;
      bool alreadyUsed = false;
      while (checkPathNode && checkPathNode->pjourney) {
        if (checkPathNode->pjourney == nodeJourney->pdata)
          alreadyUsed = true;
        checkPathNode = checkPathNode->lastPathNode;
      }
      if (alreadyUsed)
        continue;

      PathNode *nextPathNode = new PathNode{nodeJourney->pdata, pathNode};
      pathNode->nextPathNodes.add(nextPathNode);
      search(nodeJourney->pdata->getTo(), to, nextPathNode);
    }
  }
}
