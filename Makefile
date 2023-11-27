CC = g++ # c++
CFLAGS = -Wall -g
TARGET = trajets
SRCS = main.cpp journey.cpp simpleJourney.cpp journeys.cpp compositeJourney.cpp catalog.cpp
OBJS = $(SRCS:.cpp=.o)

TEST = test
TESTSRCS = test.cpp journey.cpp simpleJourney.cpp journeys.cpp compositeJourney.cpp catalog.cpp
TESTOBJS = $(TESTSRCS:.cpp=.o)


$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(TEST): $(TESTOBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

journey.o: journey.h
simpleJourney.o: simpleJourney.h
compositeJourney.o: compositeJourney.h
journeys.o: journeys.h
catalog.o: catalog.h

.PHONY: clean
clean:
	rm -f *.o $(TARGET) $(TEST)
