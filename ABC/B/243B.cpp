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
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    set<int> st;
    rep(i,n){
        cin >> a[i];
        st.insert(a[i]);
    }
    rep(i,n){
        cin >> b[i];
        st.insert(b[i]);
    }
    int y = st.size();
    y = 2 * n - y;
    int ans1 = 0;
    int ans2 = 0;
    rep(i,n){
        rep(j,n){
            if(i == j && a[i] == b[i]){
                ans1++;
            }
            //if(i != j && a[i] == b[i]){
            //    ans2++;
            //}
        }
    }
    ans2 = y - ans1;
    cout << ans1 << endl;
    cout << ans2 << endl;
    return 0;
}
