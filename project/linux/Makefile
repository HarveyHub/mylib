ifeq (1,$(V))
ECHO :=
else
ECHO := @
endif

TARGET := target

#Direntories.
CODE_DIR := ../../code
MOD_DIR := $(shell ls $(CODE_DIR))
MOD_DIR := $(foreach D, $(MOD_DIR), $(CODE_DIR)/$(D))
TARGET_DIR := ./
INC_DIRS := $(MOD_DIR)
INC_DIRS += ./
SRC_DIRS := $(foreach D, $(MOD_DIR), $(D)/src)

# All include files
INC_FILES := $(foreach D, $(MOD_DIR), $(wildcard $D/*.h))

#Source Files
SRC_FILES_C := $(foreach D, $(MOD_DIR), $(wildcard $D/*.c))
SRC_FILES_CPP := $(foreach D, $(MOD_DIR), $(wildcard $D/*.cpp))

# Libraries
# INC_DIRS += ../../lib/gtest/include
# LIBS := ../../lib/gtest/lib/linux/gtest.a

# Compilers
CXX := g++
GCC := gcc
ICC := icc
ICPC := icpc

#Compilation flags
ifeq ($(DEBUG), 1)
CXXFLAGS += -gstabs
CFLAGS += -g
else
CXXFLAGS += -O2
CFLAGS += -O2
endif

# CXXFLAGS += -std=c++11
CXXFLAGS += -march=native
CXXFLAGS += -lpthread

#OBJS
OBJS_PATH = objs
OBJ_C = $(patsubst %.c, %.o, $(SRC_FILES_C))
OBJ_C := $(subst ../../code, $(OBJS_PATH), $(OBJ_C))
OBJ_CPP = $(patsubst %.cpp, %.o, $(SRC_FILES_CPP))
OBJ_CPP := $(subst ../../code, $(OBJS_PATH), $(OBJ_CPP))

all : $(OBJ_C) $(OBJ_CPP)
	@echo "Linking Executable..."
	$(ECHO) $(CXX) $(OBJ_C) $(OBJ_CPP) -o $(TARGET_DIR)/$(TARGET)

.SECONDEXPANSION:
$(OBJ_C): %.o : $$(subst $(OBJS_PATH), ../../code, $$*.c)
	@if [ ! -d $(dir $@) ]; then mkdir -p $(dir $@); fi;
	@echo "Compiling $< "
	$(ECHO)$(GCC) $(foreach D, $(INC_DIRS), -I$D) $(CFLAGS) -c $< -o $@
	@$(GCC) -MM $(foreach D, $(INC_DIRS), -I$D) $(CFLAGS) $< > $*.d
	@mv -f $*.d $*.d.tmp
	@sed -e 's|.*:|$*.o:|' < $*.d.tmp > $*.d
	@sed -e 's/.*://' -e 's/\\$$//' < $*.d.tmp | fmt -1 | \
	  sed -e 's/^ *//' -e 's/$$/:/' >> $*.d
	@rm -f $*.d.tmpendif
	
$(OBJ_CPP): %.o : $$(subst $(OBJS_PATH), ../../code, $$*.cpp)
	@if [ ! -d $(dir $@) ]; then mkdir -p $(dir $@); fi;
	@echo "Compiling $< "
	$(ECHO)$(CXX) $(foreach D, $(INC_DIRS), -I$D) $(CXXFLAGS) -c $< -o $@
	@$(CXX) -MM $(foreach D, $(INC_DIRS), -I$D) $(CXXFLAGS) $< > $*.d
	@mv -f $*.d $*.d.tmp
	@sed -e 's|.*:|$*.o:|' < $*.d.tmp > $*.d
	@sed -e 's/.*://' -e 's/\\$$//' < $*.d.tmp | fmt -1 | \
	  sed -e 's/^ *//' -e 's/$$/:/' >> $*.d
	@rm -f $*.d.tmpendif
	
view:
	@echo ".h:" $(INC_FILES)
	@echo ".c:" $(SRC_FILES_C)
	@echo ".cpp:" $(SRC_FILES_CPP)
	@echo "module:" $(MOD_DIR)

clean:
	$(ECHO) rm -f $(TARGET_DIR)/$(TARGET)
	$(ECHO) rm -rf $(OBJS_PATH)

.PHONY : all clean
