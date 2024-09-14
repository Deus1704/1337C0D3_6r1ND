string bin(int& num){
    string ans = "";
    while (num>0){
        ans+=(to_string(num%2));
        num/=2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

class Solution {
public:
    string convertDateToBinary(string date) {
        int year = stoi(date.substr(0,4)), month = stoi(date.substr(5,7)), dat = stoi(date.substr(8,date.size()));
        string ans = "";
        // cout<<bitset<8>(dat).to_string()<<endl;
        ans+=bin(year) + "-";
        ans+=bin(month)+ "-";
        ans+=bin(dat);
        return ans;
    }
};