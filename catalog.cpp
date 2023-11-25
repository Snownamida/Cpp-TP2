#include "catalog.h"

std::ostream &operator<<(std::ostream &os, const Catalog &catalog) {
  catalog.show('\n');
  return os;
}

void Catalog::search(const char *from, const char *to) {}
