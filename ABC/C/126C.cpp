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
int cnt(int ret, int n,int k){
    while(n < k){
        n *= 2;
        ret++;
    }
    return ret;
}
int main(){
    ll n, k;
    cin >> n >> k;
    vector<int> d;
    double ans = 0;
    int x = 0;
    rep2(i,n){
        int f = cnt(0,i,k);
        if(f == 0){
            x++;
            continue;
        }
        f = 1 << f;
        d.push_back(f); 
    }
    int y = d.size();
    rep(i,y){
        ans += (double)1 / d[i];
    }
    rep(i,x){
        ans += (double)1;
    }
    ans /= (double)n;
    printf("%.10f\n",ans);
    return 0;
}
//確率計算問題
