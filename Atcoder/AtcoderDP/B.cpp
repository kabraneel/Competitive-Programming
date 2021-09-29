#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pi;

#define PB push_back
#define MP make_pair

typedef long long ll;

#define FOR(i,a,b) for(int i=a; i<b; i++)

int maxn = 1e5 + 5;

vi arr(maxn);


int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t=1;

  while(t--){
    int n,k;
    cin>>n>>k;

    vi h(n);
    FOR(i,0,n){
      cin>>h[i];
    }

    vector<long long int> arr(n);
    arr[0] = 0;

    FOR(i,1,n){
      int men = INT_MAX;
      FOR(j,1,k+1){
        if(i>=j){
          int temp = arr[i-j] + abs(h[i]-h[i-j]);
          if(temp<men){
            men = temp;
          }
        }
     }
     arr[i] = men;
   }

   cout<<arr[n-1]<<"\n";
  }
  return 0;
}
