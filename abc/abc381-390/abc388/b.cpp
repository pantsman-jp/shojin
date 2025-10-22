#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
  int n, d;
  cin >> n >> d;
  vector<int> t(n), l(n);
  for (int i = 0; i < n; i++)
    cin >> t[i] >> l[i];
  for (int i = 0; i < d; i++)
  {
    int ans = 0;
    for (int j = 0; j < n; j++)
      l[j]++;
    for (int j = 0; j < n; j++)
      ans = max(ans, t[j] * l[j]);
    cout << ans << endl;
  }
}
