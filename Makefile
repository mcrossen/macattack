# Makefile for messenger client and server

CXX=			g++ $(CCFLAGS)

MACAPPEND= macappend.o
LIBS=	sha1.o logger.o
OBJS=	$(MACAPPEND) $(LIBS)

CCFLAGS= -g -Wall -std=c++11

all: $(MACAPPEND) $(LIBS)
	$(CXX) -o macappend $(MACAPPEND) $(LIBS)

clean:
	rm -f $(OBJS) $(OBJS:.o=.d)

realclean: clean
	rm -f macappend


# These lines ensure that dependencies are handled automatically.
%.d:	%.cpp
	$(SHELL) -ec '$(CC) -M $(CPPFLAGS) $< \
		| sed '\''s/\($*\)\.o[ :]*/\1.o $@ : /g'\'' > $@; \
		[ -s $@ ] || rm -f $@'

include	$(OBJS:.o=.d)
