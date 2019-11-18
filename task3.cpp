#include <iostream>

void array_rows_cols(const int (*arr)[], int row_size, int column_size)
{
    int column_sum[row_size];

    for(int r=0; r<row_size; r++)
    {
        int row_sum = 0;
        for(int c=0; c<column_size; c++)
        {
            printf("%7.d", *(arr+c+r*column_size)); 
            row_sum += *(arr+c+r*column_size);
            column_sum[c] += *(arr+c+r*column_size);
        }
        printf("%7.d\n", row_sum);
    }

    int tot_sum = 0;
    for(int c=0; c<column_size; c++)
    {
        printf("%7.d", column_sum[c]); 
        tot_sum += column_sum[c];
    }
    printf("%7.d\n", tot_sum);
}

int main(void)
{
    int arr[8][8];

    array_rows_cols(arr,8,8);

    return 0;
}
