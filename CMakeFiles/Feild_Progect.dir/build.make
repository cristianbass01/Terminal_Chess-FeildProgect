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
include CMakeFiles/Feild_Progect.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Feild_Progect.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Feild_Progect.dir/flags.make

CMakeFiles/Feild_Progect.dir/src/main.cpp.o: CMakeFiles/Feild_Progect.dir/flags.make
CMakeFiles/Feild_Progect.dir/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Feild_Progect.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Feild_Progect.dir/src/main.cpp.o -c "/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect/src/main.cpp"

CMakeFiles/Feild_Progect.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Feild_Progect.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect/src/main.cpp" > CMakeFiles/Feild_Progect.dir/src/main.cpp.i

CMakeFiles/Feild_Progect.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Feild_Progect.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect/src/main.cpp" -o CMakeFiles/Feild_Progect.dir/src/main.cpp.s

# Object files for target Feild_Progect
Feild_Progect_OBJECTS = \
"CMakeFiles/Feild_Progect.dir/src/main.cpp.o"

# External object files for target Feild_Progect
Feild_Progect_EXTERNAL_OBJECTS =

Feild_Progect: CMakeFiles/Feild_Progect.dir/src/main.cpp.o
Feild_Progect: CMakeFiles/Feild_Progect.dir/build.make
Feild_Progect: libalfiere.a
Feild_Progect: libcavallo.a
Feild_Progect: libpedone.a
Feild_Progect: libre.a
Feild_Progect: libregina.a
Feild_Progect: libtorre.a
Feild_Progect: libcasella.a
Feild_Progect: libcomputer.a
Feild_Progect: libeccezione.a
Feild_Progect: libscacchiera.a
Feild_Progect: libumano.a
Feild_Progect: CMakeFiles/Feild_Progect.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Feild_Progect"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Feild_Progect.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Feild_Progect.dir/build: Feild_Progect

.PHONY : CMakeFiles/Feild_Progect.dir/build

CMakeFiles/Feild_Progect.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Feild_Progect.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Feild_Progect.dir/clean

CMakeFiles/Feild_Progect.dir/depend:
	cd "/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect" "/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect" "/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect" "/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect" "/home/cristian/OneDrive/2 anno/Laboratorio di programmazione/Feild_Progect/CMakeFiles/Feild_Progect.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Feild_Progect.dir/depend

