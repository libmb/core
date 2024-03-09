include ../include/init.mk
include ../include/name.mk

ACTUAL_TARGETS = clean init

all:
	$(MAKE) -C ../actual all
	cp ../actual/$(NAME) ../../$(NAME)
.PHONY: all

.PHONY: $(ACTUAL_TARGETS)
$(ACTUAL_TARGETS):
	$(MAKE) -C ../actual $@

.PHONY: pre_clean
clean: pre_clean
pre_clean:
	sh ../clean.sh

.PHONY: fclean
fclean: clean
	rm -f ../../$(NAME)

.PHONY: re
re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: test
test:
	$(MAKE) -C ../../test

.PHONY: check
check:
	sh ../check.sh
