include build/include/name.mk

TARGETS = all clean fclean re test check init

$(NAME): all

.PHONY: $(TARGETS)
$(TARGETS):
	(cd build/fake && $(MAKE) $@)

.PHONY: package
package:
	sh build/package.sh
