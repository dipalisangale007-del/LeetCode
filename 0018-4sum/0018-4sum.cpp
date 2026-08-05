class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                long long sum = (long long)target - (nums[i] + nums[j]);
                int left = j + 1;
                int right = n - 1;

                while (left < right) {

                    long long sum2 = nums[left] + nums[right];  // FIXED

                    if (sum2 < sum)
                        left++;
                    else if (sum2 > sum)
                        right--;
                    else {
                        vector<int> temp(4);
                        temp[0] = nums[i];
                        temp[1] = nums[j];
                        temp[2] = nums[left];
                        temp[3] = nums[right];

                        ans.push_back(temp);  

                        while (left < right && nums[left] == temp[2])
                            left++;
                        while (left < right && nums[right] == temp[3])
                            right--;
                    }
                }
                while (j + 1 < n && nums[j + 1] == nums[j])
                    j++;
            }
            while (i + 1 < n && nums[i + 1] == nums[i])
                i++;
        }

        return ans;
    }
};
