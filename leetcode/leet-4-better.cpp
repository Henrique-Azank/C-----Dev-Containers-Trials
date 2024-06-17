
// Include the necessary libraries and namespaces
#include <vector>
#include <iostream>
using std::vector;

// Brute force "naive" method: "Sort-merging" the two arrays
double bruteForce(vector<int>& nums1, vector<int>& nums2) {

    // Double result
    double result = 0.0;

    // Hyphotetical vector size
    int vector_size = nums1.size() + nums2.size();
    bool is_even = vector_size % 2 == 0;
    int index_to_stop = vector_size/2;

    // Initializing the intermediate vars
    int i = 0;
    int j = 0;
    vector<int> merged_vec;

    // Looping through the two arrays
    while (i < nums1.size() && j < nums2.size()){

        // Break if the end is achieved
        if (merged_vec.size() == index_to_stop + 1) break;

        // Get the current elements
        int current1 = nums1[i];
        int current2 = nums2[j];

        // Deciding which element to add
        if (current1 < current2){
            // Add the element
            merged_vec.push_back(current1);
            ++i;
        } else {
            // Add the element
            merged_vec.push_back(current2);
            // Increase the variable count
            ++j;
        }
    }

    // Adding the final elements
    if (merged_vec.size() != index_to_stop + 1){
        // If the first vector is not done
        while (i < nums1.size()){
            merged_vec.push_back(nums1[i++]);
            if (merged_vec.size() == index_to_stop + 1) break;
        }

        // If the last vector is not done
        while (j < nums2.size()){
            merged_vec.push_back(nums2[j++]);
            if (merged_vec.size() == index_to_stop + 1) break;
        }
    }

    // Find the median
    if (is_even){
        result = (merged_vec[index_to_stop - 1] + merged_vec[index_to_stop])/2.0;
    } else {
        result = merged_vec[index_to_stop];
    }

    // Merged array is sorted
    return result;
};

// Main function
int main() {
    // Test case 1
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    double result = bruteForce(nums1, nums2);
    std::cout << "Median: " << result << '\n';

    // Test case 2
    vector<int> nums3 = {1, 2};
    vector<int> nums4 = {3, 4};
    double result2 = bruteForce(nums3, nums4);
    std::cout << "Median: " << result2 << '\n';

    return 0;
}
