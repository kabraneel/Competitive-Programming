// na ho paega humse
// nai_aati_coding
// i love PD
// Motivation when feeling low : http://bitly.com/98K8eH
#include <bits/stdc++.h>
#include <chrono>
#include <cstdlib>

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
const int N = 1e6 + 5;

#define LSB(i) ((i) & -(i))
typedef struct fenwick{
	int maxn;
	int A[N];
	void operator()(int n){
		maxn = n+1;
		FOR(i,0,n+1) A[i] = 0;
	}
	fenwick(){}
	fenwick(int n){
		maxn = n+1;
		FOR(i,0,n+1) A[i] = 0;
	}
	int query(int i){
		int sum = 0;
		while (i > 0)
			sum += A[i], i -= LSB(i);
		return sum;
	}
	void update(int i, int k){
		if(i<1)return;
		while (i < maxn)
			A[i] += k, i += LSB(i);
	}
	int query(int l,int r){
		return (query(r) - query(l-1)) ;
	}
}fenw;

void solve(){
	int n; cin>>n;
	map<int,int> M;

	vector<int> arr(n);
	for(int i = 0; i<n; i++){
		cin>>arr[i];
		M[arr[i]]++;
	}

	// map<int,int> MC;
	vector<int> cnt(n+1);

	cnt[0] = 0;

	debug(M);
	for(auto v : M){
		cnt[v.second]++;
	}

	// for(int i = 1; i<=n; i++){
	// 	cnt[i] += cnt[i-1];
	// }

	// int tsum = 0;
	// for(int i = 0; i<=n; i++){
	// 	tsum += cnt[i];
	// }


	// M.clear();
	map<int,int> Mc;

	fenwick tree(n+2);
	for(int i = 1; i<=n; i++){
		tree.update(i+1, cnt[i]);
	}

	int ans = 0;

	debug(cnt);
	int ind = 0;

	// for(int j = 1; j<=n; j++){
	// 		cout << tree.query(j,j) << ' ';
	// }
	// cout << '\n';

	// while(cnt[ind] == 0){
	// 	ind++;
	// }


	for(int i = n-1; i>=0; i--){

		Mc[arr[i]]++;
		M[arr[i]]--;
		int x = Mc[arr[i]];
		int f = 0;

		f += tree.query(1, x); // - tree.query(min(x-1, ind-1));
		debug(arr[i], x, f);

		ans += min(f, n - i - 1);
		// ans += f;

		// if(M[arr[i]] - Mc[arr[i]] != 0)
		// 	tree.update(min(M[arr[i]] - Mc[arr[i]] + 1ll, Mc[arr[i]] + 1ll), 1);
		tree.update(M[arr[i]] + 1, -1);
		// for(int j = 1; j<=n; j++){
		// 	cout << tree.query(j, j) << ' ';
		// }
		// cout << '\n';

		// M[arr[i]]--;

	}

	debug(Mc);
	for(auto v : Mc){
		// ans += (v.second - 1 * (v.second - 2))/2;

	}

	cout << ans << '\n';




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