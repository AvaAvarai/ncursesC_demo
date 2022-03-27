# Makefile for ncursesC_demo project

CC=gcc
SRC_DIR=src
OUT_DIR=bin
LIBS=-lncurses

.PHONY: build
build: ${SRC_DIR}/ncursesC_demo.c
	${CC} ${SRC_DIR}/ncursesC_demo.c ${SRC_DIR}/entity.c ${LIBS} -o ${OUT_DIR}/ncursesC_demo

.PHONY: clean
clean:
	$(RM) -r ${OUT_DIR} && mkdir ${OUT_DIR}

.PHONY: all
all: clean build
