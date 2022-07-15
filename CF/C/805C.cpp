#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = N - 1; i >= 0; i--)
#define rep4(i,N) for(int i = N; i > 0; i--)
#define replr(i,l,r) for(int i = l; i < r; i++)
#define reprl(i,l,r) for(int i = l; i >= r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
using ll = long long;
using P = pair<int,int>;
using TP = tuple<int,int,int>;
void chmin(int &x, int y){ x = min(x,y); }
void chmax(int &x, int y){ x = max(x,y); }
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
void solve(){
  //n:駅の要素数,k:クエリtiの中のクエリ数
  int n, k;
  cin >> n >> k;
  //key:駅の数字u,value:fi=駅keyが最初に登場するindex,se=駅keyが最後に登場するindex
  map<int,P> mp;
  //全駅の番号について処理
  //O(N),全体でO(NlogN) (mapのinsertにlogN)
  rep(i,n){
    //u:i番目の駅の数字
    int u;
    cin >> u;
    //mapのkeyがuの要素がmap内に存在しないなら処理(初登場)
    if(!mp.count(u)){
      //駅uが最初に登場するindexとしてmp[u].firstにindexのiを格納
      mp[u].first = i;
      //駅uが最後に登場するindexとしてmp[u].secondにindexのiを格納
      //(以降またuが登場する場合はここを更新していく)
      mp[u].second = i;
    }else {
      //1回以上数字uが登場しているなら処理
      //駅uが最後に登場するindexとしてmp[u].secondにindexのiを格納
      mp[u].second = i;
    }
  }
  //クエリ処理
  //O(k),全体でO(NlogN)
  rep(i,k){
    //a:駅の始点、b:駅の終点
    int a, b;
    cin >> a >> b;
    //左二つで駅の番号a,bがそもそも駅の要素u0~un-1の存在するかを判定している O(logN)
    //(map内にkeyがa,bの数字のものが存在しないならtrue)
    //(左側に書くことでa,bが存在しない場合のmapアクセス時の未定義動作を回避する)
    //右の条件文で数字aの駅が最初に存在するindexと、数字bの駅が最後に存在するindexを
    //比較し、bの最後のindexよりもaの最初のindexが大きい場合...b..a..という順番になり
    //aからbに順に辿って到達できないのでNoを出力させるために条件式の結果をtrueにする
    if(!mp.count(a) || !mp.count(b) || mp[a].first > mp[b].second){
      //上の条件を満たす場合aからbに到達不可
      cout << "No" << '\n';
    }else {
      //上の条件を満たさない場合aからbに到達可
      cout << "Yes" << '\n';
    }
  }
}
int main(){
  int t;
  cin >> t;
  rep(i,t) solve();
  return 0;
}
