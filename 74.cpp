#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    ifstream in("in.txt");
    ofstream out("out.txt");
    int N, M;
    in >> N >> M;
    if (M == 1)
        out << N;
    else if (M % 2 == 0)
        out << M / 2;
    else {
        int a = 0;
        while (M % 2 != 0 and N != 1) {
            a += (N - (N % 2)) / 2;
            N -= (N - (N % 2)) / 2;
            M -= (M - (M % 2)) / 2;
        }

        out << a + M / 2;
    }

}
