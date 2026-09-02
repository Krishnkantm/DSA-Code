class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;

        int edge = 33554432;
       //time => O(n)
      //space => O(n)

        for (int i = 0; i < n; i++) {
            int curr_z = nums[i] / edge;
            string str(curr_z, 'z');

            int remain = nums[i] % edge;

            for (int j = 25; j >= 0; j--) {
                if ((remain & (1 << j))) {
                    str += char('a' + j);
                }
            }

            ans.push_back(str);
        }

        return ans;
    }
};
