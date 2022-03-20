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
const int INF = 1001001001;
//DFS 一度辿った頂点に到達するまで(oかσみたいなグラフを1周するイメージ)
void dfs(int i,ll &cnt,ll &cnt2,vector<ll> &a,vector<int> &ans,vector<bool> &visit,vector<int> &visit2){
    //ベースケース すでに到達している頂点なら終了
    if(visit[i]){
        //閉区間の移動数を導出
        cnt2 = cnt - visit2[i];
        return;
    }
    //到達したのでtrueに
    visit[i] = true;
    //到達してない頂点に到達したので到達するまでにかかる移動数cntを格納
    if(visit2[i] == INF){
        visit2[i] = cnt;
    }
    //高橋が通る頂点なのでpush
    ans.push_back(i+1);
    //次の頂点に移動するので移動数を+1
    cnt++;
    //次の頂点に移動
    dfs(a[i],cnt,cnt2,a,ans,visit,visit2);
    //ベースケースを潜った後はここから再帰元に戻り続ける
    return;
}
int main(){
    ll n, k;
    cin >> n >> k;
    //有向グラフ
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
        //頂点を0indexに修正
        a[i]--;
    }
    //最初の頂点から閉区間の付け根までの移動数(dfs時は途中の移動数として機能)
    ll cnt = 0;
    //閉区間内の移動数
    ll cnt2 = 0;
    //その頂点に到達したかのbool配列
    vector<bool> visit(n);
    //最初の頂点から何回移動すれば初めてその頂点に辿り着けるかを格納
    vector<int> visit2(n,INF);
    //最終的に高橋が通る可能性のある頂点を列挙
    vector<int> ans;
    //頂点1からdfs開始
    dfs(0,cnt,cnt2,a,ans,visit,visit2);
    //ここから場合分け
    //最初の頂点からの閉区間のようなグラフだった場合(oのような)
    if(cnt2 == cnt){
        //何周もさせるのは無駄なのであまりをとる
        k %= cnt;
        //k番目を出力
        cout << ans[k] << endl;
        return 0;
    }
    //少し移動したら閉区間が始まるグラフの場合(σのような)
    if(k <= cnt - cnt2){
        //閉区間より前の場合は単純にk番目を出力
        cout << ans[k] << endl;
    }else {
        //閉区間内まで移動する場合閉区間で考えるために閉区間でない部分をまず引く
        k -= cnt - cnt2;
        int y = cnt - cnt2;
        k %= cnt2;
        //閉区間のスタート部分から最後の1周未満の移動分を+した移動先を出力
        cout << ans[y+k] << endl;
    }
    return 0;
}
//DFS解
