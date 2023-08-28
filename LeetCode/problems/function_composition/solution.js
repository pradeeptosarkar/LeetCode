/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
	return function(x) 
    {
        let ans=x;
        let arr = functions.reverse();
        
        arr.forEach((f)=>{
            ans=f(ans);
        });
        
        return ans;        
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */