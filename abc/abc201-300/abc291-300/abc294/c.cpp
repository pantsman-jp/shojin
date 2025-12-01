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
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m), ansa(n), ansb(m);
  rep(k, 0, n) cin >> a[k];
  rep(k, 0, m) cin >> b[k];
  int i = 0, j = 0;
  while (i < n and j < m)
  {
    if (a[i] < b[j])
      ansa[i] = i + j + 1, i++;
    else
      ansb[j] = i + j + 1, j++;
  }
  rep(k, i, n) ansa[k] = k + j + 1;
  rep(k, j, m) ansb[k] = i + k + 1;
  rep(k, 0, n) cout << ansa[k] << ' ';
  cout << endl;
  rep(k, 0, m) cout << ansb[k] << ' ';
  cout << endl;
}