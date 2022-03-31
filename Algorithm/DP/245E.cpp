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
using mint = modint998244353;
int main(){
    int n, m, K, s, t, x;
    cin >> n >> m >> K >> s >> t >> x;
    //グラフの頂点に関係するのは0indexedで持つために-1処理
    s--; x--; t--;
    vector<vector<int>> g(n);
    rep(i,m){
        int a, b;
        cin >> a >> b;
        //グラフの頂点に関係するのは0indexedで持つために-1処理
        a--; b--;
        //無向グラフの辺の接続
        g[a].push_back(b);
        g[b].push_back(a);
    }
    //dp[k][v][i]=k歩進んで頂点vにいる,xを通った回数%2=iの場合の数
    vector<vector<vector<mint>>> dp(2005,vector<vector<mint>>(2005,vector<mint>(2)));
    //dpの初期化 最初sにいて、1歩も進んでいなくそのため一回もxを通ってないため偶数0で
    //そこが最初の枝分かれの根になるため1
    dp[0][s][0] = 1;
    //dpの更新処理部
    //歩数の全段階について
    rep(k,K){
        //一歩ごとの全頂点について
        rep(v,n){
            //パスごとのxを通った回数の偶奇について
            rep(i,2){
                //頂点vから行ける全頂点を探索
                for(int u : g[v]){
                    //nk:歩数の段階 次の歩数での状態を現在の歩数の情報で更新するためk+1
                    //nv:現在の頂点から一歩で向かう次の頂点を提示、よってu
                    //ni:現在の状態から一歩先の状態に遷移する過程での偶奇、基本そのまま
                    int nk = k + 1, nv = u, ni = i;
                    //もし次の頂点がxなら偶奇を変更
                    if(u == x){
                        //偶数:0,奇数1なのでxorで反転できる
                        ni ^= 1;
                    }
                    //dpの更新処理
                    //複数の遷移元から同じ条件で遷移できるものを足し合わせる形
                    dp[nk][nv][ni] += dp[k][v][i];
                }
            }
        }
    }
    //K歩進んで頂点tにいる、xの到達回数の偶奇が偶数の組み合わせの総数をansに
    mint ans = dp[K][t][0];
    cout << ans.val() << endl;
    return 0;
}
//三次元dpで解く問題
//dp[k][v][i]=k歩進んで頂点vにいる,xを通った回数%2=iの場合の数
