class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        // Brute O(n^2) == O(10^8), so should work.
        int n = arr.size();
        // map<int, int>mp; 
        // for (int i=0; i<n; i++){
        //     int orer = 0;
        //     for (int j=i; j<n; j++){
        //         orer |= arr[j];
        //         mp[orer]++;
        //     }
        // }
        // return mp.size();
        set<int>prev,cur, result;
        for (int i=0; i<n; i++){
            for (auto &x:prev){
                cur.insert(x|arr[i]);
                result.insert(x|arr[i]);
            }
            // Cur mei khud a[i] ko bhi daalo, and even result mei
            cur.insert(arr[i]);
            result.insert(arr[i]);
            prev = cur; cur.clear();
        }
        return result.size();
    }
};