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
  //整数の個数
  int n;
  cin >> n;
  //pe[i][j]:i番目の整数のj番目の素因数分解後の項のfi=素数p,se=指数部e
  vector<vector<P>> pe(n);
  //各整数の素因数分解後の情報について入力
  rep(i,n){
    //i番目の整数の素因数分解後の項数
    int m;
    cin >> m;
    //素因数分解後の各項の情報について入力
    rep(j,m){
      //p:素数,e:指数部
      int p, e;
      cin >> p >> e;
      //i番目の整数のj番目の項がp^eであるという情報を配列peに格納
      pe[i].emplace_back(p,e);
    }
  }
  //各素数pの指数部eのmaxを求めるためのmap
  //key:p,value:eの最大値
  map<int,int> mx;
  //全数字について処理
  rep(i,n){
    //全素因数分解後の項数について処理
    for(auto [p,e] : pe[i]){
      //各素因数ごとに指数部eの最大値をmx[p]に格納
      mx[p] = max(mx[p],e);
    }
  }
  //各素因数ごとの指数部eの最大値が単独のものかを調べるために
  //各素因数のeが最大のものが何個存在するかを求めるためのmap
  //key:p,value:eが最大のものが何個存在するか
  map<int,int> cnt;
  //全数字について処理
  rep(i,n){
    //全素因数分解後の項数について処理
    for(auto [p,e] : pe[i]){
      //i番目の数字のpの指数部eが最大なら処理
      if(mx[p] == e){
        //個数のカウンタを+1する
        cnt[p]++;
      }
    }
  }
  //n個の整数から1つ選んで1に書き換えた時のn個の整数の最小公倍数の個数
  int ans = 0;
  //全数字について処理
  //全体でO(MlogM)で間に合う
  rep(i,n){
    //フラグ
    bool ok = false;
    //全素因数分解後の項数について処理
    //n回のループの中でMの最大回回る
    for(auto [p,e] : pe[i]){
      //素数pの指数部eが最大でかつ、単独のものである場合に
      //ai=1にするとLi!=Lとなるのでフラグを立てる
      //mapアクセスでO(logM)
      if(mx[p] == e && cnt[p] == 1){
        ok = true;
      }
    }
    //フラグが立っているならLi!=Lなので答えを+1する
    if(ok){
      ans++;
    }
  }
  //答えはL!=Liとなるiの個数をcとするとmin(c+1,n)となるので
  //答えがn未満なら+1する
  //(全てを1にしてもそのlcmのLi=Lになる場合(ans=1)から
  //(ans=n)となる1つを除いてLi!=Lになるパターンと全てLi!=Lになるパターンまで)
  if(ans < n){
    ans++;
  }
  cout << ans << endl;
  return 0;
}
//LCM(最小公倍数)の性質として
//各整数を素因数分解するとp1^e1*p2^e2*...となるが
//同じ素数piのei(i=1~n)の最大値をとったものが全体のLCMとなる
//例1で説明すると
//a1 = 49, 7^2
//a2 = 20, 2^2*5^1
//a3 = 5, 5^1
//a4 = 14, 2^1*7^1 の時
//L : 980, 2^2*5^1*7^2
//L1 a1=1 : 140, 2^2*5^1*7^1
//L2 a2=1 : 490, 2^1*5^1*7^2
//L3 a3=1 : 980, 2^2*5^1*7^2
//L4 a4=1 : 980, 2^2*5^1*7^2
//また、lcmがLと違うものができたとしてそれらに同じものができない理由は
//ajのpの指数がLのpの指数に等しいようなj(!=i)が存在しないことからLi!=Ljとなる
//
