cmake_minimum_required(VERSION 3.19)
project(rgbd)


list(APPEND daemon_sources "daemon/init.c" "daemon/fork.c" "daemon/socket.c" "daemon/keyboard.cpp" "daemon/parser.c")
list(APPEND ctl_sources "src/main.c")

add_executable(rgbd ${daemon_sources})
target_link_libraries(rgbd PUBLIC g810-led)
