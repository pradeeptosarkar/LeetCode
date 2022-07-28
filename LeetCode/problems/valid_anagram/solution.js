/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */

function getCode(string, i)
{
    return string.charCodeAt(i) - 'a'.charCodeAt(0);
}

var isAnagram = function(s, t) 
{
    if(s.length!=t.length)
        return false;
    
    const arr= new Array(26).fill(0);
    const n=s.length;
    
    for(let i=0;i<n;i++)
        {
            arr[getCode(s,i)]++;
            arr[getCode(t,i)]--;
        }
    
    const maxi=Math.max(...arr);
    if(maxi>0)
        return false;
    return true;
    
};