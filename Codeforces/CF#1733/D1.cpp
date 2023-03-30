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
	int n; cin>>n;
	int x; int y;
	cin>>x>>y;
	string a; string b;
	cin>>a>>b;

	vector<int> pos;
	for(int i = 0; i<n; i++){
		if(a[i] != b[i]){
			pos.PB(i);
		}
	}

	if(sz(pos) % 2 != 0){
		cout<<"-1\n";
		return;
	}

	debug(pos);

	if(sz(pos) != 2){
		cout << sz(pos)/2 * y << '\n';
	}

	else{
		if(pos[0] == pos[1] - 1){
			cout<< min (2 * y, x) << '\n';
		}
		else{
			cout << y << '\n';
		}
	}

	
	/*
		// <client1>
		// 	<name> Neel Kabra </name>
		// 	<img> jakfsjkf </img>
		// 	<ip> 10.1.1.1 </ip>
		// 	<port> 69 </port>
		// 	<userID> 1 </userID>
		// </client1> 
	*/

	/*
https://www.overleaf.com/articles/kumar-sauravs-resume/jkfhfqvhckms
08049779944

	*/
	
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