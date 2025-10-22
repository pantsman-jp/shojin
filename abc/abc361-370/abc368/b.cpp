#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<int> op(vector<int> a)
{
  sort(a.begin(), a.end(), greater<>());
  a[0] -= 1;
  a[1] -= 1;
  return a;
}

int count_pos(vector<int> a)
{
  int ans = 0;
  for (int x : a)
    if (x > 0)
      ans++;
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int ans = 0;
  while (true)
  {
    if (count_pos(a) < 2)
    {
      cout << ans << endl;
      return 0;
    }
    a = op(a);
    ans++;
  }
}
