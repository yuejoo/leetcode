//Given a 2D binary matrix filled with 0's and 1's, find
//the largest rectangle containing all ones and return 
//its area.

//Based on LRiH which is O(n), so the result is O(n^2)

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) 
    {
        int maxm=0;
        vector<int> temp;
        vector<int> prev;
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[i].size();j++)
            {
                if(matrix[i][j]=='1')
                {
                    int m=1;
                    if(i==0)
                        temp.push_back(m);
                    else
                    {
                        temp.push_back(m+prev[j]);
                    }
                }
                else
                    temp.push_back(0);
            }
            maxm=max(maxm,largestRectangleArea(temp));
            
            prev=temp;
            temp.clear();
        }
        return maxm;
    }
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


