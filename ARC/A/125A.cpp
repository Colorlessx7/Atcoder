#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = N - 1; i >= 0; i--)
#define rep4(i,N) for(int i = N; i > 0; i--)
#define replr(i,l,r) for(int i = l; i < r; i++)
#define reprl(i,l,r) for(int i = l; i > r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
typedef long long ll;
using P = pair<int,int>;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> s(n),t(m);
    bool sz = false, so = false, tz = false, to = false;
    rep(i,n){
        cin >> s[i];
        if(s[i] == 0){
            sz = true;
        }
        if(s[i] == 1){
            so = true;
        }
    }
    rep(i,m){
        cin >> t[i];
        if(t[i] == 0){
            tz = true;
        }
        if(t[i] == 1){
            to = true;
        }
    }
    if((tz==true&&sz==false)||(to==true&&so==false)){
        cout << -1 << endl;
    }else if((sz==true&&tz==true&&so==false&&to==false)||(sz==false&&tz==false&&so==true&&to==true)){
        cout << m << endl;
    }else {
        int x = s[0];
        int left = 0, right = 0;
        replr(i,1,n){
            if(s[i] != x){
                left = i;
                break;
            }
        }
        rep3(i,n){
            if(s[i] != x){
                right = n - i;
                break;
            }
        }
        left = min(left,right);
        ll ans = m;
        x = t[0];
        ll ch = 0;
        rep(i,m){
            if(t[i] != x){
                ch++;
                x = t[i];
            }
        }
        if(s[0] != t[0]){
            ch++;
        }
        if(ch >= 1){
            ch--;
            ch += left;
        }
        ans += ch;
        cout << ans << endl;
    }
    return 0;
}
//WAしつつ自力
//
