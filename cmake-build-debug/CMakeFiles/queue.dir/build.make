# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /opt/clion-2023.1/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /opt/clion-2023.1/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mateusz/.github/cpu-usage-tracker

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mateusz/.github/cpu-usage-tracker/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/queue.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/queue.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/queue.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/queue.dir/flags.make

CMakeFiles/queue.dir/queue.c.o: CMakeFiles/queue.dir/flags.make
CMakeFiles/queue.dir/queue.c.o: /home/mateusz/.github/cpu-usage-tracker/queue.c
CMakeFiles/queue.dir/queue.c.o: CMakeFiles/queue.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mateusz/.github/cpu-usage-tracker/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/queue.dir/queue.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/queue.dir/queue.c.o -MF CMakeFiles/queue.dir/queue.c.o.d -o CMakeFiles/queue.dir/queue.c.o -c /home/mateusz/.github/cpu-usage-tracker/queue.c

CMakeFiles/queue.dir/queue.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/queue.dir/queue.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/mateusz/.github/cpu-usage-tracker/queue.c > CMakeFiles/queue.dir/queue.c.i

CMakeFiles/queue.dir/queue.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/queue.dir/queue.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/mateusz/.github/cpu-usage-tracker/queue.c -o CMakeFiles/queue.dir/queue.c.s

# Object files for target queue
queue_OBJECTS = \
"CMakeFiles/queue.dir/queue.c.o"

# External object files for target queue
queue_EXTERNAL_OBJECTS =

libqueue.a: CMakeFiles/queue.dir/queue.c.o
libqueue.a: CMakeFiles/queue.dir/build.make
libqueue.a: CMakeFiles/queue.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mateusz/.github/cpu-usage-tracker/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libqueue.a"
	$(CMAKE_COMMAND) -P CMakeFiles/queue.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/queue.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/queue.dir/build: libqueue.a
.PHONY : CMakeFiles/queue.dir/build

CMakeFiles/queue.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/queue.dir/cmake_clean.cmake
.PHONY : CMakeFiles/queue.dir/clean

CMakeFiles/queue.dir/depend:
	cd /home/mateusz/.github/cpu-usage-tracker/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mateusz/.github/cpu-usage-tracker /home/mateusz/.github/cpu-usage-tracker /home/mateusz/.github/cpu-usage-tracker/cmake-build-debug /home/mateusz/.github/cpu-usage-tracker/cmake-build-debug /home/mateusz/.github/cpu-usage-tracker/cmake-build-debug/CMakeFiles/queue.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/queue.dir/depend
