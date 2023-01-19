# gmake
CXX = g++
CXXFLAGS = -g -Wall
OBJMODULES = snack.o snack_slot.o vending_machine.o
all: snack_machine

snack.o: snack.cpp snack.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

snack_slot.o: snack_slot.cpp snack_slot.h snack.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

vending_machine.o: vending_machine.cpp vending_machine.h snack_slot.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

snack_machine: main.cpp $(OBJMODULES)
	$(CXX) $(CXXFLAGS) $^

.PHONY: clean
clean:
	rm -f *.o
