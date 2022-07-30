/**
 * @param {string[]} words1
 * @param {string[]} words2
 * @return {string[]}
 */
var wordSubsets = function(words1, words2) 
{
    let ans=[];
    let max_freq= new Array(26).fill(0);
    
    for(let i of words2)
        {
            let temp_freq=findFrequency(i);
            
            for(let i=0;i<temp_freq.length;i++)
                {max_freq[i]=Math.max(temp_freq[i],max_freq[i]);}
        }
    
    for(let i of words1)
        {
            let curr_freq=findFrequency(i);
            let isSub=findSubset(curr_freq);
            
            if(isSub)
                {
                    ans.push(i);
                }
        }
    return ans;
    
    function findSubset(wordArray) 
    {
        for (let i=0; i<wordArray.length; i++) 
        {
            if (max_freq[i]>wordArray[i]) 
            {
                return false;
            }
        }

        return true;
    }
    
    function findFrequency(string) 
    {
        let stringArray = new Array(26).fill(0);

        for (let i=0; i<string.length; i++) 
        {
            let index = string.charCodeAt(i) - "a".charCodeAt();
            stringArray[index]++;
        }

        return stringArray;
    }
};