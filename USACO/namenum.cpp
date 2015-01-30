/*
ID: ck891191
PROG: namenum
LANG: C++
*/
//#include <iostream>
//#include <cstdio>
//#include <cstring>
//using namespace std;
//int main()
//{
//    const char mapping [26]={'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','0','7','7','8','8','8','9','9','9','0'};
//    char a[15],b[15];
//    int flag,i;
//    freopen("namenum.in","r",stdin);
//    freopen("namenum.out","w",stdout);
//    freopen("dict.txt","r",stderr);
//    scanf("%s",a);
//    flag=0;
//    while (fscanf(stderr,"%s",b)!=EOF)
//    {
//        if (strlen(a)!=strlen(b)) continue;
//        for (i=0;i<strlen(a);i++)
//            if (a[i]!=mapping[b[i]-'A']) break;
//        if (i==strlen(a)) {
//            flag=1;
//            printf("%s\n",b);
//        }
//    }
//    if (!flag) printf("NONE\n");
//    return 0;
//}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <fstream>
using namespace std;
int main()
{
    const char mapping [26]={'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','0','7','7','8','8','8','9','9','9','0'};
    string a,b;
    int flag,i;
    freopen("namenum.in","r",stdin);
    freopen("namenum.out","w",stdout);
    //freopen("dict.txt","r",stderr);
    ifstream tin("dict.txt");
    cin>>a;
    flag=0;
    while (tin>>b)
    {
        if (a.size()!=b.size()) continue;
        for (i=0;i<a.size();i++)
            if (a[i]!=mapping[b[i]-'A']) break;
        if (i==a.size()) {
            flag=1;
            cout<<b<<endl;
        }
    }
    if (!flag) printf("NONE\n");
    return 0;
}
