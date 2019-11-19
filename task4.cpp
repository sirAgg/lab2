#include <iostream>

void swap_sign(int& a, int& b, int& c)
{
    a *= -1; 
    b *= -1; 
    c *= -1; 
}

void swap_sort(int& a, int& b)
{
    // sorts a and b so that a <= b
    if( a > b )
    {
        int t = a; 
        a = b;
        b = t;
    }
}

void swap_sort(int& a, int& b, int& c, bool acsending_order)
{
    if (!acsending_order)
        swap_sign(a,b,c);

    swap_sort(a,b); 
    swap_sort(b,c); 
    swap_sort(a,b); 
    
    if (!acsending_order)
        swap_sign(a,b,c);
}

#define askValue(v) std::cout << "Give value " #v ": "; std::cin >> v;

int main(void)
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

    return 0;
}
