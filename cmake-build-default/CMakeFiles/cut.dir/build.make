# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mateusz/.github/cpu-usage-tracker

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mateusz/.github/cpu-usage-tracker/cmake-build-default

# Include any dependencies generated for this target.
include CMakeFiles/cut.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/cut.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/cut.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cut.dir/flags.make

CMakeFiles/cut.dir/main.c.o: CMakeFiles/cut.dir/flags.make
CMakeFiles/cut.dir/main.c.o: ../main.c
CMakeFiles/cut.dir/main.c.o: CMakeFiles/cut.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mateusz/.github/cpu-usage-tracker/cmake-build-default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/cut.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/cut.dir/main.c.o -MF CMakeFiles/cut.dir/main.c.o.d -o CMakeFiles/cut.dir/main.c.o -c /home/mateusz/.github/cpu-usage-tracker/main.c

CMakeFiles/cut.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cut.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/mateusz/.github/cpu-usage-tracker/main.c > CMakeFiles/cut.dir/main.c.i

CMakeFiles/cut.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cut.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/mateusz/.github/cpu-usage-tracker/main.c -o CMakeFiles/cut.dir/main.c.s

# Object files for target cut
cut_OBJECTS = \
"CMakeFiles/cut.dir/main.c.o"

# External object files for target cut
cut_EXTERNAL_OBJECTS =

cut: CMakeFiles/cut.dir/main.c.o
cut: CMakeFiles/cut.dir/build.make
cut: libqueue.a
cut: libreader.a
cut: libanalyzer.a
cut: CMakeFiles/cut.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mateusz/.github/cpu-usage-tracker/cmake-build-default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable cut"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cut.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cut.dir/build: cut
.PHONY : CMakeFiles/cut.dir/build

CMakeFiles/cut.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cut.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cut.dir/clean

CMakeFiles/cut.dir/depend:
	cd /home/mateusz/.github/cpu-usage-tracker/cmake-build-default && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mateusz/.github/cpu-usage-tracker /home/mateusz/.github/cpu-usage-tracker /home/mateusz/.github/cpu-usage-tracker/cmake-build-default /home/mateusz/.github/cpu-usage-tracker/cmake-build-default /home/mateusz/.github/cpu-usage-tracker/cmake-build-default/CMakeFiles/cut.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cut.dir/depend

