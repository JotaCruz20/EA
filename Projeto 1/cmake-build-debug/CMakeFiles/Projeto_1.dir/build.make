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
CMAKE_COMMAND = /cygdrive/c/Users/jotot/AppData/Local/JetBrains/CLion2020.1/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/jotot/AppData/Local/JetBrains/CLion2020.1/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/cygdrive/d/One Drive/OneDrive - Universidade de Coimbra/Univerisdade/UNI-Meu/PL EA/Projeto 1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/cygdrive/d/One Drive/OneDrive - Universidade de Coimbra/Univerisdade/UNI-Meu/PL EA/Projeto 1/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Projeto_1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Projeto_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Projeto_1.dir/flags.make

CMakeFiles/Projeto_1.dir/main.cpp.o: CMakeFiles/Projeto_1.dir/flags.make
CMakeFiles/Projeto_1.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/d/One Drive/OneDrive - Universidade de Coimbra/Univerisdade/UNI-Meu/PL EA/Projeto 1/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Projeto_1.dir/main.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Projeto_1.dir/main.cpp.o -c "/cygdrive/d/One Drive/OneDrive - Universidade de Coimbra/Univerisdade/UNI-Meu/PL EA/Projeto 1/main.cpp"

CMakeFiles/Projeto_1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Projeto_1.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/d/One Drive/OneDrive - Universidade de Coimbra/Univerisdade/UNI-Meu/PL EA/Projeto 1/main.cpp" > CMakeFiles/Projeto_1.dir/main.cpp.i

CMakeFiles/Projeto_1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Projeto_1.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/d/One Drive/OneDrive - Universidade de Coimbra/Univerisdade/UNI-Meu/PL EA/Projeto 1/main.cpp" -o CMakeFiles/Projeto_1.dir/main.cpp.s

# Object files for target Projeto_1
Projeto_1_OBJECTS = \
"CMakeFiles/Projeto_1.dir/main.cpp.o"

# External object files for target Projeto_1
Projeto_1_EXTERNAL_OBJECTS =

Projeto_1.exe: CMakeFiles/Projeto_1.dir/main.cpp.o
Projeto_1.exe: CMakeFiles/Projeto_1.dir/build.make
Projeto_1.exe: CMakeFiles/Projeto_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/cygdrive/d/One Drive/OneDrive - Universidade de Coimbra/Univerisdade/UNI-Meu/PL EA/Projeto 1/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Projeto_1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Projeto_1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Projeto_1.dir/build: Projeto_1.exe

.PHONY : CMakeFiles/Projeto_1.dir/build

CMakeFiles/Projeto_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Projeto_1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Projeto_1.dir/clean

CMakeFiles/Projeto_1.dir/depend:
	cd "/cygdrive/d/One Drive/OneDrive - Universidade de Coimbra/Univerisdade/UNI-Meu/PL EA/Projeto 1/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/cygdrive/d/One Drive/OneDrive - Universidade de Coimbra/Univerisdade/UNI-Meu/PL EA/Projeto 1" "/cygdrive/d/One Drive/OneDrive - Universidade de Coimbra/Univerisdade/UNI-Meu/PL EA/Projeto 1" "/cygdrive/d/One Drive/OneDrive - Universidade de Coimbra/Univerisdade/UNI-Meu/PL EA/Projeto 1/cmake-build-debug" "/cygdrive/d/One Drive/OneDrive - Universidade de Coimbra/Univerisdade/UNI-Meu/PL EA/Projeto 1/cmake-build-debug" "/cygdrive/d/One Drive/OneDrive - Universidade de Coimbra/Univerisdade/UNI-Meu/PL EA/Projeto 1/cmake-build-debug/CMakeFiles/Projeto_1.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Projeto_1.dir/depend

