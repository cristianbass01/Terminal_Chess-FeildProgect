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
include CMakeFiles/pedone.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pedone.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pedone.dir/flags.make

CMakeFiles/pedone.dir/pezzi/src/pedone.cpp.o: CMakeFiles/pedone.dir/flags.make
CMakeFiles/pedone.dir/pezzi/src/pedone.cpp.o: pezzi/src/pedone.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pedone.dir/pezzi/src/pedone.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pedone.dir/pezzi/src/pedone.cpp.o -c "/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect/pezzi/src/pedone.cpp"

CMakeFiles/pedone.dir/pezzi/src/pedone.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pedone.dir/pezzi/src/pedone.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect/pezzi/src/pedone.cpp" > CMakeFiles/pedone.dir/pezzi/src/pedone.cpp.i

CMakeFiles/pedone.dir/pezzi/src/pedone.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pedone.dir/pezzi/src/pedone.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect/pezzi/src/pedone.cpp" -o CMakeFiles/pedone.dir/pezzi/src/pedone.cpp.s

# Object files for target pedone
pedone_OBJECTS = \
"CMakeFiles/pedone.dir/pezzi/src/pedone.cpp.o"

# External object files for target pedone
pedone_EXTERNAL_OBJECTS =

libpedone.a: CMakeFiles/pedone.dir/pezzi/src/pedone.cpp.o
libpedone.a: CMakeFiles/pedone.dir/build.make
libpedone.a: CMakeFiles/pedone.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libpedone.a"
	$(CMAKE_COMMAND) -P CMakeFiles/pedone.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pedone.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pedone.dir/build: libpedone.a

.PHONY : CMakeFiles/pedone.dir/build

CMakeFiles/pedone.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pedone.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pedone.dir/clean

CMakeFiles/pedone.dir/depend:
	cd "/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect" "/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect" "/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect" "/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect" "/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect/CMakeFiles/pedone.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/pedone.dir/depend

