###############
## VARIABLES ##
###############
DEBUG ?= 1
ifeq ($(DEBUG), 1)
CXXFLAGS = -g -O0 -Wall -Wextra -Wpedantic -Wconversion -std=c++17
EXE_NAME = mainDebug
else
CXXFLAGS = -O3 -Wall -Wextra -Wpedantic -Wconversion -std=c++17
EXE_NAME = mainRelease
endif

CXX = g++
CXX_CALL = $(CXX) $(CXXFLAGS)

#############
## TARGETS ##
#############
build: my_lib.o
	$(CXX_CALL) main.cc my_lib.o -o $(EXE_NAME)

my_lib.o:
	$(CXX_CALL) my_lib.cc -c

execute:
	./$(EXE_NAME)
