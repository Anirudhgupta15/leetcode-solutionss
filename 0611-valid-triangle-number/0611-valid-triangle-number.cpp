class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int c=0;
        int n=nums.size();
        for(int k=n-1;k>=2;k--){
            int i=0,j=k-1;
            while(i<j){
                if(nums[i]+nums[j]>nums[k]){
                    c+=(j-i);
                    j--;
                }else{
                    i++;
                }
            }
        }return c;
    }
};