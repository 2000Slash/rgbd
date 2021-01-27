package midlevel

import (
	"github.com/2000Slash/rgbd/rgbctl/lowlevel"
	"strconv"
)

const (
    cmd_exit = iota
    cmd_refresh
    cmd_change_color
	cmd_key_color
)

func SetAllColors(color string, commit bool) error {
	return lowlevel.WriteToSocket(strconv.Itoa(cmd_change_color) + btou(commit) + color);
}

func SetKeyColor(key string, color string, commit bool) error {
	return lowlevel.WriteToSocket(strconv.Itoa(cmd_key_color) + btou(commit) + key + ";" + color);
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
