@echo off
g++ -std=c++17 -O1 -o test.exe test.cpp
g++ -std=c++17 -O1 -o solution.exe solution.cpp
g++ -std=c++17 -O1 -o brute.exe brute.cpp

for /l %%x in (1, 1, 100) do (
    test > main.inp
    soln < main.inp > main.out 
    brute < main.inp > main.ans
    fc main.out main.ans > diagnostics || exit /b
    echo %%x
)
echo all tests passed
pause