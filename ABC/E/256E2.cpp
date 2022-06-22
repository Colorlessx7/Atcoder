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
  //頂点数
  int n;
  cin >> n;
  //x[i]:i人目の人の嫌いな人(functional graphのf(i)=x[i]となる)
  vector<int> x(n);
  rep(i,n){
    cin >> x[i];
    //0indexed
    x[i]--;
  }
  //c[i]:i人目の嫌いな人が先に報酬を得た場合に増加する不満度
  vector<int> c(n);
  rep(i,n){
    cin >> c[i];
  }
  //unionfind ufの宣言(n頂点)
  dsu uf(n);
  //不満度の最小
  ll ans = 0;
  //全頂点についてループ
  rep(i,n){
    //iとiの嫌いなx[i]が連結成分になっていない場合は連結させる
    if(uf.same(i,x[i]) == false){
      //連結処理
      uf.merge(i,x[i]);
      //欲しい情報はサイクル内のcの最小値で連結させた段階では
      //サイクルになっていないのでコンティニューして次の頂点を処理させる
      continue;
    }
    //iとiの嫌いな人x[i]がすでに連結成分になっているなら以降を処理
    //(頂点iとx[i]を含むサイクルが存在する)
    //cur:サイクル内の不満度の最小値(初期値をサイクルの始点のiの不満度にしておく)
    int cur = c[i];
    //v:サイクル内を探索するときの現在地(iをサイクルの開始点とする)
    int v = i;
    //サイクルを構成する各頂点の探索(サイクルの開始点=終点なので終点に辿り着くまで処理)
    do
    {
      //vをサイクルの次の頂点に設定
      v = x[v];
      //サイクル内の不満度のminをとる
      cur = min(cur,c[v]);
    }while(v != i);
    //サイクル内の最小の不満度curを答えにたす
    ans += cur;
  }
  cout << ans << endl;
  return 0;
}
//問題の条件をグラフに落とし込んで解く問題
//問題の条件からfunctional graphに落とし込むことができる
//unionfindで解いたver
