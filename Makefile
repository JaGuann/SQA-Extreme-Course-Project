CXX = g++ 

CXXFLAGS = -Wall -g

TARGET = main

TARGET_DEL = main.exe

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o) 

all: $(TARGET) run

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	$(TARGET)

clean: 
	del $(TARGEL_DEL) $(OBJS)