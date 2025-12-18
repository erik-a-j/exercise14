
CXX = g++
STD = c++20
WARN = -Wall -Wextra
OPT = -O2
CXXFLAGS = -std=$(STD) $(WARN) $(OPT)

OBJDIR = obj
MODULESRC = numberguess.cpp
MODULEOBJ = $(patsubst %.cpp,$(OBJDIR)/%.o,$(MODULESRC))

TESTSRC = 14_numgame_test.c++
TESTOBJ = $(patsubst %.c++,$(OBJDIR)/%.o,$(TESTSRC))
TESTBIN = a.out



.PHONY: all module test clean
all: test
module: $(MODULEOBJ)
test: $(TESTBIN)

$(TESTBIN): $(MODULEOBJ) $(TESTOBJ)
	$(CXX) $^ -o $@

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@
$(OBJDIR)/%.o: %.c++ | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)
	rm -f $(TESTBIN)