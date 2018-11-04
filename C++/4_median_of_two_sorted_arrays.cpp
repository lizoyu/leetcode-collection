#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // initialize
        int totalLength = nums1.size() + nums2.size();
        int numOfMedians = 0;
        if (totalLength % 2)
            numOfMedians = 1;
        else
            // two numbers in middle are needed to compute median
            numOfMedians = 2;
        
        // loop to cut unnecessary half of a array
        // i, j: head and tail of arrays
        int i1 = 0, j1 = nums1.size() - 1, i2 = 0, j2 = nums2.size() - 1, medianIdx = totalLength / 2;
        while (true) {
            // compute the length of remaining array
            int len1 = j1 - i1 + 1, len2 = j2 - i2 + 1;

            // ending condition: only 1 or 2 numbers left
            if (len1 + len2 == numOfMedians) {
                if (numOfMedians == 1) {
                    if (len1)
                        return nums1[i1];
                    else
                        return nums2[i2];
                }
                else
                    return (double) (nums1[i1] + nums2[i2]) / 2;
            }

            // determine which part to cut
            int medianIdx1 = len1 / 2, medianIdx2 = len2 / 2;
            int median1 = nums1[i1 + medianIdx1], median2 = nums2[i2 + medianIdx2];
            if (medianIdx1 + medianIdx2 < medianIdx) {
                if (median1 > median2) {
                    i2 += medianIdx2 + 1;
                    medianIdx -= medianIdx2 + 1;
                }
                else {
                    i1 += medianIdx1 + 1;
                    medianIdx -= medianIdx1 + 1;
                }
            }
            else {
                if (median1 > median2)
                    j1 -= medianIdx1 + 1;
                else
                    j2 -= medianIdx2 + 1;
            }
        }
    }
};

// driver
int main() {
    //vector<int> nums1 = {1, 2, 3, 4, 5, 9, 10}, nums2 = {6, 7, 8};
    vector<int> nums1 = {1, 2}, nums2 = {3, 4};

    Solution sol;
    cout << sol.findMedianSortedArrays(nums1, nums2) << endl;

    system("pause");
    return 0;
}
