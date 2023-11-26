trajets: trajets.o journey.o simpleJourney.o journeys.o compositeJourney.o catalog.o
	c++ -g trajets.o journey.o simpleJourney.o journeys.o compositeJourney.o catalog.o -o trajets

testJourney: testJourney.o journey.o simpleJourney.o journeys.o compositeJourney.o catalog.o
	c++ -g testJourney.o journey.o simpleJourney.o journeys.o compositeJourney.o catalog.o -o testJourney


trajets.o: main.cpp
	c++ -g -c main.cpp -o trajets.o
	
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
	
catalog.o: catalog.cpp catalog.h
	c++ -g -c catalog.cpp -o catalog.o

clean:
	rm *.o testJourney trajets