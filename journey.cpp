#include "journey.h"

void Journey::show(void) const { std::cout << _from << " --> " << _to; }

std::ostream &operator<<(std::ostream &os, const Journey &journey)
{
  journey.show();
  return os;
}

Journey::~Journey()
{
  free((char *)_from);
  free((char *)_to);
}
