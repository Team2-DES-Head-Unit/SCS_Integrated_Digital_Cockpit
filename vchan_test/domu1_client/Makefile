# Makefile for domu1_client.cpp

# 컴파일러 및 플래그
# CXX ?= g++
# CXXFLAGS = -std=c++11 -Wall -pthread
# LDFLAGS =
# LDLIBS = -lxenvchan -pthread
CXX ?= g++
CXXFLAGS ?= -std=c++11 -Wall -pthread
LDLIBS ?= -lxenvchan -pthread

# 소스 파일 및 실행 파일 이름
SRC = domu1_client.cpp
TARGET = domu1_client

# 빌드 규칙
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(TARGET) $(SRC) $(LDLIBS)

clean:
	rm -f $(TARGET)

.PHONY: all clean
