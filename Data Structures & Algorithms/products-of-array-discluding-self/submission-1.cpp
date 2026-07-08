class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n,1);
        vector<int> suffix(n,1);
        vector<int> output(n,1);

        prefix[0] = nums[0];
        for(int i = 1;i<n;++i){
            prefix[i] = prefix[i-1]*nums[i];
        }

        suffix[n-1] = nums[n-1];
        for(int i = n-2;i >= 0;--i){
            suffix[i] = suffix[i+1]*nums[i];
        }
        for(int i =0; i<n;++i){
            int leftProduct = (i == 0) ? 1 : prefix[i-1];
            int rightProduct = (i == n - 1) ? 1 : suffix[i + 1];
            output[i] = leftProduct * rightProduct;
        }
        return output;
    }
};
