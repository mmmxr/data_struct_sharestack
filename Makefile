.PHONY:clean

sharestack:sharestack.c seqstack.c
	gcc $^ -o $@

clean:
	rm sharestack
