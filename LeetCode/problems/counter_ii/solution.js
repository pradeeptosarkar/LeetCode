/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) 
{
    let ans=init;
    
    let increment = function()
    {
        return ans+=1;
    }
    
    let decrement = function()
    {
        return ans-=1;
    }
    
    let reset = function()
    {
        return ans=init;
    }
    
    return{increment, decrement, reset};
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */