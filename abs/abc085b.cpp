#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  int n;
  cin >> n;
  set<int> d;
  rep(_, n)
  {
    int x;
    cin >> x;
    d.insert(x);
  }
  cout << d.size() << endl;
}