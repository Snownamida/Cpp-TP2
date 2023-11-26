#ifndef SIMPLEJOURNEY_H_
#define SIMPLEJOURNEY_H_

#include "journey.h"

class SimpleJourney : public Journey {
protected:
  const char *_transportMethod;

public:
  SimpleJourney(const char *start = "", const char *end = "",
                const char *transportMethod = "");

  virtual ~SimpleJourney();

private:
  void show(void) const;
};

#endif
