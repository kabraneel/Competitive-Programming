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

vector<int> arr1 = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
vector<int> arr;
void pre(){
	int ans = 1;
	int count = 2;

	while(1){
		ans = ans * count;
		if(ans > INF || ans < 0){
			break;
		}
		arr.PB(count);
		count++;
	}

}

void solve(){
	// debug(arr);

	int n; cin>>n;

	if(n%2 == 1){
		cout<<"2\n";
		return;		
	}

	// for(auto v: arr){
	for(int v = 2; v<10000; v++){
		if( (v * (v-1))/ 2 > n){
			continue;
		}
		if(v%2 == 1){
			if(n % v == 0){
				cout<<v<<"\n";
				return;
			}
		}
		else{
			if(n % v == v/2){
				cout<<v<<'\n';
				return;
			} 
		}
	}

	cout<<"-1\n";

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
	pre();
	int t=1;
	cin>>t;
	while(t--){
	  solve();
	}

	auto end = chrono::high_resolution_clock::now();
	double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	time_taken *= 1e-9;

	cerr <<fixed<<time_taken<<setprecision(9)<< " sec"<<endl;
	return 0;
}