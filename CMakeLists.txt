cmake_minimum_required(VERSION 3.10)

project(Simulator)

include_directories(osk/include include)
set(OSKSOURCES osk/src/sim.cpp osk/src/block.cpp osk/src/state.cpp)

set(SRC src/main.cpp)

add_executable(cmdtest ${SRC} ${OSKSOURCES})

