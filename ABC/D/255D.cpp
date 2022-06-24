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
using TP = tuple<ll,ll,ll>;
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
int main(){
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  rep(i,n){
    cin >> a[i];
  }
  //二分探索でai>=xとai<xの境目を見つけるためにsortする
  sort(all(a));
  //累積和配列
  vector<ll> s(n+1);
  //累積和の設定s[i]:i項目までの合計
  rep(i,n){
    s[i+1] = s[i] + a[i];
  }
  //クエリ処理
  rep(_,q){
    //x:全てのaの操作目標(aiをxに)
    int x;
    cin >> x;
    //k:二分探索により求めた境目(a配列の初めてx以上の値になる添字を返す)
    //(このkはa配列とs配列で指す場所がずれる(skはa配列でaiがx未満の項の和を示す))
    int k = lower_bound(all(a),x) - a.begin();
    //操作の回数の合計 = 操作後の和kx - ai<xの範囲の和
    //k*x:aiがx未満の項を全てxに操作で変更した時の変更後の項の和
    //s[k]:k項目までの和(aiがx未満の項の和)
    ll ans = (ll)k*x - s[k];
    //操作の回数の合計 = ai>=xの範囲の和 - 操作後の和(n-k)x
    //s[n]-s[k]:a配列のx以上の項の和
    //(n-k)x:aiがx以上の項を全てxに操作で変更した時の変更後の項の和
    ans += (s[n] - s[k]) - ll(n-k)*x;
    printf("%lld\n",ans);
  }
  return 0;
}
//Sum(0~n-1)(|ai-x|)を求める問題
//絶対値の記号がかかっていないなら合計を予め求めてからsum-kxで求まるが、
//絶対値があるためその方法ではできない
//|ai-x|はai>=xの時ai-xで、ai<xの時x-aiとなる
//またこの問題では配列aの順番が関係ないのでsortしてどこまでがai>=xで、
//どこからがai<xなのかを調べるための二分探索に使用する
//
