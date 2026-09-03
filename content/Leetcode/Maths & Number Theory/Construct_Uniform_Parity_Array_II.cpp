class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        int odd = INT_MAX;
        //time = > O(n)
        //space => O(1)

        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] % 2 != 0) {
                odd = min(odd, nums1[i]);
            }
        }

        if (odd == INT_MAX)
            return true;

        for (int x : nums1) {
            if (x % 2 == 0 && x <= odd) {
                return false;
            }
        }

        return true;
    }
};
