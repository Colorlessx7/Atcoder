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
void dfsF(int i,int &ans,vector<int> &front,int &itr){
    if(front[i] == -1){
        itr = i;
        return;
    }
    ans++;
    int x = front[i];
    dfsF(x,ans,front,itr);
}
void dfsB(int i,int &ans,vector<int> &back,bool &out){
    if(back[i] == -1){
        return;
    }
    ans++;
    int x = back[i];
    if(out){
        cout << x + 1 << " ";
    }
    dfsB(x,ans,back,out);
}
int main(){
    int n, qm;
    cin >> n >> qm;
    vector<int> front(n,-1),back(n,-1);
    int q, x, y;
    rep(i,qm){
        cin >> q;
        if(q == 1){
            cin >> x >> y;
            x--; y--;
            front[y] = x;
            back[x] = y;
        }
        if(q == 2){
            cin >> x >> y;
            x--; y--;
            front[y] = -1;
            back[x] = -1;
        }
        if(q == 3){
            cin >> x;
            x--;
            int ans = 1;
            int itr = 0;
            bool out = 0;
            dfsF(x,ans,front,itr);
            dfsB(x,ans,back,out);
            cout << ans << " ";
            cout << itr + 1 << " ";
            out = 1;
            dfsB(itr,ans,back,out);
            cout << endl;
        }
    }
    return 0;
}
