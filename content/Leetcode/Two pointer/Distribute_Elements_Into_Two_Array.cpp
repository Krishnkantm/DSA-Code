class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> a1(n,0);
        
        a1[0] = nums[0];
        a1[n-1] = nums[1];

        int idx = 0;
        int ridx = n-1;
        for(int i=2;i<n;i++){
            if(a1[idx] > a1[ridx]){
                a1[++idx] = nums[i];
            }
            else{
                a1[--ridx] = nums[i];
            }
        }

        reverse(a1.begin() + ridx,a1.end());
        return a1;
    }
};
