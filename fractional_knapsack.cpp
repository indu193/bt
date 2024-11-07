#include <bits/stdc++.h>
using namespace std;

struct item{
  int profit, weight;
  item(int profit, int weight){
    this->profit=profit;
    this->weight=weight;
  }
};


static bool compare(struct item a, struct item b){
  double r1 = (double)a.profit/(double)a.weight;
  double r2=(double)b.profit/(double)b.weight;
  return r1>r2;
}

double fractionaknapsack(int w, vector<item>arr, int n){
  sort (arr.begin(), arr.end(), compare);
  
  double finalval =0.0;
  
  for(int i=0;i<n;i++){
    if(arr[i].weight<=w){
      w-=arr[i].weight;
      finalval+=arr[i].profit;
    }
    else {
      finalval+=arr[i].profit*((double)w/(double)arr[i].weight);
      break;
    }
  }
  return finalval;
}


int main(){
  int w,n;
  cout <<"enter max weight and of the knapsack: ";
  cin >>w;
  
  cout << "eeter nu of items: ";
  cin >> n;
  
  vector<item>arr;
  
  for(int i=0;i<n;i++){
    int pr, we;
    cout << "Ebter profu ad weight for item: "<< i+1 << ": " ;
    cin >> pr >> we;
    arr.push_back(item(pr,we));
  }
  
  cout << "max pr: " << fractionaknapsack(w,arr,n) << endl;
  return 0;
}