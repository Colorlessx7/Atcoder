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
  int n;
  cin >> n;
  vector<int> a(n);
  vector<bool> b(4);
  rep(i,n){
    cin >> a[i];
  }
  int p = 0;
  rep(i,n){
    b[0] = true;
    //逆から
    rep3(j,4){
      if(b[j]){
        b[j] = false;
        if(a[i] + j < 4){          
          b[j+a[i]] = true;
        }else {
          p++;
        }
      }
    }
  }
  cout << p << endl;
  return 0;
}
