class Solution {
 public:
  int countPrimes(int n) {
    int cnt = 0;
    vector<bool> prime(n, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i < n; ++i)
      if (prime[i]) {
        ++cnt;

        int j = i + i;
        while (j < n) {
          prime[j] = false;
          j += i;
        }
      }
    return cnt; 
  }
};
