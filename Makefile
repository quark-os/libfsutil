objects = file.o scanner.o workdir.o

CPPFLAGS += -shared -fPIC -std=c++11 -Iinclude/

gnu: $(addprefix src/gnu/, $(objects))
	g++ $(CPPFLAGS) $(addprefix src/gnu/, $(objects)) -o bin/libfsutil.so

install-gnu:
	mkdir -p /usr/include/fsutil
	cp include/* /usr/include/fsutil
	cp bin/libfsutil.so /lib
