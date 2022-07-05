#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
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
int main(){
  //n:ステージ数,x:必要なステージクリア数
  ll n, x;
  cin >> n >> x;
  //a[i]:ステージiの初回のクリアのみにかかる時間
  //b[i]:ステージiのクリアにかかる時間
  vector<int> a(n),b(n);
  rep(i,n){
    cin >> a[i] >> b[i];
  }
  //minを取るため最大初期化
  ll ans = LLONG_MAX;
  //s:ステージrまで1回ずつクリアした時の総経過時間
  //l:ステージrまでの最小のbの値
  ll s = 0, l = 1e18;
  //全ステージについて回す
  rep(r,n){
    //ステージrの最初のクリアまでの経過時間a[r]+b[r]をsに加算
    s += a[r] + b[r];
    //今までクリアしたステージで周回に向いてるステージ(時間がかからない)のbをlとする
    l = min<ll>(l,b[r]);
    //初回クリアしたステージの個数だけで必要なステージクリア数を超えたら
    //クリアしたステージ数が増える以降も必要なステージクリア数を超えてしまうのでループを終了する
    //(rが0indexedなので+1して1indexedにしている)
    if(x < r+1){
      break;
    }
    //now:min(b[0]~b[r])のステージを周回してx回ステージをクリアした時のかかる時間
    //s:初回クリアのコスト,l:min(b[0]~b[r]),
    //x-r-1:b[?]=lのステージでの残りの周回数(rが0indexedなので-1して1indexedにしている)
    ll now = s + l*(x-r-1);
    //nowの最小をansに格納
    chmin(ans,now);
  }
  cout << ans << endl;
  return 0;
}
//貪欲法
//ステージr(0~n-1)までを一旦初回クリアしてから
//クリアしたステージの中から最も効率のいいステージで周回することで
//かかる時間の最小を答えとする(一旦初回クリアする範囲について0~n-1の全探索をする)
