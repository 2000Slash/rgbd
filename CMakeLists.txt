


list(APPEND daemon_sources "daemon/init.c" "daemon/fork.c" "daemon/socket.c" "daemon/keyboard.cpp")
list(APPEND ctl_sources "src/main.c")

add_executable(rgbd ${daemon_sources})
target_link_libraries(rgbd PUBLIC g810-led)
add_executable(rgbctl ${ctl_sources})
