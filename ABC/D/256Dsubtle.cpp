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
  vector<int> l(n),r(n);
  priority_queue<P,vector<P>,greater<P>> q;
  rep(i,n){
    cin >> l[i] >> r[i];
    q.push({l[i],i});
    q.push({r[i],i});
  }
  vector<bool> a(n);
  int ch = 0;
  vector<P> ans;
  int left = 0;
  int right = 0;
  int look = 0;
  while(q.size()){
    P v = q.top();
    q.pop();
    int len = v.first;
    int i = v.second;
    if(ch == 0){
      if(look < len){
        if(left != right){
          right = look;
          ans.push_back({left, right});
        }
        left = len;
        look = len;
        a[i] = !a[i];
        ch++;
      }else {
        a[i] = !a[i];
        ch++;
      }
    }else {
      if(a[i]){
        ch--;
        a[i] = !a[i];
      }else {
        ch++;
        a[i] = !a[i];
      }
      if(look < len) {
        look = len;
      }
    }
  }
  right = look;
  ans.push_back({left,right});
  int ansn = ans.size();
  rep(i,ansn){
    cout << ans[i].first << " " << ans[i].second << endl;
  }
  return 0;
}
//バラバラな半開区間を合体させる問題
//本番では脳死で区間idと区間の片方の値をpriority_queueにぶっ込んだ
//
