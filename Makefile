#!/usr/bin/make
#Options
ifeq ($(origin VERBOSE),undefined)
VERBOSE=0
endif #($(origin VERBOSE),undefined)
ifeq ($(VERBOSE),1)
$(info VERBOSE:$(VERBOSE))
endif #($(VERBOSE),1)

#Project Metadata
#mkvar(NAME,cno)
ifeq ($(origin NAME),undefined)
NAME=cno
endif #($(origin NAME),undefined)
ifeq ($(VERBOSE),1)
$(info NAME:$(NAME))
endif #($(VERBOSE),1)


#mkvar(PROJECT_DIRECTORY,$(shell pwd))
ifeq ($(origin PROJECT_DIRECTORY),undefined)
PROJECT_DIRECTORY=$(shell pwd)
endif #($(origin PROJECT_DIRECTORY),undefined)
ifeq ($(VERBOSE),1)
$(info PROJECT_DIRECTORY:$(PROJECT_DIRECTORY))
endif #($(VERBOSE),1)


#mkvar(GIT_CURRENT,$(shell git-current))
ifeq ($(origin GIT_CURRENT),undefined)
GIT_CURRENT=$(shell git-current)
endif #($(origin GIT_CURRENT),undefined)
ifeq ($(VERBOSE),1)
$(info GIT_CURRENT:$(GIT_CURRENT))
endif #($(VERBOSE),1)


#mkvar(GIT_COMMIT,$(subst commit ,commit-,$(GIT_CURRENT))
ifeq ($(origin GIT_COMMIT),undefined)
GIT_COMMIT=$(subst commit ,commit-,$(GIT_CURRENT))
endif #($(origin GIT_COMMIT),undefined)
ifeq ($(VERBOSE),1)
$(info GIT_COMMIT:$(GIT_COMMIT))
endif #($(VERBOSE),1)


#System Information
#mkvar(PROCESSOR,$(shell uname -p))
ifeq ($(origin PROCESSOR),undefined)
PROCESSOR=$(shell uname -p)
endif #($(origin PROCESSOR),undefined)
ifeq ($(VERBOSE),1)
$(info PROCESSOR:$(PROCESSOR))
endif #($(VERBOSE),1)


#mkvar(ARCHITECTURE,$(shell uname -m))
ifeq ($(origin ARCHITECTURE),undefined)
ARCHITECTURE=$(shell uname -m)
endif #($(origin ARCHITECTURE),undefined)
ifeq ($(VERBOSE),1)
$(info ARCHITECTURE:$(ARCHITECTURE))
endif #($(VERBOSE),1)


#mkvar(KERNEL,$(shell uname -s))
ifeq ($(origin KERNEL),undefined)
KERNEL=$(shell uname -s)
endif #($(origin KERNEL),undefined)
ifeq ($(VERBOSE),1)
$(info KERNEL:$(KERNEL))
endif #($(VERBOSE),1)


#mkvar(KERNEL_RELEASE,$(shell uname -r))
ifeq ($(origin KERNEL_RELEASE),undefined)
KERNEL_RELEASE=$(shell uname -r)
endif #($(origin KERNEL_RELEASE),undefined)
ifeq ($(VERBOSE),1)
$(info KERNEL_RELEASE:$(KERNEL_RELEASE))
endif #($(VERBOSE),1)


#mkvar(OPERATING_SYSTEM,$(shell uname -o))
ifeq ($(origin OPERATING_SYSTEM),undefined)
OPERATING_SYSTEM=$(shell uname -o)
endif #($(origin OPERATING_SYSTEM),undefined)
ifeq ($(VERBOSE),1)
$(info OPERATING_SYSTEM:$(OPERATING_SYSTEM))
endif #($(VERBOSE),1)


#Build Informations
#mkvar(COMPILER,gcc)
ifeq ($(origin COMPILER),undefined)
COMPILER=gcc
endif #($(origin COMPILER),undefined)
ifeq ($(VERBOSE),1)
$(info COMPILER:$(COMPILER))
endif #($(VERBOSE),1)


##Directories
#mkvar(SOURCE_DIRECTORY,./source)
ifeq ($(origin SOURCE_DIRECTORY),undefined)
SOURCE_DIRECTORY=./source
endif #($(origin SOURCE_DIRECTORY),undefined)
ifeq ($(VERBOSE),1)
$(info SOURCE_DIRECTORY:$(SOURCE_DIRECTORY))
endif #($(VERBOSE),1)

#mkvar(INCLUDE_DIRECTORY,./include)
ifeq ($(origin INCLUDE_DIRECTORY),undefined)
INCLUDE_DIRECTORY=./include
endif #($(origin INCLUDE_DIRECTORY),undefined)
ifeq ($(VERBOSE),1)
$(info INCLUDE_DIRECTORY:$(INCLUDE_DIRECTORY))
endif #($(VERBOSE),1)

#mkvar(STATIC_LIBRARY_DIRECTORY,./static_library)
ifeq ($(origin STATIC_LIBRARY_DIRECTORY),undefined)
STATIC_LIBRARY_DIRECTORY=./static_library
endif #($(origin STATIC_LIBRARY_DIRECTORY),undefined)
ifeq ($(VERBOSE),1)
$(info STATIC_LIBRARY_DIRECTORY:$(STATIC_LIBRARY_DIRECTORY))
endif #($(VERBOSE),1)

#mkvar(OBJECTS_DIRECTORY,./OBJECTS)
ifeq ($(origin OBJECTS_DIRECTORY),undefined)
OBJECTS_DIRECTORY=./OBJECTS
endif #($(origin OBJECTS_DIRECTORY),undefined)
ifeq ($(VERBOSE),1)
$(info OBJECTS_DIRECTORY:$(OBJECTS_DIRECTORY))
endif #($(VERBOSE),1)

#mkvar(OUTPUT_DIRECTORY,./OUTPUT)
ifeq ($(origin OUTPUT_DIRECTORY),undefined)
OUTPUT_DIRECTORY=./OUTPUT
endif #($(origin OUTPUT_DIRECTORY),undefined)
ifeq ($(VERBOSE),1)
$(info OUTPUT_DIRECTORY:$(OUTPUT_DIRECTORY))
endif #($(VERBOSE),1)


###Sanity Checks
ifeq ($(wildcard $(OBJECTS_DIRECTORY)/*),)
$(shell mkdir $(OBJECTS_DIRECTORY))
endif #($(wildcard $(OBJECTS_DIRECTORY)/*),)
ifeq ($(wildcard $(OUTPUT_DIRECTORY)/*),)
$(shell mkdir $(OUTPUT_DIRECTORY))
endif #($(wildcard $(OUTPUT_DIRECTORY)/*),)

##Files
#mkvar(SOURCE_FILES,$(wildcard $(SOURCE_DIRECTORY)/*.c))
ifeq ($(origin SOURCE_FILES),undefined)
SOURCE_FILES=$(wildcard $(SOURCE_DIRECTORY)/*.c)
endif #($(origin SOURCE_FILES),undefined)
ifeq ($(VERBOSE),1)
$(info SOURCE_FILES:$(SOURCE_FILES))
endif #($(VERBOSE),1)

#mkvar(INCLUDE_FILES,$(wildcard $(INCLUDE_DIRECTORY)/*.h))
ifeq ($(origin INCLUDE_FILES),undefined)
INCLUDE_FILES=$(wildcard $(INCLUDE_DIRECTORY)/*.h)
endif #($(origin INCLUDE_FILES),undefined)
ifeq ($(VERBOSE),1)
$(info INCLUDE_FILES:$(INCLUDE_FILES))
endif #($(VERBOSE),1)

#mkvar(TMP_OBJECTS,$(subst $(SOURCE_DIRECTORY),$(OBJECTS_DIRECTORY),$(SOURCE_FILES)))
ifeq ($(origin TMP_OBJECTS),undefined)
TMP_OBJECTS=$(subst $(SOURCE_DIRECTORY),$(OBJECTS_DIRECTORY),$(SOURCE_FILES))
endif #($(origin TMP_OBJECTS),undefined)
ifeq ($(VERBOSE),1)
$(info TMP_OBJECTS:$(TMP_OBJECTS))
endif #($(VERBOSE),1)

#mkvar(OBJECT_FILES,$(subst .c,.o,$(TMP_OBJECTS)))
ifeq ($(origin OBJECT_FILES),undefined)
OBJECT_FILES=$(subst .c,.o,$(TMP_OBJECTS))
endif #($(origin OBJECT_FILES),undefined)
ifeq ($(VERBOSE),1)
$(info OBJECT_FILES:$(OBJECT_FILES))
endif #($(VERBOSE),1)

#mkvar(BINARY_NAME,$(OUTPUT_DIRECTORY)/$(NAME).$(OPERATING_SYSTEM))
ifeq ($(origin BINARY_NAME),undefined)
BINARY_NAME=$(OUTPUT_DIRECTORY)/$(NAME).$(OPERATING_SYSTEM)
endif #($(origin BINARY_NAME),undefined)
ifeq ($(VERBOSE),1)
$(info BINARY_NAME:$(BINARY_NAME))
endif #($(VERBOSE),1)

#mkvar(LIBRARY_NAME,$(OUTPUT_DIRECTORY)/lib$(NAME).a)
ifeq ($(origin LIBRARY_NAME),undefined)
LIBRARY_NAME=$(OUTPUT_DIRECTORY)/lib$(NAME).a
endif #($(origin LIBRARY_NAME),undefined)
ifeq ($(VERBOSE),1)
$(info LIBRARY_NAME:$(LIBRARY_NAME))
endif #($(VERBOSE),1)


#Flags
#mkvar(FLAG_PREDEFINED_MACROS,-DMAKE_GIT_COMMIT=$(GIT_COMMIT))
ifeq ($(origin FLAG_PREDEFINED_MACROS),undefined)
FLAG_PREDEFINED_MACROS=-DMAKE_GIT_COMMIT=$(GIT_COMMIT)
endif #($(origin FLAG_PREDEFINED_MACROS),undefined)
ifeq ($(VERBOSE),1)
$(info FLAG_PREDEFINED_MACROS:$(FLAG_PREDEFINED_MACROS))
endif #($(VERBOSE),1)

#mkvar(FLAG_INCLUDE_SEARCH_DIRECTORIES,-I/usr/include -I/usr/local/include -I~/include -I$(INCLUDE_DIRECTORY)
ifeq ($(origin FLAG_INCLUDE_SEARCH_DIRECTORIES),undefined)
FLAG_INCLUDE_SEARCH_DIRECTORIES=-I/usr/include -I/usr/local/include -I~/include -I$(INCLUDE_DIRECTORY)
endif #($(origin FLAG_INCLUDE_SEARCH_DIRECTORIES),undefined)
ifeq ($(VERBOSE),1)
$(info FLAG_INCLUDE_SEARCH_DIRECTORIES:$(FLAG_INCLUDE_SEARCH_DIRECTORIES))
endif #($(VERBOSE),1)

#mkvar(FLAG_STATIC_LIBRARY_SEARCH_DIRECTORIES,-L/usr/lib -L/usr/local/lib -L~/lib -L$(STATIC_LIBRARY_DIRECTORY)
ifeq ($(origin FLAG_STATIC_LIBRARY_SEARCH_DIRECTORIES),undefined)
FLAG_STATIC_LIBRARY_SEARCH_DIRECTORIES=-L/usr/lib -L/usr/local/lib -L~/lib -L$(STATIC_LIBRARY_DIRECTORY)
endif #($(origin FLAG_STATIC_LIBRARY_SEARCH_DIRECTORIES),undefined)
ifeq ($(VERBOSE),1)
$(info FLAG_STATIC_LIBRARY_SEARCH_DIRECTORIES:$(FLAG_STATIC_LIBRARY_SEARCH_DIRECTORIES))
endif #($(VERBOSE),1)

#mkvar(LINK_FLAGS,)
ifeq ($(origin LINK_FLAGS),undefined)
LINK_FLAGS=
endif #($(origin LINK_FLAGS),undefined)
ifeq ($(VERBOSE),1)
$(info LINK_FLAGS:$(LINK_FLAGS))
endif #($(VERBOSE),1)

#mkvar(DEBUG_FLAGS,)
ifeq ($(origin DEBUG_FLAGS),undefined)
DEBUG_FLAGS=
endif #($(origin DEBUG_FLAGS),undefined)
ifeq ($(VERBOSE),1)
$(info DEBUG_FLAGS:$(DEBUG_FLAGS))
endif #($(VERBOSE),1)


#mkvar(FLAGS,$(FLAG_PREDEFINED_MACROS) $(FLAG_INCLUDE_SEARCH_DIRECTORIES) $(FLAG_STATIC_LIBRARY_SEARCH_DIRECTORIES) $(LINK_FLAGS) $(DEBUG_FLAGS))
ifeq ($(origin FLAGS),undefined)
FLAGS=$(FLAG_PREDEFINED_MACROS) $(FLAG_INCLUDE_SEARCH_DIRECTORIES) $(FLAG_STATIC_LIBRARY_SEARCH_DIRECTORIES) $(LINK_FLAGS) $(DEBUG_FLAGS)
endif #($(origin FLAGS),undefined)
ifeq ($(VERBOSE),1)
$(info FLAGS:$(FLAGS))
endif #($(VERBOSE),1)

#mkvar(TEST1_FILES,source/cno_string.c source/cno_time.c source/cno_filestream.c)
ifeq ($(origin TEST1_FILES),undefined)
TEST1_FILES=source/cno_string.c source/cno_time.c source/cno_filestream.c
endif #($(origin TEST1_FILES),undefined)
ifeq ($(VERBOSE),1)
$(info TEST1_FILES:$(TEST1_FILES))
endif #($(VERBOSE),1)

#mkvar(TEST2_FILES,$(TEST1_FILES) include/parson.h source/parson.c include/cno_build.h include/c_predefined.h include/cno_environment.h source/cno_environment.c)
ifeq ($(origin TEST2_FILES),undefined)
TEST2_FILES=$(TEST1_FILES) include/parson.h source/parson.c include/cno_build.h include/c_predefined.h include/cno_environment.h source/cno_environment.c
endif #($(origin TEST2_FILES),undefined)
ifeq ($(VERBOSE),1)
$(info TEST2_FILES:$(TEST2_FILES))
endif #($(VERBOSE),1)


#Recipes
##GNU_Make
.PHONY: copy-dependencies expand noop help
	

%.o:
	$(COMPILER) $(INCLUDE_FILES) -c $(SOURCE_DIRECTORY)/$(subst .o,.c,$(notdir $@)) -o $@

##Development
copy-dependencies: 
	cd ~/dev/CNO
	cp -f ~/dev/whereami/src/whereami.h include/whereami.h
	cp -f ~/dev/whereami/src/whereami.c source/whereami.c
	cp -f ~/dev/stb/stretchy_buffer.h include/stretchy_buffer.h
	cp -f ~/dev/utf8.h/utf8.h include/utf8.h
	cp -f ~/dev/parson/parson.h include/parson.h
	cp -f ~/dev/parson/parson.c source/parson.c
	cp -f ~/dev/tinyheaders/tinyfiles.h include/tinyfiles.h
	
expand:
	cd ~/dev/CNO
	vim -S ~/.external_expand include/*.h source/*.c

noop:
	

help:
	$(info Available commands, with synonyms:)
	$(info help: Display this help text.)
	$(info noop: Print configuration variables and exit.)

test:
	$(COMPILER) $(FLAGS) $(TEST1_FILES) source/test.c -o a.out
	./a.out

test2:
	$(COMPILER) $(FLAGS) $(TEST2_FILES) source/test2.c -o a.out
	./a.out

