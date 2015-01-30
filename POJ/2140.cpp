#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int N;
    int i,j,sum,s;
    scanf("%d",&N);
    if (N==1){
        printf("1\n");
        return 0;
    }
    sum=1;
    for (i=N/2+1;i>0;i--){
        s=0;
        for (j=i;j>0;j--){
            s+=j;
            if (s>=N) break;
        }
        if (s==N) sum++;
    }
    printf("%d\n",sum);
    return 0;
}
