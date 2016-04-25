Make file is used to specify compilation information i.e what flags shoud be included while compiling and what should be the order in which files should be complied so that dependencies can be preseverd while compiling.

eg.
all: find generate

find: find.c helpers.c helpers.h
		clang -ggdb3 -O0 -std=c11 -Wall -Werror -o find find.c helpers.c -lcs50 -lm

generate: generate.c
		clang -ggdb3 -O0 -std=c11 -Wall -Werror -o generate generate.c

clean:
		rm -f *.o a.out core find generate

-Here all specifies the sections to be executed like generate and find.
-Each word before the ':' specifies the section name and files that will be used in that section are named along
-The compilation inforamtion is written in the next line tabs and consisting of all the flags

- make or make all will perform the same function i.e the rule specified with the all.
- make [section name] e.g make find will execute only the rule specified in the find section.
- clean section is not necessary but it is required if we want to delete the compiled files.
