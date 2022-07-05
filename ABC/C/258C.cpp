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
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  int diff = 0;
  rep(_,q){
    int t, x;
    cin >> t >> x;
    if(t == 1){
      diff += n;
      diff -= x;
      diff %= n;
    }else {
      x--;
      x += diff;
      x %= n;
      cout << s[x] << endl;
    }
  }
  return 0;
}
