#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++)
    cin >> p[i];
  int q;
  cin >> q;
  for (int i = 0; i < q; i++)
  {
    int a, b;
    cin >> a >> b;
    for (int n : p)
    {
      if (n == a)
      {
        cout << a << endl;
        break;
      }
      if (n == b)
      {
        cout << b << endl;
        break;
      }
    }
  }
}
