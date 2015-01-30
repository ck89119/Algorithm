/*
ID: ck891191
PROG: fence8
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <stack>

using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;

int n,r,board[55],rail[1024],rail_sum[1024];
int sum_board;

int input(){
    int i;
    freopen("fence8.in","r",stdin);
    freopen("fence8.out","w",stdout);
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf("%d",&board[i]);
        sum_board+=board[i];
    }
    scanf("%d",&r);
    for (i=0;i<r;i++){
        scanf("%d",&rail[i]);
    }
    //dump(n)dump(r)
    return 0;
}

int search(int k, int min_i, int sum, int lim){
    int i;
    int flag;
    if (k>=r) return 1;
    if (sum>lim) return 0;
    flag=0;
    for (i=min_i;i<n;i++)
        if (board[i]>=rail[k]){
            board[i]-=rail[k];
            if (k!=r-1&&rail[k]==rail[k+1]) min_i=i;
            else min_i=0;
            flag=search(k+1,min_i,sum+(board[i]<rail[r-1]?board[i]:0),lim);
            board[i]+=rail[k];
            if (flag) return 1;
        }
    return 0;
}

int cmp(const int &a,const int &b){
    return a>b;
}

int solve(){
    int i,left,right,mid;
    sort(board,board+n,cmp);
    sort(rail,rail+r,cmp);
    rail_sum[r-1]=rail[r-1];
    for (i=r-2;i>=0;i--)
         rail_sum[i]=rail_sum[i+1]+rail[i];
    left=0;right=r-1;
    while (left<=right){
        mid=(left+right)/2;
        if (search(mid,0,0,sum_board-rail_sum[mid])) right=mid-1;
        else left=mid+1;
    }
    //dump(left)dump(right)
    printf("%d\n",r-right-1);
    return 0;
}

int main(){
    input();
    solve();
    return 0;
}
