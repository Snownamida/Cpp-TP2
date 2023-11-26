#include "catalog.h"
#include <cstring>
#include <ostream>

std::ostream &operator<<(std::ostream &os, const Catalog &catalog) {
  catalog.show('\n');
  return os;
}

PathNode *Catalog::search(const char *from, const char *to,
                          PathNode *pathNode) {
  if (!strcmp(from, to)) {
    // LinkedList<Journey> path;
    // auto currentPathHead = &pathNode;
    // while (currentPathHead) {

    //   std::cout << *(currentPathHead->pjourney) << std::endl;
    //   path.add(currentPathHead->pjourney, false);
    //   currentPathHead = currentPathHead->plastPathNode;
    // }

    // auto nodeJourney = path.getFirst();
    // while (nodeJourney) {
    //   std::cout << *(nodeJourney->pdata) << std::endl;
    //   nodeJourney = nodeJourney->next;
    // }

    return nullptr;
  }
  if (!pathNode)
    pathNode = new PathNode{nullptr, nullptr};

  auto nodeJourney = journeyLinkedList.getFirst();
  while (nodeJourney) {
    if (!strcmp(nodeJourney->pdata->getFrom(), from)) {
      auto subNode = new PathNode{nodeJourney->pdata, pathNode};
      pathNode->nextPathNodes.add(subNode);
      search(nodeJourney->pdata->getTo(), to, subNode);
    }
    nodeJourney = nodeJourney->next;
  }

  // std::cout << *(pathHead.pathNodes.getFirst()->pdata->pjourney);
  return pathNode;
}
