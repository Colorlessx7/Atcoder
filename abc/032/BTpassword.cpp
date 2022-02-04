#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
int main(){
    string s;
    int k;
    cin >> s >> k;
    if(s.size() < k){
        cout << 0 << endl;
        return 0;
    }
    int x;
    if(s.size() % k != 0){
        x = s.size() % k;
        rep(i,x + 1){
            s.pop_back();
        }
    }
    int N = s.size() / k;
    vector<string> Z(N);
    rep(i,N) {
        rep(j,k){
           Z.at(i) += s.at(2 * i + j); 
        }
    }
    set<string> z;
    rep(i,N){
        s.insert(Z.at(i));
    }
    int ans = 0;
    for(int i = 1; i < N; i++){
        if(Z.at(i-1) != Z.at(i)){
            ans++;
        }
    }
    return 0;
}
