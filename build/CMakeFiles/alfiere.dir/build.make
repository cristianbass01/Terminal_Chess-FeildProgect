# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = "/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect/build"

# Include any dependencies generated for this target.
include CMakeFiles/alfiere.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/alfiere.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/alfiere.dir/flags.make

CMakeFiles/alfiere.dir/src/alfiere.cpp.o: CMakeFiles/alfiere.dir/flags.make
CMakeFiles/alfiere.dir/src/alfiere.cpp.o: ../src/alfiere.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/alfiere.dir/src/alfiere.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/alfiere.dir/src/alfiere.cpp.o -c "/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect/src/alfiere.cpp"

CMakeFiles/alfiere.dir/src/alfiere.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/alfiere.dir/src/alfiere.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect/src/alfiere.cpp" > CMakeFiles/alfiere.dir/src/alfiere.cpp.i

CMakeFiles/alfiere.dir/src/alfiere.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/alfiere.dir/src/alfiere.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect/src/alfiere.cpp" -o CMakeFiles/alfiere.dir/src/alfiere.cpp.s

# Object files for target alfiere
alfiere_OBJECTS = \
"CMakeFiles/alfiere.dir/src/alfiere.cpp.o"

# External object files for target alfiere
alfiere_EXTERNAL_OBJECTS =

libalfiere.a: CMakeFiles/alfiere.dir/src/alfiere.cpp.o
libalfiere.a: CMakeFiles/alfiere.dir/build.make
libalfiere.a: CMakeFiles/alfiere.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libalfiere.a"
	$(CMAKE_COMMAND) -P CMakeFiles/alfiere.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/alfiere.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/alfiere.dir/build: libalfiere.a

.PHONY : CMakeFiles/alfiere.dir/build

CMakeFiles/alfiere.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/alfiere.dir/cmake_clean.cmake
.PHONY : CMakeFiles/alfiere.dir/clean

CMakeFiles/alfiere.dir/depend:
	cd "/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect" "/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect" "/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect/build" "/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect/build" "/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect/build/CMakeFiles/alfiere.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/alfiere.dir/depend
