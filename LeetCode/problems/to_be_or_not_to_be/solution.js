/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {
    
        let toBe = function(compareVal){
            if (val !== compareVal) {
                throw new Error("Not Equal");
            }
            return true;
        }
        
        let notToBe = function(compareVal){
            if (val === compareVal) {
                throw new Error("Equal");
            }
            return true;
        }
        
        return {toBe, notToBe};
    
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */