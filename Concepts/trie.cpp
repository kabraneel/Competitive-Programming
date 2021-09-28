// QUESTION LINK : https://leetcode.com/problems/longest-word-in-dictionary
string ans = "";

void dfs(int i, string tillnow, vector<vector<int>>& nodes, vector<bool>& isterminal){

  if(tillnow.length() > ans.length()){
    ans = tillnow;
  }

  for(int j = 0; j<26; j++){
    if(nodes[i][j] && isterminal[i][j]){
      dfs(nodes[i][j], tillnow + (a + 'c', nodes, isterminal));
    }
  }

}

void solve(){
    vector<vector<int>> nodes(1, vector<int> (26));
    vector<bool> isterminal(1, false);

    int n; cin>>n;
    vector<string> words(n);

    FOR(i,0,n) cin>>words[i];
    int N = 0;


    for(auto v: words){
      int node = 0;
      for(auto u: v){
        if(nodes[node][u - 'a'] == 0){
          N++;
          nodes[node][u - 'a'] = N;
          nodes.PB(vector<int> (26));
          isterminal.PB(false);
        }
        node  = nodes[node][u-'a'];
      }
      isterminal[node] = true;
    }

    dfs(0, "", nodes, isterminal);
    cout<<ans<<'\n';

}
