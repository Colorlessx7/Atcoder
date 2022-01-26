#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0; i<N; i++)
int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i,N){
        cin >> a.at(i);
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    if(a.size() % 2 != 0){
        a.push_back(0);
    }
    int x = a.size() / 2;
    vector<int> A(x);
    vector<int> B(x);
    rep(i,x){
        A.at(i) = a.at(i * 2);
    }
    rep(i,x){
        B.at(i) = a.at(i * 2 + 1);
    }
    int Alice = 0;
    int Bob = 0;
    rep(i,x){
        Alice += A.at(i);
    }
    rep(i,x){
        Bob += B.at(i);
    }
    cout << Alice - Bob << endl;
}
