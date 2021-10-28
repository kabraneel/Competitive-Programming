#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

int t[4*N];

void update(int v, int tl, int tr, int ind, int val){

  if(tl == ind && tr == ind){
    t[v]  = val;
    return;
  }

  if(ind>tr || ind<tl){
    return;
  }

  int tm = (tl + tr)/2;
  update(2*v, tl, tm, ind, val);
  update(2*v+1, tm+1, tr, ind, val);

  t[v] = __gcd(t[2*v], t[2*v+1]);
}

int query(int v, int tl, int tr, int l, int r){

  //fully outside
  if(tl>r || tr<l){ //tl ... tr .. l ... r or l..r .. tl.. tr
    return -1;
  }

  if(l<=tl && tr<=r){//l ...tl ...tr ... r
    return t[v];
  }

  int ans = 0;
  int tm = (tl + tr)/2;
  ans = __gcd(ans , query(2*v, tl, tm, l, r));
  ans = __gcd(ans , query(2*v+1, tm+1, tr, l, r));

  return ans;
}

void solve(){

    int n; cin>>n;
    vector<int> arr(n);

    for(int i = 0; i<n; i++){
      cin>>arr[i];
      update(1, 0, n-1, i, arr[i]);
    }

    int ans = 0;

    for(int i = 0; i<n; i++){
      for(int j = i+1; j<n; j++){

        // cout<<"here\n";

        int temp1 = arr[i];
        int temp2 = arr[j];
        //
        update(1, 0, n-1, i, temp1*temp2);
        // update(j, j, temp1*temp2);
        update(1, 0, n-1, j, temp1*temp2);

        ans = max(ans, query(1, 0, n-1, 0, n-1));

        // for(int k = 0; k<n; k++){
        //   // cout<<arr[i]<<" ";
        //   cout<< s.query(k,k).v << " ";
        // }
        // cout<<'\n';
        //
        // cout<<s.query(0, n-1).v<<"\n";
        //
        // s.rupd(i, i, temp1);
        // s.rupd(j, j, temp2);

        update(1, 0, n-1, i, temp1);
        // update(j, j, temp1*temp2);
        update(1, 0, n-1, j, temp2);

      }
    }

    cout<<ans<<'\n';

}

int main(){

  #ifndef ONLINE_JUDGE
  freopen("/home/kabraneel/coding/inputfa.txt", "r", stdin);
  freopen("/home/kabraneel/coding/outputfa.txt", "w", stdout);
  freopen("/home/kabraneel/coding/error.txt","w",stderr);
  #endif

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  auto start = chrono::high_resolution_clock::now();

  int t=1;
  cin>>t;
  while(t--){
    solve();
  }


  return  0;
}
