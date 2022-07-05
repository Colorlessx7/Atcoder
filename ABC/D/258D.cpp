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
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
int main(){
  ll n, x;
  cin >> n >> x;
  vector<ll> a(n),b(n);
  rep(i,n){
    cin >> a[i] >> b[i];
  }
  //minを取るため最大初期化(10^18だと計算過程で超えるものが出てきてバグる)
  ll ans = LLONG_MAX;
  //見ているステージまでを1回ずつクリアしていった時にかかる時間
  ll num = 0;
  //処理中のステージのクリア数
  int dx = 0;
  //各ステージについて回す
  rep(i,n){
    //最初にクリアしたので経過時間a,bの時間を加算
    num += a[i] + b[i];
    //num2:ステージiで合計x回周回した時の最終的にかかる経過時間(numで初期化)
    ll num2 = num;
    //ステージクリア回数をインクリメント
    dx++;
    //ステージクリア数がxを超過する場合以外はステージiを最終周回場所として処理
    if(dx <= x){
      //残りのステージクリア数x-dxに一回あたりの経過時間b[i]をかけたものをnum2に加算
      num2 += b[i] * (x - dx);
    }else {
      //ステージクリア数がxを超過した場合はあり得ないのでコンティニュー
      continue;
    }
    //x回ステージをクリアした時にかかる時間num2の最小をansに格納
    chmin(ans,num2);
  }
  cout << ans << endl;
  return 0;
}
//貪欲法
//1周にb[i]だけかかる所を最終ステージとして、周回場所(最終ステージ)n個についての全探索をしている
