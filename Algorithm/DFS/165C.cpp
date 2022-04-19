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
ll n, m, q;
vector<ll> a,b,c,d;
//正整数列xの得点の最大値
ll ans;
//広義単調増加の重複順列に対するdfs全探索
//xが問題分の正整数列Aに対応する
void dfs(vector<ll> x){
  //dfsのベースケース
  //xはdfsの開始時点でx[0]=1が埋まっており、そこからpush_backをn回するため
  //サイズがn+1になったらベースケースになる
  if(x.size() == n+1){
    //calc部分
    //now:長さnの正整数列xを決め終えた後のその正整数列xのパターンで得られるスコア
    ll now = 0;
    //スコアの計算処理
    rep(i,q){
      //問題文の条件に合っているか判定
      //xはdfsの開始時点でx[0]=1が埋まっており、そこからpush_backを繰り返すため
      //正整数列xはx[1]~x[n]までの範囲のものになる
      //よって入力のa[i],b[i]は1indexedだったがxも1indexedとして扱うため
      //下の式のようになる
      if(x[b[i]] - x[a[i]] == c[i]){
        //上の式の条件(問題分の条件)を満たすなら現在のスコアnowにd点を加算
        now += d[i];
      }
      //正整数列xの一パターンで得られるスコアが現在の最大値より多いなら更新
      ans = max(ans,now);
    }
    //ベースケースの終了
    return;
  }
  //xの末尾に末尾だった値を追加(xを{1}で初期化した理由)
  //これによりx[1]を1で始めることができ、かつ広義単調増加を実現できる
  x.push_back(x.back());
  //正整数列xのとりうる最大値mまで末尾の値を加算させる
  while(x.back() <= m){
    //末尾を加算する前にdfsをすることでxを単調増加ではなく
    //広義単調増加として扱えるようにしている
    dfs(x);
    //dfsでベースケースを踏んだ後に一つ前の再帰元のこの位置に帰ってくる
    //末尾をmより大きくなるまで+1してdfsしてを繰り返す
    x.back()++;
  }
  //おそらく上のwhile文を処理しきった後にここのリターンを踏まずに
  //再帰元のwhile文の終わっていない部分の処理をするため
  //このリターンは必要ない可能性が高い
  return;
}
int main(){
  //入力部
  cin >> n >> m >> q;
  //a,b,c,dの配列サイズをqに指定
  a = b = c = d = vector<ll>(q);
  rep(i,q){
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }
  //dfsの開始
  dfs(vector<ll>(1,1));
  cout << ans << endl;
  return 0;
}
//制約よりn<=10,m<=10であるため数列xの全探索ができそう
//重複順列としてdfsを使って数列を全探索していきたいが
//重複順列として考えると10^10でTLEしてしまう
//ただ、今回は数列xが広義単調増加で前の要素以下を列挙しなければ
//探索範囲が枝刈りされて重複順列のdfsによる全探索が間に合う
//今回は広義単調増加である数列xすべてに対してスコアを計算して最大値を求めると答え
