all:
	gcc slack_completion.c -pedantic -Wall -Wextra \
		`pkg-config --cflags mcabber` \
		`pkg-config --libs x11` -lxdo \
		-std=gnu99 \
		-shared -DMODULES_ENABLE  -fPIC\
		-o libslack_completion.so

install:
	install -D libslack_completion.so /usr/lib/mcabber/libslack_completion.so
