MAKE_DEPEND = @set -e; rm -f $@; \
	$(CC) -MM  $(CFLAGS) $< > $@; \
	sed -i -e 's,\($*\)\.o[ :]*,\1.o $@ : ,g' $@

%.d : %.c
	$(MAKE_DEPEND)

%.d : %.S
	$(MAKE_DEPEND)

