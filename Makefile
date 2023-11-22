testJourney: testJourney.o journey.o simpleJourney.o journeys.o compositeJourney.o
	c++ -g testJourney.o journey.o simpleJourney.o journeys.o compositeJourney.o -o testJourney

testJourney.o: testJourney.cpp
	c++ -g -c testJourney.cpp -o testJourney.o

journey.o: journey.cpp journey.h
	c++ -g -c journey.cpp -o journey.o

simpleJourney.o: simpleJourney.cpp simpleJourney.h
	c++ -g -c simpleJourney.cpp -o simpleJourney.o

compositeJourney.o: compositeJourney.cpp compositeJourney.h
	c++ -g -c compositeJourney.cpp -o compositeJourney.o

journeys.o: journeys.cpp journeys.h
	c++ -g -c journeys.cpp -o journeys.o

clean:
	rm *.o testJourney