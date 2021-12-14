class Solution
{
public:
    int peakIndex(int low, int high, MountainArray &mountainArr)
    {
        if (low > high)
            return -1;
        int mid = (low + high) / 2;
        int a = mountainArr.get(mid - 1);
        int b = mountainArr.get(mid);
        int c = mountainArr.get(mid + 1);

        if (a < b && b > c)
            return mid;

        if (b < c)
            return peakIndex(mid, high, mountainArr);

        return peakIndex(low, mid, mountainArr);

        // return -1;
    }
    int binary1(int low, int high, int target, MountainArray &mountainArr)
    {
        // left search
        if (low > high)
            return -1;

        int mid = (low + high) / 2;

        int b = mountainArr.get(mid);
        if (b == target)
            return mid;

        if (b < target)
            return binary1(mid + 1, high, target, mountainArr);

        else
            return binary1(low, mid - 1, target, mountainArr);
    }
    int binary2(int low, int high, int target, MountainArray &mountainArr)
    {
        // left search
        if (low > high)
            return -1;

        int mid = (low + high) / 2;

        int b = mountainArr.get(mid);

        if (b == target)
            return mid;

        if (b > target)
            return binary2(mid + 1, high, target, mountainArr);

        else
            return binary2(low, mid - 1, target, mountainArr);
    }
    int findInMountainArray(int target, MountainArray &m)
    {
        int index = peakIndex(0, m.length() - 1, m);
        if (m.get(index) == target)
        {
            return index;
        }
        int Lres = binary1(0, index - 1, target, m);
        if (Lres != -1)
        {
            return Lres;
        }
        int Rres = binary2(index + 1, m.length() - 1, target, m);
        if (Rres != -1)
        {
            return Rres;
        }
        return -1;
    }
};