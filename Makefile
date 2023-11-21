testJourney: testJourney.o journey.o
	c++ -g testJourney.o journey.o -o testJourney

testJourney.o: testJourney.cpp
	c++ -g -c testJourney.cpp -o testJourney.o

journey.o: journey.cpp journey.h
	c++ -g -c journey.cpp -o journey.o

clean:
	rm *.o testJourney