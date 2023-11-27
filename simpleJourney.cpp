#include "simpleJourney.h"

SimpleJourney::SimpleJourney(const char *start, const char *end,
                             const char *transportMethod)
    : Journey(start, end), _transportMethod(strdup(transportMethod)) {}

void SimpleJourney::show(void) const {
  std::cout << _from << " --(" << _transportMethod << ")-> " << _to;
}

//Using free instead of delete because the string was created with strdup(), which require a free
SimpleJourney::~SimpleJourney() { free((char *)_transportMethod); }