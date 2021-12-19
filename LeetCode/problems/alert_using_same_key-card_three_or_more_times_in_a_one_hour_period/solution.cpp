class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
         map<string,set<int>> nameToTimes;
        for( int i = 0; i < keyName.size(); i++)
        {
            auto& timeString = keyTime[ i ];
            auto timeInDayMins = stoi( timeString.substr( 0, 2 ) ) * 60 + stoi( timeString.substr( 3 ) );
            nameToTimes[ keyName[ i ] ].insert( timeInDayMins );
        }
        
        vector<string> result;
        for( auto mapPair: nameToTimes )
        {
            auto& times = mapPair.second;
            auto prevTime1 = -1;
            auto prevTime2 = -1;
            for( auto time: times )
            {
                if ( prevTime1 == -1 )
                {
                    prevTime1 = time;
                }
                else if ( prevTime2 == -1 )
                {
                    prevTime2 = prevTime1;
                    prevTime1 = time;
                }
                else
                {
                    if ( time - prevTime2 <= 60 )
                    {
                        result.push_back( mapPair.first );
                        break;
                    }
                    prevTime2 = prevTime1;
                    prevTime1 = time;
                }
            }
        }
        
        return result;
     
    }
};