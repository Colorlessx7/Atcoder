#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = n - 1; i >= 0; i--)
#define rep4(i,N) for(int i = n; i > 0; i--)
#define all(x) x.begin(),x.end() 
typedef long long ll;
using P = pair<int,int>;
int main(){
    int n;
    string s;
    cin >> n >> s;
    vector<int> ansl;
    ansl.push_back(n);
    vector<int> ansr;
    rep3(i,n){
        if(s[i] == 'L'){
            ansl.push_back(i);
        }
    }
    rep(i,n){
        if(s[i] == 'R'){
            ansr.push_back(i);
        }
    }
    ansr.insert(ansr.end(),all(ansl));
    rep(i,n + 1){
        cout << ansr[i] << " ";
    }
    cout << endl;
    return 0;
}
//考察解 後ろから考えると
//0indexで左から数えた時のRが登場する箇所の添字が順番に並んだ後nがあり
//その後右から左に0indexで数えた時Lが登場する箇所の添字が順番に並ぶ形が答えとなる
