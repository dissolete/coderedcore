#----------------------------#
#  CODE RED ENGINE MAKEFILE  #
#----------------------------#
#  We should probably switch #
# to CMAKE eventually... lol #
#----------------------------#
# Author: Jake Shepherd      #
# Last updated: 7/30/2016    #
#----------------------------#

TARGET = App

SRC = CRE/src
INC = CRE/include
BIN = App/bin
APPSRC = App/src
APPINC = App/include
PUGI = Extlibs/Pugi

SFML = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system

#---------------------------------------------#
# DON'T CHANGE ANYTHING BETWEEN THESE ARROWS! #
#---------------------------------------------#
#vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv#

# Source files for the CRE
CRSOURCE = $(wildcard $(SRC)/*.cpp)

# Source files for the App
APPSOURCE = $(wildcard $(APPSRC)/*.cpp)

# Header files for the CRE
CRINCLUDES = $(wildcard $(INC)/*.hpp)

# Header files for the App
APPINCLUDES = $(wildcard $(APPINC)/*.hpp)

# Source files for the Pugi Library
PUGISOURCE = $(wildcard $(PUGI)/*.cpp)

# Head files for the Pugi Library
PUGISINCLUDES = $(wildcard $(PUGI)/*.hpp)

# Object files for the CRE
OBJECTS = $(patsubst %,$(BIN)/%, $(notdir $(CRSOURCE:.cpp=.o)))

# Object files for the App
APPOBJECTS = $(patsubst %,$(BIN)/%, $(notdir $(APPSOURCE:.cpp=.o)))

# Object files for the Pugi Library
PUGIOBJECTS = $(patsubst %,$(BIN)/%, $(notdir $(PUGISOURCE:.cpp=.o)))

# Compiling options
CC = g++ -std=c++11

# Flags for compiling
CFLAGS = -I$(INC) -I$(APPINC) -I$(PUGI) -c

link: premessage $(PUGIOBJECTS) $(OBJECTS) $(APPOBJECTS)
	@echo "\nLinking..."
	$(CC) $(PUGIOBJECTS) $(OBJECTS) $(APPOBJECTS) -o $(BIN)/$(TARGET) \
	$(SFML)
	@echo "\nLinking finished. Type \"make run\" to execute app.\n"

premessage:
	@echo "Did you remember to save everything?\n"
	@echo "Compiling..."

#^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^#

#headers:
#	$(CC) $(CFLAGS) -c $(APPINCLUDES) $(CRINCLUDES)

$(BIN)/pugixml.o: $(PUGI)/pugixml.cpp $(PUGI)/pugixml.hpp $(PUGI)/pugiconfig.hpp
	$(CC) $(CFLAGS) $(PUGI)/pugixml.cpp -o $(BIN)/pugixml.o

#-----------------------------------#
# ADD NEW ENGINE OBJECT FILES BELOW #
#-----------------------------------#

$(BIN)/main.o: $(APPSRC)/main.cpp $(APPINCLUDES) $(CRINCLUDES)
	$(CC) $(CFLAGS) $(APPSRC)/main.cpp -o $(BIN)/main.o

$(BIN)/CRApp.o: $(SRC)/CRApp.cpp $(INC)/CRApp.hpp
	$(CC) $(CFLAGS) $(SRC)/CRApp.cpp -o $(BIN)/CRApp.o

$(BIN)/CRStateManager.o: $(SRC)/CRStateManager.cpp $(INC)/CRStateManager.hpp
	$(CC) $(CFLAGS) $(SRC)/CRStateManager.cpp -o $(BIN)/CRStateManager.o

$(BIN)/CRState.o: $(SRC)/CRState.cpp $(INC)/CRState.hpp
	$(CC) $(CFLAGS) $(SRC)/CRState.cpp -o $(BIN)/CRState.o

$(BIN)/SplashState.o: $(SRC)/SplashState.cpp $(INC)/SplashState.hpp
	$(CC) $(CFLAGS) $(SRC)/SplashState.cpp -o $(BIN)/SplashState.o

$(BIN)/CRTextManager.o: $(SRC)/CRTextManager.cpp $(INC)/CRTextManager.hpp
	$(CC) $(CFLAGS) $(SRC)/CRTextManager.cpp -o $(BIN)/CRTextManager.o

$(BIN)/CRSoundManager.o: $(SRC)/CRSoundManager.cpp $(INC)/CRSoundManager.hpp
	$(CC) $(CFLAGS) $(SRC)/CRSoundManager.cpp -o $(BIN)/CRSoundManager.o

$(BIN)/CRStatManager.o: $(SRC)/CRStatManager.cpp $(INC)/CRStatManager.hpp
	$(CC) $(CFLAGS) $(SRC)/CRStatManager.cpp -o $(BIN)/CRStatManager.o

$(BIN)/CRMath.o: $(SRC)/CRMath.cpp $(INC)/CRMath.hpp
	$(CC) $(CFLAGS) $(SRC)/CRMath.cpp -o $(BIN)/CRMath.o

$(BIN)/CREntityManager.o: $(SRC)/CREntityManager.cpp $(INC)/CREntityManager.hpp
	$(CC) $(CFLAGS) $(SRC)/CREntityManager.cpp -o $(BIN)/CREntityManager.o

$(BIN)/Action.o: $(SRC)/Action.cpp $(INC)/Action.hpp
	$(CC) $(CFLAGS) $(SRC)/Action.cpp -o $(BIN)/Action.o

$(BIN)/CRTileMap2.o: $(SRC)/CRTileMap2.cpp $(INC)/CRTileMap2.hpp
	$(CC) $(CFLAGS) $(SRC)/CRTileMap2.cpp -o $(BIN)/CRTileMap2.o

$(BIN)/CREntity2.o: $(SRC)/CREntity2.cpp $(INC)/CREntity2.hpp
	$(CC) $(CFLAGS) $(SRC)/CREntity2.cpp -o $(BIN)/CREntity2.o

$(BIN)/CRPropertyManager.o: $(SRC)/CRPropertyManager.cpp $(INC)/CRPropertyManager.hpp
	$(CC) $(CFLAGS) $(SRC)/CRPropertyManager.cpp -o $(BIN)/CRPropertyManager.o

$(BIN)/Property.o: $(SRC)/Property.cpp $(INC)/Property.hpp
	$(CC) $(CFLAGS) $(SRC)/Property.cpp -o $(BIN)/Property.o

$(BIN)/CRGroup.o: $(SRC)/CRGroup.cpp $(INC)/CRGroup.hpp
	$(CC) $(CFLAGS) $(SRC)/CRGroup.cpp -o $(BIN)/CRGroup.o

#--------------------------------#
# ADD NEW APP OBJECT FILES BELOW #
#--------------------------------#

$(BIN)/Main.o: $(APPSRC)/Main.cpp $(APPINCLUDES) $(CRINCLUDES)
	$(CC) $(CFLAGS) $(APPSRC)/main.cpp -o $(BIN)/main.o

$(BIN)/TestApp.o: $(APPSRC)/TestApp.cpp $(APPINC)/TestApp.hpp
	$(CC) $(CFLAGS) $(APPSRC)/TestApp.cpp -o $(BIN)/TestApp.o

$(BIN)/TestState.o: $(APPSRC)/TestState.cpp $(APPINC)/TestState.hpp
	$(CC) $(CFLAGS) $(APPSRC)/TestState.cpp -o $(BIN)/TestState.o

.PHONY: run clean clean-o help

#---------------------------------#
# ADDITIONAL FUNCTION DECLARATION #
#---------------------------------#

run: $(BIN)/$(TARGET)
	$(BIN)/$(TARGET)

clean:
	rm -f $(OBJECTS) $(APPOBJECTS) $(PUGIOBJECTS) $(BIN)/$(TARGET)
	@echo "Removed all object files and app executable.\n"

clean-o:
	rm -f $(OBJECTS) $(APPOBJECTS) $(PUGIOBJECTS)
	@echo "Removed all object files only. App executable remains.\n"

help:
	@echo ""
	@echo "extlibs: $(PUGISOURCE) $(PUGISINCLUDES)\n"
	@echo "crsrc: $(CRSOURCE)\n"
	@echo "crinc: $(CRINCLUDES)\n"
	@echo "crobj: $(OBJECTS)\n"
	@echo "appsrc: $(APPSOURCE)\n"
	@echo "appinc: $(APPINCLUDES)\n"
	@echo "appobj: $(APPOBJECTS)\n"
	@echo "extobj: $(PUGIOBJECTS)\n"
