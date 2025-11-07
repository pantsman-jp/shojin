#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m), c;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < m; i++)
    cin >> b[i];
  c.insert(c.end(), a.begin(), a.end());
  c.insert(c.end(), b.begin(), b.end());
  sort(c.begin(), c.end());
  for (int i = 0; i < n + m - 1; i++)
  {
    if (find(a.begin(), a.end(), c[i]) != a.end() and find(a.begin(), a.end(), c[i + 1]) != a.end())
    {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
