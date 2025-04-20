# Makefile template

__START = @echo @start: $(@)
__ECHO = @echo
__MAKE = make
__RM = rm
__MKDIR = mkdir
__SHELL = sh
__MAKEFILE = make -f Makefile

.PHONY: default
default: all_hook

.PHONY: all_hook
all_hook:
	$(__START)
	$(__MAKEFILE) all

.PHONY: all
all:
	$(__START)
	$(__MAKE) -f Makefile.c.template $(@)

.PHONY: libf_ds.a
libf_ds.a:
	$(__START)
	$(__MAKE) -f Makefile.c.template $(@)

.PHONY: libf_sl.a
libf_sl.a:
	$(__START)
	$(__MAKE) -f Makefile.c.template $(@)

.PHONY: test_bench_avltree
test_bench_avltree:
	$(__START)
	$(__MAKE) -f Makefile.c.template $(@)

.PHONY: test_bench_rbtree
test_bench_rbtree:
	$(__START)
	$(__MAKE) -f Makefile.c.template $(@)

.PHONY: test_bench_list
test_bench_list:
	$(__START)
	$(__MAKE) -f Makefile.c.template $(@)

.PHONY: clean
clean:
	$(__START)
	$(__MAKE) -f Makefile.c.template $(@)

.PHONY: clean_obj
clean_obj:
	$(__START)
	$(__MAKE) -f Makefile.c.template $(@)
