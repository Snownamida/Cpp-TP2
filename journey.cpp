#include "journey.h"
#include <cstring>

Journey::Journey(const char *start, const char *end)
    : _start(strdup(start)), _end(strdup(end)) {}

void Journey::show(void) const { std::cout << _start << " --> " << _end; }

std::ostream &operator<<(std::ostream &os, const Journey &journey) {
  journey.show();
  return os;
}

Journey::~Journey() {
  free((char *)_start);
  free((char *)_end);
}

