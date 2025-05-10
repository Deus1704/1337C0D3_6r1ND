// // O(N^2 + N^2) : MY SOLUTION WHICH IS FUCKING GIVING TLE EVEN THOUGH IT WORKS WHEN TESTED WITH SAME TC
// class Solution {
// public:
//     int uniqueXorTriplets(vector<int>& nums) {
//         int n = nums.size();
//         int temp = 0; set<int>aij, final_pos;
//         //O(N^2)
//         for (int i=0; i<n; i++){
//             for (int j=i; j<n; j++){
//                 aij.insert(nums[i]^nums[j]);
//             }
//         }
//         // O(3000N); Since at max there can be x1+x2 (1500+1500)
//         for (auto x:aij){
//             for (auto k:nums){
//                 final_pos.insert(x^k);
//             }
//         }
//         return final_pos.size();
//     }
// };

// Some Random Guys' Same logic based code:
class Solution {
public:
    int uniqueXorTriplets(vector<int>& a) {
        unordered_set<int> st, s;
        int n = a.size();

        for(int i=0; i<n; i++){
            for(int j = i; j<n; j++){
                st.insert(a[i]^a[j]);
            }
        }

        for(auto num: st){
            for(auto x: a){               // num = a[i] ^ a[j] (XOR of pairs)
                s.insert(num^x);          // num^x = a[i]^a[j]^a[k]  ---> triplet xor inserted in set s for uniqueness
            }
        }
        return s.size();
    }
};