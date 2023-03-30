#include "bits/stdc++.h"
using namespace std;
#define ll long long
const char nl='\n';
double const pi= 3.141592653;
int dx[] = { 0, 0, -1, -1, -1, 1, 1, 1 };
int dy[] = { -1, 1, 0, -1, 1, -1, 1, 0 };
ll MOD=1e9+7;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        int a[n+1],last[n+1];
        for (int i =1; i <=n; ++i) {
            cin>>a[i];
            last[a[i]]=i;
        }
        int ind=n;
        for (int i = n-1; i >0 ; --i) {
            if(a[i]<=a[i+1])
                ind=i;
            else
                break;
        }
        for (int i = 1; i <ind ; ++i) {
            if(last[a[i]]>=ind){
                ind=last[a[i]];
            }
        }
        set<int>s;
        for (int i = 1; i <ind ; ++i) {
            s.insert(a[i]);
        }
        cout<<s.size()<<nl;
    }
}