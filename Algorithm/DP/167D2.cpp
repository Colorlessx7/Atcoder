#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(ll i = 0; i < N; i++)
#define rep2(i,N) for(ll i = 1; i <= N; i++)
#define rep3(i,N) for(ll i = N - 1; i >= 0; i--)
#define rep4(i,N) for(ll i = N; i > 0; i--)
#define replr(i,l,r) for(ll i = l; i < r; i++)
#define reprl(i,l,r) for(ll i = l; i > r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
typedef long long ll;
using P = pair<ll,ll>;
int main(){
    int n; ll k;
    cin >> n >> k;
    const int D = 60;
    const int MAX_N = 200005;
    //to[i][j]はjから2^i個移動した先の頂点
    vector<vector<int>> to(D,vector<int>(MAX_N));
    rep(i,n){
        cin >> to[0][i];
        to[0][i]--;
    } 
    rep(i,D-1){
        rep(j,n){
            to[i+1][j] = to[i][to[i][j]];
        }
    }
    //最初の頂点
    int v = 0;
    //上の桁2^59から見る
    for(ll i = D-1; i >= 0; --i){
        //longlongでキャストしないといけない
        ll l = 1ll << i;
        //lがk以下ならl個先を見れる
        if(l <= k){
            //l個先を辿る
            v = to[i][v];
            //移動回数をlこ減らす
            k -= l;
        }
    }
    //0indexだったので+1
    cout << v+1 << endl;
    return 0;
}
//DPのダブリングを用いた解
//例として下のように上の段の頂点から下の段の頂点に移動するとした場合
//123456
//652432
//DP ダブリングは
//   123456
//1  652432
//2  235425
//4  352432
//8 
//という感じでto[i+1][j] = to[i][to[i][j]]つまり
//頂点番号iから２倍進む動作はひとつ前の段(1倍)の結果を頂点番号としてみて
//ひとつ前のその頂点番号のdpの結果が最終的な移動先になる
//これでk個先を見る
//ダブリングはあくまで最初の頂点の時点で2^i回遷移した時に到達する頂点の集合なので
//問題なく解くことができる
