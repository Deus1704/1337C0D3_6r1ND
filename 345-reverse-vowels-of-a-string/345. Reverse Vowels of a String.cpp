class Solution {
public:
    string reverseVowels(string s) {
        set<char> vowels {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};
        int left =0, right = s.size()-1;
        while (left<=right){
            //left check
            if (vowels.find(s[left])==vowels.end()){left++;}
            //right check
            if (vowels.find(s[right])==vowels.end()){right--;}
            //move ahead if not vowel.
            else if (vowels.find(s[left])!=vowels.end() && vowels.find(s[right])!=vowels.end()){
                char temp = s[left];
                s[left] = s[right];
                s[right] = temp;
                left++;right--;
            }
        }
        return s;
    }
};