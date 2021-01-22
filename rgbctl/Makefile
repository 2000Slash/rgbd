

install: build
	sudo install ./rgbctl /usr/bin/rgbctl
	sudo install ./udev/rgbd.rules /etc/udev/rules.d/
	sudo udevadm control --reload-rules

uninstall:
	sudo rm /usr/bin/rgbctl
	sudo rm /etc/udev/rules.d/rgbd.rules
	sudo udevadm control --reload-rules

build:
	go build
