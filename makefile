.SUFFIXES: .c.o

GCC         = gcc
CFLAGS		= -O2 -W -Wall -I. -Iinclude
SOX			= sox

OUT_DIR		= bin
OBJ_DIR		= src

TEST_DIR	= test
LIB_DIR		= libs

C_OBJS      = $(OBJ_DIR)/src/BR_api.o $(OBJ_DIR)/src/BR_core.o $(OBJ_DIR)/src/common.o
	
DEMO_OBJ    = $(OBJ_DIR)/demo/BR_demo.o
DEMO		= $(OUT_DIR)/BR_demo

ALIB		= $(LIB_DIR)/libBR_api.a
HRIR_mat	= HRIR/IRC_1002_C_HRIR.mat
HRIR_h		= include/HRIR.h

all: PyHRIR $(ALIB) $(DEMO)
###############################################################################################################
### Header File Generation
###############################################################################################################
PyHRIR:
	@python src/python/matFileIO.py -i $(HRIR_mat)  -o $(HRIR_h)


###############################################################################################################
### Demo
###############################################################################################################
$(DEMO): $(DEMO_OBJ) $(ALIB)
	@rm -rf $(OUT_DIR)
	@mkdir $(OUT_DIR)
	$(GCC) -o $(DEMO) $(DEMO_OBJ) $(ALIB) -lm


###############################################################################################################
### Library
###############################################################################################################
$(ALIB): $(C_OBJS)
	@rm -rf $(LIB_DIR)
	@mkdir $(LIB_DIR)
	ar rcs  $(ALIB) $(C_OBJS)

###############################################################################################################
### Global rules
###############################################################################################################
.c.o:
	$(GCC) $(CFLAGS) -c $< -o $@

###############################################################################################################
### Test demo 
###############################################################################################################

test: 
	./$(DEMO) $(TEST_DIR)/sample.wav $(OUT_DIR)/sample_out.raw -a 40 -e 20 -d 2
	$(SOX) -r 44100 -b 16 -e signed -c 2 $(OUT_DIR)/sample_out.raw $(OUT_DIR)/sample_out.wav
	@$(RM) -rf $(OUT_DIR)/sample_out.raw

clean:
	@echo Removing all temporary binaries...
	@$(RM) -rf $(C_OBJS) $(DEMO_OBJ) $(DEMO) $(ALIB) $(HRIR_h) $(OUT_DIR) $(LIB_DIR)
	@echo Done.


clear: clean

.PHONY: clean clear test all
.DELETE_ON_ERRORS:
