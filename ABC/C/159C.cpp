#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    double l;
    cin >> l;
    double ans = 0;
    ans = (l / 3) * (l / 3) * (l / 3);
    printf("%.10f\n",ans);
    return 0;
}
