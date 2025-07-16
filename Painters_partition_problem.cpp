#include <iostream>
#include <vector>
#include <algorithm> // for max_element
#include <climits>   // for INT_MIN
using namespace std;

// Checks if it is possible to paint all walls with 'm' painters such that
// no painter paints more than 'mid' time in total.
bool ispossible(vector<int> &arr, int n, int m, int mid) {
  int painters = 1; // Start with one painter
  int time = 0;     // Time accumulated by current painter

  for (int i = 0; i < n; i++) {
    // If a single wall takes more time than 'mid', allocation is not possible
    if (arr[i] > mid) {
      return false;
    }
    // If current painter can paint this wall within 'mid' time
    if (time + arr[i] <= mid) {
      time += arr[i];
    } else {
      // Allocate to next painter
      painters++;
      time = arr[i];
    }
  }
  // Return true if number of painters used is less than or equal to 'm'
  return painters <= m;
}

// Finds the minimum time required to paint all walls using 'm' painters
// Time Complexity: O(n * log(sum - maxVal + 1)), where n is the number of walls.
// The binary search runs for log(sum - maxVal + 1) iterations, and each iteration checks all n walls.
int min_Time_to_paint(int n, int m, vector<int> &arr) {
  int sum = 0, maxVal = INT_MIN;
  // Calculate total time and maximum single wall time
  for (int i = 0; i < n; i++) {
    sum += arr[i];
    maxVal = max(maxVal, arr[i]);
  }
  int st = maxVal, end = sum, ans = -1;

  // Binary search for the minimum possible maximum time
  while (st <= end) {
    int mid = st + (end - st) / 2;
    if (ispossible(arr, n, m, mid)) {
      ans = mid;      // Possible to paint within 'mid' time
      end = mid - 1;  // Try to find a smaller maximum
    } else {
      st = mid + 1;   // Increase minimum possible maximum
    }
  }
  return ans;
}

int main() {
  int n, m;
  cout << "Enter the number of painters: ";
  cin >> m;
  cout << "Enter the number of walls: ";
  cin >> n;

  vector<int> arr(n);
  cout << "Enter the time taken by each painter to paint each wall: ";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  // Compute and display the minimum time required
  int result = min_Time_to_paint(n, m, arr);
  cout << "The minimum time required to paint all walls is: " << result << endl;
  return 0;
}
//time complexity: O(n * log(sum - maxVal + 1))
//space complexity: O(1) for variables, O(n) for input vectorz