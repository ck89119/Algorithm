const long long MOD = 1LL << 60;
struct integer {
  long long h, l;
  
  integer() {}
  
  integer(int _h, int _l): h(_h), l(_l) {}
  
  integer neg() {
    if (h == 0) return integer(h, -l);
    else return integer(-h, l);
  }
  
  integer operator+(const integer &a) const {
    integer ans(h+a.h, l+a.l);
    if (ans.l >= MOD) {
      ans.l -= MOD;
      ans.h += 1;
    }
    return ans;
  }

  int operator<(const integer &a) const {
    if (h == a.h) return l < a.l;
    else return h < a.h;
  }

};
