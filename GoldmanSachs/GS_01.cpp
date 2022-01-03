#Given an array of strings, return all groups of strings that are anagrams.

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        map<map<char, int>, vector<string>> m;
      
        for(string str: string_list)
        {
            map<char, int> tmap;
            vector<string> tlist;
            
            for(int i=0; i<str.size(); i++)
                ++tmap[str[i]];
                
            auto it = m.find(tmap);
                
            if(it != m.end())
                it->second.push_back(str);
            else
            {
                tlist.push_back(str);
                m.insert({tmap, tlist});
            }
            
        }
      
        vector<vector<string>> res;
        for(auto it = m.begin(); it!= m.end(); ++it)
                res.push_back(it->second);
        
        return res;
        }
};
