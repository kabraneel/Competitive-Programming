#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int t[4*N];

void update(int v, int tl, int tr, int ind, int val){

  if(tl == ind && tr == ind){
    t[v]  = val;
    return;
  }

  if(id>tr || id<tl){
    return;
  }

  int tm = (tl + tr)/2;
  update(2*v, tl, tm, ind, val);
  update(2*v+1, tm+1, tr, ind, val);

  t[v] = t[2*v] + t[2*v+1];
}

int query(int v, int tl, int tr, int l, int r){

  //fully outside
  if(tl>r || tr<l){ //tl ... tr .. l ... r or l..r .. tl.. tr
    return;
  }

  if(l<=tl && tr<=r){//l ...tl ...tr ... r
    return t[v];
  }

  int ans = 0;
  int tm = (tl + tr)/2;
  ans = ans + query(2*v, tl, tm, l, r);
  ans = ans + query(2*v+1, tm+1, tr, l, r);

  return ans;
}

int main(){

}
