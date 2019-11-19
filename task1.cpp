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
    int inp; 
    std::cout << "Enter array length: ";
    std::cin >> inp;

    int a[inp];

    for (int i = 0; i < inp; ++i)
    {
        std::cout << "Enter element: ";
        std::cin >> a[i];
    }

    if (is_sorted(a,inp))
        std::cout << "Array is sorted!" << std::endl;
    else
        std::cout << "Array is not sorted!" << std::endl;
    
    return 0;
}
