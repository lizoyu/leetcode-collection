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
            numOfMedians = 2;
        
        // loop to cut unnecessary half of a array
        int i1 = 0, j1 = nums1.size() - 1, i2 = 0, j2 = nums2.size() - 1, medianIdx = totalLength / 2;
        while (true) {
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

/***
*def findMedianSortedArrays(self, A, B):
*    l = len(A) + len(B)
*    if l % 2 == 1:
*        return self.kth(A, B, l // 2)
*    else:
*        return (self.kth(A, B, l // 2) + self.kth(A, B, l // 2 - 1)) / 2.   
*    
*def kth(self, a, b, k):
*    if not a:
*        return b[k]
*    if not b:
*        return a[k]
*    ia, ib = len(a) // 2 , len(b) // 2
*    ma, mb = a[ia], b[ib]
*    
*    # when k is bigger than the sum of a and b's median indices 
*    if ia + ib < k:
*        # if a's median is bigger than b's, b's first half doesn't include k
*        if ma > mb:
*            return self.kth(a, b[ib + 1:], k - ib - 1)
*        else:
*            return self.kth(a[ia + 1:], b, k - ia - 1)
*    # when k is smaller than the sum of a and b's indices
*    else:
*        # if a's median is bigger than b's, a's second half doesn't include k
*        if ma > mb:
*            return self.kth(a[:ia], b, k)
*        else:
*            return self.kth(a, b[:ib], k)
***/