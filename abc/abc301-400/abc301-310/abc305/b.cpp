#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  char p, q;
  cin >> p >> q;
  vector<int> b = {0, 3, 4, 8, 9, 14, 23};
  cout << abs(b[p - 'A'] - b[q - 'A']) << endl;
}
