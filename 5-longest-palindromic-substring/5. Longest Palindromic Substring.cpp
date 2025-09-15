
// Note 2, CANT USE THE SAME CONCEPT AS THE PALINDROMIC SUBSEQUENCE. THIS IS SOMETHING DIFF.
// IT PASSES 141 FUCKING TEST CASES OUT OF 142
// Read the fucking question correctly. It is Substring and not Subsequence
class Solution {
public:
    bool is_palindrome(string &s, int i, int j, vector<vector<char>>&dp){ // This is the bottleneck, this has a TC-> ~O(N)
        if (i>=j){
            return  true;
        }
        if (s[i] == s[j]){
            return dp[i][j] = is_palindrome(s, i+1, j-1, dp);
        }else return false;
    }
    string longestPalindrome(string s1) {
        string s2 = "";
        int n=s1.size();
        int len = 0, ptr = -1;
        vector<vector<char>>dp(n, vector<char>(n,0));
        for(int i=0; i<n; i++){ // O(n)
            for(int j=0; i+j<n; j++){ // ~O(n)
                // string temp = s1.substr(i, j+1); This too is O(n)
                if (dp[i][i+j]){ // already calculated and its a palindrome, simply use its length
                    if (j+1 > len){
                        len = j+1; ptr = i;
                    }
                }
                else if (is_palindrome(s1, i , i+j, dp) && j+1 > len) { // ~O(n)
                    len = j+1; ptr= i;
                    dp[i][i+j] = 1;
                }
            }
        }
        // for(auto&i:dp){
        //     for(auto &j:i) cout<<j<<","; cout<<"\n";
        // }
        return s1.substr(ptr, len);
    }
};