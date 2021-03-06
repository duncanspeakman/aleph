
# change this to your module name
module_name = mix

# paths to aleph repository sources
audio = ../../dsp
bfin = ../../bfin_lib/src

include version.mk
version = $(maj).$(min).$(rev)
ldr_name = aleph-$(module_name)-$(version).ldr

# add sources from here/audio library.
module_obj = mix.o \
	$(audio)/filter_1p.o \


# -----  below here, probably dont need to customize.

all: aleph-$(module_name).ldr

# this gets the core configuration and sources
include ../../bfin_lib/bfin_lib.mk

CFLAGS += -D ARCH_BFIN=1
# diagnose gcc errors
# CFLAGS += --verbose

desc_src = \
	$(bfin_lib_srcdir)desc.c \
	$(bfin_lib_srcdir)pickle.c \
	params.c

# this target generates the descriptor helper program
desc:
	gcc $(desc_src) \
	$(INC) \
	-D NAME=\"$(module_name)\" \
	-o $(module_name)_desc_build

$(module_obj): %.o : %.c	
	$(CC) $(CFLAGS) -c -o $@ $< $(LDFLAGS)

aleph-$(module_name): bfin_lib_target $(module_obj)
	$(CC) $(LDFLAGS) -T aleph-$(module_name).lds \
	$(patsubst %.o, $(bfin_lib_objdir)%.o, $(bfin_lib_obj)) \
	$(module_obj) \
	-o aleph-$(module_name) \
	-lm -lbfdsp -lbffastfp

clean: bfin_lib_clean
	rm $(module_obj)
	rm aleph-$(module_name).ldr 
	rm aleph-$(module_name)

# this generates the module and descriptor helper app,
# runs the descrptor app to generate .dsc,
# and makes copies with version number strings.
# best used after "make clean"
deploy: aleph-$(module_name).ldr
	make desc
	./$(module_name)_desc_build
	cp aleph-$(module_name).ldr aleph-$(module_name)-$(maj).$(min).$(rev).ldr
	cp aleph-$(module_name).dsc aleph-$(module_name)-$(maj).$(min).$(rev).dsc

.PHONY: clean
	deploy