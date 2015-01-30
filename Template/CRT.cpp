//extended euclid(a,b) = ax + by 
int  extended_euclid(int a,int b,int &x,int &y) 
{ 
    if(b==0)
    { 
        x=1,y=0; 
        return a;	
    } 
    else
    {
        int res=extended euclid(b,a%b,x,y); 
        int t=x; x=y; y=t-(a/b)*y; 
        return  res ; 
    } 
} 
//ax ≡ b (mod n) , n > 0 
int modular_linear_equation_solver(int a,int b,int n)
{
    int d,x,y,e,i;
    d=extended_euclid(a,n,x,y);
    if(b%d!=0) cout<<"No answer ! ";  
    else
    {
        e=x*(b/d)%n;	//  x=e is a basic solution
        for(i=0;i<d;i++) cout<<(e+i+(n/d))%n<<endl;
    }
    return 0;
} 
//Given bi , wi , i = 0···len-1 which wi > 0 , i = 0···len-1 and (wi,wj)==1,	i=j
//Find an x which satisfies: x ≡ bi (mod wi), i = 0···len-1
//中国剩余定理 
int modular_linear_system(int b[],int w[],int k){
	int d,x,y,a=0,m,n=1,i;
	for (i=0;i<k;i++) n*=w[i];
	for (i=0;i<k;i++){
		m=n/w[i];
		d=extended_euclid(w[i],m,x,y);
		a=(a+y*m*b[i])%n;
	}
	return (a+n)%n;
}
