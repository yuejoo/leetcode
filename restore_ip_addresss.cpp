//Given a string containing only digits, restore it by returning all possible 
//valid IP address combinations.
//
//For example:
//Given "25525511135",
//
//return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

// remaining questions can not handle "00000000" "0000000001"






#include<iostream>
#include<vector>
#include<cstdlib>
#include<string>
using namespace std;
class Solution {
public:
    vector<string> output;
    vector<string> restoreIpAddresses(string s) 
    {
        string temp;
        int flag=0;
        storeip(temp,s,0,flag);
        return output;
        
        
    }
    
    void storeip(string temp, const string &s, int index, int &flag)
    {
        
        if(flag>4)
	{
            return;
        }
	if(flag == 4)
        {
	    if(index == s.size())
	    {
		temp.erase(temp.size()-1,1);
	    	cout<<temp<<endl;
            	output.push_back(temp);
            }
	    return;
            
	}
        
        
        string this_s;
        for(int i=index; i< index+3; i++)
        {
            if(i >= s.size())
                break;
	    if(i!=index && this_s[0]=='0')
	    {
		continue;
	    }	   
	    	this_s += s[i];
            if(atoi(this_s.c_str())<=255)
            {                          
                flag++;
                storeip(temp+this_s+'.',s, i+1 ,flag);
		flag--;
            }
            else
                return;
        }
        return;
        
    }
    
    
    
};

int main(int argc, char **argv)
{
	Solution m;

	vector<string> out;
	out=m.restoreIpAddresses(argv[1]);
	for(int i=0;i<out.size();i++)
		cout<<out[i];	
	return 0;
}
