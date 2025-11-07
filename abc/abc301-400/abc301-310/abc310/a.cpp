#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  int n, p, q;
  cin >> n >> p >> q;
  vector<int> d(n);
  rep(i, n) { cin >> d[i]; }
  cout << min(*min_element(d.begin(), d.end()) + q, p) << endl;
}
