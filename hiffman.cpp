#include <bits/stdc++.h>
using namespace std;

struct Node{
    char data;
    int freq;
    Node *left, *right;
    Node(char data, int freq){
        left=right=NULL;
        this->data=data;
        this->freq=freq;
    }
    
};

struct compare{
    bool operator()(Node* l, Node*r){
        return (l->freq > r->freq);
    }
};

void printCodes(struct Node* root, string str){
    if(!root){
        return ;
    }
    
    if(root->data!='$'){
        cout << root->data << ": " << str << endl;
    }
    printCodes(root->left, str+"0");
    printCodes(root->right,str+"1");
}

void HuffmanCode(char data[], int freq[], int n){
    Node *left, *right, *top;
    
    priority_queue<Node*, vector<Node*>,compare>minheap;
    
    for(int i=0;i<n;i++){
        minheap.push(new Node(data[i], freq[i]));
    }
    
    while(minheap.size()!=1){
        left=minheap.top();
        minheap.pop();
        right=minheap.top();
        minheap.pop();
        
        top= new Node('$', left->freq+right->freq);
        
        top->left=left;
        top->right=right;
        
        minheap.push(top);
    }
    
    printCodes(minheap.top(), "");
}

int main(){
    int n;
    cin >> n;
    char arr[n];
    int freq[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
        cin >> freq[i];
    }
    
    HuffmanCode(arr,freq,n);
    return 0;
    
}





