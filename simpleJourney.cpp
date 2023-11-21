#include "simpleJourney.h"
#include <cstring>

SimpleJourney::SimpleJourney(const char *start, const char *end,
                             const char *transportMethod)
    : Journey(start, end), _transportMethod(strdup(transportMethod)) {}

void SimpleJourney::show(void) const {
  std::cout << _start << " --(" << _transportMethod << ")-> " << _end;
}

SimpleJourney::~SimpleJourney() { free((char *)_transportMethod); }