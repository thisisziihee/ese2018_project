DIR_SW=STOPWATCH/lib STOPWATCH/app
.PHONY: all clean


all:
	@for d in $(DIR_SW);\
	do\
		$(MAKE) -C $$d;\
	done

clean:
	@for d in $(DIR_SW);\
	do\
		$(MAKE) -C $$d clean;\
	done



