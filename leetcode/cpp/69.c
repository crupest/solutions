int mySqrt(int x) {
  long long l = 0, r = x;

  while (l != r) {
    long long m = (l + r + 1) / 2;
    if (m * m <= x) {
      l = m;
    } else {
      r = m - 1;
    }
  }

  return l;
}
