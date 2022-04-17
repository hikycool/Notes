#include <iostream>
#include <vector>
#include <functional>
#include <queue>
#include <set>
#include <memory>

struct pair_greater
  : std::binary_function<std::pair<int, int>, std::pair<int, int>, bool>
{
  bool operator()(const std::pair<int, int> &one,
                  const std::pair<int, int> &two) const {
    return one.second > two.second ||
      (one.second == two.second && one.first > two.first);
  }
};

/*
template <>
bool std::greater<std::pair<int, int>>::operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) const {
  return true;
  }*/
template <>
struct std::greater<std::pair<int, int>> {
  bool operator()(const std::pair<int, int> &p1,
                  const std::pair<int, int> &p2) const {
    return p1.second > p2.second ||
      (p1.second == p2.second && p1.first > p2.first);
  }
};

template <> struct std::less < std::pair<int, int>> {
  bool operator()(const std::pair<int, int> &p1,
                  const std::pair<int, int> &p2) const {
    return p1.second < p2.second ||
      (p1.second == p2.second && p1.first < p2.first);
  }
};

int main() {
  std::cout << "hello world" << std::endl;
  std::vector<int> s { 1, 2, 3 };

  // pair
  std::priority_queue<
    std::pair<int, int>,
    std::vector<std::pair<int, int>>,
    std::less<std::pair<int, int>>> q;

  q.push({3, 2});
  q.push({1, 2});
  q.push({2, 3});
  q.push({2, 2});
  q.push({9, 1});

  while (!q.empty()) {
    std::pair<int, int> p = q.top();
    std::cout << p.first << ", " << p.second << std::endl;
    q.pop();
  }

  return 0;
}
