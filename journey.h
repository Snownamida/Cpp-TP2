#ifndef JOURNEY_H_
#define JOURNEY_H_

#include <iostream>

class Journey {
protected:
  const char *_start;
  const char *_end;

public:
  Journey(const char *start = "", const char *end = "");

  virtual void show(void) const;

  friend std::ostream &operator<<(std::ostream &os, const Journey &journey);

  virtual ~Journey();
};

#endif
