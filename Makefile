CPPFLAGS=-g
CXX=g++
OBJS=main.o fonctions.o task.o todo.o date.o
EXE=todo

all: $(EXE)

$(EXE): $(OBJS)
	$(CXX) $^ $(CPPFLAGS) -o $@

%.o: %.cpp
	$(CXX) $< $(CPPFLAGS) -c -o $@

clean:
	rm $(OBJS) $(EXE)