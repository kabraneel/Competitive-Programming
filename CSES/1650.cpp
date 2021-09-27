// na ho paega humse
// nai_aati_coding
// i love PD
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
#define int long long
#define PB push_back
#define all(x) (x).begin(),(x).end()
#define MP make_pair
#define sz(x) (int)(x.size())

template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

#define FOR(i,a,b) for(int i=a; i<b; i++)

const int MOD = 1e9 + 7;
const int INF = 1e18;

struct node{
  int v = 0; // 1
	// use more variables if you want more information
	// these default values should be identity_element
	node(){}
	node(int val){
    v = val; // 2
	}
	void merge(const node &l,const node &r){ // store the thing you wanna query

    v = (l.v) ^ (r.v); // 3
		// if we wanted the maximum, then we would do
		// like v = max(l.v,r.v)
	}
};

// example: add on a range: identity transformation = 0
// old += new

// if old is identity which is 0, then 0 + new which new

struct update
{
	int v = 0; // 4
	// use more variables if you want more information
	// these default values should be identity_transformation
	update(){}
	update(int val){
		v = val; // 5
	}
	// combine the current update with the other update (see keynotes)
	void combine(update &other,const int32_t &tl,const int32_t &tr){

  	v = other.v; // 6

		// you can be sure that the "other" is newer than current

	}
	// store the correct information in the node x
	void apply(node &x,const int32_t &tl,const int32_t &tr){

		// no change in freq
		x.v = (tr - tl + 1)*v; // 7

	}
};

// template<typename node,typename update>
struct segtree
{
	int len;
	vector<node> t;
	vector<update> u;
	vector<bool> lazy;
	node identity_element;
	update identity_transformation;
	segtree(int l){
		len = l;
		t.resize(4 * len);
		u.resize(4 * len);
		lazy.resize(4 * len);
		identity_element = node();
		identity_transformation = update();
	}

	void pushdown(const int32_t &v, const int32_t &tl, const int32_t &tr){
		if(!lazy[v]) return;
		int32_t tm = (tl + tr) >> 1;
		apply(v<<1,tl,tm,u[v]);
		apply(v<<1|1,tm+1,tr,u[v]);
		u[v] = identity_transformation;
		lazy[v] = 0;
	}

	void apply(const int32_t &v, const int32_t &tl, const int32_t &tr, update upd){
		if(tl != tr){
			lazy[v] = 1;
			u[v].combine(upd,tl,tr);
		}
		upd.apply(t[v],tl,tr);
	}

	template<typename T>
	void build(const T &arr,const int32_t &v, const int32_t &tl, const int32_t &tr){
		if(tl == tr){
			t[v] = tl;
			return;
		}
		int32_t tm = (tl + tr) >> 1;
		build(arr,v<<1,tl,tm);
		build(arr,v<<1|1,tm+1,tr);
		t[v].merge(t[v<<1],t[v<<1|1]);
	}

	node query(const int32_t &v,const int32_t &tl,const int32_t &tr,const int32_t &l,const int32_t &r){
		if(l > tr || r < tl){
			return identity_element;
		}
		if(tl >= l && tr <= r){
			return t[v];
		}

		pushdown(v,tl,tr);
		int32_t tm = (tl + tr) >> 1;
		node a = query(v<<1,tl,tm,l,r),b = query(v<<1|1,tm+1,tr,l,r),ans;
		ans.merge(a,b);
		return ans;
	}

	// rupd = range update
	void rupd(const int32_t &v,const int32_t &tl,const int32_t &tr,const int32_t &l,const int32_t &r,const update &upd){
		if(l > tr || r < tl){
			return;
		}
		if(tl >= l && tr <= r){
			apply(v,tl,tr,upd);
			return;
		}
		pushdown(v,tl,tr);
		int32_t tm = (tl + tr) >> 1;
		rupd(v<<1,tl,tm,l,r,upd);
		rupd(v<<1|1,tm+1,tr,l,r,upd);
		t[v].merge(t[v<<1],t[v<<1|1]);
	}

	public:
	template<typename T>
	void build(const T &arr){
		build(arr,1,0,len-1);
	}
	node query(const int32_t &l,const int32_t &r){
		return query(1,0,len-1,l,r);
	}
	void rupd(const int32_t &l,const int32_t &r,const update &upd){
		rupd(1,0,len-1,l,r,upd);
	}
};



void solve(){
  int n,q; cin>>n>>q;
  segtree s(n);
  vector<int> arr(n);

  for(int i = 0; i<n; i++) cin>>arr[i];


  for(int i = 0; i<n; i++){
    s.rupd(i,i, arr[i]);
  }

  while(q--){
    // int x; cin>>x;
    // if(x == 1){
      // int u,v; cin>>u>>v;
      // s.rupd(u-1,u-1,v);
    // }
    // else{
    int u,v; cin>>u>>v;
    cout<<s.query(u-1,v-1).v<<'\n';
    // }
  }

}

signed main(){

  #ifndef ONLINE_JUDGE
  freopen("/home/kabraneel/coding/inputfa.txt", "r", stdin);
  freopen("/home/kabraneel/coding/outputfa.txt", "w", stdout);
  freopen("/home/kabraneel/coding/error.txt","w",stderr);
  #endif

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  auto start = chrono::high_resolution_clock::now();

  int t=1;
  // cin>>t;
  while(t--){
    solve();
  }

  auto end = chrono::high_resolution_clock::now();
  double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

  time_taken *= 1e-9;

  cerr <<fixed<<time_taken<<setprecision(9)<< " sec"<<endl;
  return 0;
}
