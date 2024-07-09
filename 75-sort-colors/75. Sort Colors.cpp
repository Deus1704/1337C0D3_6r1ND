class Solution {
public:
    void sortColors(vector<int>& nums) {
        // sort(nums.begin(),nums.end()); //lol?
        // DNF Algo
        int leftptr =0;
        int highptr = nums.size()-1;
        int midptr =0;
        while (highptr >= midptr){
            switch (nums[midptr]){
                case 0:
                    swap(nums[leftptr++], nums[midptr++]);
                    break;
                case 1:
                    midptr++;
                    break;
                case 2:
                    swap(nums[midptr], nums[highptr--]);
                    break;
            }
        }
    }
};