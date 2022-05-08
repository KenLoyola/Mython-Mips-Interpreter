CFLAGS=-g -Og -Wall -Wno-unused-variable -Wno-unused-function -ly -lfl
CC=gcc

p4_c:	p4.lex.yy.c p4.tab.c 
	$(CC) -o $@ p4.lex.yy.c p4.tab.c  $(CFLAGS)

p4.lex.yy.c:	p4_c.l
	flex -o $@ p4_c.l

p4.tab.c:	p4_c.y
	bison -o p4.tab.c -dv p4_c.y

clean:	
	rm -f p4_c p4.lex.yy.c p4.tab.* p4.output

