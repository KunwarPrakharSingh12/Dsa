#include <bits/stdc++.h> // Includes all standard C++ libraries
using namespace std;

// Checks if it's possible to place 'c' cows with at least 'mid' distance apart
int ispos(vector<int>& v, int c, int n, int mid)
{
    int cow = 1;            // Place the first cow at the first stall
    int lastpos = v[0];     // Track the position of the last placed cow
    for (int i = 1; i < n; i++) // Iterate through remaining stalls
    {
        if (v[i] - lastpos >= mid) // If the current stall is at least 'mid' away
        {
            cow++;                // Place another cow
            lastpos = v[i];       // Update last placed cow's position
        }
        if (cow == c)             // If all cows are placed
            return true;          // Return true (possible)
    }
    return false;                 // Not possible to place all cows
}

// Binary search to find the largest minimum distance
int bs(vector<int>& v, int c, int n)
{
    int ans = 0;                  // Store the answer
    int st = 0, end = v[n-1] - v[0]; // Search space: 0 to max possible distance
    while (st <= end)             // Standard binary search loop
    {
        int mid = (st + end) / 2; // Try middle distance
        if (ispos(v, c, n, mid))  // If possible to place cows with 'mid' distance
        {
            ans = mid;            // Update answer
            st = mid + 1;         // Try for a larger distance
        }
        else
        {
            end = mid - 1;        // Try for a smaller distance
        }
    }
    return ans;                   // Return the largest minimum distance found
}

int main() {
    int n, c;
    cout << "Enter the no stall and cows " << endl; // Prompt user for input
    cin >> n >> c;                  // Read number of stalls and cows
    vector<int> v(n);               // Create a vector to store stall positions
    cout << "Enter the positions of the stalls: " << endl; // Prompt for stall positions
    for (int i = 0; i < n; i++) {
        cin >> v[i];                // Read each stall position
    }
    sort(v.begin(), v.end());       // Sort stall positions for correct placement logic
    int ans = bs(v, c, n);          // Find the answer using binary search
    cout << "The largest minimum distance is: " << ans << endl; // Output result
    return 0;                       // End program
}

/*
1. Sorting Stall Positions
Time Complexity: O(n log n)
Space Complexity: O(1) (in-place sort, ignoring input vector)
2. ispos Function
Time Complexity: O(n)
(Iterates through all stalls once)
Space Complexity: O(1)
(Uses only a few variables)
3. Binary Search (bs Function)
Time Complexity: O(n log D)
D = v[n-1] - v[0] (the search space for minimum distance)
Each binary search iteration calls ispos (O(n)), and there are O(log D) iterations.
Space Complexity: O(1)
(Uses only a few variables)
4. Main Function
Time Complexity: O(n log n) (for sorting) + O(n log D) (for binary search)
Space Complexity: O(n)
(for the input vector v)
Summary Table
Part	Time Complexity	Space Complexity
Sorting	O(n log n)	O(1)
ispos	O(n)	O(1)
Binary Search	O(n log D)	O(1)
Main	O(n log n + n log D)	O(n)
Overall Time Complexity: O(n log n + n log D)
Overall Space Complexity: O(n)
*/