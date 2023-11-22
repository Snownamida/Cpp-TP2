#ifndef COMPOSITEJOURNEY_H_
#define COMPOSITEJOURNEY_H_

#include "journey.h"
#include "journeys.h"

class CompositeJourney : public Journey, public Journeys {
public:
  // return value
  // 0  OK
  // -1 _to of the last journey != _from of the journey to add
  int add(Journey *journey); // important:should pass a new Journey* object,
                             // CompositeJourney will make the GC for it
  virtual void show(void) const;

  // we need to redifine << here because it exist in both Journey and Journeys
  friend std::ostream &operator<<(std::ostream &os,
                                  const CompositeJourney &compositeJourney);
};

#endif