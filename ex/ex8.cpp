#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int p;
  string text;
  int price;
  int N;
  cin >> p;
 
  // パターン1
  /*if (p == 1) {
  }*/
 
  // パターン2
  if (p == 2) {
      cin >> text;
  }
  cin >> price;
  cin >> N;
  if (p == 2){
      cout << text << "!" << endl;
  }
  cout << price * N << endl;
}
