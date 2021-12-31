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

##############
## PATTERNS ##
##############
$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	$(CXX_CALL) -I $(INCLUDE_DIR) -c $< -o $@

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.cc
	$(CXX_CALL) -I $(INCLUDE_DIR) -c $< -o $@
