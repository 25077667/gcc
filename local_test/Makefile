CXXFLAGS = -std=c++11 -Wall -Wextra -O2

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
DEP = $(SRC:.cpp=.d)
OUT = $(SRC:.cpp=)

TARGET_SUBDIR := $(shell grep 'target_alias=[^$$]' ../Makefile | sed -n 's/.*=\(.*\)/\1/p')
TARGET_CXX := $(shell cd ../$(TARGET_SUBDIR)/libstdc++-v3; grep 'CXX =' Makefile | sed -n 's/^CXX =\(.*\)/\1/p')
CXX := $(TARGET_CXX)
LIBS := -L../$(TARGET_SUBDIR)/libstdc++-v3/src/.libs -lstdc++ -lm -lpthread -lc -lgcc_s -lgcc -lrt -ldl
INCS := -I../$(TARGET_SUBDIR)/libstdc++-v3/include -I../$(TARGET_SUBDIR)/libstdc++-v3/include/$(TARGET_SUBDIR) -I../libstdc++-v3/libsupc++/

DEF_CXX := $(shell which g++)
DEF_CXXFLAGS := $(CXXFLAGS)

.PHONY: all clean before after

all: before after

before: $(SRC)
	$(DEF_CXX) $(DEF_CXXFLAGS) $(SRC) -o $(OUT)-before

after: $(OBJ)
	$(CXX) $(CXXFLAGS) $(INCS) $(LIBS) $^ -o $(OUT)-after

$(OBJ): $(SRC)
	$(CXX) $(CXXFLAGS) $(INCS) $(LIBS) -c $< -o $@

$(DEP): $(SRC)
	$(CXX) $(CXXFLAGS) $(INCS) $(LIBS) -MM $< -o $@

clean:
	rm -f $(OBJ) $(DEP) $(OUT)-*


# -include $(DEP)
