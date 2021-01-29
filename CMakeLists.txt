cmake_minimum_required(VERSION 3.19)
project(rgbd)


list(APPEND daemon_sources "daemon/init.c" "daemon/fork.c" "daemon/socket.c" "daemon/parser.cpp" "daemon/keyboard/KeyboardParser.cpp" "daemon/keyboard/Keyboard.cpp" "daemon/keyboard/KeyboardConfig.cpp")
list(APPEND g810_sources "g810-led/src/main.cpp" "g810-led/src/classes/Keyboard.cpp" "g810-led/src/helpers/help.cpp" "g810-led/src/helpers/utils.cpp")

add_executable(rgbd ${daemon_sources})
add_definitions("-Dhidapi")
add_library(g810-led SHARED ${g810_sources})

target_include_directories(rgbd PRIVATE "g810-led/src")

target_link_libraries(g810-led PUBLIC hidapi-hidraw)
target_link_libraries(rgbd PUBLIC g810-led)
