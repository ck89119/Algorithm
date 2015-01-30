#include <iostream>
using namespace std;
const int MAXM = 30,KIND = 26;
int m;
struct Node
{
    char* s;
    int prefix;
    bool isword;
    Node* next[KIND];
    Node()
    {
        s = NULL;
        prefix = 0;
        isword = false;
        memset(next,0,sizeof(next));
    }
};
Node *root;
void insert(Node *root,char *s)
{
    Node *p = root;
    for (int i = 0;s[i];i++)
    {
        int x = s[i] - 'a';
        p->s = s+i;
        if (p->next[x] == NULL)
            p->next[x] = new Node;
        p = p->next[x];
        p->prefix++;
    }
    p->isword = true;
}
bool del(Node *root,char *s)
{
    Node *p = root;
    for (int i = 0;s[i];i++)
    {
        int x = s[i] - 'a';
        if (p->next[x] == NULL)
            return false;
        p = p->next[x];
    }
    if (p->isword)
        p->isword = false;
    else
        return false;
    return true;
}
bool search(Node *root,char* s)
{
    Node* p = root;
    for (int i = 0;s[i];i++)
    {
        int x = s[i]-'a';
        if (p->next[x] == NULL)
            return false;
        p = p->next[x];
    }
    return p->isword;
}
int count(Node *root,char *s)
{
    Node *p = root;
    for (int i = 0;s[i];i++)
    {
        int x = s[i] - 'a';
        if (p->next[x] == NULL)
            return 0;
        p = p->next[x];
    }
    return p->prefix;
}
int main()
{
    m = 0;
    root = new Node;
    char s[MAXM];
    while (gets(s))
    {
        if (strcmp(s,"") == 0)
            break;
        insert(root,s);
    }
    while (gets(s))
        printf("%d\n",count(root,s));
}
