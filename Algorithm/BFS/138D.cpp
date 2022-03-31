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
    ll n, q;
    cin >> n >> q;
    //無向グラフ
    vector<vector<ll>> g(n);
    rep(i,n-1){
        ll a, b;
        cin >> a >> b;
        //0indexed調整
        a--; b--;
        //辺の接続
        g[a].push_back(b);
        g[b].push_back(a);
    }
    //最終的に部分木の全ての頂点にたされる数字とその範囲(部分木の根)を管理するmap
    map<ll,ll> plus;
    rep(i,q){
        ll p, x;
        cin >> p >> x;
        //0indexed調整
        p--;
        //mapの更新(部分木の根の場所(key)に部分木全部に足す値valueを足す)
        plus[p] += x;
    }
    //全頂点と最終的なカウンタの値を格納
    vector<ll> ans(n);
    //bfs用のqueue
    queue<P> qq;
    //頂点一から何回でその頂点に到達できるか(今回はその頂点を辿ったかの確認用)
    vector<ll> dist(n,-1);
    //bfsの初期設定(頂点1,頂点1からの部分木全てに足し合わせる値)
    P f = make_pair(0,plus[0]);
    qq.push(f);
    //頂点1には最初からいるので0初期化
    dist[0] = 0;
    //bfs処理部分
    while(qq.size()){
        //queueの先頭を入手しqueueから削除
        P v = qq.front();
        qq.pop();
        //各頂点の最終的なカウンタの値の更新部分
        ans[v.first] = v.second;
        //今いる頂点を根としたときに1回で行ける頂点について処理
        for(ll u : g[v.first]){
            //すでに到達済み(その頂点から見て根の頂点)はスルー
            if(dist[u] != -1){
                continue;
            }
            //根から1回で辿り着ける頂点なので距離を+1更新
            dist[u] = dist[v.first] + 1;
            ll x2 = u;
            //uを根とした部分木全てにxを足せというクエリが来ていたら
            //それをこれまでの部分木全てに足し合わせる値に足す
            ll y2 = v.second + plus[u];
            //queueに次の頂点uとuから部分木全てに足し合わせる値をpush
            f = make_pair(x2,y2);
            qq.push(f);
        }
    }
    //頂点全てのカウンタを出力
    rep(i,n){
        cout << ans[i] << endl;
    }
    return 0;
}
//BFS mapでxが足される部分木の根とその点数を格納し続け
//最後にbfsを使ってqueueで点数を配り続けるイメージ
