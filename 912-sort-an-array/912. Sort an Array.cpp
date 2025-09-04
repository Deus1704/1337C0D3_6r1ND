class Solution {
public:
    vector<int>merge(vector<int>&left, vector<int>&right){
        int l=0,r=0,n=left.size(), m=right.size();
        vector<int>fin;
        while (l<n && r<m){
            if (left[l] <= right[r]){
                fin.push_back(left[l]); l++;
            }else if (left[l] > right[r]){
                fin.push_back(right[r]); r++;
            }
        }
        while(l<n){ 
            fin.push_back(left[l]); l++;
        }
        while(r<m){ 
            fin.push_back(right[r]); r++;
        }
        return fin;
    }
    vector<int> merge_sort(vector<int>&a){
        if (a.size() == 1) return a;
        int mid = a.size()/2;
        vector<int>left(a.begin(), a.begin()+mid);
        vector<int>right(a.begin()+mid, a.end());
        vector<int> left_sorted = merge_sort(left), right_sorted = merge_sort(right) ;
        return merge( left_sorted, right_sorted) ;
    }
    vector<int> sortArray(vector<int>& nums) {
        return merge_sort(nums);
        // return vector<int>c(nums.begin(), nums.begin()+nums.size()/2);
    }
};