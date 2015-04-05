MSI_READ_RULE_SET	= microservices/msiReadRuleSet
MSI_WRITE_RULE_SET	= microservices/msiWriteRuleSet
MSI_CHKSUM_RULE_SET	= microservices/msiChksumRuleSet
MSI_RM_RULE_SET	= microservices/msiRmRuleSet
MSI_MV_RULE_SET	= microservices/msiMvRuleSet
MSI_GET_ALL_RESOURCES	= microservices/msiGetAllResources
MSI_RULE_SET_EXISTS	= microservices/msiRuleSetExists

MAKEFLAGS += --no-print-directory

LIBS = $(MSI_READ_RULE_SET) $(MSI_WRITE_RULE_SET) $(MSI_CHKSUM_RULE_SET) $(MSI_RM_RULE_SET) $(MSI_MV_RULE_SET) $(MSI_GET_ALL_RESOURCES) $(MSI_RULE_SET_EXISTS)

.PHONY: all $(LIBS) clean
all: $(LIBS)

$(LIBS):
	@$(MAKE) -C $@;

clean:
	@$(MAKE) -C $(MSI_READ_RULE) clean;
	@$(MAKE) -C $(MSI_WRITE_RULE) clean;
