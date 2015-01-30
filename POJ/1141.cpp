#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string s;
int dp[105][105]={0},path[105][105]={0};

int output(int i,int j)
{
    if (i>j) return 0;
    if (i==j)
    {
        if (s[i]==']'||s[i]=='[') printf("[]");
        else printf("()");
    } 
    else if (path[i][j]==-1)
    {
        cout<<s[i];
        output(i+1,j-1);
        cout<<s[j];
    }
    else 
    {
        output(i,path[i][j]);
        output(path[i][j]+1,j);
    }
    return 0;
}

int main()
{   
    int i,j,k;
    cin>>s;
    int len=s.size();
    for (i=0;i<len;i++) dp[i][i]=1;
    
    for (i=len-1;i>=0;i--)
       for (j=i+1;j<len;j++)
       {
           dp[i][j]=INT_MAX;
           if (s[i]=='('&&s[j]==')'||s[i]=='['&&s[j]==']') dp[i][j]=dp[i+1][j-1],path[i][j]=-1;
           for (k=i;k<j;k++)
              if (dp[i][j]>dp[i][k]+dp[k+1][j]) dp[i][j]=dp[i][k]+dp[k+1][j],path[i][j]=k;              
       }
    
    //printf("%d",dp[0][len-1]);
    output(0,len-1);
    printf("\n");
    
    system("pause");
    return 0;
}
