CPP = g++
LINK = wx-config --cxxflags --libs 

all: 
	$(CPP) *.cpp -o MoneyManager `$(LINK)` -I. 
