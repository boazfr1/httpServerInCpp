# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/hilma/development/c++/httpServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hilma/development/c++/httpServer/build

# Include any dependencies generated for this target.
include CMakeFiles/TcpServer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TcpServer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TcpServer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TcpServer.dir/flags.make

CMakeFiles/TcpServer.dir/http_tcpServer_linux.cpp.o: CMakeFiles/TcpServer.dir/flags.make
CMakeFiles/TcpServer.dir/http_tcpServer_linux.cpp.o: ../http_tcpServer_linux.cpp
CMakeFiles/TcpServer.dir/http_tcpServer_linux.cpp.o: CMakeFiles/TcpServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hilma/development/c++/httpServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TcpServer.dir/http_tcpServer_linux.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TcpServer.dir/http_tcpServer_linux.cpp.o -MF CMakeFiles/TcpServer.dir/http_tcpServer_linux.cpp.o.d -o CMakeFiles/TcpServer.dir/http_tcpServer_linux.cpp.o -c /home/hilma/development/c++/httpServer/http_tcpServer_linux.cpp

CMakeFiles/TcpServer.dir/http_tcpServer_linux.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TcpServer.dir/http_tcpServer_linux.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hilma/development/c++/httpServer/http_tcpServer_linux.cpp > CMakeFiles/TcpServer.dir/http_tcpServer_linux.cpp.i

CMakeFiles/TcpServer.dir/http_tcpServer_linux.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TcpServer.dir/http_tcpServer_linux.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hilma/development/c++/httpServer/http_tcpServer_linux.cpp -o CMakeFiles/TcpServer.dir/http_tcpServer_linux.cpp.s

CMakeFiles/TcpServer.dir/server_linux.cpp.o: CMakeFiles/TcpServer.dir/flags.make
CMakeFiles/TcpServer.dir/server_linux.cpp.o: ../server_linux.cpp
CMakeFiles/TcpServer.dir/server_linux.cpp.o: CMakeFiles/TcpServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hilma/development/c++/httpServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TcpServer.dir/server_linux.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TcpServer.dir/server_linux.cpp.o -MF CMakeFiles/TcpServer.dir/server_linux.cpp.o.d -o CMakeFiles/TcpServer.dir/server_linux.cpp.o -c /home/hilma/development/c++/httpServer/server_linux.cpp

CMakeFiles/TcpServer.dir/server_linux.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TcpServer.dir/server_linux.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hilma/development/c++/httpServer/server_linux.cpp > CMakeFiles/TcpServer.dir/server_linux.cpp.i

CMakeFiles/TcpServer.dir/server_linux.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TcpServer.dir/server_linux.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hilma/development/c++/httpServer/server_linux.cpp -o CMakeFiles/TcpServer.dir/server_linux.cpp.s

# Object files for target TcpServer
TcpServer_OBJECTS = \
"CMakeFiles/TcpServer.dir/http_tcpServer_linux.cpp.o" \
"CMakeFiles/TcpServer.dir/server_linux.cpp.o"

# External object files for target TcpServer
TcpServer_EXTERNAL_OBJECTS =

TcpServer: CMakeFiles/TcpServer.dir/http_tcpServer_linux.cpp.o
TcpServer: CMakeFiles/TcpServer.dir/server_linux.cpp.o
TcpServer: CMakeFiles/TcpServer.dir/build.make
TcpServer: CMakeFiles/TcpServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hilma/development/c++/httpServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable TcpServer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TcpServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TcpServer.dir/build: TcpServer
.PHONY : CMakeFiles/TcpServer.dir/build

CMakeFiles/TcpServer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TcpServer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TcpServer.dir/clean

CMakeFiles/TcpServer.dir/depend:
	cd /home/hilma/development/c++/httpServer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hilma/development/c++/httpServer /home/hilma/development/c++/httpServer /home/hilma/development/c++/httpServer/build /home/hilma/development/c++/httpServer/build /home/hilma/development/c++/httpServer/build/CMakeFiles/TcpServer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TcpServer.dir/depend

