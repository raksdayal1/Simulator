cmake_minimum_required(VERSION 3.10)

project(Simulator)

include_directories(osk/include include)
set(OSKSOURCES osk/src/sim.cpp osk/src/block.cpp osk/src/state.cpp)

set(SRC src/main.cpp src/simplerover.cpp src/p_utils.cpp src/libAP_JSON.cpp src/SocketExample.cpp)

add_executable(cmdtest ${SRC} ${OSKSOURCES})

