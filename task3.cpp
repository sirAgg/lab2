#include <iostream>
#include <cstdlib>
#include <time.h>

void array_rows_cols(const int *arr, int row_size, int column_size)
{
	int *column_sum = new int[row_size]();

    int tot_sum = 0;

    for(int r=0; r<row_size; r++)
    {
        int row_sum = 0;
        for(int c=0; c<column_size; c++)
        {
            printf("%7.d", *(arr+c+r*column_size)); 
            row_sum += *(arr+c+r*column_size);
            column_sum[c] += *(arr+c+r*column_size);
        }
        printf(" | %7.d\n", row_sum);

        tot_sum += row_sum;
    }

	// print separating line
	std::cout << "   ";
	for (int i = 0; i < (row_size+1) * 7; i++)
		std::cout << '-';
	std::cout << '\n';

    for(int c=0; c<column_size; c++)
    {
        printf("%7.d", column_sum[c]); 
        tot_sum += column_sum[c];
    }
    printf(" | %7.d\n", tot_sum);
}

int main(void)
{

	srand(time(NULL)); // set seed for rand
    int row, col;

    std::cout << "Number of rows: ";
    std::cin >> row;
    std::cout << "Number of columns: ";
    std::cin >> col;

    int *arr = new int[row*col];

    for (int i = 0; i < row*col; ++i)
        arr[i] = rand()%10+1; // +1 to avoid zeros, zeros won't print

    array_rows_cols(arr,row,col);

    return 0;
}
