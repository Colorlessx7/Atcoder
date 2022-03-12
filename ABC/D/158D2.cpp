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
    cin >> s;
    deque<char> q;
    for(char c : s){
        q.push_back(c);
    }
    bool frag = false;
    int qn;
    cin >> qn;
    rep(i,qn){
        int ty;
        cin >> ty;
        if(ty == 1){
            frag = !frag;
        }else if(ty == 2){
            int f;
            char c;
            cin >> f >> c;
            if(frag){
                f = 3 - f;
            }
            if(f == 1){
                q.push_front(c);
            }else {
                q.push_back(c);
            }
        }
    }
    if(frag) reverse(all(q));
    string ans;
    for(char c : q){
        ans += c;
    }
    cout << ans << endl;
    return 0;
}
