CC 	= clang++
LD	= clang++

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
DST = book
FLG = -Wall -O1 -std=c++11 -g
LIB =

all: $(DST)
$(DST): $(OBJ) Makefile
	$(LD) -o $@ $(OBJ) $(FLG) $(LIB)
.cpp.o:
	$(CC) -c -o $@ $< $(FLG)
$(foreach file,$(SRC),$(eval $(shell $(CC) -MM $(FLG) $(file)) Makefile))

clean:
	rm -f ./*.o $(DST)

.PHONY: clean
