#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    ll n;
    cin >> n;
    set<ll> s;//2^4と4^2が一緒で重複するのでsetで処理
    //a^2 <= Nはa <= sqrt(N)になるからそこまでの範囲
    for(ll a = 2; a*a <= n; ++a){
        ll x = a * a;//a^2の処理 
        while(x <= n){
            s.insert(x);//a^bに置き換えれるものをsetに追加
            x *= a;//指数部の追加
        }
    }
    //setは除外するa^bに置き換えられるものが格納されているのでnから引く
    cout << n - s.size() << endl;
    return 0;
}
