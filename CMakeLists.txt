


list(APPEND daemon_sources "daemon/init.c" "daemon/fork.c" "daemon/socket.c")

add_executable(rgbd ${daemon_sources})
