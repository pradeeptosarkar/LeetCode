/**
 * @param {string[]} words
 * @param {string} pattern
 * @return {string[]}
 */
var findAndReplacePattern = function(words, pattern) 
{
    let ans=[];
    
    for(let i=0;i<words.length;i++)
        {
            let mp= new Map();
            let sett= new Set();
            let word= words[i];
            let check= true;
            
            for(let j=0;j<pattern.length;j++)
                {
                    if(mp[pattern[j]]===undefined && !sett.has(word[j]))
                        {
                            mp[pattern[j]]=word[j];
                            sett.add(word[j]);
                        }
                    if(word[j]!==mp[pattern[j]])
                        {
                            check=false;
                            break;
                        }
                }
            if(check)
                {
                    ans.push(word);
                }
        }
    return ans;
    
};