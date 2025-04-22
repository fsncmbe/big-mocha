TARGET_EXEC = main.exe

SDIR := src
BDIR := build
IDIR := include

# Gets all source cpps
SRC := $(wildcard src/*.cpp)
SRC += $(wildcard src/modules/**/*.cpp)
SRC += $(wildcard src/modules/**/*.c)

# Defines resulting .o files
OBJS := $(patsubst src/%,%,$(SRC))
OBJS := $(patsubst %,build/%,$(OBJS))
OBJS := $(patsubst %.cpp,%.o,$(OBJS))
OBJS := $(patsubst %.c,%.o,$(OBJS))

DIRS := $(sort $(dir $(OBJS)))

CXX := g++

LIBS := ./libs/libglfw3.a -lgdi32 -lopengl32

# Normal run which also creates needed dirs
all: prep_dir $(BDIR)/$(TARGET_EXEC)

# Get .o -> .exe
$(BDIR)/$(TARGET_EXEC): $(OBJS)
	$(CXX) -o $@ $^ $(LIBS)

# Get .cpp -> .o
$(BDIR)/%.o: $(SDIR)/%.cpp
	$(CXX) -I$(IDIR) -c $< -o $@

# Get .c -> .o
$(BDIR)/%.o: $(SDIR)/%.c
	$(CXX) -I$(IDIR) -c $< -o $@

# Clean call
.PHONY: clean
clean:
	rm -r $(BDIR)/*

# Run call
.PHONY: run
run: $(BDIR)/$(TARGET_EXEC)
	$(BDIR)/$(TARGET_EXEC)

# Create directories call, -p is there to prevent error throw
.PHONY: prep_dir
prep_dir:
	@mkdir -p $(DIRS)