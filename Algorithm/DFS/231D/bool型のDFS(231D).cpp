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
//返り値がboolのdfs(v:現在いる頂点,par:一つ前の頂点(戻らないように))
//(visited:すでに到達したか格納するbool配列visitを参照渡し)
//(adj:グラフの辺に関係する2次元配列、(i,j)とした時に頂点iが頂点jと辺で繋がっている)
bool dfs(int v, int par, vector<bool>& visited, vector<ll> adj[]){
    //グラフの頂点vに到達したのでvisit配列のv番目のフラグを立てる
    visited[v] = 1;
    //到達した頂点から辺で繋がっている各頂点を探索
    for(int u : adj[v]){
        //u-vを入力する過程でadj配列のu番目に頂点vが
        //adj配列のv番目に頂点uが登録されていてuからvに移った後
        //vからuに戻ってはいけないため一つ前の頂点をparに格納して
        //今の頂点から次の頂点にいく過程で戻らないようにしている
        if(u == par){
            continue;
        }
        //実質的なベースケース
        //uから辺で繋がっている頂点vのどれかにすでに到達したものがある場合
        //サイクルが存在していることになるので
        //このbool関数から再帰元にtrueを返し続ける
        if(visited[u]){
            return 1;
        }
        //まだ頂点vから行ける頂点adj[v]の中のuがあり
        //それまでにサイクルを発見できていないならdfsで再帰先に飛ぶ
        //最終的にベースケースを通ったらこのif分岐を通り1が再帰元に返され続ける
        //u:次いく頂点,v:次に行く前(今)の頂点,visited:到達したかのbool配列:
        //adj:頂点i,辺で繋がっている各頂点jの二次元配列
        if(dfs(u,v,visited,adj)){
            return 1;
        }
    }
    //頂点vから行ける頂点adj[v]の中のuがもう存在しなく、ベースケースを
    //通らなかった場合最終的に範囲for文を抜けてここから0が再帰元に返され続ける
    return 0;
}
int main(){
    ll n, m;
    cin >> n >> m;
    //グラフの辺の接続に関する2次元配列(i,j)とすると頂点iに対し
    //辺で繋がっている頂点がjとなる
    //iは0~n-1のn個,jは辺の個数個となる(辺が存在しない場合もある)
    vector<ll> adj[n];
    rep(i,m){
        ll u, v;
        cin >> u >> v;
        //0indexで扱いたいので-1
        u--; v--;
        //i番目の辺の接続がu-vなので
        //u番目の配列にvをpush,v番目の配列にuをpush
        //これで頂点uからvが、頂点vからuがつながったことになる
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //このグラフがパスの集合なら1,違う(サイクルありor3以上の次数が存在)なら0
    bool flag = 1;
    //グラフの頂点の次数(辺が頂点から何本別の頂点に繋がっているか)が3以上なら
    //パスの集合(一直線のグラフと繋がっていないグラフの集合体)ではないのでflagを0に
    rep(i,n){
        if(adj[i].size() > 2){
            flag = 0;
        }
    }
    //dfsをする過程でその頂点にすでに訪れているかを判定するbool配列
    vector<bool> visit(n,0);
    //サイクルの有無の判定
    //全頂点についてdfsを用いて調べる
    //(頂点のグループ(辺に繋がれている頂点の塊)が複数あるので片方にサイクルがなくても
    //もう片方にサイクルがあったりするから)
    rep(i,n){
        //その頂点iに訪れていない状態でdfsしてサイクルがあったならflagを0に
        //訪れていないことを確認しないとサイクルがなかったグループをもう一回
        //調べてサイクルがあったことにしてしまうため
        if(!visit[i]){
            if(dfs(i,0,visit,adj)){
                flag = 0;
            }
        }
    }
    //flagが1ならYes,0ならNo
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}
//DFS解
//グラフの問題 パスの集合かどうかを判定 パス:一直線のグラフ
//パスグラフの特徴は次数が2以下であることと 次数:辺の数
//サイクルがないこと サイクル:グラフがループ構造になっている状態
//サイクルがないグラフは木とも呼ばれる
//
