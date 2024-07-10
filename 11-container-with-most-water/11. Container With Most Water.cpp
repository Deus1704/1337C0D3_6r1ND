class Solution {
public:
    int maxArea(vector<int>& height) {
        int leftptr=0;
        int rightptr = height.size()-1;
        int maxArea = 0;
        while(rightptr > leftptr){
            maxArea = max(maxArea, (min(height[leftptr],height[rightptr])*(rightptr-leftptr)));
            if (height[leftptr]>height[rightptr]) rightptr--;
            else{
                leftptr++;
            }
        }
        return maxArea;
    }
};