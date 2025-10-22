#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> a(4);
  cin >> a[0] >> a[1] >> a[2] >> a[3];
  sort(a.begin(), a.end());
  if (a[0] == a[1] && a[1] == a[2] && a[2] != a[3])
  {
    cout << "Yes" << endl;
    return 0;
  }
  if (a[0] != a[1] && a[1] == a[2] && a[2] == a[3])
  {
    cout << "Yes" << endl;
    return 0;
  }
  if (a[0] == a[1] && a[1] != a[2] && a[2] == a[3])
  {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
  return 0;
}
