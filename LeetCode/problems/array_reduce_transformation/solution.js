/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) 
{
    let accumlator = init;
    nums.forEach(element => accumlator = fn(accumlator, element) );
    return accumlator;
    
};