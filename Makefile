# Makefile for ncursesC_demo project

CC=gcc
PROG=ncursesC_demo
FILE=${PROG}.c
SRC_DIR=src
OUT_DIR=bin
LIBS=-lncurses

.PHONY: build
build: ${SRC_DIR}/${FILE}
	${CC} ${SRC_DIR}/${FILE} ${LIBS} -o ${OUT_DIR}/${PROG}

.PHONY: clean
clean:
	$(RM) -r ${OUT_DIR}
