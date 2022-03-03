#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = N - 1; i >= 0; i--)
#define rep4(i,N) for(int i = N; i > 0; i--)
#define all(x) x.begin(),x.end() 
typedef long long ll;
using P = pair<int,int>;
void dfs(int cnt,int num,int n,int m,vector<int>& a,vector<int>& b,vector<bool>& f,bool& ans){
    if(cnt == m){
        return;
    }
    if(f[num]){
        ans = 1;
        return;
    }
    rep(i,m){
        if(a[i] == num){
            num = b[i];
            f[a[i]] = 1;
            dfs(cnt+1,num,n,m,a,b,f,ans);
            break;
        }
        if(b[i] == num){
            num = a[i];
            f[b[i]] = 1;
            dfs(cnt+1,num,n,m,a,b,f,ans);
            break;
        }
    }
    return;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(m),b(m);
    rep(i,m){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }
    bool ans = 0;
    vector<bool> f(n);
    dfs(0,0,n,m,a,b,f,ans);
    cout << (!ans ? "Yes" : "No") << endl;
    return 0;
}
