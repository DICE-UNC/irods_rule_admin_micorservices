MSI_READ_RULE	= microservices/msiReadRule
MSI_WRITE_RULE	= microservices/msiWriteRule

MAKEFLAGS += --no-print-directory

LIBS = $(MSI_READ_RULE) $(MSI_WRITE_RULE)

.PHONY: all $(LIBS) clean
all: $(LIBS)

$(LIBS):
	@$(MAKE) -C $@;

clean:
	@$(MAKE) -C $(MSI_READ_RULE) clean;
	@$(MAKE) -C $(MSI_WRITE_RULE) clean;
