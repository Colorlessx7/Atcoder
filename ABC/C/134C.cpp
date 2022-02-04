#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
    }
    vector<int> b(n);
    rep(i,n){
        b[i] = a[i];
    }
    sort(b.begin(),b.end());
    int max = b[n - 1];
    int sec = b[n - 2];
    bool check = 0;
    if(max == sec){
        check = 1;
    }
    rep(i,n){
        if(check){
            cout << max << endl;
        }else if(a[i] == max){
            cout << sec << endl;
        }else {
            cout << max << endl;
        }
    }
    return 0;
}
