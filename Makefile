CC 	= clang++
CXX = clang++
LD	= clang++

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
OBJ_FILTES = $(filter-out main.o, $(OBJ))
TEST= tests/test.cpp
DST = book
FLG = -pipe -Wall -O1 -std=c++11 -g
LIB =
TESTLIB = -lgtest

$(DST): $(OBJ) Makefile
	$(LD) -o $@ $(OBJ) $(FLG) $(LIB)
.cpp.o:
	$(CXX) -c -o $@ $< $(FLG)
$(foreach file,$(SRC),$(eval $(shell $(CXX) -MM $(FLG) $(file)) Makefile))

all: $(DST) test

test: $(OBJ)
	$(CXX) -o $@ $(OBJ_FILTES) $(TEST) $(FLG) $(LIB) $(TESTLIB)

clean:
	rm -f ./*.o ./$(DST) ./test

.PHONY: clean
