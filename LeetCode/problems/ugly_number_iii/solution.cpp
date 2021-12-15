class Solution 
{
public:
    using ll=long long;
    ll lcm(ll a,ll b)
    {
        return (a*b)/(__gcd(a,b));
    }
    ll find(ll a,ll b,ll c,ll mid)
    {
        ll x1=(mid/a)+(mid/b)+(mid/c);
        return x1-(mid/lcm(a,b))-(mid/lcm(b,c))-(mid/lcm(a,c))+(mid/lcm(a,lcm(b,c)));
    }
    int nthUglyNumber(int n, int a, int b, int c) 
    {
        ll l=min({a,b,c});
        ll r=1e18+1000;
        ll ans=0;
        while(l<=r)
        {
            ll mid=l+(r-l)/2;
            if(find(a,b,c,mid)<n)
            {
                l=mid+1;
            }
            else
            {
                ans=mid;
                r=mid-1;
            }
        }
        return (int)ans;
    }
};