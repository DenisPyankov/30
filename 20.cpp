#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int F(int a, int b) {
    if (a > b)
        return 0;
    if (a < b)
        return 1;
}

int main()
{
    ifstream in("in.txt");
    ofstream out("out.txt");
    int N;
    in >> N;
    vector <int> v;
    for (int i = 0; i < N; i++) {
        int a;
        in >> a;
        v.push_back(a);
    }
    vector <int> res;
    int max = 0;
    int k = 2;
    res.push_back(v[0]);
    res.push_back(v[1]);
    int sw = F(res[0], res[1]);
    for (int i = 2; i < N; i++) {
        int q = sw;
        res.push_back(v[i]);
        sw = F(res[i - 1], res[i]);
        if (sw != q)
            k++;
        else {
            if (max < k)
                max = k;
            k = 2;
        }
    }
    if (max < k)
        max = k;
    out << max;




}
