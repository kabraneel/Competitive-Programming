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
