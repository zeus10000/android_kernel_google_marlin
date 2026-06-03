# SPDX-License-Identifier: GPL-2.0-only
#
# fixdep: used to generate dependency information during build process

hostprogs-always-y	+= fixdep
hostprogs-always-y	+= bin2c

# bin2c is compiled with if_changed_dep, which invokes fixdep; force fixdep first
# to avoid a parallel-build race (scripts/basic/fixdep: not found).
$(obj)/bin2c: $(obj)/fixdep
