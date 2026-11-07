CXX = g++ 

CXXFLAGS = -Wall -g

TARGET = main

TARGET_DEL = main.exe

SRCS = main.cpp account.cpp game.cpp user.cpp admin_user.cpp

OBJS = $(SRCS:.cpp=.o) 

all: $(TARGET) run

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
		./$(TARGET)

clean: 
	del $(TARGEL_DEL) $(OBJS) main.o account.o game.o user.o admin_user.o