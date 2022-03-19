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
    int t;
    cin >> t;
    rep(i,t){
        ll n;
        cin >> n;
        if(n % 2 != 0){
            cout << "Odd" << endl;
        }else if(n % 4 == 0){
            cout << "Even" << endl;
        }else if(n % 4 != 0 && n % 2 == 0){
            cout << "Same" << endl;
        }
    }
    return 0;
}
//数学的考察 if場合分け
