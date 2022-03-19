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
    int a, b;
    cin >> a >> b;
    vector<ll> ans;
    ll num = 1;
    ll ch = 0;
    bool frag = false;
    if(a < b){
        swap(a,b);
        frag = true;
    }
    rep(i,a){
        ans.push_back(num);
        ch += num;
        num++;
    }
    ll num2 = -1;
    int nb = b;
    int cnt = 1;
    while(nb >= 2){
        ans.push_back(num2);
        ch += num2;
        num2--;
        nb--;
    }
    ch *= -1;
    ans.push_back(ch);
    int x = ans.size();
    if(frag){
        rep(i,x){
            ans[i] *= -1;
        }
    }
    rep(i,x){
        cout << ans[i] << " ";
    }
    cout << endl;    
    return 0;
}
//a,bの大きい方を1から順にansに格納して
//小さい方を1ずつ足したものを格納して最後の1つで残りの数字を格納したい
