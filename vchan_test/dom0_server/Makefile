# Makefile for dom0_server.cpp

# 컴파일러 및 플래그
CXX ?= g++
CXXFLAGS = -std=c++11 -Wall -pthread
LDFLAGS = 
LDLIBS = -lxenvchan -pthread

# 소스 파일 및 실행 파일 이름
SRC = dom0_server.cpp
TARGET = dom0_server

# 빌드 규칙
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(TARGET)

.PHONY: all clean