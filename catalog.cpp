#include "catalog.h"
#include "compositeJourney.h"
#include <cstring>
#include <ostream>

std::ostream &operator<<(std::ostream &os, const Catalog &catalog) {
  catalog.show('\n');
  return os;
}

void Catalog::search(const char *from, const char *to) {
  CompositeJourney path;

  auto node = journeyLinkedList.getFirst();
  while (node) {
    if (!strcmp(node->pdata->getFrom(), from)) {
      path.add(node->pdata, false);
    }
    node = node->next;
  }
      std::cout << path << std::endl;
}
