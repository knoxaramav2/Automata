echo Starting Compilation
LIBS=-lncurses
SRCF="-c src/automata/launcher.cpp -c src/automata/Color.cpp -c src/automata/Menu.cpp -c src/automata/Terminals.cpp -c src/automata/Util.cpp"
OBJS="launcher.o Color.o Menu.o Terminals.o Util.o"
OUTPUT="-oautomata.exe"
STANDARD=-std=c++11

g++ $SRCF $LIBS $STANDARD -m64
g++ $OBJS $OUTPUT $LIBS $STANDARD -m64
echo done
