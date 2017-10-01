/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>

#include <vector>

#include <algorithm>
#include <functional>

using namespace std;

vector<int> nums;
vector<int> stack;
vector<bool> used;

bool compute(int rem, int size) {
  if (rem == 0) {
    for (int i = 0; i < size; i++) {
      cout << stack[i];
      if (i < size - 1) cout << "+";
    }
    cout << endl;
    return true;
  }
  if (rem < 0 || size >= stack.size()) return false;

  bool found = false;
  for (int i = 0; i < nums.size(); i++) {
    if (used[i]) continue; // Already used
    if (nums[i] > rem) continue; // We will overflow
    if (size > 0 && nums[i] > stack[size - 1]) continue; // Select them in decreasing order
    if (i > 0 && !used[i - 1] && nums[i - 1] == nums[i]) continue; // Don't visit the same path twice in the loop

    used[i] = true;
    stack[size] = nums[i];
    found = compute(rem - nums[i], size + 1) || found;
    used[i] = false;
  }
  return found;
}

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  int T, N;
  while (true) {
    cin >> T >> N;
    if (N == 0) break;
    nums.resize(N);
    used.resize(N);
    stack.resize(N);
    int sum = 0;
    for (int i = 0; i < N; i++) {
      cin >> nums[i];
      sum += nums[i];
    }
    // This allows us to simplify the recursion.
    sort(nums.begin(), nums.end(), std::greater<int>());

    // Never start the recursion if we already know that this is impossible.
    bool foundable = nums[0] <= T && sum >= T;

    cout << "Sums of " << T << ":" << endl;
    bool found = (foundable && compute(T, 0));
    if (!found) {
      cout << "NONE" << endl;
    }
  }

  return 0;
}
