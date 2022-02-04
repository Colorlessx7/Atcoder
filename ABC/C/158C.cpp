#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int a, b;
    cin >> a >> b;
    int mina = 12.5 * a;
    if(a % 2 != 0){
        mina++;
    }
    int maxa = 12.5 * (a + 1);
    if(a % 2 == 0){
        maxa++;
    }
    int minb = 10 * b;
    int maxb = 10 * (b + 1);
    int ans = max(mina,minb);
    if(!(max(mina,minb) <= ans && ans < min(maxa,maxb))){
        ans = -1;
    }
    cout << ans << endl;
    return 0;
}
