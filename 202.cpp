#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ifstream in("in.txt");
    ofstream out("out.txt");
    string S, T;
    in >> S >> T;
    int start = 0;
    int pos = 0;
    for (;;) {
        pos = S.find(T.c_str(), start);
        if (pos != -1) {
            start = pos + 1;
            out << pos << " ";
        }
        else {
            break;
        }
    }


}
