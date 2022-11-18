#MAKEFILE FOR PROJECT 'zGameOfLife'
PROG = live
CC = g++
INC = -Iinc
OUT = lib/lib.a
LDFLAGS = -L/usr/include/SFML -lsfml-graphics -lsfml-window -lsfml-system -lm -pg
ODIR = obj
SDIR = src

_OBJS = main.o automaton.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

$(ODIR)/%.o: $(SDIR)/%.cpp
	$(CC) -c $(INC) -o $@ $<
$(PROG): $(OBJS)
	$(CC) -o $@ $< $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(ODIR)/*.o $(OUT) $(PROG) ./*.out
