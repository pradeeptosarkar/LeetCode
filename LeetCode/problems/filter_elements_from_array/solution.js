/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) 
{
    let ans=[];
    
    arr.forEach((v,i) => {
        if(fn(v,i)) ans.push(v);
    })
    
    return ans;
};