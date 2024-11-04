main: main_matrix.cpp Matrix.cpp
    g++ -std=c++11 main_matrix.cpp Matrix.cpp -o main

clean:
    rm -f *.o main
