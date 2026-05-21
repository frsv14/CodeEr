# Programnamn
TARGET = myapp

# Källfiler
BASE_PATH = base/
SRCS =$(BASE_PATH)app.cpp main.cpp

# Kompilator
CXX = g++
OBJS = $(SRCS:.cpp=.o)

# Kontrollera wx-config
WX_CONFIG := $(shell which wx-config)

check-wx:
	@if ! command -v wx-config >/dev/null 2>&1; then \
		echo "wxWidgets not found. Installing..."; \
		sudo apt update && sudo apt install -y libwxgtk3.2-dev; \
	else \
		echo "wxWidgets already installed."; \
	fi

# Om wx-config inte finns, försök installera wxWidgets
ifeq ($(WX_CONFIG),)
    $(error wxWidgets is not installed. Run: sudo apt install libwxgtk3.2-dev)
endif

# Hämta flaggor från wx-config
CXXFLAGS = -std=c++17 -Wall `wx-config --cxxflags` `wxDEBUG_LEVEL=0`
LDFLAGS  = `wx-config --libs`



# Byggregel
all: check-wx $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(CXXFLAGS) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: all
	./$(TARGET)

#relode: ls *.cpp *.h | entr -r make run

# Städa
clean:
	rm -f $(TARGET) main.o