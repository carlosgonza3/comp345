# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/carlosgonzalez/Developer/GitHub/comp345

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/carlosgonzalez/Developer/GitHub/comp345/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/comp345.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/comp345.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/comp345.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/comp345.dir/flags.make

CMakeFiles/comp345.dir/MainDriver.cpp.o: CMakeFiles/comp345.dir/flags.make
CMakeFiles/comp345.dir/MainDriver.cpp.o: /Users/carlosgonzalez/Developer/GitHub/comp345/MainDriver.cpp
CMakeFiles/comp345.dir/MainDriver.cpp.o: CMakeFiles/comp345.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/carlosgonzalez/Developer/GitHub/comp345/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/comp345.dir/MainDriver.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/comp345.dir/MainDriver.cpp.o -MF CMakeFiles/comp345.dir/MainDriver.cpp.o.d -o CMakeFiles/comp345.dir/MainDriver.cpp.o -c /Users/carlosgonzalez/Developer/GitHub/comp345/MainDriver.cpp

CMakeFiles/comp345.dir/MainDriver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/comp345.dir/MainDriver.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/carlosgonzalez/Developer/GitHub/comp345/MainDriver.cpp > CMakeFiles/comp345.dir/MainDriver.cpp.i

CMakeFiles/comp345.dir/MainDriver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/comp345.dir/MainDriver.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/carlosgonzalez/Developer/GitHub/comp345/MainDriver.cpp -o CMakeFiles/comp345.dir/MainDriver.cpp.s

CMakeFiles/comp345.dir/GameEngine/GameEngine.cpp.o: CMakeFiles/comp345.dir/flags.make
CMakeFiles/comp345.dir/GameEngine/GameEngine.cpp.o: /Users/carlosgonzalez/Developer/GitHub/comp345/GameEngine/GameEngine.cpp
CMakeFiles/comp345.dir/GameEngine/GameEngine.cpp.o: CMakeFiles/comp345.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/carlosgonzalez/Developer/GitHub/comp345/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/comp345.dir/GameEngine/GameEngine.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/comp345.dir/GameEngine/GameEngine.cpp.o -MF CMakeFiles/comp345.dir/GameEngine/GameEngine.cpp.o.d -o CMakeFiles/comp345.dir/GameEngine/GameEngine.cpp.o -c /Users/carlosgonzalez/Developer/GitHub/comp345/GameEngine/GameEngine.cpp

CMakeFiles/comp345.dir/GameEngine/GameEngine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/comp345.dir/GameEngine/GameEngine.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/carlosgonzalez/Developer/GitHub/comp345/GameEngine/GameEngine.cpp > CMakeFiles/comp345.dir/GameEngine/GameEngine.cpp.i

CMakeFiles/comp345.dir/GameEngine/GameEngine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/comp345.dir/GameEngine/GameEngine.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/carlosgonzalez/Developer/GitHub/comp345/GameEngine/GameEngine.cpp -o CMakeFiles/comp345.dir/GameEngine/GameEngine.cpp.s

CMakeFiles/comp345.dir/GameEngine/GameEngineDriver.cpp.o: CMakeFiles/comp345.dir/flags.make
CMakeFiles/comp345.dir/GameEngine/GameEngineDriver.cpp.o: /Users/carlosgonzalez/Developer/GitHub/comp345/GameEngine/GameEngineDriver.cpp
CMakeFiles/comp345.dir/GameEngine/GameEngineDriver.cpp.o: CMakeFiles/comp345.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/carlosgonzalez/Developer/GitHub/comp345/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/comp345.dir/GameEngine/GameEngineDriver.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/comp345.dir/GameEngine/GameEngineDriver.cpp.o -MF CMakeFiles/comp345.dir/GameEngine/GameEngineDriver.cpp.o.d -o CMakeFiles/comp345.dir/GameEngine/GameEngineDriver.cpp.o -c /Users/carlosgonzalez/Developer/GitHub/comp345/GameEngine/GameEngineDriver.cpp

CMakeFiles/comp345.dir/GameEngine/GameEngineDriver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/comp345.dir/GameEngine/GameEngineDriver.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/carlosgonzalez/Developer/GitHub/comp345/GameEngine/GameEngineDriver.cpp > CMakeFiles/comp345.dir/GameEngine/GameEngineDriver.cpp.i

CMakeFiles/comp345.dir/GameEngine/GameEngineDriver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/comp345.dir/GameEngine/GameEngineDriver.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/carlosgonzalez/Developer/GitHub/comp345/GameEngine/GameEngineDriver.cpp -o CMakeFiles/comp345.dir/GameEngine/GameEngineDriver.cpp.s

CMakeFiles/comp345.dir/Map/Map.cpp.o: CMakeFiles/comp345.dir/flags.make
CMakeFiles/comp345.dir/Map/Map.cpp.o: /Users/carlosgonzalez/Developer/GitHub/comp345/Map/Map.cpp
CMakeFiles/comp345.dir/Map/Map.cpp.o: CMakeFiles/comp345.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/carlosgonzalez/Developer/GitHub/comp345/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/comp345.dir/Map/Map.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/comp345.dir/Map/Map.cpp.o -MF CMakeFiles/comp345.dir/Map/Map.cpp.o.d -o CMakeFiles/comp345.dir/Map/Map.cpp.o -c /Users/carlosgonzalez/Developer/GitHub/comp345/Map/Map.cpp

CMakeFiles/comp345.dir/Map/Map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/comp345.dir/Map/Map.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/carlosgonzalez/Developer/GitHub/comp345/Map/Map.cpp > CMakeFiles/comp345.dir/Map/Map.cpp.i

CMakeFiles/comp345.dir/Map/Map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/comp345.dir/Map/Map.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/carlosgonzalez/Developer/GitHub/comp345/Map/Map.cpp -o CMakeFiles/comp345.dir/Map/Map.cpp.s

CMakeFiles/comp345.dir/Map/MapDriver.cpp.o: CMakeFiles/comp345.dir/flags.make
CMakeFiles/comp345.dir/Map/MapDriver.cpp.o: /Users/carlosgonzalez/Developer/GitHub/comp345/Map/MapDriver.cpp
CMakeFiles/comp345.dir/Map/MapDriver.cpp.o: CMakeFiles/comp345.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/carlosgonzalez/Developer/GitHub/comp345/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/comp345.dir/Map/MapDriver.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/comp345.dir/Map/MapDriver.cpp.o -MF CMakeFiles/comp345.dir/Map/MapDriver.cpp.o.d -o CMakeFiles/comp345.dir/Map/MapDriver.cpp.o -c /Users/carlosgonzalez/Developer/GitHub/comp345/Map/MapDriver.cpp

CMakeFiles/comp345.dir/Map/MapDriver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/comp345.dir/Map/MapDriver.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/carlosgonzalez/Developer/GitHub/comp345/Map/MapDriver.cpp > CMakeFiles/comp345.dir/Map/MapDriver.cpp.i

CMakeFiles/comp345.dir/Map/MapDriver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/comp345.dir/Map/MapDriver.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/carlosgonzalez/Developer/GitHub/comp345/Map/MapDriver.cpp -o CMakeFiles/comp345.dir/Map/MapDriver.cpp.s

CMakeFiles/comp345.dir/Map/MapLoader.cpp.o: CMakeFiles/comp345.dir/flags.make
CMakeFiles/comp345.dir/Map/MapLoader.cpp.o: /Users/carlosgonzalez/Developer/GitHub/comp345/Map/MapLoader.cpp
CMakeFiles/comp345.dir/Map/MapLoader.cpp.o: CMakeFiles/comp345.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/carlosgonzalez/Developer/GitHub/comp345/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/comp345.dir/Map/MapLoader.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/comp345.dir/Map/MapLoader.cpp.o -MF CMakeFiles/comp345.dir/Map/MapLoader.cpp.o.d -o CMakeFiles/comp345.dir/Map/MapLoader.cpp.o -c /Users/carlosgonzalez/Developer/GitHub/comp345/Map/MapLoader.cpp

CMakeFiles/comp345.dir/Map/MapLoader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/comp345.dir/Map/MapLoader.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/carlosgonzalez/Developer/GitHub/comp345/Map/MapLoader.cpp > CMakeFiles/comp345.dir/Map/MapLoader.cpp.i

CMakeFiles/comp345.dir/Map/MapLoader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/comp345.dir/Map/MapLoader.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/carlosgonzalez/Developer/GitHub/comp345/Map/MapLoader.cpp -o CMakeFiles/comp345.dir/Map/MapLoader.cpp.s

CMakeFiles/comp345.dir/Player/Player.cpp.o: CMakeFiles/comp345.dir/flags.make
CMakeFiles/comp345.dir/Player/Player.cpp.o: /Users/carlosgonzalez/Developer/GitHub/comp345/Player/Player.cpp
CMakeFiles/comp345.dir/Player/Player.cpp.o: CMakeFiles/comp345.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/carlosgonzalez/Developer/GitHub/comp345/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/comp345.dir/Player/Player.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/comp345.dir/Player/Player.cpp.o -MF CMakeFiles/comp345.dir/Player/Player.cpp.o.d -o CMakeFiles/comp345.dir/Player/Player.cpp.o -c /Users/carlosgonzalez/Developer/GitHub/comp345/Player/Player.cpp

CMakeFiles/comp345.dir/Player/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/comp345.dir/Player/Player.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/carlosgonzalez/Developer/GitHub/comp345/Player/Player.cpp > CMakeFiles/comp345.dir/Player/Player.cpp.i

CMakeFiles/comp345.dir/Player/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/comp345.dir/Player/Player.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/carlosgonzalez/Developer/GitHub/comp345/Player/Player.cpp -o CMakeFiles/comp345.dir/Player/Player.cpp.s

CMakeFiles/comp345.dir/Player/PlayerDriver.cpp.o: CMakeFiles/comp345.dir/flags.make
CMakeFiles/comp345.dir/Player/PlayerDriver.cpp.o: /Users/carlosgonzalez/Developer/GitHub/comp345/Player/PlayerDriver.cpp
CMakeFiles/comp345.dir/Player/PlayerDriver.cpp.o: CMakeFiles/comp345.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/carlosgonzalez/Developer/GitHub/comp345/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/comp345.dir/Player/PlayerDriver.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/comp345.dir/Player/PlayerDriver.cpp.o -MF CMakeFiles/comp345.dir/Player/PlayerDriver.cpp.o.d -o CMakeFiles/comp345.dir/Player/PlayerDriver.cpp.o -c /Users/carlosgonzalez/Developer/GitHub/comp345/Player/PlayerDriver.cpp

CMakeFiles/comp345.dir/Player/PlayerDriver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/comp345.dir/Player/PlayerDriver.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/carlosgonzalez/Developer/GitHub/comp345/Player/PlayerDriver.cpp > CMakeFiles/comp345.dir/Player/PlayerDriver.cpp.i

CMakeFiles/comp345.dir/Player/PlayerDriver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/comp345.dir/Player/PlayerDriver.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/carlosgonzalez/Developer/GitHub/comp345/Player/PlayerDriver.cpp -o CMakeFiles/comp345.dir/Player/PlayerDriver.cpp.s

CMakeFiles/comp345.dir/OrderList/OrdersList.cpp.o: CMakeFiles/comp345.dir/flags.make
CMakeFiles/comp345.dir/OrderList/OrdersList.cpp.o: /Users/carlosgonzalez/Developer/GitHub/comp345/OrderList/OrdersList.cpp
CMakeFiles/comp345.dir/OrderList/OrdersList.cpp.o: CMakeFiles/comp345.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/carlosgonzalez/Developer/GitHub/comp345/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/comp345.dir/OrderList/OrdersList.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/comp345.dir/OrderList/OrdersList.cpp.o -MF CMakeFiles/comp345.dir/OrderList/OrdersList.cpp.o.d -o CMakeFiles/comp345.dir/OrderList/OrdersList.cpp.o -c /Users/carlosgonzalez/Developer/GitHub/comp345/OrderList/OrdersList.cpp

CMakeFiles/comp345.dir/OrderList/OrdersList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/comp345.dir/OrderList/OrdersList.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/carlosgonzalez/Developer/GitHub/comp345/OrderList/OrdersList.cpp > CMakeFiles/comp345.dir/OrderList/OrdersList.cpp.i

CMakeFiles/comp345.dir/OrderList/OrdersList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/comp345.dir/OrderList/OrdersList.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/carlosgonzalez/Developer/GitHub/comp345/OrderList/OrdersList.cpp -o CMakeFiles/comp345.dir/OrderList/OrdersList.cpp.s

CMakeFiles/comp345.dir/OrderList/OrdersDriver.cpp.o: CMakeFiles/comp345.dir/flags.make
CMakeFiles/comp345.dir/OrderList/OrdersDriver.cpp.o: /Users/carlosgonzalez/Developer/GitHub/comp345/OrderList/OrdersDriver.cpp
CMakeFiles/comp345.dir/OrderList/OrdersDriver.cpp.o: CMakeFiles/comp345.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/carlosgonzalez/Developer/GitHub/comp345/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/comp345.dir/OrderList/OrdersDriver.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/comp345.dir/OrderList/OrdersDriver.cpp.o -MF CMakeFiles/comp345.dir/OrderList/OrdersDriver.cpp.o.d -o CMakeFiles/comp345.dir/OrderList/OrdersDriver.cpp.o -c /Users/carlosgonzalez/Developer/GitHub/comp345/OrderList/OrdersDriver.cpp

CMakeFiles/comp345.dir/OrderList/OrdersDriver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/comp345.dir/OrderList/OrdersDriver.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/carlosgonzalez/Developer/GitHub/comp345/OrderList/OrdersDriver.cpp > CMakeFiles/comp345.dir/OrderList/OrdersDriver.cpp.i

CMakeFiles/comp345.dir/OrderList/OrdersDriver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/comp345.dir/OrderList/OrdersDriver.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/carlosgonzalez/Developer/GitHub/comp345/OrderList/OrdersDriver.cpp -o CMakeFiles/comp345.dir/OrderList/OrdersDriver.cpp.s

CMakeFiles/comp345.dir/Cards/CardsDriver.cpp.o: CMakeFiles/comp345.dir/flags.make
CMakeFiles/comp345.dir/Cards/CardsDriver.cpp.o: /Users/carlosgonzalez/Developer/GitHub/comp345/Cards/CardsDriver.cpp
CMakeFiles/comp345.dir/Cards/CardsDriver.cpp.o: CMakeFiles/comp345.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/carlosgonzalez/Developer/GitHub/comp345/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/comp345.dir/Cards/CardsDriver.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/comp345.dir/Cards/CardsDriver.cpp.o -MF CMakeFiles/comp345.dir/Cards/CardsDriver.cpp.o.d -o CMakeFiles/comp345.dir/Cards/CardsDriver.cpp.o -c /Users/carlosgonzalez/Developer/GitHub/comp345/Cards/CardsDriver.cpp

CMakeFiles/comp345.dir/Cards/CardsDriver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/comp345.dir/Cards/CardsDriver.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/carlosgonzalez/Developer/GitHub/comp345/Cards/CardsDriver.cpp > CMakeFiles/comp345.dir/Cards/CardsDriver.cpp.i

CMakeFiles/comp345.dir/Cards/CardsDriver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/comp345.dir/Cards/CardsDriver.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/carlosgonzalez/Developer/GitHub/comp345/Cards/CardsDriver.cpp -o CMakeFiles/comp345.dir/Cards/CardsDriver.cpp.s

CMakeFiles/comp345.dir/Cards/Cards.cpp.o: CMakeFiles/comp345.dir/flags.make
CMakeFiles/comp345.dir/Cards/Cards.cpp.o: /Users/carlosgonzalez/Developer/GitHub/comp345/Cards/Cards.cpp
CMakeFiles/comp345.dir/Cards/Cards.cpp.o: CMakeFiles/comp345.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/carlosgonzalez/Developer/GitHub/comp345/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/comp345.dir/Cards/Cards.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/comp345.dir/Cards/Cards.cpp.o -MF CMakeFiles/comp345.dir/Cards/Cards.cpp.o.d -o CMakeFiles/comp345.dir/Cards/Cards.cpp.o -c /Users/carlosgonzalez/Developer/GitHub/comp345/Cards/Cards.cpp

CMakeFiles/comp345.dir/Cards/Cards.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/comp345.dir/Cards/Cards.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/carlosgonzalez/Developer/GitHub/comp345/Cards/Cards.cpp > CMakeFiles/comp345.dir/Cards/Cards.cpp.i

CMakeFiles/comp345.dir/Cards/Cards.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/comp345.dir/Cards/Cards.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/carlosgonzalez/Developer/GitHub/comp345/Cards/Cards.cpp -o CMakeFiles/comp345.dir/Cards/Cards.cpp.s

CMakeFiles/comp345.dir/GameEngine/LoggingObserver.cpp.o: CMakeFiles/comp345.dir/flags.make
CMakeFiles/comp345.dir/GameEngine/LoggingObserver.cpp.o: /Users/carlosgonzalez/Developer/GitHub/comp345/GameEngine/LoggingObserver.cpp
CMakeFiles/comp345.dir/GameEngine/LoggingObserver.cpp.o: CMakeFiles/comp345.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/carlosgonzalez/Developer/GitHub/comp345/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/comp345.dir/GameEngine/LoggingObserver.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/comp345.dir/GameEngine/LoggingObserver.cpp.o -MF CMakeFiles/comp345.dir/GameEngine/LoggingObserver.cpp.o.d -o CMakeFiles/comp345.dir/GameEngine/LoggingObserver.cpp.o -c /Users/carlosgonzalez/Developer/GitHub/comp345/GameEngine/LoggingObserver.cpp

CMakeFiles/comp345.dir/GameEngine/LoggingObserver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/comp345.dir/GameEngine/LoggingObserver.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/carlosgonzalez/Developer/GitHub/comp345/GameEngine/LoggingObserver.cpp > CMakeFiles/comp345.dir/GameEngine/LoggingObserver.cpp.i

CMakeFiles/comp345.dir/GameEngine/LoggingObserver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/comp345.dir/GameEngine/LoggingObserver.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/carlosgonzalez/Developer/GitHub/comp345/GameEngine/LoggingObserver.cpp -o CMakeFiles/comp345.dir/GameEngine/LoggingObserver.cpp.s

CMakeFiles/comp345.dir/GameEngine/LoggingObserverDriver.cpp.o: CMakeFiles/comp345.dir/flags.make
CMakeFiles/comp345.dir/GameEngine/LoggingObserverDriver.cpp.o: /Users/carlosgonzalez/Developer/GitHub/comp345/GameEngine/LoggingObserverDriver.cpp
CMakeFiles/comp345.dir/GameEngine/LoggingObserverDriver.cpp.o: CMakeFiles/comp345.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/carlosgonzalez/Developer/GitHub/comp345/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/comp345.dir/GameEngine/LoggingObserverDriver.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/comp345.dir/GameEngine/LoggingObserverDriver.cpp.o -MF CMakeFiles/comp345.dir/GameEngine/LoggingObserverDriver.cpp.o.d -o CMakeFiles/comp345.dir/GameEngine/LoggingObserverDriver.cpp.o -c /Users/carlosgonzalez/Developer/GitHub/comp345/GameEngine/LoggingObserverDriver.cpp

CMakeFiles/comp345.dir/GameEngine/LoggingObserverDriver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/comp345.dir/GameEngine/LoggingObserverDriver.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/carlosgonzalez/Developer/GitHub/comp345/GameEngine/LoggingObserverDriver.cpp > CMakeFiles/comp345.dir/GameEngine/LoggingObserverDriver.cpp.i

CMakeFiles/comp345.dir/GameEngine/LoggingObserverDriver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/comp345.dir/GameEngine/LoggingObserverDriver.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/carlosgonzalez/Developer/GitHub/comp345/GameEngine/LoggingObserverDriver.cpp -o CMakeFiles/comp345.dir/GameEngine/LoggingObserverDriver.cpp.s

# Object files for target comp345
comp345_OBJECTS = \
"CMakeFiles/comp345.dir/MainDriver.cpp.o" \
"CMakeFiles/comp345.dir/GameEngine/GameEngine.cpp.o" \
"CMakeFiles/comp345.dir/GameEngine/GameEngineDriver.cpp.o" \
"CMakeFiles/comp345.dir/Map/Map.cpp.o" \
"CMakeFiles/comp345.dir/Map/MapDriver.cpp.o" \
"CMakeFiles/comp345.dir/Map/MapLoader.cpp.o" \
"CMakeFiles/comp345.dir/Player/Player.cpp.o" \
"CMakeFiles/comp345.dir/Player/PlayerDriver.cpp.o" \
"CMakeFiles/comp345.dir/OrderList/OrdersList.cpp.o" \
"CMakeFiles/comp345.dir/OrderList/OrdersDriver.cpp.o" \
"CMakeFiles/comp345.dir/Cards/CardsDriver.cpp.o" \
"CMakeFiles/comp345.dir/Cards/Cards.cpp.o" \
"CMakeFiles/comp345.dir/GameEngine/LoggingObserver.cpp.o" \
"CMakeFiles/comp345.dir/GameEngine/LoggingObserverDriver.cpp.o"

# External object files for target comp345
comp345_EXTERNAL_OBJECTS =

comp345: CMakeFiles/comp345.dir/MainDriver.cpp.o
comp345: CMakeFiles/comp345.dir/GameEngine/GameEngine.cpp.o
comp345: CMakeFiles/comp345.dir/GameEngine/GameEngineDriver.cpp.o
comp345: CMakeFiles/comp345.dir/Map/Map.cpp.o
comp345: CMakeFiles/comp345.dir/Map/MapDriver.cpp.o
comp345: CMakeFiles/comp345.dir/Map/MapLoader.cpp.o
comp345: CMakeFiles/comp345.dir/Player/Player.cpp.o
comp345: CMakeFiles/comp345.dir/Player/PlayerDriver.cpp.o
comp345: CMakeFiles/comp345.dir/OrderList/OrdersList.cpp.o
comp345: CMakeFiles/comp345.dir/OrderList/OrdersDriver.cpp.o
comp345: CMakeFiles/comp345.dir/Cards/CardsDriver.cpp.o
comp345: CMakeFiles/comp345.dir/Cards/Cards.cpp.o
comp345: CMakeFiles/comp345.dir/GameEngine/LoggingObserver.cpp.o
comp345: CMakeFiles/comp345.dir/GameEngine/LoggingObserverDriver.cpp.o
comp345: CMakeFiles/comp345.dir/build.make
comp345: CMakeFiles/comp345.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/carlosgonzalez/Developer/GitHub/comp345/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Linking CXX executable comp345"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/comp345.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/comp345.dir/build: comp345
.PHONY : CMakeFiles/comp345.dir/build

CMakeFiles/comp345.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/comp345.dir/cmake_clean.cmake
.PHONY : CMakeFiles/comp345.dir/clean

CMakeFiles/comp345.dir/depend:
	cd /Users/carlosgonzalez/Developer/GitHub/comp345/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/carlosgonzalez/Developer/GitHub/comp345 /Users/carlosgonzalez/Developer/GitHub/comp345 /Users/carlosgonzalez/Developer/GitHub/comp345/cmake-build-debug /Users/carlosgonzalez/Developer/GitHub/comp345/cmake-build-debug /Users/carlosgonzalez/Developer/GitHub/comp345/cmake-build-debug/CMakeFiles/comp345.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/comp345.dir/depend

