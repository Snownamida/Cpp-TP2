#include "catalog.h"
#include <cstring>
#include <ostream>

std::ostream &operator<<(std::ostream &os, const Catalog &catalog) {
  catalog.show('\n');
  return os;
}

void Catalog::search(const char *from, const char *to, PathNode pathHead) {

  auto journeyNode = journeyLinkedList.getFirst();
  while (journeyNode) {
    if (!strcmp(journeyNode->pdata->getFrom(), from)) {
      std::cout << *(journeyNode->pdata) << std::endl;
      ;
      auto subNode = new PathNode{journeyNode->pdata, pathHead.pjourney};
      pathHead.pathNodes.add(subNode);
      search(journeyNode->pdata->getTo(), to, *subNode);
    }
    journeyNode = journeyNode->next;
  }

  // std::cout << *(pathHead.pathNodes.getFirst()->pdata->pjourney);
}
