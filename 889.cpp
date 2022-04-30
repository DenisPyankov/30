#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ifstream in("in.txt");
    ofstream out("out.txt");
    int s, N;
    in >> s >> N;
    vector <int> v1;
    vector <int> v2;
    for (int i = 0; i < N; i++) {
        int a, b; in >> a >> b;
        v1.push_back(a);
        v2.push_back(b);
    }
    int max = 0;
    for (int i = 0; i < N; i++)
        if (max < v2[i])
            max = v2[i];
    int h = 0;
    int m1, m2;

    while (h < max) {
        m1 = max;
        for (int i = 0; i < N; i++)
            if (v1[i] == s - 1 || v1[i] == s + 1) {
                if (v2[i] > h && v2[i] <= m1) {
                    m1 = v2[i];
                    m2 = v1[i];
                }
            }

        h = m1;
        s = m2;
    }


    out << s;


}
