class Solution {
public:
    char kthCharacter(int k) {
        string s="a";
        // if (pow(2, log2(k)) == k) return char('a'+log2(k));
        int runs=9;
        while (runs--){
            string temp = s;
            for (auto &c:temp){
                char origi = c;
                c = char(origi+1);
            }
            s+=temp;
        }
        cout<<s<<endl;
        return s[k-1];
    }
};