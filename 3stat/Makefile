# Makefile

DIR := out
LIBRARY := $(DIR)/mylib.a
OBJECTS := $(DIR)/hello.o $(DIR)/here.o $(DIR)/bye.o
CXX := g++

all: $(LIBRARY) $(DIR)/main.o
	$(CXX) -o $(DIR)/main $(LIBRARY) $(DIR)/main.o

$(DIR):
	mkdir -p $@

$(LIBRARY): $(OBJECTS)
	ar cr $@ $^
	
$(DIR)/%.o: %.cpp | $(DIR)
	$(CXX) -c -o $@ $<
	
$(DIR)/main.o: main.cpp
	$(CXX) -c -o $@ $<


	
clean:
	rm -rf $(DIR)
