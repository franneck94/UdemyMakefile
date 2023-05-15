DEBUG ?= 1
ENABLE_WARNINGS ?= 1
WARNINGS_AS_ERRORS ?= 0

INCLUDE_DIR = include
SOURCE_DIR = src
BUILD_DIR = build

ifeq ($(ENABLE_WARNINGS), 1)
CXX_WARNINGS = -Wall -Wextra -Wpedantic
else
CXX_WARNINGS =
endif
ifeq ($(WARNINGS_AS_ERRORS), 1)
CXX_WARNINGS += -Werror
endif

CXX_STANDARD = c++17
CXX = g++
CXXFLAGS = $(CXX_WARNINGS) -std=$(CXX_STANDARD)
CPPFLAGS = -I $(INCLUDE_DIR)
LDFLAGS =

ifeq ($(DEBUG), 1)
CXXFLAGS += -g -O0
EXECUTABLE_NAME = mainDebug
else
CXXFLAGS += -O3
EXECUTABLE_NAME = mainRelease
endif

CXX_COMPILER_CALL = $(CXX) $(CXXFLAGS) $(CPPFLAGS)

CXX_SOURCES = $(wildcard $(SOURCE_DIR)/*.cc)
CXX_OBJECTS = $(patsubst $(SOURCE_DIR)/%.cc, $(BUILD_DIR)/%.o, $(CXX_SOURCES))

##############
## TARGETS  ##
##############
all: create build

create:
	@mkdir -p build

build: $(CXX_OBJECTS)
	$(CXX_COMPILER_CALL) $(CXX_OBJECTS) $(LDFLAGS) -o $(BUILD_DIR)/$(EXECUTABLE_NAME)

execute:
	./$(BUILD_DIR)/$(EXECUTABLE_NAME)

clean:
	rm -f $(BUILD_DIR)/*.o
	rm -f $(BUILD_DIR)/$(EXECUTABLE_NAME)

##############
## PATTERNS ##
##############
$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.cc
	$(CXX_COMPILER_CALL) -c $< -o $@

###########
## PHONY ##
###########
.PHONY: create build execute clean
