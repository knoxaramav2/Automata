echo off
cls
echo Starting Compilation
SETLOCAL
set LIBS=-lncurses
set SRCF="-c src/automata/launcher.cpp -c src/automata/Color.cpp -c src/automata/Menu.cpp -c src/automata/Terminals.cpp -c src/automata/Util.cpp -c src/automata/Data.cpp"
set OBJS="launcher.o Color.o Menu.o Terminals.o Util.o Data.o"
set OUTPUT="-oautomata.exe"
set STANDARD=-std=c++0x
set BITMODE=-m64
if "%BITMODE%"=="-m64" ( set BITMACRO=-D _WIN64) else (set "BITMACRO=-D _WIN32")

g++ "%SRCF%" %LIBS% %STANDARD% "%BITMACRO%"
g++ "%OBJS%" %OUTPUT% %LIBS% %STANDARD% "%BITMACRO%"
ENDLOCAL
echo done
