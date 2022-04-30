#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main()
{

    ifstream in("in.txt");
    ofstream out("out.txt");
    int N;
    in >> N;
    vector < vector <int> > v(N, vector <int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            v[i][j] = 0;
        }

    int a = N, b = 0, c = 1;
    while (a != b) {

        for (int i = b; i < a; i++) {
            v[b][i] = c;
            c++;
        }
        for (int i = b + 1; i < a; i++) {
            v[i][a - 1] = c;
            c++;
        }
        for (int i = a - 2; i > b; i--) {
            v[a - 1][i] = c;
            c++;
        }
        for (int i = a - 1; i > b; i--) {
            v[i][b] = c;
            c++;
        }
        a -= 1; b += 1;
        if (N % 2 != 0 && (a-1)==b) {
            v[a-1][b] = c;
            break;
        }


    } 


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            out << v[i][j] << " ";
        }
        out << endl;
    }
}
