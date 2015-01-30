/*
ID: ck891191
PROG: packrec
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define Max2(a,b) ((a)>(b)?(a):(b))
#define Max3(a,b,c) (Max2(a,b)>(c)?Max2(a,b):(c))
#define Max4(a,b,c,d) (Max3(a,b,c)>(d)?Max3(a,b,c):(d))
struct RECT
{
    int l,w;
};
int len1,len2,len3,len4,wid1,wid2,wid3,wid4;
int min_area,l,w,ret_size;
RECT ret[3000];

int cmp(const RECT &a,const RECT &b)
{
    return a.l<b.l;
}

int init()
{
    freopen("packrec.in","r",stdin);
    freopen("packrec.out","w",stdout);
    scanf("%d%d%d%d%d%d%d%d",&len1,&wid1,&len2,&wid2,&len3,&wid3,&len4,&wid4);
    min_area=0x7fffffff;
    ret_size=0;
    return 0;
}

int update()
{
    if (l*w<min_area)
    {
        min_area=l*w;
        ret_size=1;
        ret[0].l=l;ret[0].w=w;

    }
    else if (l*w==min_area)
    {
        ret[ret_size].l=l;ret[ret_size].w=w;
        ret_size++;
    }
    return 0;
}

int assign1(int l1,int w1,int l2,int w2,int l3,int w3,int l4,int w4)
{
    l=Max4(l1,l2,l3,l4);
    w=w1+w2+w3+w4;
    update();
    return 0;
}

int assign2(int l1,int w1,int l2,int w2,int l3,int w3,int l4,int w4)
{
    l=Max3(l1,l2,l3)+l4;
    w=Max2(w1+w2+w3,w4);
    update();
    return 0;
}

int assign3(int l1,int w1,int l2,int w2,int l3,int w3,int l4,int w4)
{
    l=Max2(Max2(l1,l2)+l4,l3);
    w=Max2(w1+w2,w4)+w3;
    update();
    return 0;
}

int assign4(int l1,int w1,int l2,int w2,int l3,int w3,int l4,int w4)
{
    l=Max3(l1+l2,l3,l4);
    w=Max2(w1,w2)+w3+w4;
    update();
    return 0;
}

int assign5(int l1,int w1,int l2,int w2,int l3,int w3,int l4,int w4)
{
    l=Max3(l1+l3,l2+l4,l2+l3);
    w=Max3(w1+w2,w3+w4,w1+w4);
    update();
    return 0;
}

int assign(int l1,int w1,int l2,int w2,int l3,int w3,int l4,int w4)
{
    assign1(l1,w1,l2,w2,l3,w3,l4,w4);
    assign2(l1,w1,l2,w2,l3,w3,l4,w4);
    assign3(l1,w1,l2,w2,l3,w3,l4,w4);
    assign4(l1,w1,l2,w2,l3,w3,l4,w4);
    assign5(l1,w1,l2,w2,l3,w3,l4,w4);
    return 0;
}

int search(int l1,int w1,int l2,int w2,int l3,int w3,int l4,int w4)
{
    assign(l1,w1,l2,w2,l3,w3,l4,w4);
    assign(l1,w1,l2,w2,l3,w3,w4,l4);
    assign(l1,w1,l2,w2,w3,l3,l4,w4);
    assign(l1,w1,l2,w2,w3,l3,w4,l4);
    assign(l1,w1,w2,l2,l3,w3,l4,w4);
    assign(l1,w1,w2,l2,l3,w3,w4,l4);
    assign(l1,w1,w2,l2,w3,l3,l4,w4);
    assign(l1,w1,w2,l2,w3,l3,w4,l4);

    assign(w1,l1,l2,w2,l3,w3,l4,w4);
    assign(w1,l1,l2,w2,l3,w3,w4,l4);
    assign(w1,l1,l2,w2,w3,l3,l4,w4);
    assign(w1,l1,l2,w2,w3,l3,w4,l4);
    assign(w1,l1,w2,l2,l3,w3,l4,w4);
    assign(w1,l1,w2,l2,l3,w3,w4,l4);
    assign(w1,l1,w2,l2,w3,l3,l4,w4);
    assign(w1,l1,w2,l2,w3,l3,w4,l4);

    return 0;
}

int solve()
{
    search(len1,wid1,len2,wid2,len3,wid3,len4,wid4);
    search(len1,wid1,len2,wid2,len4,wid4,len3,wid3);
    search(len1,wid1,len3,wid3,len2,wid2,len4,wid4);
    search(len1,wid1,len3,wid3,len4,wid4,len2,wid2);
    search(len1,wid1,len4,wid4,len2,wid2,len3,wid3);
    search(len1,wid1,len4,wid4,len3,wid3,len2,wid2);

    search(len2,wid2,len1,wid1,len3,wid3,len4,wid4);
    search(len2,wid2,len1,wid1,len4,wid4,len3,wid3);
    search(len2,wid2,len3,wid3,len1,wid1,len4,wid4);
    search(len2,wid2,len3,wid3,len4,wid4,len1,wid1);
    search(len2,wid2,len4,wid4,len1,wid1,len3,wid3);
    search(len2,wid2,len4,wid4,len3,wid3,len1,wid1);

    search(len3,wid3,len1,wid1,len2,wid2,len4,wid4);
    search(len3,wid3,len1,wid1,len4,wid4,len2,wid2);
    search(len3,wid3,len2,wid2,len1,wid1,len4,wid4);
    search(len3,wid3,len2,wid2,len4,wid4,len1,wid1);
    search(len3,wid3,len4,wid4,len1,wid1,len2,wid2);
    search(len3,wid3,len4,wid4,len2,wid2,len1,wid1);

    search(len4,wid4,len1,wid1,len2,wid2,len3,wid3);
    search(len4,wid4,len1,wid1,len3,wid3,len2,wid2);
    search(len4,wid4,len2,wid2,len1,wid1,len3,wid3);
    search(len4,wid4,len2,wid2,len3,wid3,len1,wid1);
    search(len4,wid4,len3,wid3,len1,wid1,len2,wid2);
    search(len4,wid4,len3,wid3,len2,wid2,len1,wid1);

    return 0;
}

int print()
{
    int i;
    for (i=0;i<ret_size;i++)
    {
        int t;
        if (ret[i].l>ret[i].w)
        {
            t=ret[i].l;
            ret[i].l=ret[i].w;
            ret[i].w=t;
        }
    }
    sort(ret,ret+ret_size,cmp);
    printf("%d\n",min_area);
    printf("%d %d\n",ret[0].l,ret[0].w);
    for (i=1;i<ret_size;i++)
        if (ret[i].l!=ret[i-1].l)
            printf("%d %d\n",ret[i].l,ret[i].w);

}

int main()
{
    init();
    solve();
    print();
    return 0;
}
