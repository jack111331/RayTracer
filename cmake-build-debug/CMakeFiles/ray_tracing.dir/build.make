# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/edge/clion-2019.2.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/edge/clion-2019.2.1/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/edge/RayTracing

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/edge/RayTracing/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ray_tracing.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ray_tracing.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ray_tracing.dir/flags.make

CMakeFiles/ray_tracing.dir/Math.cpp.o: CMakeFiles/ray_tracing.dir/flags.make
CMakeFiles/ray_tracing.dir/Math.cpp.o: ../Math.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/edge/RayTracing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ray_tracing.dir/Math.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ray_tracing.dir/Math.cpp.o -c /home/edge/RayTracing/Math.cpp

CMakeFiles/ray_tracing.dir/Math.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray_tracing.dir/Math.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/edge/RayTracing/Math.cpp > CMakeFiles/ray_tracing.dir/Math.cpp.i

CMakeFiles/ray_tracing.dir/Math.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray_tracing.dir/Math.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/edge/RayTracing/Math.cpp -o CMakeFiles/ray_tracing.dir/Math.cpp.s

CMakeFiles/ray_tracing.dir/main.cpp.o: CMakeFiles/ray_tracing.dir/flags.make
CMakeFiles/ray_tracing.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/edge/RayTracing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ray_tracing.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ray_tracing.dir/main.cpp.o -c /home/edge/RayTracing/main.cpp

CMakeFiles/ray_tracing.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray_tracing.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/edge/RayTracing/main.cpp > CMakeFiles/ray_tracing.dir/main.cpp.i

CMakeFiles/ray_tracing.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray_tracing.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/edge/RayTracing/main.cpp -o CMakeFiles/ray_tracing.dir/main.cpp.s

# Object files for target ray_tracing
ray_tracing_OBJECTS = \
"CMakeFiles/ray_tracing.dir/Math.cpp.o" \
"CMakeFiles/ray_tracing.dir/main.cpp.o"

# External object files for target ray_tracing
ray_tracing_EXTERNAL_OBJECTS =

ray_tracing: CMakeFiles/ray_tracing.dir/Math.cpp.o
ray_tracing: CMakeFiles/ray_tracing.dir/main.cpp.o
ray_tracing: CMakeFiles/ray_tracing.dir/build.make
ray_tracing: CMakeFiles/ray_tracing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/edge/RayTracing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ray_tracing"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ray_tracing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ray_tracing.dir/build: ray_tracing

.PHONY : CMakeFiles/ray_tracing.dir/build

CMakeFiles/ray_tracing.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ray_tracing.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ray_tracing.dir/clean

CMakeFiles/ray_tracing.dir/depend:
	cd /home/edge/RayTracing/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/edge/RayTracing /home/edge/RayTracing /home/edge/RayTracing/cmake-build-debug /home/edge/RayTracing/cmake-build-debug /home/edge/RayTracing/cmake-build-debug/CMakeFiles/ray_tracing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ray_tracing.dir/depend

