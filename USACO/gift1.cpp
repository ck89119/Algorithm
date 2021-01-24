/*
ID: ck891191
PROG: gift1
LANG: C++
*/

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;
//int main()
//{
//    int np,i,j,div,total;
//    string s,tmp;
//    map<string,int> mmap;
//    map<string,int>::iterator ii;
//    freopen("gift1.in","r",stdin);
//    freopen("gift1.out","w",stdout);
//    scanf("%d",&np);
//    for (i=0;i<np;i++){
//        cin>>s;
//        mmap[s]=0;
//    }
//    while (cin>>s){
//        scanf("%d %d",&total,&div);
//        if (div){
//            i=total/div;
//            for (j=0;j<div;j++){
//                cin>>tmp;
//                mmap[tmp]+=i;
//            }
//            mmap[s]-=i*div;
//        }
//    }
//    for (ii=mmap.begin();ii!=mmap.end();ii++)
//       cout<<(*ii).first<<' '<<(*ii).second<<endl;
//    return 0;
//}
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
int main()
{
    int np,i,j,k;
    string s,tmp;
    vector<string> name;
    vector<int> money;
    freopen("gift1.in","r",stdin);
    freopen("gift1.out","w",stdout);
    scanf("%d",&np);
    for (i=0;i<np;i++){
        cin>>s;
        name.push_back(s);
        money.push_back(0);
        //dump(s);
    }
    while (cin>>s){
        //dump(s);
        int ii;
        scanf("%d%d",&j,&k);
        if (k){
            j=j/k;
            for (i=0;i<k;i++){
                cin>>tmp;
                for (ii=0;ii<name.size();ii++)
                    if (tmp==name[ii]) break;
                money[ii]+=j;
            }
            for (ii=0;ii<name.size();ii++)
                    if (s==name[ii]) break;
            money[ii]-=j*k;
        }
    }
    dump("************");
    for (i=0;i<name.size();i++)
        cout<<name[i]<<' '<<money[i]<<endl;
    return 0;
}

