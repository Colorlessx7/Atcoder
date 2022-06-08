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
  ll n;
  cin >> n;
  double ans = 0;
  //1~n-1までを|S|の値とした時の期待値をansに足し合わせる(i=|S|)
  for(ll i = 1; i < n; i++){
    //N/(N-|S|)
    ans += (double)n/ (n-i);
  }
  printf("%.10f\n",ans);
  return 0;
}
//期待値を計算する問題
//期待値における重要な事実として以下のものがある
//確率p(p!=0)で成功する試行を、成功するまで行うときの試行回数(最後の成功した回も含む)の期待値は1/p

//求める期待値をXとすると、1回試行して、成功したらそこで終わり、失敗したら全く同じ状況でやり直しなので
//X=1+(1−p)Xという式が成り立つ。変形して pX=1 なので X=1/pとなる

//確率pを考えると
//今回の問題で、今高橋君がいる連結成分に含まれる頂点集合をSと表すことにする。
//また、Sの要素数を|S|とすると、操作においてSに含まれない頂点が選ばれた場合、そしてその場合に限り|S|が1大きくなる
//Sに含まれない頂点が初めて選ばれるまでに必要な操作回数の確率は(N-|S|)/Nとなる
//(全体の頂点数NからSに含まれていない頂点数(N-|S|)を選ぶ確率)
//期待値は1/pなので期待値は確率の逆数のN/(N-|S|)となる
//問題文の条件より最初の頂点数は頂点1からスタートのため|S|=1、この計算は|S|=N-1の時点で|S|=Nになるための
//期待値までを計算するので|S|=N-1の時点まで行い、最後は全て到達するため|S|=Nで終了となる
//よってそれらの期待値を足し合わせれば良い
//答えの値は最大で 1.2×10^6程度なので、少なくとも倍精度浮動小数点数 (double型)を使えば誤差は問題ない
