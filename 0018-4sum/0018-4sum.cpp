class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        set<vector<int>> st;
        for(int i=0; i<n-3; i++){
            for(int j=i+1; j<n-2; j++){
                long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];
                
                int low = j+1; 
                int high = n-1;

                while(low < high){
                    if(nums[low] + nums[high] < newTarget){
                        low++;
                    }else if(nums[low] + nums[high] > newTarget){
                        high--;
                    }else{
                        st.insert({nums[i], nums[j], nums[low], nums[high]});
                        low++;
                        high--;
                    }
                } 
            }
        }
        vector<vector<int>> result;
        for(auto p: st){
            result.push_back(p);
        }
        return result;
    }
};