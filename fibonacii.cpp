#include <bits/stdc++.h>

using namespace std;

int fibonacci(int n){
    if(n<=1){
        return n;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}

int main(){
    int i,n,t1=0,t2=1,n1;
    cout << "fibonacci seriec in non-recursion: "<< endl;
    cout << "ENter any number: ";
    cin >> n;
    for(int i=0;i<=n;i++){
        cout << t1 << " ";
        n1=t1+t2;
        t1=t2;
        t2=n1;
    } 

    cout << "using recursion" << endl;
    cout << "enter number: " ;
    int p;
    cin >> p;
    cout << fibonacci(p);

}