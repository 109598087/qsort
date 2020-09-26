#include <iostream>
#include <array>
#include <vector>
using namespace std;
#define MAX 10



int ppartition(double * nums_begin, double * nums_end, int low, int high)
{
    bool high_flag = true;
    bool low_flag = false;
    double pivot = nums_begin[low];
    int len_of_nums = nums_end-nums_begin;
    while(low<high && low<len_of_nums && high<len_of_nums)
    {
        if(high_flag)
        {
            if(nums_begin[high]<pivot) /////////////////////////////////
            {
                nums_begin[low] = nums_begin[high];
                high_flag = false;
                low_flag = true;
            }
            else
            {
                high -= 1;
            }
        }
        if(low_flag)
        {
            if(nums_begin[low]>pivot) /////////////////////////////////
            {
                nums_begin[high] = nums_begin[low];
                high_flag = true;
                low_flag = false;
            }
            else
            {
                low += 1;
            }
        }
    }
    nums_begin[low] = pivot;
    return low;
}
double * qsort(double * nums_begin, double * nums_end)
{
    vector< int > arr;

    int low = 0;
    int high = (nums_end-nums_begin)-1;
    if(low<high)
    {
        int mid = ppartition(nums_begin, nums_end, low, high);
        if(low<mid-1)
        {
            arr.push_back(low);
            arr.push_back(mid - 1);
        }
        if( mid + 1 < high)
        {
            arr.push_back(mid + 1);
            arr.push_back(high);
        }
        while(!arr.empty())
        {
            int r = arr.back();
            arr.pop_back();
            int l = arr.back();
            arr.pop_back();
            mid = ppartition(nums_begin, nums_end, l, r);
            if(l<mid-1)
            {
                arr.push_back(l);
                arr.push_back(mid - 1);
            }
            if(mid + 1 < r)
            {
                arr.push_back(mid + 1);
                arr.push_back(r);
            }
        }


    }

    return nums_begin;
}

int main()
{
    array <double, 7> nums1 = {2, 1, 5, 8, 10, 7, 3};
    qsort(nums1.begin(), nums1.end());
    int i;
    for(i=0; i<nums1.end()-nums1.begin(); i++)
    {
        cout << nums1[i] << endl;
    }









    return 0;
}
