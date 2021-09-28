#include <bits/stdc++.h>
using namespace std;

const int N = 3*(1e5) + 5;

//the segment tree
int t[4*N];

//this array tells us if a particular node is lazy or not
bool lazy[4*N];

// the value to remember
int upd[4*N];

void apply(int v, int tl, int tr, int val){ //tl, tr is node range and v is node id
  t[v] += val * (tr - tl + 1);
  if(tl != tr){//if it is not a leaf node
    lazy[v] = 1;
    upd[v] += val;
  }
}

//assigning the task to both children
void pushdown(int v, int tl, int tr){

  if(lazy[v]){ //if its lazy, we need to propogate
    lazy[v] = 0; // not lazy

    int tm = (tl + tr)/2;

    //upd[v] was the the value we needed to push down
    apply(2*v, tl, tm, upd[v]);
    apply(2*v + 1, tm+1, tr, upd[v]);
    upd[v] = 0;
    // the man doesnt have to remember
  }

}

void update(int v, int tl, int tr, int l, int r, int val){

  if(tl > r || tr < l){
    //no overlap
    return;
  }

  if( l<= t1 && tr <= r){
    // fully within
    apply(v, tl, tr, val);
  }

  pushdown(v, tl, tr);
  int tm = (tl + tr) / 2;

  update(2*v, tl, tm, l, r, val);
  update(2*v + 1, tm+1, tr, l, r, val);

  t[v] = t[2*v] + t[2*v + 1];

}

int query(int v, int tl, int tr, int l, int r){

  if(tl > r || tr < l){
    return 0;
  }

  if(l<= tl && tr <= r){
    return t[v];
  }

  pushdown(v, tl, tr); //getting rid of the lazy tag

  int tm = (tl + tr)/2;
  int ans = 0;

  ans += query(2*v, tl, tm, l, r);
  ans += query(2*v + 1, tm + 1, tr, l, r);

}

// v, tl, tr -> 1, 0, Length - 1
int main(){
  
}
