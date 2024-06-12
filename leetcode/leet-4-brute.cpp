
// Include the necessary libraries and namespaces
#include <vector>
#include <iostream>
using std::vector;

// Brute force "naive" method: "Sort-merging" the two arrays
double bruteForce(vector<int>& nums1, vector<int>& nums2) {

    // Initializing the intermediate vars
    int i = 0;
    int j = 0;
    vector<int> merged_vec;

    // Median return
    double result = 0.0;

    // Looping through the two arrays
    while (i < nums1.size() && j < nums2.size()){

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

    // Iterator is out of bounds (end)
    if (i == nums1.size()){
        std::cout << "\nFirst vector is done" << std::endl;
        // First vector is done
        merged_vec.insert(merged_vec.end(), nums2.begin() + j, nums2.end());
    }

    if (j == nums2.size()){
        std::cout << "\nSecond vector is done" << std::endl;
        // Second vector is done
        merged_vec.insert(merged_vec.end(), nums1.begin() + i, nums1.end());
    }

    // Find the median of the return vector
    if (merged_vec.size() % 2 == 0){
        // Merged vector has even size
        int index = merged_vec.size() / 2;
        result = (merged_vec[index] + merged_vec[index - 1]) / 2.0;
    } else {
        // Merged vector has odd size
        int index = merged_vec.size() / 2;
        result = merged_vec[index];
    }


    // Print the merged vector
    for (int num : merged_vec){
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Merged array is sorted
    return result;
};

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
