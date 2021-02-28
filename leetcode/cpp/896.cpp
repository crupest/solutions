#include <vector>

using std::vector;

enum Order { Ascend, Descend, Unknown };

class Solution {
public:
  bool isMonotonic(vector<int> &A) {
    Order order = Unknown;

    int count = A.size();
    for (int i = 1; i < count; i++) {
      int last = A[i - 1];
      int current = A[i];
      if (order == Unknown) {
        if (current > last) {
          order = Ascend;
        } else if (current < last) {
          order = Descend;
        }
      } else if (order == Ascend) {
        if (last > current) {
          return false;
        }
      } else {
        if (last < current) {
          return false;
        }
      }
    }

    return true;
  }
};
