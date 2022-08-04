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

const int N = 15;
vector<string> S(N);
map<string,int> M;
vector<int> fans;
vector<int> ffans;
int n;

int findmin(string &s){

	// debug(s);
	if(s.length() == 0){
		if(sz(fans) < sz(ffans)){
			ffans = fans;
		}
		return 0;
	}

	if(M.find(s) != M.end()){
		if(sz(fans) < sz(ffans)){
			ffans = fans;
		}
		return M[s];
	}
	
	int minans = INF;

	for(int i = 0; i<n; i++){
		
		if( S[i].length() > s.length() ){
			continue;
		}

		bool pos = false;
		for(int j = 0; j<S[i].length(); j++){
			if(s[j] != S[i][j]){
				pos = true;
				break;
			}
		}
		
		if(pos){
			continue;
		}
		string temp = s;		
		for(int j = 0; j<S[i].size(); j++){
			temp.erase(0, 1);
			fans.PB(i);
			// debug(s, S[i], temp);
			minans = min(minans, 1 + findmin( temp ) );
			fans.pop_back();
		}



	}
	M[s] = minans;
	return minans;

}

void solve(){
	string s; cin>>s;
	cin>>n;
	ffans.clear();
	fans.clear();
	M.clear();
	for(int i = 0; i<=100; i++){
		ffans.PB(i);
	}
	for(int i = 0; i<n; i++){
		cin>>S[i];
	}
	// s = "a";

	int x = findmin(s);
	if(x == INF){
		cout<<"-1\n";
		return;
	}
	// if(sz(ffans) == 101){
	// 	cout<<"-1\n";
	// 	return;
	// }
	debug(ffans);
	cout<<ffans.size()<<'\n';
	cout<< ffans[0] + 1 << " " << 1 << '\n';
	int curr = S[ffans[0]].length();
	for(int i = 1 ; i<sz(ffans); i++){
		// curr +=  S[ffans[i-1]].length();
		for(int j = curr; j>=0; j--){
			bool pos = false;
			for(int k = j; k< j + S[ffans[i]].size(); k++){
				if(s[k] != S[ffans[i]][k-j]){
					pos = true;
					break;
				}
			}
			if(!pos){
				// debug(j);
				debug(j);
				curr = j + S[ffans[i]].length() ; 
				debug(curr);
				cout << ffans[i] + 1<< " " << j + 1<<'\n';
				break;
			}
		}

	}

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