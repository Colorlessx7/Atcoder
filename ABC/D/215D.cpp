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
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
    }
    vector<bool> prime(m+1,1);
    queue<int> q;
    rep(i,n){
        for(int j = 1; j * j <= a[i]; j++){
            if(a[i] % j == 0){
                if(j != 1){
                    q.push(j);
                }
                if(j * j != a[i]){
                    q.push(a[i] / j);
                }
            }
        }
    }
    n = q.size();
    rep(i,n){
        int nt = q.front();
        q.pop();
        if(prime[nt]){
            for(int j = 1; nt * j <= m; j++){
                prime[nt * j] = 0;
            }
        }
    }
    int ans = 0;
    rep2(i,m){
        if(prime[i]){
            ans++;
        }
    }
    cout << ans << endl;
    rep2(i,m){
        if(prime[i]){
            cout << i << endl;
        }
    }
    return 0;
}
