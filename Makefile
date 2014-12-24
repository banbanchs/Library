OS := $(shell uname -s)

ifeq (Linux, $(OS))
	CC 	= clang++
	CXX = clang++
	LD	= clang++
	CXXFLAG = -pipe -Wall -O1 -std=c++11 -g
	LDFLAG =
else
	CC 	= g++
	CXX = g++
	LD	= g++
	CXXFLAG = -pipe -Wall -O3 -std=c++11
	LDFLAG = -static-libgcc -static-libstdc++
endif


SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
OBJ_FILTES = $(filter-out main.o, $(OBJ))
TEST= tests/test.cpp
DST = book
TESTLDFLAG = -lgtest

$(DST): $(OBJ) Makefile
	$(LD) -o $@ $(OBJ) $(CXXFLAG) $(LDFLAG)
.cpp.o:
	$(CXX) -c -o $@ $< $(CXXFLAG)
$(foreach file,$(SRC),$(eval $(shell $(CXX) -MM $(CXXFLAG) $(file)) Makefile))

all: $(DST) test

test: $(OBJ)
	$(CXX) -o $@ $(OBJ_FILTES) $(TEST) $(CXXFLAG) $(LDFLAG) $(TESTLDFLAG)

clean:
	rm -f ./*.o ./$(DST) ./test

.PHONY: clean
