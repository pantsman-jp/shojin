#include <iostream>
#include <vector>
using namespace std;

vector<int> inc_all(vector<int> xs)
{
  for (int i = 0; i < xs.size(); i++)
    xs[i]++;
  return xs;
}

int count(vector<int> xs, int t)
{
  int ans = 0;
  for (int x : xs)
    if (t <= x)
      ans++;
  return ans;
}

int main()
{
  int n, t, p;
  cin >> n >> t >> p;
  vector<int> l(n);
  for (int i = 0; i < n; i++)
    cin >> l[i];
  int ans = 0;
  while (true)
  {
    if (p <= count(l, t))
    {
      cout << ans << endl;
      return 0;
    }
    l = inc_all(l);
    ans++;
  }
}
