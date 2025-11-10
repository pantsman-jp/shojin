#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> a(3);
  rep(i, 0, 3) cin >> a[i];
  sort(all(a));
  if (a[2] - a[1] == a[1] - a[0])
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}