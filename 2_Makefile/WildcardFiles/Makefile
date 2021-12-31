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

CPP_SRCS = $(wildcard *.cpp)
CPP_OBJECTS = $(patsubst %.cpp, %.o, $(CPP_SRCS))

CC_SRCS = $(wildcard *.cc)
CC_OBJECTS = $(patsubst %.cc, %.o, $(CC_SRCS))

####################
## PESUDO TARGETS ##
####################
build: $(EXE_NAME)

#############
## TARGETS ##
#############
$(EXE_NAME): $(CPP_OBJECTS) $(CC_OBJECTS)
	$(CXX_CALL) $^ -o $@

execute:
	./$(EXE_NAME)

##############
## PATTERNS ##
##############
%.o: %.cpp
	$(CXX_CALL) -c $< -o $@

%.o: %.cc
	$(CXX_CALL) -c $< -o $@
