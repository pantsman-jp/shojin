#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int f(int n)
{
  if (n % 2 == 0)
    return n / 2;
  return 3 * n + 1;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int s;
  cin >> s;
  vector<int> a = {s};
  int i = 0;
  while (true)
  {
    int next = f(a[i]);
    auto it = find(all(a), next);
    if (it != a.end())
    {
      cout << a.size() + 1 << endl;
      return 0;
    }
    a.push_back(next), i++;
  }
}