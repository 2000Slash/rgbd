package midlevel

import (
	"github.com/2000Slash/rgbd/rgbctl/lowlevel"
	"strconv"
)

func Exit(noSave bool) error {
	if noSave {
		return lowlevel.WriteToSocket(strconv.Itoa(cmd_exit) + "0");
	} else {
		return lowlevel.WriteToSocket(strconv.Itoa(cmd_exit) + "1");
	}
}
