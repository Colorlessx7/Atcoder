//参考文献:(リファレンス)https://cpprefjp.github.io/reference/deque/deque.html

//ABC237Dより

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
signed main(){
    ll n;
    string s;
    cin >> n >> s;
    //deque 最初にnを格納
    deque<ll> a = {n};
    //n-1~0の範囲でループ
    //処理は下2行で解説
    rep3(i,n){
        if(s[i] == 'L'){
            a.push_back(i);
        }else{
            a.push_front(i);
        }
    }
    rep(i,n + 1){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
//両端queue(deque)を使った解
//形は考察解と一緒
//0indexで左から数えた時のRが登場する箇所の添字が順番に並んだ後nがあり
//その後右から左に0indexで数えた時Lが登場する箇所の添字が順番に並ぶ形が答えとなる
