int getInt() {
  int n = 0;
  int op = 1;
  char ch = getchar();
  while ((ch > '9' || ch < '0') && ch != '-') ch = getchar();
  if (ch == '-') {op = -1;ch = getchar();}
  while (ch <= '9' && ch >= '0') {
    n = n * 10 + ch - '0';
    ch = getchar();
  }
  return n*op;
}
