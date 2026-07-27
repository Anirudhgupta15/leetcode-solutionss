class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1; // Peak lies to the right
            } else {
                right = mid;    // Peak lies at mid or to the left
            }
        }

        return left;
    }
};