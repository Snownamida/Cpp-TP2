#ifndef JOURNEY_H_
#define JOURNEY_H_

#include <cstring>
#include <iostream>

class Journey {
protected:
  const char *_from;
  const char *_to;

public:
  Journey(const char *start = "", const char *end = "");

  virtual void show(void) const;

  const char *getFrom(void) const { return _from; }
  const char *getTo(void) const { return _to; }

  friend std::ostream &operator<<(std::ostream &os, const Journey &journey);

  virtual ~Journey();
};

#endif
