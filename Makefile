CFLAGS := -std=c11 -Wall -Wextra -g

rm0: rm0.c
	cc $(CFLAGS) -o rm0.o $^ 

ls0: ls0.c
	cc $(CFLAGS) -o ls0.o $^ 

cat0: cat0.c
	cc $(CFLAGS) -o cat0.o $^ > $@

stat0: stat0.c
	cc $(CFLAGS) -o stat0.o $^ > $@

clean:
	rm -f *.o
