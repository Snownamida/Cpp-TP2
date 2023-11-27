#include "journey.h"

void Journey::show(void) const { std::cout << _from << " --> " << _to; }

std::ostream &operator<<(std::ostream &os, const Journey &journey) {
  journey.show();
  return os;
}

Journey::~Journey() {
  //Using free instead of delete because the string was created with strdup(), which require a free
  free((char *)_from);
  free((char *)_to);
}
