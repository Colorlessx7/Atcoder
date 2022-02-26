#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = N - 1; i >= 0; i--)
#define rep4(i,N) for(int i = N; i > 0; i--)
#define all(x) x.begin(),x.end() 
typedef long long ll;
using P = pair<int,int>;
int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
    }
    ll ans = 0;
    ll x = 0;
    rep(i,n){
        x = a[i];
        for(int j = i; j < n; j++){
            x = min(x,a[j]);
            ans = max(ans,x*(j-i+1));
        }
    }
    cout << ans << endl;
    return 0;
}
//単純に2重ループを回す問題
//Nが10^2なので二重ループを回しても0(10^8)でギリ間に合う
//解法は、l,rを固定した場合xはその中で取りうる値の中で
//一番大きい値にすれば良い
//まずlを固定して、rを順に大きくしながら都度区間の最小値を更新し
//都度区間の最小値x * 区間の幅j-i+1を求め
//その最大値をansに格納し、出力すれば良い
