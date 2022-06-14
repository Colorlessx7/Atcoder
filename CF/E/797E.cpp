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
void chmin(int &x, int y){ x = min(x,y); }
void chmax(int &x, int y){ x = max(x,y); }
void solve(){
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  ll sum = 0;
  rep(i,n){
    cin >> a[i];
    //商を答えに加算
    sum += a[i] / k;
    //aの要素をkで割った余りに変更
    a[i] = a[i] % k;
  }
  //降順に並べる
  sort(allr(a));
  //two pointers解法
  //i:aの値を大きい順に指すカーソル
  //j:aの値を小さい順に指すカーソル
  for(int i = 0, j = n - 1; i < j; i++, j--){
    //aiとajが足したらk以上になるjの位置までカーソルを進める
    //(iがjより小さい限りカーソルを進めるかの判定をする)
    while(a[i] + a[j] < k && i < j){
      //jのカーソルを進める
      j--;
    }
    //カーソルが進み、i,jが一緒になった場合これ以上kを超えるai,ajの組み合わせが存在しないため終了
    if(i == j){
      break;
    }
    //ai+aj<=kの組み合わせが存在したため、(ai+aj)/k=1となるから答えに1を足す
    sum++;
  }
  cout << sum << endl;
}
int main(){
  int t;
  cin >> t;
  rep(i,t) solve();
  return 0;
}
//貪欲法
//偶数個の重さの品物から2つ選び、重さの合計をkで割って切り捨てた時の値が最大になるように
//選び方を工夫した時の重さの合計をkで割って切り捨てた時の値の合計値を答える問題
//n=6,k=10,a=19,5,5,2,0,0の場合(19+2)/10=2,(5+5)/10=1で3が答えとなる
//(3番目の5が3ならば(5+3)/10=0で総和は2となる)
//貪欲法の解き方はまずaの全ての値をkで割って商を答えに加算し、aの値を余りの値にする
//次にaを降順に並べ、aの大きい値とそれに足したらk以上になるaの小さい値を足すことにすると
//その合計がkを超えるためkで割ると商が1になるので、k以上になる大小の組み合わせの個数だけ1を足す
//できるだけ数字を無駄にしない組み合わせは(ai+aj)%kの合計ができるだけ小さい組み合わせ
//これを作るように実装する
