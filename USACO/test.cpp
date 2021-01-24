/*
ID: ck891191
PROG: test
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <string>
using namespace std;

int main()
{
    //ofstream fout ("test.out");
    //ifstream fin ("test.in");
    //string a;
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    int a, b;
    cin >> a >> b;
    cout << a+b << endl;
    return 0;
}
