COMPILER		:= g++
LANG_VERSION	:= -std=c++20
CXX_DLL	:= $(COMPILER) -shared $(LANG_VERSION)

WIN_FLAGS := -static-libstdc++ -lpthread -lmsvcrt

BIN     := bin
SRC     := src

DLL_NAME  := AdventTools
OUTEXE := $(BIN)/$(EXECUTABLE)
OUTDLL := $(BIN)/$(DLL_NAME).dll

LIBPATHS := -Lbin/

BASE_LIB   := 
DLL_LIB := $(BASE_LIB)
EXE_LIB := $(DLL_LIB) -l$(DLL_NAME)

DIRS = $(SRC)
vpath %.c $(DIRS)
vpath %.cpp $(DIRS)
SEARCHC = $(addsuffix /*.c ,$(DIRS))
SEARCHCPP = $(addsuffix /*.cpp ,$(DIRS))
SRCS = $(wildcard $(SEARCHC))
SRCS += $(wildcard $(SEARCHCPP))

dll: 
	$(CXX_DLL) $(WIN_FLAGS) -g $(SRCS) -o $(OUTDLL) $(LIBPATHS) $(DLL_LIB)