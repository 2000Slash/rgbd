


list(APPEND daemon_sources "daemon/init.c" "daemon/fork.c" "daemon/socket.c")
list(APPEND ctl_sources "src/main.c")

add_executable(rgbd ${daemon_sources})
add_executable(rgbctl ${ctl_sources})
