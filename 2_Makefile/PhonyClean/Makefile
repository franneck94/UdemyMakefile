###############
## VARIABLES ##
###############
COMPILATION_MODE ?= Debug
ENABLE_WARNINGS ?= 1
WARNINGS_AS_ERRORS ?= 0
EXECUTABLE_PREFIX ?= main
CXX ?= g++ # g++, clang++
CPP_STANDARD ?= c++17 # c++11, c++14, c++17, c++20

ifeq ($(COMPILATION_MODE), Debug)
CXXFLAGS = -g -O0 -std=$(CPP_STANDARD)
EXE_NAME = $(EXECUTABLE_PREFIX)Debug
else
CXXFLAGS = -O3 -Wall -std=$(CPP_STANDARD)
EXE_NAME = $(EXECUTABLE_PREFIX)Release
endif

ifeq ($(ENABLE_WARNINGS), 1)
CXXFLAGS += -Wall -Wextra -Wpedantic -Wconversion
endif

ifeq ($(WARNINGS_AS_ERRORS), 1)
CXXFLAGS += -Werror
endif

CXX_CALL = $(CXX) $(CXXFLAGS)

INCLUDE_DIR = include
SOURCE_DIR = src
BUILD_DIR = build

CPP_SRCS = $(wildcard $(SOURCE_DIR)/*.cpp)
CPP_OBJECTS = $(patsubst $(SOURCE_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(CPP_SRCS))

CC_SRCS = $(wildcard $(SOURCE_DIR)/*.cc)
CC_OBJECTS = $(patsubst $(SOURCE_DIR)/%.cc, $(BUILD_DIR)/%.o, $(CC_SRCS))

####################
## PESUDO TARGETS ##
####################
build: $(BUILD_DIR)/$(EXE_NAME)

#############
## TARGETS ##
#############
$(BUILD_DIR)/$(EXE_NAME): $(CPP_OBJECTS) $(CC_OBJECTS)
	$(CXX_CALL) $^ -o $@

execute:
	./$(BUILD_DIR)/$(EXE_NAME)

clean:
	rm $(BUILD_DIR)/*.o

##############
## PATTERNS ##
##############
$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	$(CXX_CALL) -I $(INCLUDE_DIR) -c $< -o $@

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.cc
	$(CXX_CALL) -I $(INCLUDE_DIR) -c $< -o $@

###########
## PHONY ##
###########
.PHONY: clean build
