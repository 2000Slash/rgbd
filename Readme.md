# rgbd

This is a simple daemon that configures the rgb colors on a logitech Keyboard. This uses [g810-led](https://github.com/MatMoul/g810-led) so it supports the same keyboards.

## Installation

The daemon only depends on [g810-led](https://github.com/MatMoul/g810-led). Both the libusb and hidapi backends should work, although hidapi is the only thing tested right now. For building CMake is needed. With CMake  installed you can just run `cmake .` to generate the makefile. Then run `make` to build the daemon and the controller. The daemon (`rgbd`) will apply color to all keys if a keycode is sent to the unix socket in /tmp/rgbd.sock. For testing you can use the controller (`rgbctl`) with the color as the first argument. For example if you want red keys: `./rgbctl ff0000`.
