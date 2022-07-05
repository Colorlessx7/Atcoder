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
int main(){
  //n:文字列sの長さ
  //q:クエリ数
  int n, q;
  cin >> n >> q;
  //s:文字列
  string s;
  cin >> s;
  //現在の文字列の先頭がsのどこから始まっているか
  int p = 0;
  //クエリ処理
  rep(_,q){
    //t:クエリのタイプ
    int t, x;
    cin >> t >> x;
    if(t == 1){
      //t=1の時、x:操作の回数
      //x回の操作で先頭の文字はsの(p-x+n)%n番目の文字となる
      //(最初が0番目の場合操作1回ごとに先頭はn-1,n-2,n-3...と変わっていく)
      //p-xが負になることがあるので先にnを足してからnで割った余りをx回の移動後の先頭の場所とする
      p = (p-x+n)%n;
    }else {
      //t=2の時,x:出力する文字の場所
      //配列は0indexedなので-1
      x--;
      //現在の状態のx番目の文字はsの(p+x)%n番目の文字となるのでそれを出力
      printf("%c\n",s[(p+x)%n]);
    }
  }
  return 0;
}
//substr,pop_back,insert等で文字列を直接入れ替える解法の場合は
//入れ替えに使う関数insertあたりがO(N)で、x回行うためO(NX)、
//X<=Nという制約からO(N^2)、そのクエリが最大Q回くるのでO(N^2*Q)となり10^15で間に合わない
//本番でTLEしたようにdequeを使った解にするとinsert部分をO(1)にできるが、
//その他の部分で結局O(NQ)となり10^10で間に合わない
//先頭が最初のsの何文字目かだけを管理してt=2のクエリで都度出力すれば入れ替えの計算量がO(1)になり、
//O(Q)で求まる
