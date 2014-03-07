//Given an array of strings, return all groups of strings that are anagrams.

//Note: All inputs will be in lower-case.


// using Hashtable 
// in stl unordered_map is a banlance tree.
// the methods of using hash for saving.

// It's like a example in beautiful code in charpter 1 or 2 not sure.
// sort the string as the key.




class Solution {
	public:
		vector<string> anagrams(vector<string> &strs) 
		{
			vector<string> output;
			unordered_map<string,vector<string> > string_map;

			for(int i=0; i<strs.size(); i++)
			{
				string temp=strs[i];
				sort(temp.begin(),temp.end());
				vector<string> val;
				val = string_map[temp];
				if(val.size()==0)
				{

					val.push_back(strs[i]);
					string_map[temp]=val;
				}
				else
					string_map[temp].push_back(strs[i]);
			}

			for (auto pos = string_map.begin(); pos != string_map.end(); ++pos) 
			{
				if(pos->second.size()>1)
				{
					for(int i=0;i<pos->second.size();++i)
						output.push_back(pos->second[i]);
				}
			}
			return output;   
		}
};
