/*
ID: ck89119
PROG: lgame
LANG: C++
*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CLR(a,x) memset(a,x,sizeof(a))
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause");
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(n) (n^(n-1))&n
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout);
//ifstream fin("");
//ofstream fout("");

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=99999;
const int MAXM=9999999;
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;

string wordSet[40005], word, wordExdSet[40005];
int wordSetSize, wordExdSetSize;
int letterNum[26];
int wordExdScore[40005];
int score[26] = {2, 5, 4, 4, 1, 6, 5, 5, 1, 7, 6, 3, 5, 2, 3, 5, 7, 2, 1, 2, 4 ,6, 6, 7, 5, 7};

int input() {
    int i;
    freopen("lgame.dict", "r", stdin);
    for (i = 0; ; i++) {
        cin >> wordSet[i];//dump(wordSet[i])
        if (wordSet[i] == ".") break;
    }
    wordSetSize = i;
    //sort(wordSet, wordSet+wordSetSize);

    freopen("lgame.in", "r", stdin);
    freopen("lgame.out", "w", stdout);
    cin >> word;//dump(word)
    CLR(letterNum, 0);
    for (i = 0; i < word.size(); i++)
        letterNum[word[i]-'a']++;
    //out(letterNum, 26);
    return 0;
}

int remove() {
    int i, j;
    int tmpNum[26];
    wordExdSetSize = 0;
    for (i = 0; i < wordSetSize; i++) {
        int flag = 1;
        int tscore = 0;
        CLR(tmpNum, 0);
        for (j = 0; j < wordSet[i].size(); j++) {
            int t = wordSet[i][j]-'a';
            tscore += score[t];
            tmpNum[t]++;
            if (tmpNum[t] > letterNum[t]) {flag = 0; break;}
        }
        if (flag) {wordExdSet[wordExdSetSize] = wordSet[i]; wordExdScore[wordExdSetSize++] = tscore;}
    }
    //dump(wordExdSetSize)
    return 0;
}

int solve() {
    int res = 0;
    vector<string> resSet1;
    vector<pair<string, string> >resSet2;
    int i, j, k;
    int tmpNum[26];
    for (i = 0; i < wordExdSetSize; i++)
        if (res < wordExdScore[i]) {
            res = wordExdScore[i];
            resSet1.clear();
            resSet1.PB(wordExdSet[i]);
        }
        else if (res == wordExdScore[i]) {
                    resSet1.PB(wordExdSet[i]);
                }
    //dump("########")
    for (i = 0; i < wordExdSetSize-1; i++)
        for (j = i+1; j < wordExdSetSize; j++) {
            CLR(tmpNum, 0);
            for (k = 0; k < wordExdSet[i].size(); k++)
                tmpNum[wordExdSet[i][k]-'a']++;
            for (k = 0; k < wordExdSet[j].size(); k++)
                tmpNum[wordExdSet[j][k]-'a']++;
            for (k = 0; k < 26; k++)
                if (tmpNum[k] > letterNum[k]) break;
            if (k < 26) continue;
            //dump(i)dump(j)
            if (res < wordExdScore[i] + wordExdScore[j]) {
                    res = wordExdScore[i] + wordExdScore[j];
                    resSet1.clear();
                    resSet2.clear();
                    resSet2.PB(MP(wordExdSet[i], wordExdSet[j]));
                } else if (res == wordExdScore[i] + wordExdScore[j]) {
                            resSet2.PB(MP(wordExdSet[i], wordExdSet[j]));
                        }
        }

    cout << res << endl;
    i = j = 0;
    while (i < resSet1.size() || j < resSet2.size()) {

        if (i < resSet1.size() && j < resSet2.size() && resSet1[i] <= resSet2[j].first) {
            //dump("!")
            cout << resSet1[i] << endl;
            i++;
        }
        else if (i < resSet1.size() && j < resSet2.size() && resSet1[i] > resSet2[j].first) {
            //dump("@")
            cout << resSet2[j].first << ' ' << resSet2[j].second << endl;
            j++;
        }
        else if (j >= resSet2.size()) {
            //dump("#")
            cout << resSet1[i] << endl;
            i++;
        }
        else {
            //dump("$")
            cout << resSet2[j].first << ' ' << resSet2[j].second << endl;
            j++;
        }
        //dump(i)dump(j)
        //dump(resSet1.size()) dump(resSet2.size())
    }

    return 0;
}

int main() {
    input();
    remove();
    solve();
    return 0;
}
