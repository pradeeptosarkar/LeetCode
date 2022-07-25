var searchRange = function(nums, target) {
    const ans = [Number.MAX_SAFE_INTEGER, Number.MIN_SAFE_INTEGER];
    const bs = (s = 0, e = nums.length - 1) => {
        if(s > e) return;
        
        const mid = Math.floor(s + (e - s) / 2);
        if(nums[mid] == target) {
            ans[0] = Math.min(mid, ans[0]);
            ans[1] = Math.max(mid, ans[1]);
            bs(s, mid - 1);
            bs(mid + 1, e);
        } else if(nums[mid] < target) {
            bs(mid + 1, e);
        } else {
            bs(s, mid - 1);
        }
    };
    bs();
    ans[0] = ans[0] == Number.MAX_SAFE_INTEGER ? -1 : ans[0];
    ans[1] = ans[1] == Number.MIN_SAFE_INTEGER ? -1 : ans[1];
    return ans;
};