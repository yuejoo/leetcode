//Given n non-negative integers representing the histogram's bar 
//height where the width of each bar is 1, find the area of larg
//est rectangle in the histogram.
//For example,
//Given height = [2,1,5,6,2,3],
//return 10.
//
//


class Solution {
public:
    int largestRectangleArea(vector<int> &height) 
    {
        vector<int> stack;
        int out=0;
        height.push_back(0);
        
        for(int i=0; i<height.size(); i++)
        {
            if(stack.size()==0 || height[i] > height[stack.back()])
            {
                stack.push_back(i);
            }
            else
            {
                int tmp=stack.back();
                stack.pop_back();
                out = max(out, height[tmp]*(stack.empty()? i : i-stack.back()-1)); 
                i--;

            }
        }

        
        return out;
    }
};
