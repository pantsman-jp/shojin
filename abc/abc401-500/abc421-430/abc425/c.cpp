#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n, q;
  cin >> n >> q;
  vector<long long> a(n);
  vector<long long> presum(n + 1);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    presum[i + 1] = presum[i] + a[i];
  int head = 0;
  for (int i = 0; i < q; i++)
  {
    int j, l, r;
    long long ans = 0;
    cin >> j >> l;
    if (j == 1)
      head = (head + l) % n;
    if (j == 2)
    {
      cin >> r;
      l--;
      r--;
      int left = (head + l) % n;
      int right = (head + r) % n;
      if (left < right + 1)
        cout << presum[right + 1] - presum[left] << endl;
      else
        cout << (presum[n] - presum[left]) + presum[right + 1] << endl;
    }
  }
}
