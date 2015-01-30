const int maxn=999999;
class UnionFindSet {
  public:
    int rank[maxn], pnt[maxn];
    int init() {
      memset(rank, 0, sizeof(rank));
      memset(pnt, 0, sizeof(pnt));
      return 0;
    }
    UnionFindSet() { init(); }
    int makeset(int x) {
      rank[pnt[x] = x] = 0;
      return 0;
    }
    int find(int x) { //可以写个递归更简单
      int px = x, i;
      while (px != pnt[px]) px = pnt[px];
      while (x != px) {
        i = pnt[x];
        pnt[x] = px;
        x = i;
      }
      return px;
    }
    int merge(int x, int y) { // or  just  pnt[find(x)] = find(y)
      if (rank[x=find(x)] > rank[y=find(y)]) {
        pnt[y] = x;
      } else {
        pnt[x] = y;
        rank[y] += (rank[x] == rank[y]);
      }
      return 0;
    }
}
