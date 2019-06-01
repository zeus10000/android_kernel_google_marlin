# SPDX-License-Identifier: GPL-2.0-only
# tools/power/acpi/Makefile - ACPI tool Makefile
#
# Copyright (c) 2013, Intel Corporation
#   Author: Lv Zheng <lv.zheng@intel.com>
#

include ../../scripts/Makefile.include

all: acpidump ec
clean: acpidump_clean ec_clean
install: acpidump_install ec_install
uninstall: acpidump_uninstall ec_uninstall

acpidump ec: FORCE
	$(call descend,tools/$@,all)
acpidump_clean ec_clean:
	$(call descend,tools/$(@:_clean=),clean)
acpidump_install ec_install:
	$(call descend,tools/$(@:_install=),install)
acpidump_uninstall ec_uninstall:
	$(call descend,tools/$(@:_uninstall=),uninstall)

.PHONY: FORCE
