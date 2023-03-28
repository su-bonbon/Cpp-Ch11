pa11: Bag.o Set.o pa11.o
	$(CXX) $(CXXFLAGS) Bag.o Set.o pa11.o -o pa11

Bag.o: Bag.cpp Bag.h
	$(CXX) $(CXXFLAGS) Bag.cpp -c

Set.o: Set.cpp Bag.h Set.h
	$(CXX) $(CXXFLAGS) Set.cpp -c

pa11.o: pa11.cpp Bag.h Set.h
	$(CXX) $(CXXFLAGS) pa11.cpp -c

clean:
	rm -f Bag.o Set.o pa11.o

turnin:
	turnin -c cs202 -p pa11 -v Bag.h Bag.cpp Set.h Set.cpp pa11.cpp Makefile
