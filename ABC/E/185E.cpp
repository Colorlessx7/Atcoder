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
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n),b(m);
  rep(i,n){
    cin >> a[i];
  }
  rep(i,m){
    cin >> b[i];
  }
  const ll INF = 1001001001;
  //dp[i][j]:Aが先頭i文字だけ、Bが先頭j文字だけで問題の条件を満たす最適な取り除き方をした時の答え
  auto dp = vector(n+1,vector(m+1,INF));
  //A0文字,B0文字では取り除く文字がなく間違いが存在しないため0
  dp[0][0] = 0;
  //dpの遷移の処理
  rep(i,n+1){
    rep(j,m+1){
      if(i < n){
        //数列Aから数字を1個削除する遷移
        chmin(dp[i+1][j],dp[i][j]+1);
      }
      if(j < m){
        //数列Bから数字を1個削除する遷移
        chmin(dp[i][j+1],dp[i][j]+1);
      }
      //AiとBjを、最終的に同じ位置になるように残す遷移
      if(i < n && j < m){
        //遷移のコスト(AとBのカーソルが示す文字が同じなら0)
        ll co = 0;
        //AとBのカーソルが示す文字が同じでない場合コストはペナルティの1になる
        if(a[i] != b[j]){
          co = 1;
        }
        //AiとBjを、最終的に同じ位置になるように残す遷移
        chmin(dp[i+1][j+1],dp[i][j]+co);
      }
    }
  }
  //An文字、Bm文字で問題の条件を満たす最適な取り除き方をした時の答えを出力
  cout << dp[n][m] << endl;
  return 0;
}
//dpの中のLCS:最長共通部分列に似た問題
//i!=0かつj!=0のときのdp[i][j]の値を考えると、AiとBjは両方列の最後なので、
//Ai,Bjの少なくとも一方を消すか、Ai,Bjを最終的な列で同じ位置に来るように残すしかない
//よってdp[i][j] の値は以下の中で一番小さいものになる
//dp[i−1][j] +1 (Aiを消すことにするとき)
//dp[i][j-1] +1 (Bjを消すことにするとき)
//dp[i−1][j-1] +(Ai!=Bj ? 1 : 0) (AiとBjを最終的に同じ位置になるように残すことにするとき)
