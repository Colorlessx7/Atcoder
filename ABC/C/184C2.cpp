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
#define sz(v) (int)v.size()
using ll = long long;
using P = pair<int,int>;
using TP = tuple<int,int,int>;
template<typename Tx, typename Ty>Tx dup(Tx x, Ty y){return (x+y-1)/y;}
void chmin(int &x, int y){ x = min(x,y); }
void chmax(int &x, int y){ x = max(x,y); }
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
int main(){
  //(a,b)-(c,d)
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  //座標が一致(0)
  if(a == c && b == d){
    cout << 0 << endl;
    return 0;
    //座標移動の操作式1のa+b=c+dを満たす(1)
  }else if(a + b == c + d){
    cout << 1 << endl;
    return 0;
    //座標移動の操作式2のa−b=c−dを満たす(1)
  }else if(a - b == c - d){
    cout << 1 << endl;
    return 0;
    //座標移動の操作式3のabs(a-c)+abs(b-d)<=3を満たす(1)
  }else if(abs(a-c)+abs(b-d) <= 3){
    cout << 1 << endl;
    return 0;
  }
  //ab,cd:x1',x2'
  //ba,dc:y1',y2'
  int ab = a + b;
  int ba = a - b;
  int cd = c + d;
  int dc = c - d;
  //操作式1,3の順で移動可能(2)
  if(abs(ab-cd) <= 3){
    cout << 2 << endl;
    return 0;
    //操作式2,3の順で移動可能(2)
  }else if(abs(ba-dc) <= 3){
    cout << 2 << endl;
    return 0;
  }
  //ac,bd:x座標とy座標の差分計算
  int ac = a - c;
  int bd = b - d;
  //始点と終点のパリティが一致しているなら操作式1,2で移動可能(2)
  if(abs(ac-bd) % 2 == 0){
    cout << 2 << endl;
    return 0;
  }
  //操作式3を2回で移動可能(2)
  if(abs(a-c)+abs(b-d) <= 6){
    cout << 2 << endl;
    return 0;
  }
  //全て満たさないなら3回
  cout << 3 << endl;
  return 0;
}
