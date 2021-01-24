#include <iostream>
#include <cstdio>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
int next[10010];
int a[1000100],b[10010],n,m;

int getNext()
{
    int j,k;
    j=0;k=-1;next[0]=-1;
    while (j<m)
    {
         if (k==-1||b[j]==b[k]) next[++j]=++k;
         else k=next[k];
    }
    return 0;
}

int KMP_Index()
{
    int i,j=0;
    getNext();
    for (i=0;i<n;i++)
    {
        while (j>0&&a[i]!=b[j]) j=next[j];
        if (a[i]==b[j]) j++;
        if (j==m) break;
    }
    if (j==m) return i-m+2;
    else return -1;
}

/*int KMP_Index()
{
	int i = 0, j = 0;
	getNext();

	while(i < n && j < m)
	{
		if(j == -1 || a[i] == b[j])
		{
			i++; j++;
		}
		else
			j = next[j];
	}
	if(j == m)
		return i - m + 1;
	else
		return -1;
}
*/
int main()
{
    int cases;
    int i,j,ret;
    scanf("%d",&cases);
    for (j=0;j<cases;j++)
    {
        scanf("%d%d",&n,&m);
        for (i=0;i<n;i++) scanf("%d",&a[i]);
        for (i=0;i<m;i++) scanf("%d",&b[i]);
        ret=KMP_Index();
        printf("%d\n",ret);
    }
    
    return 0;
}
