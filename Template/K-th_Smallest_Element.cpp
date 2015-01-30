int select(int& a,int b,int e,int k) 
{ 
    if (b==e) return a[b]; 
    int x = a[b+rand()%(e-b+1)],i=b,j=e;
    i--; j++;
    while(i<j)	
    {
        while(a[++i]<x);  
        while(a[--j]>x);
        if (i<j) swap(a[i],a[j]);
    } 
    if(j==e) j--; i=j-b+1;
    if (k<=i) return select(a,b,j,k) ;
    else return select(a,j+1,e,k-i);
} 
