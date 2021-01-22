package lowlevel

import (
	"errors"
	"net"
	"fmt"
)

const sockPath = "/tmp/rgbd.sock"

func WriteToSocket(message string) error {
	sock, err := openSocket()
	if err != nil {
		return err
	}
	fmt.Fprintf(sock, message)
	sock.Close()
	return nil
}

func openSocket() (net.Conn, error) {
	sock, err := net.Dial("unix", sockPath)
	if err != nil {
		return nil, errors.New("No connection could be established. Is rgbd running?")
	}
	return sock, err
}
