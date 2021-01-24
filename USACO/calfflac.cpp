/*
ID: ck891191
PROG: calfflac
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define dump(x)  cerr<< __LINE__ << " : " << #x << " = " << (x) <<endl;
int letter(char ch)
{
    if (ch>='a'&&ch<='z'||ch>='A'&&ch<='Z') return 1;
    else return 0;
}

int par(char s[20005])
{
    int i,j,len=strlen(s);
    int ret=0;
    i=0;j=len-1;
    while (i<j)
    {
        while (!letter(s[i])&&i<j) i++;
        while (!letter(s[j])&&i<j) j--;
        if (s[i]>='A'&&s[i]<='Z') s[i]=s[i]-'A'+'a';
        if (s[j]>='A'&&s[j]<='Z') s[j]=s[j]-'A'+'a';
        if (s[i]==s[j]) {i++;j--;}
        else break;
    }
    if (i<j) return -1;
    else
    {
        for (i=0;i<len;i++)
            if (letter(s[i])) ret++;
        return ret;
    }
}

int main()
{
    char str[20005],mstr[2005],s[85];
    int mi,i,j,x,y;
    freopen("calfflac.in","r",stdin);
    freopen("calfflac.out","w",stdout);
    while (gets(s))
    {
        strcat(str,s);
        str[strlen(str)]='\n';
    }
    mi=1;mstr[0]=str[0];mstr[1]='\0';
    for (i=0;i<strlen(str)-1;i++)
    {
        int l;
        if (!letter(str[i])) continue;
        x=i-1;y=i+1;l=1;
        while (x>=0&&y<strlen(str))
        {
            while (!letter(str[x])&&x>=0) x--;
            while (!letter(str[y])&&y<strlen(str)) y++;
            if (x>=0&&y<strlen(str))
            {
                if (str[x]==str[y]||str[x]+'a'-'A'==str[y]||str[y]+'a'-'A'==str[x])
                {
                    l+=2;
                    x--;y++;
                }
                else
                {
                    if (l>mi)
                    {
                        strncpy(mstr,str+x+1,y-x-1);
                        mi=l;
                        //dump(str[x]);dump(str[y]);dump(x);dump(y);
                        mstr[y-x-1]='\0';
                    }
                    break;
                }
            }
        }
        if (l>mi)
        {
            strncpy(mstr,str+x+1,y-x-1);
            mi=l;
            //dump(str[x]);dump(str[y]);dump(x);dump(y);
            mstr[y-x-1]='\0';
        }
        x=i;y=i+1;l=1;
        while (!letter(str[y])&&y<=strlen(str)) y++;
        if (x>=0&&y<strlen(str)&&str[x]==str[y])
        {
            l=0;
            while (x>=0&&y<strlen(str))
            {
                while (!letter(str[x])&&x>=0) x--;
                while (!letter(str[y])&&y<strlen(str)) y++;
                if (x>=0&&y<strlen(str))
                {
                    if (str[x]==str[y]||str[x]+'a'-'A'==str[y]||str[y]+'a'-'A'==str[x])
                    {
                        l+=2;
                        x--;y++;
                    }
                    else
                    {
                        if (l>mi)
                        {
                            strncpy(mstr,str+x+1,y-x-1);
                            mi=l;
                            //dump(str[x]);dump(str[y]);dump(x);dump(y);
                            mstr[y-x-1]='\0';
                        }
                        break;
                    }
                }
            }
            if (l>mi)
            {
                strncpy(mstr,str+x+1,y-x-1);
                mi=l;
                //dump(str[x]);dump(str[y]);dump(x);dump(y);
                mstr[y-x-1]='\0';
            }

        }
    }

    i=strlen(mstr)-1;
    while (!letter(mstr[i])) i--;
    mstr[i+1]='\0';
    i=0;
    while (!letter(mstr[i])) i++;
    printf("%d\n",mi);
    printf("%s\n",mstr+i);

    return 0;
}
