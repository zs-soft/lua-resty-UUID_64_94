CC      := gcc
LD      := ld
CFLAGS  := -fPIC -fno-stack-protector
LIB		:= -luuid
LDFLAGS := -shared 
SOURCE  := $(wildcard clib/*.c)
OBJS    := $(patsubst clib/%.c,clib/%.o,$(SOURCE))
TARGET_LIB := clib/libuuidx.so

all:$(OBJS)
	@echo $(OBJS)
	$(CC) $(LDFLAGS) $(LIB) -o $(TARGET_LIB) $(OBJS) 
	@rm *.o -rf

clib/%.o:clib/%.c
	@echo Compiling $< ...
	@$(CC) -c $(CFLAGS)  $< -o clib/$*.o

.PHONY: clean install

clean:
	rm clib/*.so clib/*.o -rf

install:
	cp clib/libuuidx.so $(INST_LIBDIR)
	cp -r lib/resty $(INST_LUADIR)
	cp clib/libuuidx.so /usr/local/lib64
