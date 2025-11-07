#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;

int main()
{
  int q;
  cin >> q;
  vector<int> a;
  for (int i = 0; i < q; i++)
  {
    int n, m;
    cin >> n >> m;
    if (n == 1)
      a.push_back(m);
    else
      cout << a[a.size() - m] << endl;
  }
}
