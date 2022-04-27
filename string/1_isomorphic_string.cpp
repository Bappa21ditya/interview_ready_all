 bool isIsomorphic(string s, string t) {
        map<char,char>map1;
        map<char,bool>map2;
//         abac,xyxx
//    a->x ,b->y,a->x,c->y
        for(int i=0;i<s.size();i++)
        {
           if(map1.find(s[i])!=map1.end()) 
           {
             if(map1[s[i]]!=t[i])
               return false;
              }
             else
             { if(map2[t[i]]==true)
               return false;
              else
              {
                  
                map1[s[i]]=t[i];
                 map2[t[i]]=true;
                }
             }
        }
        return true;
        
    }
