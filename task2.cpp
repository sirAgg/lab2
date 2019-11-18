#include <iostream>

bool is_palindrome(const char word[])
{
    int head = 0,tail;

    // find end of word
    for( tail = 0; word[tail] != '\0'; tail++);
    tail--;

    while(head > tail)
    {
        if(word[head] != word[tail])
            return false;        

        head++;
        tail--;
    } 

    return true;
}

int main(void)
{

    std::cout << is_palindrome("madam") << std::endl;
    
    return 0;
}
