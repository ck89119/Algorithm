const int MOD = 10003;
const int MAXN = 999999;
const int SEED = 13331;  // 10003, 10007, 13331, 1000000007, 1000000009

struct HashMap {
  int head[MOD], next[MAXN], cnt[MAXN];
  ULL data[MAXN];
  int size;

  int init() {
    size = 0;
    CLR(head, -1);
    return 0;
  }

  int insert(ULL key) {
    int k = key % MOD;
    for (int i = head[k]; i != -1; i = next[i])
      if (data[i] == key) {
        ++cnt[i];
        return 0;
      }
    data[size] = key;
    next[size] = head[k];
    cnt[size] = 1;
    head[k] = size++;
    return 0;
  }

  int count(ULL key) {
    int k = key % MOD;
    for (int i = head[k]; i != -1; i = next[i])
      if (data[i] == key) return cnt[i];
    return 0;
  }

};
