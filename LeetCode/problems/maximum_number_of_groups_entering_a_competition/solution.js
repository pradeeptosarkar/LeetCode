/**
 * @param {number[]} grades
 * @return {number}
 */
var maximumGroups = function(grades) 
{
    var ans=1;
    var n=grades.length;
    while(n-ans>ans)
        {
            n-=ans;
            ans++;
        }
    return ans;
};