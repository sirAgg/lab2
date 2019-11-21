#include "lab2lib.h"

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

//
// TASK 1
//

bool is_sorted(const int arr[], int size)
{
    for (int i = 1; i < size; ++i) 
    {
        if (!( arr[i-1] < arr[i]))
            return false;
    }

    return true;
}

void run_task1()
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
}

//
// TASK 2
//

bool is_palindrome(const char word[])
{
    int head = 0,tail;

    // find end of word
    for( tail = 0; word[tail] != '\0'; tail++);
    tail--;

    while(head <= tail)
    {
        if(word[head] != word[tail])
            return false;        

        head++;
        tail--;
    } 

    return true;
}

void run_task2()
{
    char inp[100];
    
    printf("Enter word: ");
    scanf("%100s",inp);

    printf("word is%s palindrome\n", (is_palindrome(inp) ? "" : " not"));
}

//
// TASK 3
//

void array_rows_cols(const int *arr, int row_size, int column_size)
{
    int *column_sum = new int[row_size];

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

void run_task3()
{

    int row, col;

    std::cout << "Number of rows: ";
    std::cin >> row;
    std::cout << "Number of columns: ";
    std::cin >> col;

    int *arr = new int[row*col];

    for (int i = 0; i < row*col; ++i)
        arr[i] = rand()%10;

    array_rows_cols(arr,row,col);
}

//
// TASK 4
//

bool greater_than(int& a, int& b)
{
    return a > b;
}

bool less_than(int& a, int& b)
{
    return a < b;
}

void swap_sort(int& a, int& b, bool (*sort_func)(int&,int&))
{
    // swaps a and b if sort_func is true
    if(sort_func(a,b))
    {
        a = b-a;
        b -= a;
        a += b;
    }
}

void swap_sort(int& a, int& b, int& c, bool acsending_order)
{
    bool (*sort_func)(int&,int&) = acsending_order ? greater_than : less_than;

    swap_sort(a,b,sort_func); 
    swap_sort(b,c,sort_func); 
    swap_sort(a,b,sort_func); 
}

#define askValue(v) std::cout << "Give value " #v ": "; std::cin >> v;

void run_task4()
{
    int a,b,c;
    
    askValue(a)
    askValue(b)
    askValue(c)

    char ans;

    std::cout << "Sort ascending? (Y/n) ";
    std::cin >> ans;

    bool sort_ascending = ans != 'n';

    swap_sort(a,b,c,sort_ascending);

    std::cout << "Result: " << a << ", " << b << ", " << c << std::endl;
}

//
// TASK 5
//

void shrink_array(int arr[], unsigned int size)
{
    unsigned int new_arr_tail = 0;
    unsigned int i = 0;

    for (; i < (size & ~1); i+=2) // i < size rounded down to closest even number
    {
        arr[new_arr_tail] = arr[i] + arr[i+1];     
        new_arr_tail++;
    }

    if(size & 1) // if size if odd
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

void run_task5()
{
    const int arr_size = 9;
    int a[arr_size];

    for (int i = 0; i < arr_size; ++i) {
        a[i] = rand()%10;
    }

    print_array(a,arr_size);

    shrink_array(a,arr_size);

    print_array(a,arr_size);
}

//
// TASK 6
//

void init_database( std::vector<std::string>& names )
{
    std::cout << "Are you sure? (yes/no)" << std::endl;
    while (true)
    {
        std::string input; 
        std::cin >> input;

        if (input == "yes")
            break;
        else if (input == "no")
            return;
        else
            std::cout << "Please type 'yes' or 'no'" << std::endl;
        
    }
    names = std::vector<std::string>();
}

void insert_name( std::vector<std::string>& names )
{
    while(true)
    {
        std::string new_name;
        std::cout << "Insert name ('q' to quit): ";  
        std::cin >> new_name;
        if (new_name == "Q" || new_name == "q")
            break;

        names.push_back(new_name);
    }
}

void search_name( std::vector<std::string>& names )
{
    std::string search_name;
    std::cout << "search: ";
    std::cin >> search_name;

    for( auto name : names )
    {
        if( search_name.length() <=  name.length())  
            if (search_name == name.substr(0,search_name.length()))
                std::cout << name << std::endl;
    }
}

void delete_name( std::vector<std::string>& names )
{
    std::string name;
    std::cout << "delete name: ";
    std::cin >> name;

    for (auto it = names.cbegin(); it != names.cend(); it++) 
    {
        if (name == *it)
        {
            names.erase(it);
            return;
        }
    }
    std::cout << "name not found" << std::endl;
}

void print_names( const std::vector<std::string>& names )
{
    for (auto name : names) 
        std::cout << name << std::endl;
}

void run_task6()
{
    std::vector<std::string> names = std::vector<std::string>();
    while(true)
    {
        std::cout << "\nMENU:" << std::endl; 
        std::cout << 
            "1. Intialise Database\n"
            "2. Insert\n"
            "3. Search\n"
            "4. Delete\n"
            "5. Print\n"
            "0. Quit\n";

        int input;
        std::cin >> input;
        std::cout << "\n";
        
        switch (input) {
            case 0: return;
            case 1: init_database(names); break;
            case 2: insert_name(names); break;
            case 3: search_name(names); break;
            case 4: delete_name(names); break;
            case 5: print_names(names); break;

            default:
                    std::cout << "Not a valid option" << std::endl;
        }
 
        
    }
}
