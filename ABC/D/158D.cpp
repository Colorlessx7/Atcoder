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
    string s;
    int q;
    cin >> s >> q;
    string t;
    rep(i,q){
        int ty;
        cin >> ty;
        if(ty == 1){
            swap(s,t);
        }else if(ty == 2){
            int f;
            char c;
            cin >> f >> c;
            if(f == 1){
                t += c;
            }else if(f == 2){
                s += c;
            }
        }
    }
    reverse(all(t));
    t += s;
    cout << t << endl;
    return 0;
}
