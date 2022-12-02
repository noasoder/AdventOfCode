COMPILER		:= g++
LANG_VERSION	:= -std=c++20
CXX_EXE	:= $(COMPILER) $(LANG_VERSION)
CXX_DLL	:= $(COMPILER) -shared $(LANG_VERSION)

WIN_FLAGS := -static-libstdc++ -lpthread -lmsvcrt

BIN     := bin
SRC     := src
SRC_TOOLS := ../../AdventTools/src

DLL_NAME  := AdventTools
EXECUTABLE  := Application
OUTEXE := $(BIN)/$(EXECUTABLE)
OUTDLL := $(BIN)/$(DLL_NAME).dll

LIBPATHS := -Lbin/

BASE_LIB   := 
DLL_LIB := $(BASE_LIB)
EXE_LIB := $(DLL_LIB) -l$(DLL_NAME)

INCLUDE_DLL = -I$(SRC_TOOLS)
INCLUDE_EXE =  $(INCLUDE_DLL) -Isrc

DIRS = $(SRC)
vpath %.c $(DIRS)
vpath %.cpp $(DIRS)
SEARCHC = $(addsuffix /*.c ,$(DIRS))
SEARCHCPP = $(addsuffix /*.cpp ,$(DIRS))
SRCS = $(wildcard $(SEARCHC))
SRCS += $(wildcard $(SEARCHCPP))

DIRS_TOOLS = $(SRC_TOOLS)
vpath %.c $(DIRS_TOOLS)
vpath %.cpp $(DIRS_TOOLS)
SEARCH_C_TOOLS = $(addsuffix /*.c ,$(DIRS_TOOLS))
SEARCH_CPP_TOOLS = $(addsuffix /*.cpp ,$(DIRS_TOOLS))
SRCS_TOOLS = $(wildcard $(SEARCH_C_TOOLS))
SRCS_TOOLS += $(wildcard $(SEARCH_CPP_TOOLS))

full:
	$(CXX_EXE) $(WIN_FLAGS) -g $(SRCS) $(SRCS_TOOLS) -o $(OUTEXE) $(INCLUDE_EXE) $(LIBPATHS) $(DLL_LIB)

exe: 
	$(CXX_EXE) $(WIN_FLAGS) -g $(SRCS) -o $(OUTEXE) $(INCLUDE_EXE) $(LIBPATHS) $(EXE_LIB)

dll: 
	$(CXX_DLL) $(WIN_FLAGS) -g $(SRCS_TOOLS) -o $(OUTDLL) $(DLL_LIB)