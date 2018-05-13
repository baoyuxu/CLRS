SUBDIRS:=chapter4 chapter6 chapter7

define op_subdir
	for sub in $(SUBDIRS) ; do \
		make $1 -C $$sub; \
	done;
endef

all:
	$(call op_subdir,all)

.PHONY:clean
clean:
	$(call op_subdir,clean)

