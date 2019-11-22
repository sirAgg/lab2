#include <vector>
#include <string>

bool is_sorted(const int arr[], int size);
void run_task1();

bool is_palindrome(const char word[]);
void run_task2();

void array_rows_cols(const int *arr, int row_size, int column_size);
void run_task3();

bool greater_than(int& a, int& b);
bool less_than(int& a, int& b);
void swap_sort(int& a, int& b, bool (*sort_func)(int&,int&));
void swap_sort(int& a, int& b, int& c, bool acsending_order);
void run_task4();

void shrink_array(int arr[], unsigned int size);
void print_array(int arr[], int size);
void run_task5();

void init_database( std::vector<std::string>& names );
void insert_name( std::vector<std::string>& names );
void search_name( std::vector<std::string>& names );
void delete_name( std::vector<std::string>& names );
void print_names( const std::vector<std::string>& names );
void run_task6();
