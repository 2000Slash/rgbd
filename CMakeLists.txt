


list(APPEND daemon_sources "daemon/init.c" "daemon/fork.c")

add_executable(rgbd ${daemon_sources})
