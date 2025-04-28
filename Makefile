TARGET_EXEC = main.exe
MIN_TARGET_EXEC = minmain.exe

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

MIN_SRC := $(SDIR)/main.cpp 
MIN_SRC += $(MDIR)/glad/glad.c
MIN_SRC += $(MDIR)/graphics/shader.cpp $(MDIR)/graphics/rectangle.cpp $(MDIR)/graphics/stb.cpp $(MDIR)/graphics/graphics.cpp
MIN_SRC += $(MDIR)/window/window.cpp

MIN_OBJS := $(patsubst src/%,%,$(MIN_SRC))
MIN_OBJS := $(patsubst %,build/%,$(MIN_OBJS))
MIN_OBJS := $(patsubst %.cpp,%.o,$(MIN_OBJS))
MIN_OBJS := $(patsubst %.c,%.o,$(MIN_OBJS))

DIRS := $(sort $(dir $(OBJS)))

CXX := g++

UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
LIBS := ./libs/libglfw3.a -lGL -lglfw -ldl
endif
ifeq ($(UNAME), MSYS_NT-10.0-26100)
LIBS := ./libs/libglfw3.a -lgdi32 -lopengl32
endif
# Normal run which also creates needed dirs
all: prep_dir $(BDIR)/$(TARGET_EXEC)

# Get .o -> .exe
$(BDIR)/$(TARGET_EXEC): $(OBJS)
	$(CXX) -o $@ $^ $(LIBS)

min: prep_dir $(BDIR)/$(MIN_TARGET_EXEC)

$(BDIR)/$(MIN_TARGET_EXEC): $(MIN_OBJS)
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
run: prep_dir $(BDIR)/$(TARGET_EXEC)
	$(BDIR)/$(TARGET_EXEC)

.PHONY: minrun
minrun: prep_dir $(BDIR)/$(MIN_TARGET_EXEC)
	$(BDIR)/$(MIN_TARGET_EXEC)

# Create directories call, -p is there to prevent error throw
.PHONY: prep_dir
prep_dir:
	@mkdir -p $(DIRS)