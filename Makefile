CPPFLAGS=-g
CXX=g++
OBJS=main.o fonctions.o task.o todo.o date.o
TEST=test.py
EXE=todo

all: $(EXE) test

$(EXE): $(OBJS)
	$(CXX) $^ $(CPPFLAGS) -o $@

%.o: %.cpp
	$(CXX) $< $(CPPFLAGS) -c -o $@

clean:
	rm $(OBJS) $(EXE)

test: $(TEST)
	dos2unix $<
	bash $<
	rm test.todo