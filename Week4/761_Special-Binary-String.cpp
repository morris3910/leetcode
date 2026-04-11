class Solution {
public:
    string makeLargestSpecial(string s) {
        if(s.length() < 3)
            return s;
        
        int counter = 0, pos = 0;
        std::vector<std::string> mountains;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '0')
                counter--;
            else
                counter++;

            if(!counter){
                std::string mountain = makeLargestSpecial(s.substr(pos+1, i-pos-1));
                pos = i + 1;
                cout<<mountain<<endl;
                mountains.push_back("1" + mountain + "0");
            }
        }

        std::sort(mountains.begin(), mountains.end(), std::greater<std::string>());

        std::string ans = "";
        for(auto &m : mountains)
            ans += m;

        return ans; 
    }
};