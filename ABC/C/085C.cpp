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
  ll n, y;
  cin >> n >> y;
  //取りうる値が1000の倍数しかないので1000で事前に割る
  y /= 1000;
  //10000yenと5000yenの枚数を決めた時の合計の値段
  ll num = 0;
  //最大がn枚なので10000yenの枚数を0~nで回す
  for(ll i = 0; i <= n; i++){
    //5000yenの枚数を10000yenの枚数と合わせてn枚になるまでの枚数で回す
    for(ll j = 0; i+j <= n; j++){
      //10000yenと5000yenの枚数を決めた時の合計の値段を計算
      num = 10 * i + 5 * j;
      //それがy円を超えたら1000yenの枚数がマイナスになるためbreak
      if(num > y){
        break;
      }
      //合計yから現在の値段numを引いたものが1000yenでのみ構成される残りの値段
      //事前に1000で割っているのでこれだけでy円を達成するのに必要な1000yenの枚数がわかる
      ll k = y - num;
      //10000*i+5000*j+1000*k=y,i+j+k=nの両方が満たされるなら
      //i,j,kが答えとなるのでそれを出力
      if(i + j + k == n){
        printf("%lld %lld %lld\n",i,j,k);
        return 0;
      }
    }
  }
  //10000*i+5000*j+1000*k=y,i+j+k=nを満たすものが存在しないなら
  //-1 -1 -1を出力
  printf("-1 -1 -1\n");
  return 0;
}
