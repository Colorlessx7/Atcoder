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
  ll a, b, x;
  cin >> a >> b >> x;
  //ans:買うことのできる最も大きい整数(maxを取るため0初期化)
  ll ans = 0;
  //取りうる桁数で全探索
  rep2(dn,19){
    //問題文よりa*n+b*d(n)<=xからa*n<=x-b*d(n)となる
    //(右辺がマイナスになった時がわからないので0とのmaxをとる)
    ll an = max(x-b*dn,0LL);
    //上のa*nの条件からaで切り捨てて桁数dnの時のnの取りうる最大を求める
    ll n = an / a;
    //変える数字は10^9までなのでそれとnのminを取る
    n = min(n,1000000000LL);
    //計算で求まった買えるnの数の桁数を求めるために文字列に直す
    string s = to_string(n);
    //di:nの桁数
    ll di = s.size();
    if(di == dn){
      //最初の指定と桁数が同じならnは買える数字なので最大か検証し最大なら格納
      chmax(ans,n);
    }else if(di < dn){
      //買える最大の整数nが最初に指定した桁数dn以下なら辻褄が合わないのでコンティニュー
      continue;
    }else {
      //買える最大の整数nが最初に指定した桁数dnを超えているなら処理
      string num;
      //桁数がdnの時、買える整数は桁数の限界値なので桁数分9を文字列に追加しそれを数字に直す
      rep(i,dn){
        num += '9';
      }
      ll num_ = stoll(num);
      //num_は買える整数なのでそれが最大か検証し最大なら更新
      chmax(ans,num_);
    }
  }
  cout << ans << endl;
  return 0;
}
//桁数d(N)を取りうる値1~19で全探索したもの
