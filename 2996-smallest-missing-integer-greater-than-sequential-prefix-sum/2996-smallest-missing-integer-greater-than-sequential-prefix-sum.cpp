class Solution {
public:
    int missingInteger(vector<int>& nums) {
        long long sum=0;
        int ind=0,n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i+1]==nums[i]+1){
                sum+=nums[i];
                ind=i;
            }
            else{
                ind=i;
                break;
            }
        }
        if(ind==n-2 && nums[n-2]+1 == nums[n-1]) sum+=nums[n-1];
        else if(sum+=nums[ind]);
        while(find(nums.begin(), nums.end(), sum) != nums.end()){
            sum++;
        }
        return sum;
    }
};