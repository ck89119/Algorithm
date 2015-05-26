const long long MOD = 1000000007;

inline unsigned long mul(unsigned long x, unsigned long y) {
  unsigned long ans = 0;
  __asm__ (
      "movq %1,%%rax\n mulq %2\n divq %3\n"
      :"=d"(ans):"m"(x),"m"(y),"m"(MOD):"%rax"
      );  
  return ans;
}
