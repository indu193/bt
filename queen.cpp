#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>>&b){
  int n=b.size();
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(b[i][j])
         cout << "Q ";
      else{
        cout << ". ";
      }
    }
    cout << endl;
  }
}

bool issafe(vector<vector<int>>&b, int row, int col){
  int n=b.size();
  int i,j;
  
  for(int i=0;i<n;i++){
    if(b[row][i]){
      return false;
    }
    
  }
  for(int i=row,j=col; i>=0 && j>=0 ; i--,j-- ){
    if(b[i][j]){
      return false;
    }
  }
  for(int i=row, j=col; i<n&&j>=0; i++,j--){
    if(b[i][j]){
      return false;
    }
  }
  
  return true;
}



bool solve(vector<vector<int>>&b, int col){
  int n=b.size();
  if(col>=n){
    return true;
  }
  
  for(int i=0;i<n;i++){
    if(issafe(b,i,col)){
      b[i][col]=1;
      if(solve(b,col+1)){
        return true;
      }
      
      b[i][col]=0;
    }
  }
  return false;
  
  
}



bool solvenQ(int n){
  vector<vector<int>>b(n,vector<int>(n,0));
  
  if(solve(b,0)==false){
    cout << "Eror"<< endl;
    return false;
  }
  print(b);
  return true;
}

int main(){
  int n;
  cin >>n;
  solvenQ(n);
}