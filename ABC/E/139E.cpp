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
  vector<vector<ll>> a(n,vector<ll>(n-1));
  rep(i,n){
    rep(j,n-1){
      cin >> a[i][j];
      //0indexedで選手番号を扱うため-1
      a[i][j]--;
    }
    //選手の並びをvectorをqueueとして扱うためにreverseする(vectorはpop_backだけO(1)でできるため)
    reverse(all(a[i]));
  }
  //q:次の日に行う試合の情報(fi:対戦相手の選手番号1,se:対戦相手の選手番号2)
  vector<P> q;
  //選手iが次の対戦相手と戦えるか確認し、戦えるなら次の日の対戦の情報のリストqに格納する関数
  auto check = [&](ll i){
    //選手iの対戦が全て終了し今後の予定がない場合何もしない
    if(a[i].size() == 0){
      return;
    }
    //j:選手iの次の対戦相手
    ll j = a[i].back();
    //選手jの次の対戦相手が選手iなら処理
    if(a[j].back() == i){
      //i,jが対戦するので対戦情報のリストとしてi,jのpairを作成
      P p(i,j);
      //重複回避のため対戦情報のリストをfirst>secondの順にする
      if(p.second < p.first){
        swap(p.first,p.second);
      }
      //対戦情報のリストpをqにpush
      q.push_back(p);
    }
  };
  //初期化:とりあえず1日目に全選手が誰かと対戦できるか確認し、できるなら対戦情報をqに格納する
  rep(i,n){
    check(i);
  }
  //やり切るのにかかる日数
  ll day = 0;
  //実行できる対戦の組み合わせが存在し続ける限り回す(日数分(O(N^2))
  while(q.size() > 0){
    //日数を+1する
    day++;
    //erase,uniqueで重複削除をする場合に事前にsortしておく必要がある
    sort(all(q));
    //q内の重複している要素を削除する(uniqueで重複してない要素が先頭に固まり、重複している要素が末尾に固まる
    //unique(all(q))で重複している要素の先頭のイテレータが返り、そこから末尾までがeraseで消える)
    q.erase(unique(all(q)),q.end());
    //qを次の日に行う試合の情報、prevqを今日行う試合の情報として扱う
    vector<P> prevq;
    //swap前の段階では今日行う組み合わせがqに入ったままなので
    //swapしprevqに移動させた後に以降の処理で次の日にできる組み合わせをqに格納していく
    swap(prevq,q);
    //その日にできる試合のみ処理(O(1))
    //試合が実行できたので対戦予定の選手番号のリストから対戦した人を消すループ
    for(P p : prevq){
      //i,j:今日対戦できる組み合わせの対戦する選手2人の選手番号
      ll i = p.first;
      ll j = p.second;
      //i,jの対戦予定の選手リストから今日の時点で一番最初に対戦する選手の番号(iならj,jならi)を削除
      a[i].pop_back();
      a[j].pop_back();
    }
    //対戦が終わりリストからも削除したので対戦したi,jの2名が明日に別の人と対戦できるか
    //確認し、対戦できるならqに格納するループ
    for(P p : prevq){
      ll i = p.first;
      ll j = p.second;
      //選手i,jの2名が明日に別の人と対戦できるか確認し、対戦できるならqに格納
      check(i);
      check(j);
    }
  }
  //各選手の対戦すべき相手の番号が残っていたら総当たり戦が条件通りできないので-1を出力
  rep(i,n){
    if(a[i].size() != 0){
      cout << -1 << endl;
      return 0;
    }
  }
  //総当たりが完遂できるのでかかる日数を出力
  cout << day << endl;
  return 0;
}
//貪欲法高速化解
//1日に1試合しかできない最悪パターンだと計算量がO(N*N^2)となり間に合わない
//(Nが全選手についてのループ,N^2が試合数N*(N-1)/2をオーダー表記に落とし込んだもの)
//高速化の方法はNの部分の計算量を落とす方針でできる
//全ての選手について試合をできるか試すのではなく、その日行える試合のみを処理することによってO(N^2)になる
