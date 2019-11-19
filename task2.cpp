#include <iostream>

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

int main(void)
{
    char inp[100];
    
    scanf("%100s",inp);

    printf("word is%s palindrome\n", (is_palindrome(inp) ? "" : " not"));
    
    return 0;
}
