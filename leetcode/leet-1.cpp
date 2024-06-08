
// Include the necessary data structures
#include <vector>
#include <unordered_map>

// Namespace
using namespace std;

class Solution {


public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // Initializing the hash map
        unordered_map<int, int> hash_map;

        // Loop through the nums vector/array
        for (int i = 0; i < nums.size(); ++i) {

            // Complement of the target
            int complement = target - nums[i];

            // Verify if the complement is in the hash map
            if (hash_map.find(complement) != hash_map.end()) {
                return {i, hash_map[complement]};
            }

            // Else, populate the hash and continue
            hash_map[complement] = i;
        }

        // Base case if no solution is found
        return {};
    }
};