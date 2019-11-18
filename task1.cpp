#include <iostream>

bool is_sorted(const int arr[], int size)
{
    for (int i = 1; i < size; ++i) 
    {
        if (!( arr[i-1] < arr[i]))
            return false;
    }

    return true;
}

int main(void)
{
    int arr[] = {1,3,4,2,7,9};

    std::cout << is_sorted(arr,6) << std::endl;
    
    return 0;
}
