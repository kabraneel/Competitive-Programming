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

// #define int long long
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
// const int INF = 1e18;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename num_t>
using ordered_set = tree<num_t, null_type,less_equal<num_t>, rb_tree_tag,   tree_order_statistics_node_update>;


void solve(){
	/*
		
		1 2 3
		3 2 1

		(i, j) -> inversion + number of pairs (j, k) which are inversions
		
		for every element j ==> find number of numbers on the right which are larger than arr[j]
								number of numbers on the left smaller than arr[j]


	*/

	int n;
	cin>>n;

	vector<int> arr(n);
	for(int i = 0; i<n; i++){
		cin>>arr[i];
	}	

	ordered_set<int> oset1;
	ordered_set<int> oset2;

	for(int i = n-1; i>=1; i--){
		oset2.insert(arr[i]);
	}

	// for(auto v : oset2){
	// 		cout << v << ' ';
	// 	}
	// 	cout << '\n';

	long long int ans = 0;
	for(int i = 1; i<n-1; i++){
		oset1.insert(-1 * arr[i-1]);

		// auto t1 = oset2.find(arr[i]);
		// debug(arr[i]);
		// if(t1 != oset2.end()){
		// 	oset2.erase(oset2.find(arr[i]));
		// }
		// else{
		// 	cout << "HERE\n";
		// }

		int rank = oset2.order_of_key(arr[i]);//Number of elements that are less than v in t
    	auto it = oset2.find_by_order(rank); //Iterator that points to the (rank+1)th element in t
    	oset2.erase(it);

		// 6 + 4
		// for(auto v : oset2){
		// 	cout << v << ' ';
		// }
		// cout << '\n';

		long long int x = oset1.order_of_key(-1*(arr[i]));
		long long int y = oset2.order_of_key(arr[i]);

		// debug(arr[i], x, y);
		ans += 1ll * x * y;

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