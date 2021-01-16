# rgbd

This is a simple daemon that configures the rgb colors on a logitech Keyboard. It uses [g810-led](https://github.com/MatMoul/g810-led) so it supports the same keyboards.

## Overview

This github repo contains the RGB-Daemon (rgbd) and a controller for the daemon (rgbctl). The daemon is an executable writte in c and c++. The controller is written in go. Since the daemon listens to /tmp/rgbd.sock, one can build their own controller, or even use netcat-openbsd with the flag -U. Right now the controller only supports the set option that can be called with a hex color, for example `rgbctl set ff0000` to turn the whole keyboard red.

## Installation

### Daemon
The daemon uses cmake and depends on [g810-led](https://github.com/MatMoul/g810-led). Both the libusb and hidapi backends should work, although hidapi is the only thing tested right now. For building, the cmake cache has to be generated first. This is done with `cmake .` After this the binary can be build with either `make` (if using the make build system), or `cmake --build .`

### Controller
The controller uses the golang build system, so a simple `go build -o rgbctl` should compile the binary. For argument parsing, [cobra](https://github.com/spf13/cobra) is used.
