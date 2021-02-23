#include <algorithm>
// #include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
  int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int X) {
    int customer_count = customers.size();

    int total_customer_count = 0;
    int total_unsatisfied_customer_count = 0;

    for (int i = 0; i < X; i++) {
      total_customer_count += customers[i];
      if (grumpy[i]) {
        total_unsatisfied_customer_count += customers[i];
      }
    }

    int current_suppress_customer_count = total_unsatisfied_customer_count;
    int max_suppress_customer_count = total_unsatisfied_customer_count;

    for (int i = X; i < customer_count; i++) {
      total_customer_count += customers[i];
      if (grumpy[i]) {
        total_unsatisfied_customer_count += customers[i];
        current_suppress_customer_count += customers[i];
      }

      if (grumpy[i - X]) {
        current_suppress_customer_count -= customers[i - X];
      }

      max_suppress_customer_count = std::max(max_suppress_customer_count,
                                             current_suppress_customer_count);
    }

    // std::cout << total_customer_count << '\n';
    // std::cout << total_unsatisfied_customer_count << '\n';
    // std::cout << max_suppress_customer_count << '\n';

    return total_customer_count - total_unsatisfied_customer_count +
           max_suppress_customer_count;
  }
};
