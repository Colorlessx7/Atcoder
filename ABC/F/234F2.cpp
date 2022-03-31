#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(ll i = 0; i < N; i++)
#define rep2(i,N) for(ll i = 1; i <= N; i++)
#define rep3(i,N) for(ll i = N - 1; i >= 0; i--)
#define rep4(i,N) for(ll i = N; i > 0; i--)
#define replr(i,l,r) for(ll i = l; i < r; i++)
#define reprl(i,l,r) for(ll i = l; i > r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
typedef long long ll;
using P = pair<ll,ll>;
using mint = modint998244353;
const int mod = 998244353;
//nCkmodをO(1)で求めるための構造体(n=5005で初期化,0!~5005!とその逆元が格納される)
struct combination {
  vector<mint> fact, ifact;
  combination(int n):fact(n+1),ifact(n+1) {
    assert(n < mod);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
  }
  mint val(int n){
      return fact[n];
  }
  mint ret(int k){
      return ifact[k];
  }
  mint operator()(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n]*ifact[k]*ifact[n-k];
  }
}comb(5005);
int main(){
    string S;
    cin >> S;
    int m = 26;
    //Sに出てくるアルファベットの頻度を格納
    vector<int> f(m);
    //頻度の計上と格納の処理
    for (char c : S) f[c-'a']++;
    int n = S.size();
    //dp[i][j]:i種類目まで使って長さjの文字列を作る場合の数
    //dpのiについてをpからdpの遷移で考えるためdp[j]として処理する
    vector<mint> dp(n+1);
    //dpの初期化,アルファベットを1種類も使わない文字列のパターン空文字列の1つのみ
    dp[0] = 1;
    //dp遷移部分 アルファベット1~26種類について何種類目までを使ったかのループ
    for (int s : f) {
        //dpの遷移元,pからdpへの遷移について考えれば良くなる
        //漸化式のdp[i+1]がdpにdp[i]がpに対応する
        vector<mint> p(n+1);
        //p,dpをswapしてdpの遷移を行う
        swap(dp,p);
        //新しい種類のアルファベットが0~s(s=f[i]:iは添字)あるので
        //その中からk個使って新しい文字列のパターンを作る時の
        //そのパターン数の遷移について処理
        rep(k,s+1) {
            //jのとりうる値は既存の文字列に追加でk文字突っ込む時の
            //既存の文字列のサイズの幅なので最初から何も選んでいない0から
            //k文字追加したらちょうどn文字になるn-kまで
            //(既存の文字数+k文字で物理的に埋められないものも含む)
            //(埋められないようなところは元々p[j]=0だから掛け算で0のまま)
            rep(j,n-k+1) {
                //nj:遷移先のj,既にj文字あった文字列に
                //k文字追加したパターン数の遷移を見る
                int nj = j+k;
                //元々二次元dpの漸化式はdp[i+1][j+k]=dp[i][j]*(j+k)Cj
                //これは元々の文字列のパターン数dp[i][j]に
                //アルファベットk文字の挿入場所のパターン数(j+k)Cjをかけたもの
                //例としてooの文字にkを1文字挿入するなら|oo,o|o,oo|のどれかとなる
                //これはoの数+1(j+k)からk個選ぶことになり(j+k)Ckとなる
                //総数がj+kなので組み合わせCの計算上どっちでも正しい
                //jを選ぶなら仕切りの位置ではなくoの位置を選ぶ形
                dp[nj] += p[j]*comb.ret(k);
            }
        }
    }
    mint ans;
    //dp[0]は空文字列なのでそれ以外のdp[1]~dp[n]までの総和が答え
    rep(i,n) ans += dp[i+1]*comb.val(i+1);
    cout << ans.val() << endl;
    return 0;
}
//改善ver
//実装を楽する方法としてACLのconvolutionを使う方法がある
//https://atcoder.jp/contests/abc234/submissions/28402488
