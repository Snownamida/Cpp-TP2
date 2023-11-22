#include "simpleJourney.h"

SimpleJourney::SimpleJourney(const char *start, const char *end,
                             const char *transportMethod)
    : Journey(start, end), _transportMethod(strdup(transportMethod)) {}

void SimpleJourney::show(void) const {
  std::cout << _from << " --(" << _transportMethod << ")-> " << _to;
}

SimpleJourney::~SimpleJourney() { free((char *)_transportMethod); }