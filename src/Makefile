# Makefile - General Makefile for build
#

# include gerneral Makefile configuration file
include Makefile.inc

# object file list
OBJECTS = main.o parse_proc.o mmap.o

# execute file

EXE = my_ps

all : ${EXE}

clean : 
	${RM} *.o ${EXE}

showall :
	@ echo ${EXE}

${EXE} : ${OBJECTS}
	${CC} ${CFLAGS} -o $@ $^
