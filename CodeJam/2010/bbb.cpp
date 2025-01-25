#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int ans;
	int T,L,P,C;
	scanf("%d",&T);
	for(int tcase=1;tcase<=T;tcase++)
	{
		scanf("%d%d%d",&L,&P,&C);
        int tmp; 
		tmp=ceil(log((double)P/L)/log(C));
		ans=ceil(log(tmp)/log(2));
		printf("Case #%d: %d\n",tcase,ans);
	}
	return 0;
}
