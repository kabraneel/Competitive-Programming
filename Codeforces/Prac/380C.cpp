// na ho paega humse
// nai_aati_coding
// i love PD
// Motivation when feeling low : http://bitly.com/98K8eH
#include <bits/stdc++.h>
#include <chrono>
using namespace std;


#ifdef KABRANEEL
#include<sys/resource.h>
#include <sys/time.h>
#endif

#define int long long
#ifdef KABRANEEL
#define LOCAL
#include "/home/kabraneel/coding/debug.h"
#else
#define debug(x...)
#define debugln(x...)
#endif


#define PB push_back
#define all(x) (x).begin(),(x).end()
#define MP make_pair
#define sz(x) (int)(x.size())

template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

#define FOR(i,a,b) for(int i=a; i<b; i++)

const int MOD = 1e9 + 7;
const int INF = 1e18;

template<typename node,typename update>
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
      t[v] = arr[tl];
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


struct node
{
  // int mn = 0;
  // int freq = 0;
  int l1 = 0;
  int r1 = 0;
  int ans = 0;
  node(){}
  node(int val){
    // mn = val;
    // freq = 1;
    l1 = val ^ 0;
    r1 = val ^ 1;
    ans = 0;
  }
  void merge(const node &l,const node &r){
    // mn = min(l.mn,r.mn);
    // mn = __gcd(l.mn, r.mn);
    // freq = 0;
    // if(l.mn == mn) freq += l.freq;
    // if(r.mn == mn) freq += r.freq;
  	l1 = l.l1 + r.l1 - min(l.l1, r.r1);
  	r1 = l.r1 + r.r1 - min(l.l1, r.r1);
  	ans = l.ans + r.ans + 2 * min(l.l1, r.r1);
  }
};

struct update
{
  int v = 0;
  update(){}
  update(int val){
    v = val;
  }
  void combine(update &other,const int32_t &tl,const int32_t &tr){
    v += other.v;
  }
  void apply(node &x,const int32_t &tl,const int32_t &tr){
    x.l1 += v;
  }
};


void solve(){
	string s; cin>>s;
	int n = s.length();

	vector<int> arr(n);

	for(int i = 0; i<n; i++){
		if(s[i] == '('){
			arr[i] = 1;
		}
		else{
			arr[i] = 0;
		}
	}

	segtree<node, update> tree(n);
	tree.build(arr);

	// for(int i = 0; i<n; i++){
	// }

	// cout << tree.query(i,i).l1 << " " << tree.query(i,i).r1 << '\n';

	int q;
	cin>>q;

	while(q--){
		int l; int r; cin>>l>>r;
		l--; r--;
		auto x = tree.query(l, r);

		cout << x.ans << '\n';
	}

}

signed main(){

	#ifdef KABRANEEL
	freopen("/home/kabraneel/coding/Contests/inputfa.txt", "r", stdin);
	freopen("/home/kabraneel/coding/Contests/outputfa.txt", "w", stdout);
	freopen("/home/kabraneel/coding/Contests/error.txt","w",stderr);
	#endif

	#ifdef KABRANEEL
        /* setting up soft limit on resources */
        rlimit rlim , rlim_time ;
        if(getrlimit( RLIMIT_FSIZE , &rlim) || getrlimit(RLIMIT_CPU , &rlim_time) )
           return 1 ;
        // maximum file size (in bytes) that your program will be able to create ;
        rlim.rlim_cur = 1000*1000;
        // maximum allowed runtime for your program ;
        rlim_time.rlim_cur = 1;
        if(setrlimit( RLIMIT_FSIZE , &rlim ) || setrlimit(RLIMIT_CPU , &rlim_time))
           return 2 ;
    #endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	auto start = chrono::high_resolution_clock::now();

	int t=1;
	int zcount = 1;
	// cin>>t;

	while(t--){
		//cout<<"Case #"<<zcount++<<": ";
	  solve();
	}

	auto end = chrono::high_resolution_clock::now();
	double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	time_taken *= 1e-9;

	cerr <<fixed<<time_taken<<setprecision(9)<< " sec"<<endl;
	return 0;
}