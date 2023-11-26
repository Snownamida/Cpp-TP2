testJourney: testJourney.o journey.o simpleJourney.o journeys.o compositeJourney.o catalog.o linkedList.o
	c++ -g testJourney.o journey.o simpleJourney.o journeys.o compositeJourney.o catalog.o linkedList.o -o testJourney

testJourney.o: testJourney.cpp
	c++ -g -c testJourney.cpp -o testJourney.o

journey.o: journey.cpp journey.h
	c++ -g -c journey.cpp -o journey.o

simpleJourney.o: simpleJourney.cpp simpleJourney.h
	c++ -g -c simpleJourney.cpp -o simpleJourney.o

compositeJourney.o: compositeJourney.cpp compositeJourney.h
	c++ -g -c compositeJourney.cpp -o compositeJourney.o

linkedList.o: linkedList.cpp linkedList.h
	c++ -g -c linkedList.cpp -o linkedList.o

journeys.o: journeys.cpp journeys.h
	c++ -g -c journeys.cpp -o journeys.o
	
catalog.o: catalog.cpp catalog.h
	c++ -g -c catalog.cpp -o catalog.o

clean:
	rm *.o testJourney