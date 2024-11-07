#include <bits/stdc++.h>
using  namespace std;

int kanpsack(int w, vector<int>&we, vector<int>&pr, int n){
  vector<vector<int>>dp(n+1,vector<int>(w+1,0));
  
  for(int i=1;i<=n;i++){
    for(int j=0;j<=w;j++){
      if(we[i-1]<=j){
        dp[i][j] =max(dp[i-1][j], pr[i-1]+dp[i-1][j-we[i-1]]);
      }
      else{
        dp[i][j]= dp[i-1][j];
      }
    }
  }
  return dp[n][w];
}

int main(){
  int w,n;
  cin >> w >> n;
  vector<int>pr(n),we(n);
  for(int i=0;i<n;i++){
    cout << "item: " << i+1 << ": " ;
    cin >> pr[i];
    cin >> we[i];
  }
  
  int maxp=kanpsack(w,we,pr,n);
  cout << "result: " << maxp << endl;
  return 0;
}