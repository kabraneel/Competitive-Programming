const int modn 1e9 + 7

//function used to convert
int fast_pow(int a, int p) {
  int res = 1;
  while (p) {

    if (p % 2 == 0) {
      a = a * 1ll * a % mod;
      p /= 2;
    }

    else {
      res = res * 1ll * a % mod;
      p--;
    }

  }
  return res;
}

int inverse(int a){
  return fast_pow(a,modn-2);
}
