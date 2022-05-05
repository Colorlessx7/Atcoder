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
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
  }
  //高いスコアを取るならa[i]の大きい順に到着させるのが最適解となるため降順sort
  sort(allr(a));
  //座る場所の候補と座った時のスコアについてのqueue
  queue<ll> q;
  //queueの初期状態(一番a[i]の高い人が1人だけ座っている状態)
  q.push(a[0]);
  //スコアの合計値
  ll ans = 0;
  //a[0]の人が既に座っている状態で、a[i]の値が2番目に高い人から順に処理
  replr(i,1,n){
    //queueの先頭が座れる場所かつ最大スコアなのでそれを答えに足す
    ans += q.front();
    //queueの先頭を取り出したのでpop
    q.pop();
    //i番目の人が座ったことでi番目の両端に座るスペースができたので
    //queueに2回a[i]をpush
    q.push(a[i]);
    q.push(a[i]);
  }
  cout << ans << endl;
  return 0;
}
//貪欲法をqueueを使って解いた解法
//最初の人だけ座っている状態で次の人が座ると隣接する人の数は1人のみ
//(座ったら隣接する人のスコアが入手できる場所が1つ増える)
//それ以降はずっと次の人が座ると隣接する人の数が2人の状態となる
//(座ったら隣接する人のスコア(小さい方)が入手できる場所が2つ増える)
//これをqueueでシミュレーションする
