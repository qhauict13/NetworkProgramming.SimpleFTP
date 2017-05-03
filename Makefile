# compiler
CC=gcc
CFLAGS=-Wall -g -DNODEBUG
#-L/usr/lib/mysql -lmysqlclient

# solaris
uname_S := $(shell sh -c 'uname -s 2>/dev/null || echo not')
ifeq ($(uname_S),SunOS)
	CFLAGS=$(CFLAGS) -lnsl -lsocket -lresolv -D_PLATFORM_SOLARIS
endif

# targets
DEPS=siftp.o service.o
TARGETS=siftp siftpd

all: $(TARGETS)

siftpd: $(DEPS) server.o
	$(CC) $(CFLAGS) -o $@ $^ `mysql_config --cflags --libs`

siftp: $(DEPS) client.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f *.o $(TARGETS)

