ifeq ($(WORKSPACE),)
$(error WORKSPACE variable is not defined)
endif

_ := $(shell [ -f $(WORKSPACE)/build/config/local.mk ] || sh $(WORKSPACE)/build/config/generate.sh > $(WORKSPACE)/build/config/local.mk)
include $(WORKSPACE)/build/config/local.mk
.PHONY: clean_local_mk
clean: clean_local_mk
clean_local_mk:
	rm -f $(WORKSPACE)/build/config/local.mk

ifeq ($(filter-out clang gcc, $(CC)),)
CLANG_OR_GCC := 1
endif

RELEASE ?= 1

-include $(WORKSPACE)/env.mk
