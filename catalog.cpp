#include "catalog.h"

std::ostream &operator<<(std::ostream &os, const Catalog &catalog) {
  catalog.show('\n');
  return os;
}