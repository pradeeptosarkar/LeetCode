/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) 
{
    let ans=[];
    arr.forEach((n,i) => ans.push(fn(n,i)));
    return ans;   
};