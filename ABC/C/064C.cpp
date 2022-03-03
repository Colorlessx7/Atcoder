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
    int n;
    cin >> n;
    map<int,int> mp;
    int ch = 0;
    rep(i,n){
        int a;
        cin >> a;
        if(1 <= a && a <= 399){
            mp[1]++;
        }else if(400 <= a && a <= 799){
            mp[2]++;
        }else if(800 <= a && a <= 1199){
            mp[3]++;
        }else if(1200 <= a && a <= 1599){
            mp[4]++;
        }else if(1600 <= a && a <= 1999){
            mp[5]++;
        }else if(2000 <= a && a <= 2399){
            mp[6]++;
        }else if(2400 <= a && a <= 2799){
            mp[7]++;
        }else if(2800 <= a && a <= 3199){
            mp[8]++;
        }else {
            ch++;
        }
    }
    int x = mp.size();
    if(x == 0){
        x++;
        ch--;
    }
    cout << x << " " << x + ch << endl;
    return 0;
}
