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
  int n, m;
  cin >> n >> m;
  vector<int> s(n-1),x(m);
  rep(i,n-1){
    cin >> s[i];
  }
  rep(i,m){
    cin >> x[i];
  }
  //A1をXと置くとしてX=keyとした時に良い数列上で
  //ラッキーナンバーになるAiの個数をvalueとする
  map<ll,int> cnt;
  //a+cx=xj
  ll a = 0;
  //c:Ai+1の式のXに対する正負係数
  //A1=X=a+cX=0+1Xとなるので最初は正
  int c = 1;
  //全ての良い数列Aiについて回すO(N)
  //全体O(NM)
  rep(i,n){
    //全てのラッキーナンバーについて回すO(M)
    rep(j,m){
      //AiがラッキーナンバーになるようなA1=Xを求め、それをカウントしていく
      //Aiがラッキーナンバーx[j]のどれかになるにはA1=Xが
      //(x[j]-a)*cになっている必要がある
      //この式はx[j]=Ai=a+cXよりX=(x[j]-a)/cとなって
      //cが1or-1なので除算でも乗算でも変わらないためこの形となっている
      cnt[(x[j]-a)*c]++;
    }
    //iがn-1(最後)の場合それ以降のSi,Ai+1が存在しないためここで終わる
    if(i == n-1){
      break;
    }
    //Ai=old_a+cx,Ai+1=new_a+cx(=Xjのどれか)のnew_aについて
    //式のXがかからない整数部分を計算し、aとする
    //(Ai+1=Si-Aiよりnew_a+cx=Si-old_a-cx,cの符号が違うので消えて
    //new_a=Si-old_aとなる)
    a = s[i] - a;
    //iの偶奇で係数の正負が逆転する
    c = -c;
  }
  //良い数列AをAの要素のうちラッキーナンバーであるものの個数が一番多くなるように
  //選んだ時のラッキーナンバーの個数の最大値(0初期化)
  int ans = 0;
  //map:cntの情報はA1=X=xとした時の良い数列内に出来上がる
  //ラッキーナンバーの個数がc個となっている
  //全てのXの候補について回す
  for(auto [x,c] : cnt){
    //X=xとした時にできるラッキーナンバーの個数cの最大値をansに格納
    chmax(ans,c);
  }
  cout << ans << endl;
  return 0;
}
//S =  2  3 3  4 -4  -7 -4  -1
//A = 3 -1 4 -1 5  -9  2  -6  5
//この問題では隣り合うAi,Ai+1を足したものがSiになるという条件だが
//これは一番左のA1を固定した時にSiから自動的にAi+1以降が決定する
//Ai+Ai+1=SiよりAi+1=Si-Aiとなる
//例の場合だと
//A1=3=Xと置くと、A2=S1-A1=S1-X=2-X、A3=S2-A2=S2-(2-X)=3-(2-X)=1+X、...
//これを一般化するとAi+1=a+cX(=Xj)となる(xの係数cはiの偶奇で+1と-1が入れ替わる)

//すべての i=1,2,…,N と j=1,2,…,Mの組についてAi=XとなるXを調べ
//NM個のXの候補の中で最も登場頻度が高いものをA1とすれば
//問題の条件を満たす良い数列を作ることができる
