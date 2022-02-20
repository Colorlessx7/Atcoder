//参考資料:https://atcoder.jp/contests/abc239/editorial/3390
//切り捨て除算はこれからも頻出のテクニックであるため覚えること
//切り捨て除算のコツ
//1: 小数(double)を使わない
//小数を経由して求めるのは将来的にバグの温床になるためやらないように
//C++のdoubleは(2進53桁)~=(10進16桁)程度の精度しかない
//2: 負数の除算に注意すること
//C++の商は小数部分を無視した数学的な商を求めている
//C++では-24/10は-2.4となり.4を無視いて-2が答えとなる
//よって、C++の整数除算では割られる数が負である・余りが発生している
//という2つの条件を満たすなら答えを-1したものが答えとなる

//ABC239Bより

#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = n - 1; i >= 0; i--)
#define rep4(i,N) for(int i = n; i > 0; i--)
#define all(x) x.begin(),x.end() 
typedef long long ll;
using P = pair<int,int>;
#include <iostream>
using namespace std;
int main() {
  long long X;
  cin >> X;
  //割られる数Xが負かつ、余りが発生しているなら
  //通常の処理X / 10 後に-1
  if (X < 0 and X % 10 != 0) {
    cout << X / 10 - 1 << "\n";
  } else {
    cout << X / 10 << "\n";
  }
}

//また別解として、C++では%は(a / b) * b + a % b = a
//を満たす演算子として定義されているので、
//切り上げが発生するのは「a % b が負である」ときのみであることから以下のように示せる
//一般に、A を B で切り捨て除算したい場合は、
//A,B ともに正の場合 A / B
//A,B が負を取り得る場合 A / B - (A % B < 0)で計算すれば良い

#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = n - 1; i >= 0; i--)
#define rep4(i,N) for(int i = n; i > 0; i--)
#define all(x) x.begin(),x.end() 
typedef long long ll;
using P = pair<int,int>;
int main() {
  long long X;
  cin >> X;
  //X/10が0より小さい時のみ右項が計算される
  cout << X / 10 - (X % 10 < 0) << "\n";
}

