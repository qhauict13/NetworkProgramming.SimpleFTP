# compiler
CC=gcc
CFLAGS=-Wall -g
MYSQL_CONFIG = mysql_config
INCLUDES = ${shell $(MYSQL_CONFIG) --cflags}
LIBS = ${shell $(MYSQL_CONFIG) --libs}

# solaris
uname_S := $(shell sh -c 'uname -s 2>/dev/null || echo not')
ifeq ($(uname_S),SunOS)
	CFLAGS=$(CFLAGS) -lnsl -lsocket -lresolv -D_PLATFORM_SOLARIS
endif

# targets
DEPS=siftp.o service.o
TARGETS=siftp siftpd database

all: $(TARGETS)

siftpd: $(DEPS) server.o
	$(CC) $(CFLAGS) -o $@ $^ $(INCLUDES) $(LIBS)

siftp: $(DEPS) client.o
	$(CC) $(CFLAGS) -o $@ $^

database: database.o
	$(CC) $(CFLAGS) -o $@ $^ $(INCLUDES) $(LIBS)

clean:
	rm -f *.o $(TARGETS)

