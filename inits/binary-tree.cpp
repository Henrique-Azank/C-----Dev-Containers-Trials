
// Include the default structs and data types
#include <iostream>
#include <vector>

// Include the namespace
using std::vector;

// Binary tree function
int searchTarget(vector<int>& nums, int target) {

    // initial left, right and mid
    int left = 0;
    int right = nums.size() -1; 

    // Try to find the target
    while (left <= right) {
        // Calculate the middle index safely
        int mid = left + (right - left) / 2;

        // Check if the target is present at mid
        if (nums[mid] == target) {
            return mid; // Target found
        }
        // If target is greater, ignore the left half
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        // If target is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }
    
    return -1;
}

// Run test cases
int main(){
    // Test case 1
    vector<int> nums1 = {1, 2, 3, 4, 5};
    int target1 = 3;
    int result1 = searchTarget(nums1, target1);
    std::cout << "Result: " << result1 << '\n';
}
