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
    string s;
    cin >> s;
    string s1;
    rep(i,n){
        if(s[i] == 'A'){
            s1 += "BB";
            continue;
        }
        s1 += s[i];
    }
    n = s1.size();
    string s2;
    rep(i,n){
        if(i!=n-1&&s1[i] == 'B'&&s1[i+1] == 'B'){
            s2 += "A";
            i++;
            continue;
        }
        s2 += s1[i];
    }
    cout << s2 << endl;
    return 0;
}
