#include <cmath>
#include <iostream>

using ll = long long;

int main() {
  ll X, Y;
  std::cin >> X >> Y;

  ll result = 0;

  if (X == 0 && Y == 0) {
    return 0;
  }

  if (std::abs(X) > std::abs(Y) ||
      (std::abs(X) == std::abs(Y) && !(X < 0 && Y < 0))) {
    ll c = std::abs(X);

    result += ((c - 1) * 4 + 2) * (c - 1);

    if (X > 0) {
      result += (c * 2 - 1) * 2;
      result += c * 2;
      result += (c - Y);
    } else {
      result += (c * 2 - 1);
      result += (Y - (-c + 1));
    }

  } else {
    ll c = std::abs(Y);

    result += ((c - 1) * 4 + 2) * (c - 1);

    if (Y > 0) {
      result += (c * 2 - 1) * 2;
      result += (X - (-c));
    } else {
      result += (c * 2 - 1) * 2;
      result += c * 2 * 2;
      result += c - X;
    }
  }

  std::cout << result;

  return 0;
}
