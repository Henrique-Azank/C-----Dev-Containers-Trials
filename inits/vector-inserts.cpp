#include <vector>
#include <iostream>

int main() {

    // Instantiate the vectors
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = {6, 7, 8};

    // Insert the entire vec2 into vec1 at the end
    vec1.insert(vec1.end(), vec2.begin() + 0, vec2.end());

    // Print the elements of vec1
    for (int num : vec1) {
        std::cout << num << " ";
    }

    std::cout << std::endl;

    return 0;
}