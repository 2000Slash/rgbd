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

func SetAllColors(color string, commit bool) error {
	return lowlevel.WriteToSocket(strconv.Itoa(cmd_change_color) + btou(commit) + color);
}

func btou(b bool) string {
	if b {
		return strconv.Itoa(1)
	}
	return strconv.Itoa(0)
}

func Update() error {
	return lowlevel.WriteToSocket(strconv.Itoa(cmd_refresh));
}
