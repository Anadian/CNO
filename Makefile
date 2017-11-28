#!/usr/bin/make

copy-dependencies: 
	cp ~/dev/whereami/src/whereami.h include/whereami.h
	cp ~/dev/whereami/src/whereami.c source/whereami.c
expand:
	cd ~/dev/CNO
	vim -S ~/.external_expand include/*.h source/*.c
