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
CMAKE_BINARY_DIR = "/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect"

# Include any dependencies generated for this target.
include CMakeFiles/scacchiera.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/scacchiera.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/scacchiera.dir/flags.make

CMakeFiles/scacchiera.dir/src/scacchiera.cpp.o: CMakeFiles/scacchiera.dir/flags.make
CMakeFiles/scacchiera.dir/src/scacchiera.cpp.o: src/scacchiera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/scacchiera.dir/src/scacchiera.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/scacchiera.dir/src/scacchiera.cpp.o -c "/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect/src/scacchiera.cpp"

CMakeFiles/scacchiera.dir/src/scacchiera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/scacchiera.dir/src/scacchiera.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect/src/scacchiera.cpp" > CMakeFiles/scacchiera.dir/src/scacchiera.cpp.i

CMakeFiles/scacchiera.dir/src/scacchiera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/scacchiera.dir/src/scacchiera.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect/src/scacchiera.cpp" -o CMakeFiles/scacchiera.dir/src/scacchiera.cpp.s

# Object files for target scacchiera
scacchiera_OBJECTS = \
"CMakeFiles/scacchiera.dir/src/scacchiera.cpp.o"

# External object files for target scacchiera
scacchiera_EXTERNAL_OBJECTS =

libscacchiera.a: CMakeFiles/scacchiera.dir/src/scacchiera.cpp.o
libscacchiera.a: CMakeFiles/scacchiera.dir/build.make
libscacchiera.a: CMakeFiles/scacchiera.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libscacchiera.a"
	$(CMAKE_COMMAND) -P CMakeFiles/scacchiera.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/scacchiera.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/scacchiera.dir/build: libscacchiera.a

.PHONY : CMakeFiles/scacchiera.dir/build

CMakeFiles/scacchiera.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/scacchiera.dir/cmake_clean.cmake
.PHONY : CMakeFiles/scacchiera.dir/clean

CMakeFiles/scacchiera.dir/depend:
	cd "/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect" "/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect" "/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect" "/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect" "/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect/CMakeFiles/scacchiera.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/scacchiera.dir/depend

