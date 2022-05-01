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
  //n:園児の数,q:クエリの数
  ll n, q;
  cin >> n >> q;
  //a[i]:園児iのレート,b[i]:園児iが所属する幼稚園
  vector<ll> a(n),b(n);
  //s[i]:幼稚園iに所属する園児のレートを平衡二分探索木(昇順)で管理した配列
  vector<multiset<ll>> s(200005);
  //平等さ:AtCoderに参加している園児が一人以上いるような幼稚園それぞれについて
  //園内で最もレートの高い園児のレートを求め、その最小値として得られる値とする時の
  //平等さを求めるための平衡二分探索木
  multiset<ll> maxs;
  //幼稚園内のレートの最大をとる関数
  //引数i:園児のID
  auto getmax = [&](ll i){
    //s[i]に園児が存在しない場合は平等さの計算から除くために-1にしておく
    if(s[i].size() == 0){
      return -1LL;
    }
    //幼稚園s[i]に園児が存在する場合はその幼稚園のレートの最大を返す
    return *s[i].rbegin();
  };
  //平等さを計算するために条件を満たす全幼稚園のレートの最大を格納する平衡二分探索木maxsに
  //幼稚園iのレートの最大値を格納する関数
  auto addyochien = [&](ll i) {
    //幼稚園iのレートの最大値を関数getmaxで得る
    ll x = getmax(i);
    //園児が幼稚園iに存在しない場合はmaxsにレートを格納しない
    if(x == -1){
      return;
    }
    //幼稚園iのレートの最大値xをmaxsに格納
    maxs.insert(x);
  };
  //平等さを計算するために条件を満たす全幼稚園のレートの最大を格納する平衡二分探索木maxsから
  //すでにmaxsに格納していた幼稚園iのレートの最大値を削除する関数
  auto delyochien = [&](ll i) {
    //幼稚園iのレートの最大値を関数getmaxで得る
    ll x = getmax(i);
    //園児が幼稚園iに存在しない場合はmaxsにレートを格納しない
    if(x == -1){
      return;
    }
    //幼稚園iのレートの最大値xをmaxsから削除
    maxs.erase(maxs.find(x));
  };
  //幼稚園iに園児のレートxを追加する関数(入園処理)
  auto addenji = [&](ll i, ll x) {
    //幼稚園に園児が入園するとレートの最大が更新される可能性があるため
    //園児が入園する幼稚園iのレートの最大値を平等さ計算のためのmaxsから削除しておく
    delyochien(i);
    //幼稚園iの園児全員のレートを管理している平衡二分探索木に園児のレートxを格納
    s[i].insert(x);
    //幼稚園iに園児を入園させたので幼稚園iのレートの最大が更新された可能性があるので
    //改めて園児が入園する幼稚園iのレートの最大値を平等さ計算のためのmaxsに格納
    addyochien(i);
  };
  //幼稚園iから園児xを削除する関数(退園処理)
  auto delenji = [&](ll i, ll x) {
    //addenjiと同様に、退園により幼稚園のレートの最大が更新される可能性があるため
    //園児が退園する幼稚園iのレートの最大値を平等さ計算のためのmaxsから削除しておく
    delyochien(i);
    //幼稚園iの園児全員のレートを管理している平衡二分探索木から園児のレートxを削除
    //multisetのeraseは単一要素のみを削除する
    //(s[i].find(x)で最初に見つけたx1つのみをmultiset(今回はs[i])から削除する)
    //(今回は違うが(iter first,iter last)で[first,last)の範囲を削除)
    s[i].erase(s[i].find(x));
    //addenjiと同様に幼稚園iから園児を退園させたので幼稚園iのレートの最大が更新された
    //可能性があるため、改めて園児が退園した幼稚園iのレートの最大値を平等さ計算のためのmaxsに格納
    addyochien(i);
  };
  //入力部
  rep(i,n){
    //a[i]:園児iのレート,b[i]:園児iが所属する幼稚園を入力
    cin >> a[i] >> b[i];
    //maxsで幼稚園b[i]のレートの最大値の変更についての更新をしつつ
    //幼稚園b[i]のレートを管理している平衡二分探索木に園児iのレートa[i]を格納する
    addenji(b[i],a[i]);
  }
  //クエリ変更処理
  rep(i,q) {
    //c:転園する園児,d:転園先の幼稚園
    ll c, d;
    cin >> c >> d;
    //園児は0indexed,幼稚園は1nidexedとして扱う
    --c;
    //園児cがすでに所属していた幼稚園から抜けるように処理
    delenji(b[c], a[c]);
    //園児cの所属先を幼稚園dに変更
    b[c] = d;
    //maxsで幼稚園b[c]のレートの最大値の変更についての更新をしつつ
    //幼稚園b[c]のレートを管理している平衡二分探索木に園児cのレートa[c]を格納する
    addenji(b[c], a[c]);
    //園児が1人以上存在する幼稚園のレートの最大値全てを格納する平衡二分探索木
    //maxsの最小値のイテレータは昇順で並んでいるため.begin()で指すことができ、
    //*iteratorでイテレータが指す場所の値を得ることができる(これで平等さの値を得る)
    ll ans = *maxs.begin();
    //平等さを都度出力
    printf("%lld\n", ans);
  }
  return 0;
}
//multiset:平衡二分探索木を使って幼稚園ごとのレートの最大値と、条件を満たす
//全幼稚園のレートの最大を管理し、クエリに対処する問題

//multiset平衡二分探索木で今回の処理をした時にかかる計算量はO((N+Q)logN)
//(平衡二分探索木の処理にNlogNかかる(左のnが操作数、右のnが要素数))

//イテレータの位置はmultiset内の要素が5つあった場合、(要素内のイテレータを空,0,1,2,3,4,空とすると)
//begin()が0番目,end()が4の後の空,rbegin()が4番目,rend()が0の前の空を指す
