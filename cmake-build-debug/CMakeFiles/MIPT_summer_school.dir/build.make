# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.3.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Projects\MIPT-summer-school

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Projects\MIPT-summer-school\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MIPT_summer_school.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MIPT_summer_school.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MIPT_summer_school.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MIPT_summer_school.dir/flags.make

CMakeFiles/MIPT_summer_school.dir/Quadratic-equation-solver/equation.cpp.obj: CMakeFiles/MIPT_summer_school.dir/flags.make
CMakeFiles/MIPT_summer_school.dir/Quadratic-equation-solver/equation.cpp.obj: ../Quadratic-equation-solver/equation.cpp
CMakeFiles/MIPT_summer_school.dir/Quadratic-equation-solver/equation.cpp.obj: CMakeFiles/MIPT_summer_school.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projects\MIPT-summer-school\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MIPT_summer_school.dir/Quadratic-equation-solver/equation.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MIPT_summer_school.dir/Quadratic-equation-solver/equation.cpp.obj -MF CMakeFiles\MIPT_summer_school.dir\Quadratic-equation-solver\equation.cpp.obj.d -o CMakeFiles\MIPT_summer_school.dir\Quadratic-equation-solver\equation.cpp.obj -c D:\Projects\MIPT-summer-school\Quadratic-equation-solver\equation.cpp

CMakeFiles/MIPT_summer_school.dir/Quadratic-equation-solver/equation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MIPT_summer_school.dir/Quadratic-equation-solver/equation.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Projects\MIPT-summer-school\Quadratic-equation-solver\equation.cpp > CMakeFiles\MIPT_summer_school.dir\Quadratic-equation-solver\equation.cpp.i

CMakeFiles/MIPT_summer_school.dir/Quadratic-equation-solver/equation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MIPT_summer_school.dir/Quadratic-equation-solver/equation.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Projects\MIPT-summer-school\Quadratic-equation-solver\equation.cpp -o CMakeFiles\MIPT_summer_school.dir\Quadratic-equation-solver\equation.cpp.s

# Object files for target MIPT_summer_school
MIPT_summer_school_OBJECTS = \
"CMakeFiles/MIPT_summer_school.dir/Quadratic-equation-solver/equation.cpp.obj"

# External object files for target MIPT_summer_school
MIPT_summer_school_EXTERNAL_OBJECTS =

MIPT_summer_school.exe: CMakeFiles/MIPT_summer_school.dir/Quadratic-equation-solver/equation.cpp.obj
MIPT_summer_school.exe: CMakeFiles/MIPT_summer_school.dir/build.make
MIPT_summer_school.exe: CMakeFiles/MIPT_summer_school.dir/linklibs.rsp
MIPT_summer_school.exe: CMakeFiles/MIPT_summer_school.dir/objects1.rsp
MIPT_summer_school.exe: CMakeFiles/MIPT_summer_school.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Projects\MIPT-summer-school\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MIPT_summer_school.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\MIPT_summer_school.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MIPT_summer_school.dir/build: MIPT_summer_school.exe
.PHONY : CMakeFiles/MIPT_summer_school.dir/build

CMakeFiles/MIPT_summer_school.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\MIPT_summer_school.dir\cmake_clean.cmake
.PHONY : CMakeFiles/MIPT_summer_school.dir/clean

CMakeFiles/MIPT_summer_school.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Projects\MIPT-summer-school D:\Projects\MIPT-summer-school D:\Projects\MIPT-summer-school\cmake-build-debug D:\Projects\MIPT-summer-school\cmake-build-debug D:\Projects\MIPT-summer-school\cmake-build-debug\CMakeFiles\MIPT_summer_school.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MIPT_summer_school.dir/depend

