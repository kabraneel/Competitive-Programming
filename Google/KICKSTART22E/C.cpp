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

bool check(string &s){
	string z = s;
	reverse(all(z));

	return z == s;
}

void computeLPSArray(string &str, int M, int lps[])
{
    // length of the previous longest prefix suffix
    int len = 0;
    int i;
  
    lps[0] = 0; // lps[0] is always 0
    i = 1;
  
    // the loop calculates lps[i] for i = 1 to M-1
    while (i < M) {
        if (str[i] == str[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            if (len != 0) {
                // This is tricky. Consider the example
                // AAACAAAA and i = 7.
                len = lps[len - 1];
  
                // Also, note that we do not increment i
                // here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
  
// Returns true if str is repetition of one of its
// substrings else return false.
int isRepeat(string &s)
{
    // Find length of string and create an array to
    // store lps values used in KMP
    int n = s.length();
    int lps[n];
  
    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(s, n, lps);

    for(int i = 0; i<n; i++){
    	cout<<lps[i] << ' ';
    }
  
    // Find length of longest suffix which is also
    // prefix of str.
    int len = lps[n - 1];
    return len;
  
}

string findSmallestUnit(string &str){
      vector<int> lps(str.length(),0);
      int i=1;
      int len=0;

      while(i<str.length()){
          if(str[i] == str[len]){
              len++;
              lps[i] = len;
              i++;
          }
          else{
              if(len == 0) i++;
              else{
                  len = lps[len-1];
              }
          }
      }
      int n=str.length();
      int x = lps[n-1];
      if(n%(n-x) == 0){
          return str.substr(0,n-x);    
      }
      return str;
 }

void solve(){
	int n; cin>>n;
	string s; cin>>s;
	// string temp = s;

	// /**/int x = isRepeat(s);
	// debug(x);

	string temp = findSmallestUnit(s);

	if(check(temp)){
		cout<<temp<<'\n';
		return;
	}

	cout<<s<<'\n';
	

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
		cout<<"Case #"<<zcount++<<": ";
	  solve();
	}

	auto end = chrono::high_resolution_clock::now();
	double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	time_taken *= 1e-9;

	cerr <<fixed<<time_taken<<setprecision(9)<< " sec"<<endl;
	return 0;
}