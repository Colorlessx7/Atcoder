#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(ll i = 0; i < N; i++)
#define rep2(i,N) for(ll i = 1; i <= N; i++)
#define rep3(i,N) for(ll i = N - 1; i >= 0; i--)
#define rep4(i,N) for(ll i = N; i > 0; i--)
#define replr(i,l,r) for(ll i = l; i < r; i++)
#define reprl(i,l,r) for(ll i = l; i >= r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
using ll = long long;
using P = pair<ll,ll>;
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
int main(){
  ll n;
  cin >> n;
  //key:数字について,value:none[i]でsのi文字目にkeyの数字が来た回数
  //(二次元vectorでいい気がする)
  map<ll,vector<ll>> mp;
  //mapのvalueのvectorの初期化
  rep(i,10){
    mp[i].resize(10);
  }
  //全リールの情報の入力
  rep(i,n){
    string s;
    cin >> s;
    //sの全文字について回す
    rep(j,10){
      //x:リールiのj番目の数字
      ll x = s[j] - '0';
      //xがsのj文字目に来たので個数のカウンタに加算
      mp[x][j]++;
    }
  }
  //全てのリールを止めた上で、表示されている文字が全て同じになるように
  //全てのリールを止めるまでに、スロットが回り始めてから最小で何秒かかるか
  //minを取るので大きい値で初期化
  const ll INF = 1001001001;
  ll ans = INF;
  //文字0~9について回す(表示される文字をiのみにすると仮定する)
  rep(i,10){
    //全てiにするのに最小で何秒かかるか
    ll num = 0;
    //何個目のリールが全てをiで止める過程で最後になるか(最大かつ一番右が欲しい)
    //value:1周期上で同じ秒数にiが固まっている個数の最大値(多いほど10秒追加で待つ必要がある)
    ll value = 0;
    //right:何個目のリールが全てをiで止める過程で最後になるか
    ll right = 0;
    //リールの1周期の秒数0~9について回す
    rep(j,10){
      //1周期上で同じ秒数にiが固まっている個数の最大値がリールの別の秒の方が多い場合
      //10秒待つ回数が多くなり、かかる時間が多くなるのでその秒と待つ回数の情報を採用
      if(mp[i][j] > value){
        //1周期上で同じ秒数にiが固まっている個数の最大値を更新
        value = mp[i][j];
        //何個目のリールが全てをiで止める過程で最後になるかを更新
        right = j;
        //秒jで待つ回数が同じなら処理
      }else if(mp[i][j] == value){
        //待つ回数が同じでも1周期上のリールをiで止められる時間が長いなら
        //かかる時間が多くなるのでその秒の情報を採用
        if(right < j){
          //何個目のリールが全てをiで止める過程で最後になるかを更新
          right = j;
        }
      }
    }
    //全てのリールをiで止めた時にかかる時間を計算
    //数字iが5つのリールで0秒のところに固まっている場合
    //0-10-20-30-40というふうに10秒ずつ待つ必要がある
    //最初だけは待つ必要がないので待つ回数はvalue-1になり、
    //*10したものに最後の1周期でリールを押すのにかかる時間rightを足したものがかかる時間となる
    num = (value-1)*10+right;
    //数字iで止めた時のかかる時間が最小ならansを更新
    chmin(ans,num);
  }
  cout << ans << endl;
  return 0;
}
//一つ条件としてリールは1秒にどれか一つしか止められない
//同じ秒に同じ数字が固まっていると1周期待たないといけない
