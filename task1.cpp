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
    const int MAX_LENGTH = 200;

    int arr[MAX_LENGTH];
    int len;

    std::cout << "Enter lenght: ";
    std::cin >> len;

    for (int i = 0; i < len; i++)
    {
        std::cout << "Enter element: ";
        std::cin >> arr[i];
    }

    if (is_sorted(arr,len))
        std::cout << "Array is sorted!" << std::endl;
    else
        std::cout << "Array is not sorted!" << std::endl;
    
    return 0;
}
