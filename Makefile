TARGET_EXEC = main.exe

BDIR = ./build
IDIR = -I ./include

SOURCES = ./src/main.cpp ./include/glad/glad.c
OBJS = $(BDIR)/main.o $(BDIR)/glad.o

CXX = g++

LIBS = ./libs/libglfw3.a -lgdi32 -lopengl32

$(BDIR)/$(TARGET_EXEC): $(OBJS)
	mkdir -p $(BDIR)
	$(CXX) $(OBJS) -o $@  $(LIBS)

$(BDIR)/main.o: ./src/main.cpp
	$(CXX) -c ./src/main.cpp $(IDIR) -o $@

$(BDIR)/glad.o: ./include/glad/glad.c
	$(CXX) -c ./include/glad/glad.c $(IDIR) -o $@

.PHONY: clean
clean:
	rm -r $(BDIR)/*

run: $(BDIR)/$(TARGET_EXEC)
	$(BDIR)/$(TARGET_EXEC)