class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<Key, vector<string>, Key::Hash> dict;

        for (const auto& str : strs) 
        {
            Key key = generateHash(str);

            if (dict.find(key) != dict.end())
                dict[key].push_back(str);
            else
                dict[key] = { str };
        }

        vector<vector<string>> result;
        
        for (const auto& kvp : dict) 
            result.push_back(kvp.second);
        
        return result;
    }

private:
    struct Key 
    {
        long long first;
        long long second;
        long long third;

        bool operator==(const Key& other) const 
        {
            return first == other.first && second == other.second && third == other.third;
        }

        struct Hash 
        {
            size_t operator()(const Key& k) const 
            {
                return hash<long long>()(k.first) ^ hash<long long>()(k.second) ^ hash<long long>()(k.third);
            }
        };
    };

    Key generateHash(const string& input) {
        Key result = {0, 0, 0};

        for (char c : input) 
        {
            int charIndex = c - 'a';
            int slotIndex = charIndex % 9;

            switch (charIndex / 9) 
            {
                case 0:
                    result.first += (1LL << (slotIndex * 7));
                    break;
                case 1:
                    result.second += (1LL << (slotIndex * 7));
                    break;
                case 2:
                    result.third += (1LL << (slotIndex * 7));
                    break;
            }
        }

        return result;
    }
};
