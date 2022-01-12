::Change directory to where program is
cd %~dp0
color 2

::Compiling the calc.c maker
gcc -ggdb3 -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow -o createCalc main.c -lm

@echo off
pause
echo ..
echo ..

::Number up to which to create calculations
set /P NUMBER="Enter a positive number: " 
set /A NUMBER += 1

::Create calc.c
start createCalc.exe %NUMBER%
echo calc.c creation successful!

::Compile calc.c
cd ../calculator
@echo on
gcc -ggdb3 -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow -o calc calc.c -lm
@echo off
pause
exit