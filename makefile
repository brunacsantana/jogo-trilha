ifeq ($(PROJ),)
PROJ = Trilha
endif

SOURCES_DIR=$(shell find ./src/ -name "*.cpp" -type f)
INCLUDE_DIR := include
$(shell mkdir -p bin)

OBJ=$(patsubst ./src%, ./bin%, $(patsubst %.cpp, %.o , $(SOURCES_DIR)))
CXXFLAGS= -std=c++17 -Wall -Wextra -Werror -Wshadow -Wconversion -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Wno-unused -Wnull-dereference $(addprefix -I ,$(INCLUDE_DIR))

all: $(PROJ)

$(PROJ): $(OBJ)
	g++ -o $@ $^ $(CXXFLAGS)

bin/%.o: src/%.cpp
	g++ -c -o $@ $^ $(CXXFLAGS)

run: $(PROJ)
	./$(PROJ)

rerun: 
	$(MAKE) clean
	$(MAKE) run

valgrind:
	valgrind --leak-check=full --track-origins=yes ./$(PROJ) 

clean:
	-rm -rf $(OBJ) $(PROD)

remake:
	$(MAKE) clean
	$(MAKE) run