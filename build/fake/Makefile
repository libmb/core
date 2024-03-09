SUPPORTED_TARGETS = all clean fclean re check
UNSUPPORTED_TARGETS = test init

$(SUPPORTED_TARGETS):
	sh ../$@.sh
.PHONY: $(SUPPORTED_TARGETS)

.PHONY: $(UNSUPPORTED_TARGETS)
$(UNSUPPORTED_TARGETS):
	@echo GNU Make required. try gmake. ; ! :
