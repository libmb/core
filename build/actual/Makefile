include ../include/init.mk
include ../include/name.mk

WORKSPACE := ../..

include ../config/include.mk

SRCS := $(shell sh ../script/get-source.sh)
OBJS := $(SRCS:.c=.o)

CFLAGS += -I../../include

TARGET := $(NAME)

all: $(TARGET)
.PHONY: all

$(TARGET): $(addprefix obj/,$(OBJS))
	rm -f $@ $@.tmp
	$(AR) -c -r -s $@.tmp $^
	mv $@.tmp $@

obj/%.o: ../../src/%.c
	mkdir -p $$(dirname "$@")
ifeq ($(CLANG_OR_GCC),1)
ifeq ($(RELEASE),1)
	$(CC) $(CFLAGS) $(CPPFLAGS) -MMD -DNDEBUG -O3 -c -o $@ $<
else
	$(CC) $(CFLAGS) $(CPPFLAGS) -MMD -DDEBUG -g -c -o $@ $<
endif
-include $(OBJS:.o=.d)
else
	rm -f $@ $@.tmp
ifeq ($(RELEASE),1)
	$(CC) $(CFLAGS) $(CPPFLAGS) -DNDEBUG -O -c -o $@.tmp $<
else
	$(CC) $(CFLAGS) $(CPPFLAGS) -DDEBUG -g -c -o $@.tmp $<
endif
	mv $@.tmp $@
endif

.PHONY: clean
clean:
	rm -f $(NAME)
	find . -name "*.d" -delete
	find . -name "*.o" -delete
	find . -name "*.tmp" -delete

.PHONY: init
init:

.PHONY: init_compile_commands
init: init_compile_commands
init_compile_commands:
	sh ../misc/compile_commands.json.init.sh
.PHONY: clean_compile_commands
clean: clean_compile_commands
clean_compile_commands:
	sh ../misc/compile_commands.json.clean.sh
