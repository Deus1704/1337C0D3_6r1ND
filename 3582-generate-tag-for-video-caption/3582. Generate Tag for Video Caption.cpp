#include <bits/stdc++.h>;
class Solution {
public:
    string generateTag(string caption) {
        string ans="#";
        int index=1, i=0, n=caption.size();
        while (i<n){
            string temp="";bool first=true;
            while ( isalpha(caption[i])){
                if (index==1 && first){
                    temp+=tolower(caption[i]);first=false;
                }else if (first){
                    temp+=toupper(caption[i]);first=false;
                }else{
                    temp+=tolower(caption[i]);
                }
                index++;i++;
            }ans+=temp;i++;
        }
        string cock="";int len = min(100,(int)ans.size());
        for (int i=0; i<len; i++){
            cock+=ans[i];
        }
        return cock;
    }
};