# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /home/jacob/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/211.7142.21/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/jacob/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/211.7142.21/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/jacob/Dropbox/Code/CS 142/1-16 Main Lab"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/jacob/Dropbox/Code/CS 142/1-16 Main Lab/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/1_16_Main_Lab.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/1_16_Main_Lab.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/1_16_Main_Lab.dir/flags.make

CMakeFiles/1_16_Main_Lab.dir/main.cpp.o: CMakeFiles/1_16_Main_Lab.dir/flags.make
CMakeFiles/1_16_Main_Lab.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/jacob/Dropbox/Code/CS 142/1-16 Main Lab/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/1_16_Main_Lab.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/1_16_Main_Lab.dir/main.cpp.o -c "/home/jacob/Dropbox/Code/CS 142/1-16 Main Lab/main.cpp"

CMakeFiles/1_16_Main_Lab.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1_16_Main_Lab.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/jacob/Dropbox/Code/CS 142/1-16 Main Lab/main.cpp" > CMakeFiles/1_16_Main_Lab.dir/main.cpp.i

CMakeFiles/1_16_Main_Lab.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1_16_Main_Lab.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/jacob/Dropbox/Code/CS 142/1-16 Main Lab/main.cpp" -o CMakeFiles/1_16_Main_Lab.dir/main.cpp.s

# Object files for target 1_16_Main_Lab
1_16_Main_Lab_OBJECTS = \
"CMakeFiles/1_16_Main_Lab.dir/main.cpp.o"

# External object files for target 1_16_Main_Lab
1_16_Main_Lab_EXTERNAL_OBJECTS =

1_16_Main_Lab: CMakeFiles/1_16_Main_Lab.dir/main.cpp.o
1_16_Main_Lab: CMakeFiles/1_16_Main_Lab.dir/build.make
1_16_Main_Lab: CMakeFiles/1_16_Main_Lab.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/jacob/Dropbox/Code/CS 142/1-16 Main Lab/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 1_16_Main_Lab"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/1_16_Main_Lab.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/1_16_Main_Lab.dir/build: 1_16_Main_Lab

.PHONY : CMakeFiles/1_16_Main_Lab.dir/build

CMakeFiles/1_16_Main_Lab.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/1_16_Main_Lab.dir/cmake_clean.cmake
.PHONY : CMakeFiles/1_16_Main_Lab.dir/clean

CMakeFiles/1_16_Main_Lab.dir/depend:
	cd "/home/jacob/Dropbox/Code/CS 142/1-16 Main Lab/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/jacob/Dropbox/Code/CS 142/1-16 Main Lab" "/home/jacob/Dropbox/Code/CS 142/1-16 Main Lab" "/home/jacob/Dropbox/Code/CS 142/1-16 Main Lab/cmake-build-debug" "/home/jacob/Dropbox/Code/CS 142/1-16 Main Lab/cmake-build-debug" "/home/jacob/Dropbox/Code/CS 142/1-16 Main Lab/cmake-build-debug/CMakeFiles/1_16_Main_Lab.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/1_16_Main_Lab.dir/depend

