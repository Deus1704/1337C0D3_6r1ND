class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>s(wordList.begin(),wordList.end());
        queue<pair<string, int>>q; q.push({beginWord, 1});
        s.erase(beginWord);
        while (!q.empty()){
            string word = q.front().first;
            int steps = q.front().second; q.pop();
            if (word == endWord) return steps;
            for (int i=0; i<word.size(); i++){
                char origin = word[i];
                for (char j = 'a'; j<='z'; j++){
                    word[i]=j;
                    if(s.find(word)!=s.end()){
                        s.erase(word);
                        q.push({word, steps+1});
                    }
                }
                word[i]=origin;
            }
        }
        return 0;
    }
};