#include<bits/stdc++.h>
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
template<typename Tx, typename Ty>Tx dup(Tx x, Ty y){return (x+y-1)/y;}
void chmin(int &x, int y){ x = min(x,y); }
void chmax(int &x, int y){ x = max(x,y); }
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
//O(N*MAX_b)
void solve(){
  //n:暗号の桁数
  int n;
  cin >> n;
  //暗号の初期番号
  vector<int> a(n);
  rep(i,n){
    cin >> a[i];
  }
  //暗号の各桁について処理O(N)
  rep(i,n){
    //暗号のi桁目の操作数
    int b;
    //暗号のi桁目の操作情報
    string s;
    cin >> b >> s;
    //操作による最終的な数字の変動量
    int ch = 0;
    //各操作について処理O(MAX_b)
    //aから操作sで正しい暗証番号にするのではなく、
    //暗証番号を操作sでaにしちゃった問題なので正しい暗証番号を得るには操作を逆に考える必要がある
    rep(j,b){
      //j番目の操作がUなら逆に戻す操作で数字a[i]は減少する
      if(s[j] == 'U'){
        ch--;
        //j番目の操作がDなら逆に戻す操作で数字a[i]は増加する
      }else if(s[j] == 'D'){
        ch++;
      }
    }
    //元の暗証番号のi桁目を復元する計算処理
    //a[i]+chが0未満になる可能性があるため先に括弧内で+10しておいて
    //a[i]+chが10以上になる可能性があるため括弧の処理が終わった後に10で割ったあまりをとる
    a[i] = (a[i]+10 + ch) % 10;
  }
  //出力部
  rep(i,n){
    //暗号aのi桁目を出力
    //%cは最後以外が空白、最後が改行を出力
    printf("%d%c",a[i],(i != n-1 ? ' ' : '\n'));
  }
}
int main(){
  int t;
  cin >> t;
  rep(i,t) solve();
  return 0;
}
//正しい暗証番号から各桁にb回の操作(情報s)を行った結果暗号がaの状態になったとして
//元の正しい暗証番号を出力する問題
