#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  int a, b;
  cin >> a >> b;
  if ((a * b) % 2 == 0)
    cout << "Even" << endl;
  else
    cout << "Odd" << endl;
}