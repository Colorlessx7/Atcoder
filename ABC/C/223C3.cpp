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
#define sz(v) (int)v.size()
using ll = long long;
using P = pair<int,int>;
using TP = tuple<int,int,int>;
template<typename Tx, typename Ty>Tx dup(Tx x, Ty y){return (x+y-1)/y;}
void chmin(int &x, int y){ x = min(x,y); }
void chmax(int &x, int y){ x = max(x,y); }
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
int main(){
  //要素数
  int n;
  cin >> n;
  //時間に関する累積和
  vector<double> s(n+1);
  //長さに関する累積和
  vector<double> len(n+1);
  //入力 a:道のり,b:速さ
  vector<double> a(n),b(n);
  //累積和の作成
  rep(i,n){
    cin >> a[i] >> b[i];
    //長さの累積和に導火線の長さを加算
    len[i+1] = len[i] + a[i];
    //時間の累積和に導火線を焼き切るまでの時間を加算
    //時間=道のりa/速さb
    s[i+1] += s[i] + (a[i]/b[i]);
  }
  //二つの火がぶつかる時間を計算(時間の累積和の最後の値/2)
  double time = s[n]/2;
  //it:二分探索でとるindex(二つの火がぶつかる時間より大きい値を最初に指す)
  int it = upper_bound(all(s),time) - s.begin();
  //-1することによりindexが二つの火がぶつかる導火線の一つ前のところを指すようになる
  it--;
  //len[it]が二つの火がぶつかる導火線の一つ前の導火線までの長さの合計を示すのでそれを答えとする
  double ans = len[it];
  //now:二つの火がぶつかる導火線で左側の火が導火線の開始位置からぶつかる所にたどり着くまでに何秒かかるか
  //timeがぶつかる時間,s[it]が左側の火がぶつかる導火線にたどりつくまでにかかる時間
  double now = time - s[it];
  //ぶつかる導火線で左側の火が導火線の開始位置からぶつかる所にたどり着くまでの時間:now,
  //その速さ:b[it],をかけるとその導火線の開始位置からぶつかるところまでの長さとなるのでそれを加算する
  ans += now * b[it];
  printf("%.10f\n",ans);
  return 0;
}
//二分探索解法
