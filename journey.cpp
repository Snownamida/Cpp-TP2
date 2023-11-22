#include "journey.h"

Journey::Journey(const char *start, const char *end)
    : _from(strdup(start)), _to(strdup(end)) {}

void Journey::show(void) const { std::cout << _from << " --> " << _to; }

std::ostream &operator<<(std::ostream &os, const Journey &journey) {
  journey.show();
  return os;
}

Journey::~Journey() {
  free((char *)_from);
  free((char *)_to);
}
