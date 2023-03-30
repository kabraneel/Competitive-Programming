// na ho paega humse
// nai_aati_coding
// i love PD
// Motivation when feeling low : http://bitly.com/98K8eH
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

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

void solve(){
	int n; int x; int y;
	cin>>n>>x>>y;

	if(x == 0 && y == 0){
		cout << "-1\n";
		return; 
	}


	if( y < x){
		swap(x, y);
	}	

	if(x != 0){
		cout << "-1\n";
		return;
	}

	if( (n - 1) % y == 0){
		int ans = 1;

		for(int i = 0; i<n-1; i+=y){
			int count = 1;
			for(int i = 0; i<y; i++){
				cout << ans << ' ';
				count ++;
			}
			if(i == 0)
				ans += count;
			else 
				ans += count -1 ;
		}
		cout << '\n';
		return;
	}

	cout << "-1\n";




	// int t1 = (n - 1) - n * x;
	// if((t1 + y - x) % (y - x) != 0){
	// 	cout << "-1\n";
	// 	return;
	// }

	// debug(n, (t1 + y - x) / (y - x));

	// int t2 = (n - 1) - n * y;
	// if((t2 + x - y) % (x - y) != 0){
	// 	cout << "-1\n";
	// 	return;
	// }

	// debug( (t2 + x - y) / (x - y) );
	// cout<<"1\n";



}

signed main(){

	#ifdef KABRANEEL
	freopen("/home/kabraneel/coding/Contests/inputfa.txt", "r", stdin);
	freopen("/home/kabraneel/coding/Contests/outputfa.txt", "w", stdout);
	freopen("/home/kabraneel/coding/Contests/error.txt","w",stderr);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	auto start = chrono::high_resolution_clock::now();

	int t=1;
	int zcount = 1;
	cin>>t;

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