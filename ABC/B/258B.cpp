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
  vector<vector<char>> a(n,vector<char>(n));
  rep(i,n){
    rep(j,n){
      cin >> a[i][j];
    }
  }
  string ans;
  ll ans_ = 0;
  rep(i,n){
    rep(j,n){
      rep(k,8){
        string num;
        num += a[i][j];
        if(k == 0){
          int l = i;
          rep(_,n-1){
            l--;
            l = (l+n) % n;
            num += a[l][j];
          }
          ll sum = stoll(num);
          if(ans_ < sum){
            ans_ = sum;
            ans = num;
          }
        }
        if(k == 1){
          int l = i;
          int r = j;
          rep(_,n-1){
            l--;
            r++;
            l = (l+n) % n;
            r = (r+n) % n;
            num += a[l][r];
          }
          ll sum = stoll(num);
          if(ans_ < sum){
            ans_ = sum;
            ans = num;
          }
        }
        if(k == 2){
          int r = j;
          rep(_,n-1){
            r++;
            r = (r+n) % n;
            num += a[i][r];
          }
          ll sum = stoll(num);
          if(ans_ < sum){
            ans_ = sum;
            ans = num;
          }
        }
        if(k == 3){
          int l = i;
          int r = j;
          rep(_,n-1){
            l++;
            r++;
            l = (l+n) % n;
            r = (r+n) % n;
            num += a[l][r];
          }
          ll sum = stoll(num);
          if(ans_ < sum){
            ans_ = sum;
            ans = num;
          }
        }
        if(k == 4){
          int l = i;
          rep(_,n-1){
            l++;
            l = (l+n) % n;
            num += a[l][j];
          }
          ll sum = stoll(num);
          if(ans_ < sum){
            ans_ = sum;
            ans = num;
          }
        }
        if(k == 5){
          int l = i;
          int r = j;
          rep(_,n-1){
            l++;
            r--;
            l = (l+n) % n;
            r = (r+n) % n;
            num += a[l][r];
          }
          ll sum = stoll(num);
          if(ans_ < sum){
            ans_ = sum;
            ans = num;
          }
        }
        if(k == 6){
          int r = j;
          rep(_,n-1){
            r--;
            r = (r+n) % n;
            num += a[i][r];
          }
          ll sum = stoll(num);
          if(ans_ < sum){
            ans_ = sum;
            ans = num;
          }
        }
        if(k == 7){
          int l = i;
          int r = j;
          rep(_,n-1){
            l--;
            r--;
            l = (l+n) % n;
            r = (r+n) % n;
            num += a[l][r];
          }
          ll sum = stoll(num);
          if(ans_ < sum){
            ans_ = sum;
            ans = num;
          }
        }
      }    
    }
  }
  cout << ans << endl;
  return 0;
}
