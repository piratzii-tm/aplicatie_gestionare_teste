# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = "D:\Compilatoare\CLion\CLion 2023.1\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Compilatoare\CLion\CLion 2023.1\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Iulian\Desktop\Teste_PP\App2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Iulian\Desktop\Teste_PP\App2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/App2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/App2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/App2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/App2.dir/flags.make

CMakeFiles/App2.dir/main.cpp.obj: CMakeFiles/App2.dir/flags.make
CMakeFiles/App2.dir/main.cpp.obj: C:/Users/Iulian/Desktop/Teste_PP/App2/main.cpp
CMakeFiles/App2.dir/main.cpp.obj: CMakeFiles/App2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Iulian\Desktop\Teste_PP\App2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/App2.dir/main.cpp.obj"
	"D:\Compilatoare\CLion\CLion 2023.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/App2.dir/main.cpp.obj -MF CMakeFiles\App2.dir\main.cpp.obj.d -o CMakeFiles\App2.dir\main.cpp.obj -c C:\Users\Iulian\Desktop\Teste_PP\App2\main.cpp

CMakeFiles/App2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/App2.dir/main.cpp.i"
	"D:\Compilatoare\CLion\CLion 2023.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Iulian\Desktop\Teste_PP\App2\main.cpp > CMakeFiles\App2.dir\main.cpp.i

CMakeFiles/App2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/App2.dir/main.cpp.s"
	"D:\Compilatoare\CLion\CLion 2023.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Iulian\Desktop\Teste_PP\App2\main.cpp -o CMakeFiles\App2.dir\main.cpp.s

CMakeFiles/App2.dir/C_/Users/Iulian/Desktop/Teste_PP/Share/Clase/Student.cpp.obj: CMakeFiles/App2.dir/flags.make
CMakeFiles/App2.dir/C_/Users/Iulian/Desktop/Teste_PP/Share/Clase/Student.cpp.obj: C:/Users/Iulian/Desktop/Teste_PP/Share/Clase/Student.cpp
CMakeFiles/App2.dir/C_/Users/Iulian/Desktop/Teste_PP/Share/Clase/Student.cpp.obj: CMakeFiles/App2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Iulian\Desktop\Teste_PP\App2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/App2.dir/C_/Users/Iulian/Desktop/Teste_PP/Share/Clase/Student.cpp.obj"
	"D:\Compilatoare\CLion\CLion 2023.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/App2.dir/C_/Users/Iulian/Desktop/Teste_PP/Share/Clase/Student.cpp.obj -MF CMakeFiles\App2.dir\C_\Users\Iulian\Desktop\Teste_PP\Share\Clase\Student.cpp.obj.d -o CMakeFiles\App2.dir\C_\Users\Iulian\Desktop\Teste_PP\Share\Clase\Student.cpp.obj -c C:\Users\Iulian\Desktop\Teste_PP\Share\Clase\Student.cpp

CMakeFiles/App2.dir/C_/Users/Iulian/Desktop/Teste_PP/Share/Clase/Student.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/App2.dir/C_/Users/Iulian/Desktop/Teste_PP/Share/Clase/Student.cpp.i"
	"D:\Compilatoare\CLion\CLion 2023.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Iulian\Desktop\Teste_PP\Share\Clase\Student.cpp > CMakeFiles\App2.dir\C_\Users\Iulian\Desktop\Teste_PP\Share\Clase\Student.cpp.i

CMakeFiles/App2.dir/C_/Users/Iulian/Desktop/Teste_PP/Share/Clase/Student.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/App2.dir/C_/Users/Iulian/Desktop/Teste_PP/Share/Clase/Student.cpp.s"
	"D:\Compilatoare\CLion\CLion 2023.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Iulian\Desktop\Teste_PP\Share\Clase\Student.cpp -o CMakeFiles\App2.dir\C_\Users\Iulian\Desktop\Teste_PP\Share\Clase\Student.cpp.s

# Object files for target App2
App2_OBJECTS = \
"CMakeFiles/App2.dir/main.cpp.obj" \
"CMakeFiles/App2.dir/C_/Users/Iulian/Desktop/Teste_PP/Share/Clase/Student.cpp.obj"

# External object files for target App2
App2_EXTERNAL_OBJECTS =

App2.exe: CMakeFiles/App2.dir/main.cpp.obj
App2.exe: CMakeFiles/App2.dir/C_/Users/Iulian/Desktop/Teste_PP/Share/Clase/Student.cpp.obj
App2.exe: CMakeFiles/App2.dir/build.make
App2.exe: CMakeFiles/App2.dir/linkLibs.rsp
App2.exe: CMakeFiles/App2.dir/objects1
App2.exe: CMakeFiles/App2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Iulian\Desktop\Teste_PP\App2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable App2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\App2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/App2.dir/build: App2.exe
.PHONY : CMakeFiles/App2.dir/build

CMakeFiles/App2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\App2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/App2.dir/clean

CMakeFiles/App2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Iulian\Desktop\Teste_PP\App2 C:\Users\Iulian\Desktop\Teste_PP\App2 C:\Users\Iulian\Desktop\Teste_PP\App2\cmake-build-debug C:\Users\Iulian\Desktop\Teste_PP\App2\cmake-build-debug C:\Users\Iulian\Desktop\Teste_PP\App2\cmake-build-debug\CMakeFiles\App2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/App2.dir/depend

