CC := gcc
CFLAGS := -g -Wall -I/usr/include/mysql -L/usr/lib/x86_64-linux-gnu 
BIN_NAME := skeylogger
OBJS := mysql_handler.o skeylogger.o key_util.o options.o config.o	

all: $(BIN_NAME)

$(BIN_NAME): $(OBJS)
	gcc $(CFLAGS)   $(OBJS) -o  $(BIN_NAME) -lmysqlclient -lpthread -lz -lm -lrt -latomic -ldl

clean:
	rm -f *.o $(BIN_NAME)
