# Cpp Makefile Tutorial

## GCC/Clang Compiler Steps

### Compilation Steps

1. Preprocessing
2. Compilation
3. Assembler
4. Linking

#### Preprocessing

- Removes comments from the source code
- Macro expansion
- Expansion of header files
- Command: g++ -E main.cc > main.i

#### Compilation

- Translates the preprocessing file into assembly language.
- Checks the C/C++ language syntax for error
- Command: g++ -S main.i
- Produces: main.s

#### Assembler

- Translates the assembly code into low-level machine code
- Command: g++ -c main.s
- Produces: main.o

#### Linker

- Linking all the source files together, that is all the other object codes in the project.
- Generates the executable file
- Command: g++ main.o -o main
- Produces: main.out (.exe for Windows)

### Compiler Flags

- Debug: ```-g```
- Release: ```-O0 -O1 -O2 -O3 -Og```
- Includes: ```-I```
- Warnings: ```-Wall -Wextra -Wpedantic -Wconversion```

## Makefile Commands of the Template

### Makefile Variables

Convention is naming in upper snake_case.

```make
  VARIABLE_NAME = Value
```

Variables can be called by $(VARIABLE_NAME)

```make
  $(VARIABLE_NAME)
```

### Makefile Targets

Convention is naming in snake_case or camelCase.

```make
  targetName: Dependecies
    Command
```

Targets can be called by the ```make``` command.

```bash
  make targetName
```

### Makefile Phony Target

Sometimes you want your Makefile to run commands that do not represent files, for example the "clean" target. You may potentially have a file named clean in your main directory. In such a case Make will be confused because by default the clean target would be associated with this file and Make will only run it when the file doesn't appear to be up-to-date.

```make
.PHONY: clean
clean:
  rm -rf *.o
```

In terms of Make, a phony target is simply a target that is always out-of-date, so whenever you ask make <phony_target>, it will run, independent from the state of the file system.

### Build the Executable

Create the executable in either Debug or Release mode.

```bash
  make build COMPILATION_MODE=Debug # Build type is debug
  make build COMPILATION_MODE=Release # Build type is release
```

### Run the Executable

Run the executable in either Debug or Release mode.

```bash
  make execute COMPILATION_MODE=Debug # Build type is debug
make execute COMPILATION_MODE=Release # Build type is release
```

### Variables of the Makefile Template

- COMPILATION_MODE: Debug or Release
- ENABLE_WARNINGS: 1 (True) or 0 (False)
- WARNINGS_AS_ERRORS: 1 (True) or 0 (False)
- CPP_STANDARD: c++11, c++14, c++17, etc.

### Important Shortcuts of the Makefile Template

- ```$@```: the file name of the target
- ```$<```: the name of the first ependency
- ```$^```: the names of all dependencies
