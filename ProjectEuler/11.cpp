#include<iostream>
#include<vector>
#include<string>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
int main()
{
    vector < vector<int> > grid;  
    int i,j,t;
    int p1,p2,p3,p4;   
    for (i=0;i<20;i++)
    {
      vector<int> tmp;
      for (j=0;j<20;j++)
      {     
          string s;
          cin>>s;
          t=s[1]-'0'+(s[0]-'0')*10;
          tmp.push_back(t);
      }
      grid.push_back(tmp);
    }
    
    p1=0;
    for (i=0;i<20;i++)
       for (j=0;j<=16;j++) 
       {
           t=grid[i][j]*grid[i][j+1]*grid[i][j+2]*grid[i][j+3];
           if (t>p1) p1=t;
       }
    
    p2=0;
    for (i=0;i<=16;i++)
       for (j=0;j<20;j++) 
       {
           t=grid[i][j]*grid[i+1][j]*grid[i+2][j]*grid[i+3][j];
           if (t>p2) p2=t;
       } 
       
    p3=0;   
    for (i=0;i<=16;i++)
       for (j=0;j<=16;j++) 
       {
           t=grid[i][j]*grid[i+1][j+1]*grid[i+2][j+2]*grid[i+3][j+3];
           if (t>p3) p3=t;
       }  
       
    p4=0;
    for (i=0;i<=16;i++)
       for (j=3;j<20;j++) 
       {
           t=grid[i][j]*grid[i+1][j-1]*grid[i+2][j-2]*grid[i+3][j-3];
           if (t>p4) p4=t;
       }
       
    if (p1<p2) p1=p2;
    if (p1<p3) p1=p3;
    if (p1<p4) p1=p4;  
    cout<<p1<<endl;system("pause");  
    return 0;
}
