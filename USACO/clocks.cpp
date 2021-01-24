/*
ID: ck891191
PROG: clocks
LANG: C++
*/

//bfs
//#include <iostream>
//#include <cstdio>
//#include <queue>
//#include <vector>
//using namespace std;
//#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
//int move[9][9]={3,3,0,3,3,0,0,0,0,
//                3,3,3,0,0,0,0,0,0,
//                0,3,3,0,3,3,0,0,0,
//                3,0,0,3,0,0,3,0,0,
//                0,3,0,3,3,3,0,3,0,
//                0,0,3,0,0,3,0,0,3,
//                0,0,0,3,3,0,3,3,0,
//                0,0,0,0,0,0,3,3,3,
//                0,0,0,0,3,3,0,3,3};
//
//int clock(vector<int> c)
//{
//    int i;
//    for (i=0;i<9;i++)
//        if (c[i]) break;
//    if (i<9) return 0;
//    else return 1;
//}
//
//int main()
//{
//    vector<int> c;
//    vector<int> t1,t2,t3,t4,t5,t6;
//    queue<vector<int> > q,path,used;
//    int i,j,tmp;
//    freopen("clocks.in","r",stdin);
//    freopen("clocks.out","w",stdout);
//    t3.clear();
//    for (i=0;i<9;i++)
//    {
//        scanf("%d",&tmp);
//        c.push_back(tmp%12);
//        t3.push_back(0);
//    }
//    used.push(t3);
//    t3.clear();t3.push_back(0);
//    q.push(c);path.push(t3);
//   // for (i=0;i<9;i++) used[i]=0;
//    while (!q.empty())
//    {
//        t1=q.front();q.pop();
//        t3=path.front();path.pop();
//        t5=used.front();used.pop();
//        //for (i=0;i<9;i++) cout<<t1[i]<<" ";cout<<endl;
//        //for (i=0;i<9;i++) cout<<t5[i]<<" ";cout<<endl;
//        //for (i=0;i<t3.size();i++) cout<<t3[i]<<" ";cout<<endl;
//        for (i=t3[t3.size()-1];i<9;i++)
//        {
//            if (t5[i]>=3) continue;
//            t2=t1;
//            for (j=0;j<9;j++)
//            {
//                t2[j]+=move[i][j];
//                t2[j]%=12;
//            }
//            if (!clock(t2))
//            {
//                q.push(t2);
//                t4=t3;
//                t6=t5;
//                t4.push_back(i);
//                t6[i]++;
//               // for (i=0;i<9;i++) cout<<t2[i]<<" ";cout<<endl;
//                path.push(t4);
//                used.push(t6);
//            }
//            else
//            {
//                for (j=1;j<t3.size();j++) printf("%d ",t3[j]+1);
//                printf("%d\n",i+1);
//                return 0;
//            }
//        }
//    }
//    return 0;
//}


//dfs
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
int c[9];
int best,best_arr[9];
int now,now_arr[9];

int check()
{
    if ((c[0]+3*now_arr[0]+3*now_arr[1]+3*now_arr[3])%12) return 0;
    if ((c[1]+3*now_arr[0]+3*now_arr[1]+3*now_arr[2]+3*now_arr[4])%12) return 0;
    if ((c[2]+3*now_arr[1]+3*now_arr[2]+3*now_arr[5])%12) return 0;
    if ((c[3]+3*now_arr[3]+3*now_arr[4]+3*now_arr[0]+3*now_arr[6])%12) return 0;
    if ((c[4]+3*now_arr[0]+3*now_arr[2]+3*now_arr[4]+3*now_arr[6]+3*now_arr[8])%12) return 0;
    if ((c[5]+3*now_arr[2]+3*now_arr[4]+3*now_arr[5]+3*now_arr[8])%12) return 0;
    if ((c[6]+3*now_arr[3]+3*now_arr[6]+3*now_arr[7])%12) return 0;
    if ((c[7]+3*now_arr[4]+3*now_arr[6]+3*now_arr[7]+3*now_arr[8])%12) return 0;
    if ((c[8]+3*now_arr[5]+3*now_arr[7]+3*now_arr[8])%12) return 0;
    return 1;
}

int better()
{
    int i;
    if (now<best) return 1;
    if (now>best) return 0;
    for (i=0;i<9;i++)
    {
        if (now_arr[i]>best_arr[i]) return 1;
        if (now_arr[i]<best_arr[i]) return 0;
    }
    return 0;
}

int update()
{
    int i;
    best=now;
    for (i=0;i<9;i++) best_arr[i]=now_arr[i];
    return 0;
}

int dfs(int dep)
{
    if (now>best) return 0;
    if (check()&&better())
    {
        update();
        return 0;
    }
    if (dep==9) return 0;
    for (now_arr[dep]=0;now_arr[dep]<4;now_arr[dep]++)
    {
        now+=now_arr[dep];
        dfs(dep+1);
        now-=now_arr[dep];
    }
    now_arr[dep]=0;
    return 0;
}

int main()
{
    int i;
    freopen("clocks.in","r",stdin);
    freopen("clocks.out","w",stdout);
    for (i=0;i<9;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        tmp%=12;
        c[i]=tmp;
    }
    //for (i=0;i<9;i++) cout<<c[i]<<" ";cout<<endl;
    best=9999999;now=0;
    memset(best_arr,-1,sizeof(best_arr));
    memset(now_arr,0,sizeof(now_arr));
    dfs(0);
    //printf("%d\n",best);
    for (i=0;i<9;i++)
        if (best_arr[i]>0)
        {
            printf("%d",i+1);
            best_arr[i]--;
            break;
        }
    for (;i<9;i++)
        while (best_arr[i]>0)
        {
            printf(" %d",i+1);
            best_arr[i]--;
        }
    printf("\n");
    return 0;
}



