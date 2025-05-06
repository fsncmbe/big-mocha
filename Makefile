TARGET_EXEC = main.exe
DEBUG_EXEC = main_debug.exe

SDIR := src
MDIR := $(SDIR)/modules
BDIR := build
IDIR := include

# Gets all source cpps
SRC := $(wildcard src/*.cpp)
SRC += $(wildcard src/modules/*.cpp)
SRC += $(wildcard src/modules/**/*.cpp)
SRC += $(wildcard src/modules/**/*.c)

# Defines resulting .o files
OBJS := $(patsubst src/%,%,$(SRC))
OBJS := $(patsubst %,build/%,$(OBJS))
OBJS := $(patsubst %.cpp,%.o,$(OBJS))
OBJS := $(patsubst %.c,%.o,$(OBJS))

DIRS := $(sort $(dir $(OBJS)))

CXX := g++

DCXX := $(CXX) -g -O1
DRUN := valgrind --leak-check=yes

UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
LIBS := -lGL -lglfw -ldl
endif
ifeq ($(UNAME), MSYS_NT-10.0-26100)
LIBS := ./libs/libglfw3.a -lgdi32 -lopengl32
endif
# Normal run which also creates needed dirs
all: prep_dir $(BDIR)/$(TARGET_EXEC)

# Get .o -> .exe
$(BDIR)/$(TARGET_EXEC): $(OBJS)
	$(CXX) -o $@ $^ $(LIBS)

# Get .o -> .exe
$(BDIR)/$(DEBUG_EXEC): $(OBJS)
	$(DCXX) -o $@ $^ $(LIBS)

# Get .cpp -> .o
$(BDIR)/%.o: $(SDIR)/%.cpp
	$(CXX) -I$(IDIR) -c $< -o $@

# Get .c -> .o
$(BDIR)/%.o: $(SDIR)/%.c
	$(CXX) -I$(IDIR) -c $< -o $@

.PHONY: debug
debug: prep_dir $(BDIR)/$(DEBUG_EXEC)

.PHONY: debugrun
debugrun: debug
	$(DRUN) $(BDIR)/$(DEBUG_EXEC)

# Clean call
.PHONY: clean
clean:
	rm -r $(BDIR)/*

# Run call
.PHONY: run
run: prep_dir $(BDIR)/$(TARGET_EXEC)
	$(BDIR)/$(TARGET_EXEC)

# Create directories call, -p is there to prevent error throw
.PHONY: prep_dir
prep_dir:
	@mkdir -p $(DIRS)