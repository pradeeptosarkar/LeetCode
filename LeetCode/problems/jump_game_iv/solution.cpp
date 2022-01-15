/* ogo

1345. Jump Game IV

Description

Hints

Submissions

Discuss

Solution

      

C++ bfs solution

C++ bfs solution

114

VIEWS

1

reated at: February 8, 2020 9:31 PM

mrmitzh

mrmitzh

 103

Use a queue to try every next step, when we have a solution, we just need to return.
*/

class Solution {

public:

    int minJumps(vector<int>& arr) {

        if(arr.size() <= 1)

            return 0;

        std::unordered_map<int,std::vector<int>> map;

        for(int i = 0;i < arr.size();i++)

        {

            map[arr[i]].push_back(i);

        }

        int n = arr.size();

        std::queue<int> q;

        std::vector<int> visited(arr.size(),0);

        std::vector<int> distance(arr.size(),0);

        q.push(n-1);

        while(!q.empty())

        {

            if(distance[0] != 0)

                break;

            int cur = q.front();

            q.pop();

            if(cur >= 1 && !visited[cur-1])

            {

                q.push(cur-1);

                visited[cur-1] = 1;

                distance[cur-1] = distance[cur] + 1;

            }

            if(cur + 1 < n && !visited[cur+1])

            {

                q.push(cur+1);

                visited[cur+1] = 1;

                distance[cur+1] = distance[cur] + 1;

            }

            for(auto i: map[arr[cur]])

            {

                if(!visited[i])

                {

                    q.push(i);

                    visited[i] = 1;

                    distance[i] = distance[cur] + 1;

                }

            }

        }

        return distance[0];

    }

};
        

