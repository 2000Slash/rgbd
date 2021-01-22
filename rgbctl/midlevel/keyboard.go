package midlevel

import (
	"github.com/2000Slash/rgbd/rgbctl/lowlevel"
	"strconv"
)

const (
    cmd_exit = iota
    cmd_refresh
    cmd_change_color
)

func SetAllColors(color string) error {
	return lowlevel.WriteToSocket(strconv.Itoa(cmd_change_color) + color);
}

func Update() error {
	return lowlevel.WriteToSocket("1");
}
