#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

int bs_helper(const vector<int> &a, int lo, int hi, int key);

map<int, int> binary_search(const vector<int> &a, const vector<int> &b) {
  map<int, int> c;
  for(int i = 0; i < b.size(); i++) {
    if(c.find(b[i]) == c.end()) {
      c[b[i]] = bs_helper(a, 0, a.size() - 1, b[i]);
    }
  }
  return c;
}

int bs_helper(const vector<int> &a, int lo, int hi, int key) {
  if(hi < lo) return -1;
  int mid = lo + (hi - lo) / 2;
  if(key == a[mid]) return mid;
  else if(key < a[mid]) return bs_helper(a, lo, mid - 1, key);
  else return bs_helper(a, mid + 1, hi, key);
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  map<int, int> c = binary_search(a, b);
  for (int i = 0; i < b.size(); ++i) {
    //replace with the call to binary_search when implemented
    std::cout << c.find(b[i])->second << ' ';
  }
}
