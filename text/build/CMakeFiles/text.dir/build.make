# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/j/code/pProj/sdl/SDL-Graphing-App-unfinished/text

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/j/code/pProj/sdl/SDL-Graphing-App-unfinished/text/build

# Include any dependencies generated for this target.
include CMakeFiles/text.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/text.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/text.dir/flags.make

CMakeFiles/text.dir/main.c.o: CMakeFiles/text.dir/flags.make
CMakeFiles/text.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/j/code/pProj/sdl/SDL-Graphing-App-unfinished/text/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/text.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/text.dir/main.c.o   -c /home/j/code/pProj/sdl/SDL-Graphing-App-unfinished/text/main.c

CMakeFiles/text.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/text.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/j/code/pProj/sdl/SDL-Graphing-App-unfinished/text/main.c > CMakeFiles/text.dir/main.c.i

CMakeFiles/text.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/text.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/j/code/pProj/sdl/SDL-Graphing-App-unfinished/text/main.c -o CMakeFiles/text.dir/main.c.s

# Object files for target text
text_OBJECTS = \
"CMakeFiles/text.dir/main.c.o"

# External object files for target text
text_EXTERNAL_OBJECTS =

text: CMakeFiles/text.dir/main.c.o
text: CMakeFiles/text.dir/build.make
text: /usr/lib/x86_64-linux-gnu/libSDL2_net.so
text: /usr/lib/x86_64-linux-gnu/libSDL2_mixer.so
text: /usr/lib/x86_64-linux-gnu/libSDL2_image.so
text: /usr/lib/x86_64-linux-gnu/libSDL2_ttf.so
text: /usr/lib/x86_64-linux-gnu/libSDL2_gfx.so
text: /usr/lib/x86_64-linux-gnu/libSDL2main.a
text: /usr/lib/x86_64-linux-gnu/libSDL2.so
text: CMakeFiles/text.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/j/code/pProj/sdl/SDL-Graphing-App-unfinished/text/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable text"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/text.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/text.dir/build: text

.PHONY : CMakeFiles/text.dir/build

CMakeFiles/text.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/text.dir/cmake_clean.cmake
.PHONY : CMakeFiles/text.dir/clean

CMakeFiles/text.dir/depend:
	cd /home/j/code/pProj/sdl/SDL-Graphing-App-unfinished/text/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/j/code/pProj/sdl/SDL-Graphing-App-unfinished/text /home/j/code/pProj/sdl/SDL-Graphing-App-unfinished/text /home/j/code/pProj/sdl/SDL-Graphing-App-unfinished/text/build /home/j/code/pProj/sdl/SDL-Graphing-App-unfinished/text/build /home/j/code/pProj/sdl/SDL-Graphing-App-unfinished/text/build/CMakeFiles/text.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/text.dir/depend

