class Solution {
public:
    string triangleType(vector<int>& nums) {
        map<int,int>mp;
        for (auto &i:nums) mp[i]++;
        if (mp.size()==1) return "equilateral";
        else{
            bool cant=false;
            for (int i=0; i<nums.size(); i++){
                cout<<"Summing="<<nums[i%3]<<" & "<<nums[(i+1)%3]<<", and third="<<nums[(i+2)%3]<<endl;
                int sum_of_two = nums[i%3]+nums[(i+1)%3];
                int third = nums[(i+2)%3];
                if (sum_of_two <= third) {
                    cant = true;
                }
            }
            if (mp.size()==2 && !cant) return "isosceles";
            if (!cant) return "scalene";
            else return "none";
        }
    }
};