# Makefile

DIR := out
CXX := g++

LIBRARY := libmylib.so
MAJOR := 5
MINOR := 1
RELEASE := 10

FULL_LIBRARY := $(LIBRARY).$(MAJOR).$(MINOR).$(RELEASE)

OBJECTS := $(DIR)/hello.o $(DIR)/here.o $(DIR)/bye.o

all: $(DIR)/$(FULL_LIBRARY) $(DIR)/main.o
	$(CXX) -o $(DIR)/main $(DIR)/$(LIBRARY) $(DIR)/main.o

$(DIR):
	mkdir -p $@

$(DIR)/%.o: %.cpp | $(DIR)
	$(CXX) -fPIC -c -o $@ $<

$(DIR)/$(FULL_LIBRARY): $(OBJECTS)
	$(CXX) -Wl -shared -fPIC -o $@ $^
	ln  -sf $(FULL_LIBRARY) $(DIR)/$(LIBRARY).$(MAJOR)
	ln  -sf $(FULL_LIBRARY) $(DIR)/$(LIBRARY)
	
$(DIR)/main.o: main.cpp
	$(CXX) -fPIC -c -o $@ $<

clean:
	rm -rf $(DIR)