rem Compiles monitor program for additional viewports

echo off
cls
echo Starting Compilation
SETLOCAL
set LIBS=-lncurses
set SRCF="src/terminal/viewport.cpp"
set OUTPUT="-oviewport.exe"
set STANDARD  "-std=c++11"

g++ %SRCF% %OUTPUT% %LIBS% %STANDARD%
ENDLOCAL
echo done