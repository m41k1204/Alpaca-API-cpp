# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /snap/clion/314/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /snap/clion/314/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/m41k1/Documents/proyectos/alpaca/Alpaca-API

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/m41k1/Documents/proyectos/alpaca/Alpaca-API/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/AlpacaAPI.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/AlpacaAPI.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/AlpacaAPI.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AlpacaAPI.dir/flags.make

CMakeFiles/AlpacaAPI.dir/main.cpp.o: CMakeFiles/AlpacaAPI.dir/flags.make
CMakeFiles/AlpacaAPI.dir/main.cpp.o: /home/m41k1/Documents/proyectos/alpaca/Alpaca-API/main.cpp
CMakeFiles/AlpacaAPI.dir/main.cpp.o: CMakeFiles/AlpacaAPI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/m41k1/Documents/proyectos/alpaca/Alpaca-API/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AlpacaAPI.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AlpacaAPI.dir/main.cpp.o -MF CMakeFiles/AlpacaAPI.dir/main.cpp.o.d -o CMakeFiles/AlpacaAPI.dir/main.cpp.o -c /home/m41k1/Documents/proyectos/alpaca/Alpaca-API/main.cpp

CMakeFiles/AlpacaAPI.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/AlpacaAPI.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/m41k1/Documents/proyectos/alpaca/Alpaca-API/main.cpp > CMakeFiles/AlpacaAPI.dir/main.cpp.i

CMakeFiles/AlpacaAPI.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/AlpacaAPI.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/m41k1/Documents/proyectos/alpaca/Alpaca-API/main.cpp -o CMakeFiles/AlpacaAPI.dir/main.cpp.s

CMakeFiles/AlpacaAPI.dir/src/Account/Account.cpp.o: CMakeFiles/AlpacaAPI.dir/flags.make
CMakeFiles/AlpacaAPI.dir/src/Account/Account.cpp.o: /home/m41k1/Documents/proyectos/alpaca/Alpaca-API/src/Account/Account.cpp
CMakeFiles/AlpacaAPI.dir/src/Account/Account.cpp.o: CMakeFiles/AlpacaAPI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/m41k1/Documents/proyectos/alpaca/Alpaca-API/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/AlpacaAPI.dir/src/Account/Account.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AlpacaAPI.dir/src/Account/Account.cpp.o -MF CMakeFiles/AlpacaAPI.dir/src/Account/Account.cpp.o.d -o CMakeFiles/AlpacaAPI.dir/src/Account/Account.cpp.o -c /home/m41k1/Documents/proyectos/alpaca/Alpaca-API/src/Account/Account.cpp

CMakeFiles/AlpacaAPI.dir/src/Account/Account.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/AlpacaAPI.dir/src/Account/Account.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/m41k1/Documents/proyectos/alpaca/Alpaca-API/src/Account/Account.cpp > CMakeFiles/AlpacaAPI.dir/src/Account/Account.cpp.i

CMakeFiles/AlpacaAPI.dir/src/Account/Account.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/AlpacaAPI.dir/src/Account/Account.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/m41k1/Documents/proyectos/alpaca/Alpaca-API/src/Account/Account.cpp -o CMakeFiles/AlpacaAPI.dir/src/Account/Account.cpp.s

CMakeFiles/AlpacaAPI.dir/src/Asset/Asset.cpp.o: CMakeFiles/AlpacaAPI.dir/flags.make
CMakeFiles/AlpacaAPI.dir/src/Asset/Asset.cpp.o: /home/m41k1/Documents/proyectos/alpaca/Alpaca-API/src/Asset/Asset.cpp
CMakeFiles/AlpacaAPI.dir/src/Asset/Asset.cpp.o: CMakeFiles/AlpacaAPI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/m41k1/Documents/proyectos/alpaca/Alpaca-API/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/AlpacaAPI.dir/src/Asset/Asset.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AlpacaAPI.dir/src/Asset/Asset.cpp.o -MF CMakeFiles/AlpacaAPI.dir/src/Asset/Asset.cpp.o.d -o CMakeFiles/AlpacaAPI.dir/src/Asset/Asset.cpp.o -c /home/m41k1/Documents/proyectos/alpaca/Alpaca-API/src/Asset/Asset.cpp

CMakeFiles/AlpacaAPI.dir/src/Asset/Asset.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/AlpacaAPI.dir/src/Asset/Asset.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/m41k1/Documents/proyectos/alpaca/Alpaca-API/src/Asset/Asset.cpp > CMakeFiles/AlpacaAPI.dir/src/Asset/Asset.cpp.i

CMakeFiles/AlpacaAPI.dir/src/Asset/Asset.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/AlpacaAPI.dir/src/Asset/Asset.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/m41k1/Documents/proyectos/alpaca/Alpaca-API/src/Asset/Asset.cpp -o CMakeFiles/AlpacaAPI.dir/src/Asset/Asset.cpp.s

CMakeFiles/AlpacaAPI.dir/src/Clock/Clock.cpp.o: CMakeFiles/AlpacaAPI.dir/flags.make
CMakeFiles/AlpacaAPI.dir/src/Clock/Clock.cpp.o: /home/m41k1/Documents/proyectos/alpaca/Alpaca-API/src/Clock/Clock.cpp
CMakeFiles/AlpacaAPI.dir/src/Clock/Clock.cpp.o: CMakeFiles/AlpacaAPI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/m41k1/Documents/proyectos/alpaca/Alpaca-API/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/AlpacaAPI.dir/src/Clock/Clock.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AlpacaAPI.dir/src/Clock/Clock.cpp.o -MF CMakeFiles/AlpacaAPI.dir/src/Clock/Clock.cpp.o.d -o CMakeFiles/AlpacaAPI.dir/src/Clock/Clock.cpp.o -c /home/m41k1/Documents/proyectos/alpaca/Alpaca-API/src/Clock/Clock.cpp

CMakeFiles/AlpacaAPI.dir/src/Clock/Clock.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/AlpacaAPI.dir/src/Clock/Clock.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/m41k1/Documents/proyectos/alpaca/Alpaca-API/src/Clock/Clock.cpp > CMakeFiles/AlpacaAPI.dir/src/Clock/Clock.cpp.i

CMakeFiles/AlpacaAPI.dir/src/Clock/Clock.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/AlpacaAPI.dir/src/Clock/Clock.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/m41k1/Documents/proyectos/alpaca/Alpaca-API/src/Clock/Clock.cpp -o CMakeFiles/AlpacaAPI.dir/src/Clock/Clock.cpp.s

CMakeFiles/AlpacaAPI.dir/src/Order/Order.cpp.o: CMakeFiles/AlpacaAPI.dir/flags.make
CMakeFiles/AlpacaAPI.dir/src/Order/Order.cpp.o: /home/m41k1/Documents/proyectos/alpaca/Alpaca-API/src/Order/Order.cpp
CMakeFiles/AlpacaAPI.dir/src/Order/Order.cpp.o: CMakeFiles/AlpacaAPI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/m41k1/Documents/proyectos/alpaca/Alpaca-API/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/AlpacaAPI.dir/src/Order/Order.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AlpacaAPI.dir/src/Order/Order.cpp.o -MF CMakeFiles/AlpacaAPI.dir/src/Order/Order.cpp.o.d -o CMakeFiles/AlpacaAPI.dir/src/Order/Order.cpp.o -c /home/m41k1/Documents/proyectos/alpaca/Alpaca-API/src/Order/Order.cpp

CMakeFiles/AlpacaAPI.dir/src/Order/Order.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/AlpacaAPI.dir/src/Order/Order.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/m41k1/Documents/proyectos/alpaca/Alpaca-API/src/Order/Order.cpp > CMakeFiles/AlpacaAPI.dir/src/Order/Order.cpp.i

CMakeFiles/AlpacaAPI.dir/src/Order/Order.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/AlpacaAPI.dir/src/Order/Order.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/m41k1/Documents/proyectos/alpaca/Alpaca-API/src/Order/Order.cpp -o CMakeFiles/AlpacaAPI.dir/src/Order/Order.cpp.s

CMakeFiles/AlpacaAPI.dir/src/Position/Position.cpp.o: CMakeFiles/AlpacaAPI.dir/flags.make
CMakeFiles/AlpacaAPI.dir/src/Position/Position.cpp.o: /home/m41k1/Documents/proyectos/alpaca/Alpaca-API/src/Position/Position.cpp
CMakeFiles/AlpacaAPI.dir/src/Position/Position.cpp.o: CMakeFiles/AlpacaAPI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/m41k1/Documents/proyectos/alpaca/Alpaca-API/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/AlpacaAPI.dir/src/Position/Position.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AlpacaAPI.dir/src/Position/Position.cpp.o -MF CMakeFiles/AlpacaAPI.dir/src/Position/Position.cpp.o.d -o CMakeFiles/AlpacaAPI.dir/src/Position/Position.cpp.o -c /home/m41k1/Documents/proyectos/alpaca/Alpaca-API/src/Position/Position.cpp

CMakeFiles/AlpacaAPI.dir/src/Position/Position.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/AlpacaAPI.dir/src/Position/Position.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/m41k1/Documents/proyectos/alpaca/Alpaca-API/src/Position/Position.cpp > CMakeFiles/AlpacaAPI.dir/src/Position/Position.cpp.i

CMakeFiles/AlpacaAPI.dir/src/Position/Position.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/AlpacaAPI.dir/src/Position/Position.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/m41k1/Documents/proyectos/alpaca/Alpaca-API/src/Position/Position.cpp -o CMakeFiles/AlpacaAPI.dir/src/Position/Position.cpp.s

CMakeFiles/AlpacaAPI.dir/src/Quote/Quote.cpp.o: CMakeFiles/AlpacaAPI.dir/flags.make
CMakeFiles/AlpacaAPI.dir/src/Quote/Quote.cpp.o: /home/m41k1/Documents/proyectos/alpaca/Alpaca-API/src/Quote/Quote.cpp
CMakeFiles/AlpacaAPI.dir/src/Quote/Quote.cpp.o: CMakeFiles/AlpacaAPI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/m41k1/Documents/proyectos/alpaca/Alpaca-API/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/AlpacaAPI.dir/src/Quote/Quote.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AlpacaAPI.dir/src/Quote/Quote.cpp.o -MF CMakeFiles/AlpacaAPI.dir/src/Quote/Quote.cpp.o.d -o CMakeFiles/AlpacaAPI.dir/src/Quote/Quote.cpp.o -c /home/m41k1/Documents/proyectos/alpaca/Alpaca-API/src/Quote/Quote.cpp

CMakeFiles/AlpacaAPI.dir/src/Quote/Quote.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/AlpacaAPI.dir/src/Quote/Quote.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/m41k1/Documents/proyectos/alpaca/Alpaca-API/src/Quote/Quote.cpp > CMakeFiles/AlpacaAPI.dir/src/Quote/Quote.cpp.i

CMakeFiles/AlpacaAPI.dir/src/Quote/Quote.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/AlpacaAPI.dir/src/Quote/Quote.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/m41k1/Documents/proyectos/alpaca/Alpaca-API/src/Quote/Quote.cpp -o CMakeFiles/AlpacaAPI.dir/src/Quote/Quote.cpp.s

CMakeFiles/AlpacaAPI.dir/src/Quote/QuoteToCSV.cpp.o: CMakeFiles/AlpacaAPI.dir/flags.make
CMakeFiles/AlpacaAPI.dir/src/Quote/QuoteToCSV.cpp.o: /home/m41k1/Documents/proyectos/alpaca/Alpaca-API/src/Quote/QuoteToCSV.cpp
CMakeFiles/AlpacaAPI.dir/src/Quote/QuoteToCSV.cpp.o: CMakeFiles/AlpacaAPI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/m41k1/Documents/proyectos/alpaca/Alpaca-API/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/AlpacaAPI.dir/src/Quote/QuoteToCSV.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AlpacaAPI.dir/src/Quote/QuoteToCSV.cpp.o -MF CMakeFiles/AlpacaAPI.dir/src/Quote/QuoteToCSV.cpp.o.d -o CMakeFiles/AlpacaAPI.dir/src/Quote/QuoteToCSV.cpp.o -c /home/m41k1/Documents/proyectos/alpaca/Alpaca-API/src/Quote/QuoteToCSV.cpp

CMakeFiles/AlpacaAPI.dir/src/Quote/QuoteToCSV.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/AlpacaAPI.dir/src/Quote/QuoteToCSV.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/m41k1/Documents/proyectos/alpaca/Alpaca-API/src/Quote/QuoteToCSV.cpp > CMakeFiles/AlpacaAPI.dir/src/Quote/QuoteToCSV.cpp.i

CMakeFiles/AlpacaAPI.dir/src/Quote/QuoteToCSV.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/AlpacaAPI.dir/src/Quote/QuoteToCSV.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/m41k1/Documents/proyectos/alpaca/Alpaca-API/src/Quote/QuoteToCSV.cpp -o CMakeFiles/AlpacaAPI.dir/src/Quote/QuoteToCSV.cpp.s

CMakeFiles/AlpacaAPI.dir/src/Trade/Trade.cpp.o: CMakeFiles/AlpacaAPI.dir/flags.make
CMakeFiles/AlpacaAPI.dir/src/Trade/Trade.cpp.o: /home/m41k1/Documents/proyectos/alpaca/Alpaca-API/src/Trade/Trade.cpp
CMakeFiles/AlpacaAPI.dir/src/Trade/Trade.cpp.o: CMakeFiles/AlpacaAPI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/m41k1/Documents/proyectos/alpaca/Alpaca-API/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/AlpacaAPI.dir/src/Trade/Trade.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AlpacaAPI.dir/src/Trade/Trade.cpp.o -MF CMakeFiles/AlpacaAPI.dir/src/Trade/Trade.cpp.o.d -o CMakeFiles/AlpacaAPI.dir/src/Trade/Trade.cpp.o -c /home/m41k1/Documents/proyectos/alpaca/Alpaca-API/src/Trade/Trade.cpp

CMakeFiles/AlpacaAPI.dir/src/Trade/Trade.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/AlpacaAPI.dir/src/Trade/Trade.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/m41k1/Documents/proyectos/alpaca/Alpaca-API/src/Trade/Trade.cpp > CMakeFiles/AlpacaAPI.dir/src/Trade/Trade.cpp.i

CMakeFiles/AlpacaAPI.dir/src/Trade/Trade.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/AlpacaAPI.dir/src/Trade/Trade.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/m41k1/Documents/proyectos/alpaca/Alpaca-API/src/Trade/Trade.cpp -o CMakeFiles/AlpacaAPI.dir/src/Trade/Trade.cpp.s

CMakeFiles/AlpacaAPI.dir/src/TradeApi/Tradeapi.cpp.o: CMakeFiles/AlpacaAPI.dir/flags.make
CMakeFiles/AlpacaAPI.dir/src/TradeApi/Tradeapi.cpp.o: /home/m41k1/Documents/proyectos/alpaca/Alpaca-API/src/TradeApi/Tradeapi.cpp
CMakeFiles/AlpacaAPI.dir/src/TradeApi/Tradeapi.cpp.o: CMakeFiles/AlpacaAPI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/m41k1/Documents/proyectos/alpaca/Alpaca-API/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/AlpacaAPI.dir/src/TradeApi/Tradeapi.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AlpacaAPI.dir/src/TradeApi/Tradeapi.cpp.o -MF CMakeFiles/AlpacaAPI.dir/src/TradeApi/Tradeapi.cpp.o.d -o CMakeFiles/AlpacaAPI.dir/src/TradeApi/Tradeapi.cpp.o -c /home/m41k1/Documents/proyectos/alpaca/Alpaca-API/src/TradeApi/Tradeapi.cpp

CMakeFiles/AlpacaAPI.dir/src/TradeApi/Tradeapi.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/AlpacaAPI.dir/src/TradeApi/Tradeapi.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/m41k1/Documents/proyectos/alpaca/Alpaca-API/src/TradeApi/Tradeapi.cpp > CMakeFiles/AlpacaAPI.dir/src/TradeApi/Tradeapi.cpp.i

CMakeFiles/AlpacaAPI.dir/src/TradeApi/Tradeapi.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/AlpacaAPI.dir/src/TradeApi/Tradeapi.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/m41k1/Documents/proyectos/alpaca/Alpaca-API/src/TradeApi/Tradeapi.cpp -o CMakeFiles/AlpacaAPI.dir/src/TradeApi/Tradeapi.cpp.s

# Object files for target AlpacaAPI
AlpacaAPI_OBJECTS = \
"CMakeFiles/AlpacaAPI.dir/main.cpp.o" \
"CMakeFiles/AlpacaAPI.dir/src/Account/Account.cpp.o" \
"CMakeFiles/AlpacaAPI.dir/src/Asset/Asset.cpp.o" \
"CMakeFiles/AlpacaAPI.dir/src/Clock/Clock.cpp.o" \
"CMakeFiles/AlpacaAPI.dir/src/Order/Order.cpp.o" \
"CMakeFiles/AlpacaAPI.dir/src/Position/Position.cpp.o" \
"CMakeFiles/AlpacaAPI.dir/src/Quote/Quote.cpp.o" \
"CMakeFiles/AlpacaAPI.dir/src/Quote/QuoteToCSV.cpp.o" \
"CMakeFiles/AlpacaAPI.dir/src/Trade/Trade.cpp.o" \
"CMakeFiles/AlpacaAPI.dir/src/TradeApi/Tradeapi.cpp.o"

# External object files for target AlpacaAPI
AlpacaAPI_EXTERNAL_OBJECTS =

AlpacaAPI: CMakeFiles/AlpacaAPI.dir/main.cpp.o
AlpacaAPI: CMakeFiles/AlpacaAPI.dir/src/Account/Account.cpp.o
AlpacaAPI: CMakeFiles/AlpacaAPI.dir/src/Asset/Asset.cpp.o
AlpacaAPI: CMakeFiles/AlpacaAPI.dir/src/Clock/Clock.cpp.o
AlpacaAPI: CMakeFiles/AlpacaAPI.dir/src/Order/Order.cpp.o
AlpacaAPI: CMakeFiles/AlpacaAPI.dir/src/Position/Position.cpp.o
AlpacaAPI: CMakeFiles/AlpacaAPI.dir/src/Quote/Quote.cpp.o
AlpacaAPI: CMakeFiles/AlpacaAPI.dir/src/Quote/QuoteToCSV.cpp.o
AlpacaAPI: CMakeFiles/AlpacaAPI.dir/src/Trade/Trade.cpp.o
AlpacaAPI: CMakeFiles/AlpacaAPI.dir/src/TradeApi/Tradeapi.cpp.o
AlpacaAPI: CMakeFiles/AlpacaAPI.dir/build.make
AlpacaAPI: /usr/lib/x86_64-linux-gnu/libcurl.so
AlpacaAPI: CMakeFiles/AlpacaAPI.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/m41k1/Documents/proyectos/alpaca/Alpaca-API/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable AlpacaAPI"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AlpacaAPI.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AlpacaAPI.dir/build: AlpacaAPI
.PHONY : CMakeFiles/AlpacaAPI.dir/build

CMakeFiles/AlpacaAPI.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/AlpacaAPI.dir/cmake_clean.cmake
.PHONY : CMakeFiles/AlpacaAPI.dir/clean

CMakeFiles/AlpacaAPI.dir/depend:
	cd /home/m41k1/Documents/proyectos/alpaca/Alpaca-API/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/m41k1/Documents/proyectos/alpaca/Alpaca-API /home/m41k1/Documents/proyectos/alpaca/Alpaca-API /home/m41k1/Documents/proyectos/alpaca/Alpaca-API/cmake-build-debug /home/m41k1/Documents/proyectos/alpaca/Alpaca-API/cmake-build-debug /home/m41k1/Documents/proyectos/alpaca/Alpaca-API/cmake-build-debug/CMakeFiles/AlpacaAPI.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/AlpacaAPI.dir/depend

