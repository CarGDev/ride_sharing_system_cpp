CXX = g++
CXXFLAGS = -Wall -g
TARGET = main
TARGET_DEL = main.exe
SRCS = $(shell find src -name '*.cpp')
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET) run

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	del $(TARGET_DEL) $(OBJS)
