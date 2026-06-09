#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (a) - 1; i >= b; i--)
#define all(p) p.begin(), p.end()
#define rall(p) p.rbegin(), p.rend()
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define yn(p) cout << (p ? "Yes\n" : "No\n");
#define dout(f) cout << fixed << setprecision(10) << f << '\n';
using ll = long long;
using ld = long double;
using P = pair<int, int>;
const int inf = 1 << 30;
const ll INF = 1LL << 60;
// const ll mod =;

int n, l, k;
vector<int> a;

bool check(int mid)
{
  int cnt = 0, pre = 0;
  rep(i, 0, n) if (a[i] - pre >= mid and l - a[i] >= mid) cnt += 1, pre = a[i];
  return cnt >= k;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> l >> k;
  a.resize(n);
  rep(i, 0, n) cin >> a[i];
  int left = -1, right = l + 1;
  while (1 < right - left)
  {
    int mid = (left + right) / 2;
    if (check(mid))
      left = mid;
    else
      right = mid;
  }
  cout << left << endl;
}