#include "journey.h"

Journey::Journey(const char *start, const char *end)
    : _start(strdup(start)), _end(strdup(end)) {}

void Journey::show(void) const { std::cout << _start << " -->" << _end; }

std::ostream &operator<<(std::ostream &os, const Journey &journey) {
  journey.show();
  return os;
}

Journey::~Journey() {
  delete [] _start;
  delete [] _end;
}