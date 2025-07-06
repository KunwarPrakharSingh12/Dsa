// Book Allocation Problem (by Binary Search)
/*
There are N books, each ith book has A[i] number of pages.

You have to allocate books to M number of students so that the maximum number of pages allocated to a student is minimum.

Note:-
@ Each book should be allocated to a student.

@ Each student has to be allocated at least one book.

@ Allotment should be in contiguous order.

Calculate and return that minimum possible number.

Return -1 if a valid assignment is not possible.
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to check if it is possible to allocate books such that
// no student reads more than 'mid' pages
// Time Complexity: O(n) per call (where n = number of books)
// Space Complexity: O(1) (uses only a few variables)
bool isValid(vector<int> &nums, int n, int m, int mid)
{

  int stud = 1, pages = 0;
  for (int i = 0; i < n; i++)
  {
    if (nums[i] > mid)
    {
      return false; // If a single book has more pages than mid, allocation is not possible
    }
    if (pages + nums[i] <= mid)
    { // Check if adding this book exceeds the limit
      // If it doesn't exceed, add it to the current student's allocation
      pages = pages + nums[i]; // Add pages to current student
    }
    else
    {
      stud++; // Allocate to next student
      pages = nums[i];
    }
  }
  if (stud > m)
  { // If the number of students needed exceeds m, allocation is not possible
    // More students needed than available
    return false; // More students needed than available
  }
  else if (stud <= m)
  {              // If the number of students is less than or equal to m, allocation is possible
    return true; // Allocation possible
  }
  if (stud > n)
  {               //
    return false; // More students needed than available
  }
  else if (stud <= n)
  {
    return true; // Allocation possible
  }
  return true;
}

int main()
{

  vector<int> nums; // Space Complexity: O(n)
  int n, m, input;  // n = number of books, m = number of students
  int ans = 0;
  int st = 0, end = 0; // st = starting point for binary search, end = sum of all pages

  // Input the number of books
  cout << "Enter the leangth of vector:" << endl;
  cin >> n;

  // Input the number of students
  cout << "Enter the no of students:" << endl;
  cin >> m;

  // Input the number of pages in each book
  // Time Complexity: O(n)
  // Space Complexity: O(n) for nums vector
  cout << "Enter the no of pages" << endl;
  for (int i = 0; i < n; i++)
  {
    cin >> input;
    nums.push_back(input);
  }

  // Calculate the sum of all pages to set the upper bound for binary search
  // Time Complexity: O(n)
  for (int i = 0; i < n; i++)
  {
    end = end + nums[i];
  }

  // Binary search to find the minimum possible maximum pages
  // Time Complexity: O(n * log S), where S = sum of all pages
  //   - log S for binary search iterations
  //   - O(n) for each isValid call
  // Space Complexity: O(1) extra (excluding input vector)
  while (st <= end)
  {
    int mid = st + (end - st) / 2;
    if (isValid(nums, n, m, mid))
    {
      ans = mid;
      end = mid - 1; // Try to find a smaller maximum (move left)
    }
    else
    {
      st = mid + 1; // Increase the minimum possible maximum (move right)
    }
  }

  // Output the result
  cout << "The minimum possible maximum pages is: " << ans << endl;

  return 0;
}

/*Certainly! Here’s a breakdown of the time and space complexity for each main part of your code:

1. isValid Function
Time Complexity:

The function iterates through all n books once: O(n).
Space Complexity:

Uses only a constant amount of extra space (for counters and variables): O(1).
2. Main Function
a. Input Reading and Summing Pages
Reading input and summing pages:
Both loops run n times: O(n) time, O(n) space for the nums vector.
b. Binary Search
Binary search loop:
The range for binary search is from st (0) to end (sum of all pages, call it S).
The number of iterations is O(log S).

Each iteration calls isValid (O(n)), so total time for binary search:
O(n * log S)

c. Overall
Total Time Complexity:

Input reading: O(n)
Binary search: O(n * log S)
Total: O(n * log S)
Total Space Complexity:

For nums vector: O(n)
Other variables: O(1)
Total: O(n)
Summary Table
Part	Time Complexity	Space Complexity
isValid	O(n)	O(1)
Input Reading	O(n)	O(n)
Binary Search	O(n * log S)	O(1)
Overall	O(n * log S)	O(n)*/