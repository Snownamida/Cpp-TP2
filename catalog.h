#ifndef CATALOG_H_
#define CATALOG_H_

#include "journeys.h"

class Catalog : public Journeys {
protected:
public:
  friend std::ostream &operator<<(std::ostream &os, const Catalog &Catalog);
  void search(const char *from, const char *to);
};

#endif
