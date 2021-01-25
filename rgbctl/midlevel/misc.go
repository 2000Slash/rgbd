package midlevel

import (
	"github.com/2000Slash/rgbd/rgbctl/lowlevel"
	"strconv"
)

func Exit() error {
	return lowlevel.WriteToSocket(strconv.Itoa(cmd_exit));
}
