#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
  int n, t = 0;
  cin >> n;
  vector<string> contestant(n);
  for (int i = 0; i < n; i++)
  {
    int c;
    cin >> contestant[i] >> c;
    t += c;
  }
  sort(contestant.begin(), contestant.end());
  map<int, string> names;
  for (int i = 0; i < n; i++)
    names[i] = contestant[i];
  cout << names[t % n] << endl;
}
