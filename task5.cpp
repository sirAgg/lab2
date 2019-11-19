#include <iostream>

void shrink_array(int arr[], unsigned int size)
{
    unsigned int new_arr_tail = 0;
    unsigned int i = 0;

    for (; i < (size & ~1); i+=2)
    {
        arr[new_arr_tail] = arr[i] + arr[i+1];     
        new_arr_tail++;
    }

    if(size & 1)
        arr[new_arr_tail++] = arr[i];

    for(; new_arr_tail < size; new_arr_tail++)
        arr[new_arr_tail] = 0;
}

void print_array(int arr[], int size)
{
    for (int i = 0; i < size; ++i) 
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main(void)
{
    const unsigned int arr_size = 9;
    int a[arr_size] = {1,2,4,5,6,7,8,9,7};

    print_array(a,arr_size);

    shrink_array(a,arr_size);

    print_array(a,arr_size);

    return 0;
}
