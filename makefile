# Makefile for testing SLICE with Borland C++.

test.exe: slice.obj slice.h test.c
    bcc -ms -v test.c slice.obj

slice.obj: slice.asm
    tasm /zi /mx /m5 slice, , ,
