CC=gcc
CC_OPT=-g3 -fsanitize=address -Wall -Werror -Wextra
OUTPUT=my_ls

all: ${OUTPUT}

${OUTPUT}: main.o my.o work_with_files.o init.o get_opt.o print_opt.o free.o
	${CC} ${CC_OPT} main.o my.o work_with_files.o init.o get_opt.o print_opt.o free.o -o ${OUTPUT}

main.o: main.c
	${CC} ${CC_OPT} -c main.c

my.o: my.c
	${CC} ${CC_OPT} -c my.c

work_with_files.o: work_with_files.c
	${CC} ${CC_OPT} -c work_with_files.c

init.o: init.c
	${CC} ${CC_OPT} -c init.c

get_opt.o: get_opt.c
	${CC} ${CC_OPT} -c get_opt.c

print_opt.o: print_opt.c
	${CC} ${CC_OPT} -c print_opt.c

free.o: free.c
	${CC} ${CC_OPT} -c free.c

clean:
	rm *.o ${OUTPUT}