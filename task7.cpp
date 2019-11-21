#include <iostream>
#include "lab2lib.h"

int main(void)
{
    while (true)
    {
        std::cout << 
            "\nLAB 2 MENU:\n"
            "1: Task 1\n"
            "2: Task 2\n"
            "3: Task 3\n"
            "4: Task 4\n"
            "5: Task 5\n"
            "6: Task 6\n"
            "0: Quit\n"
            "\n"
            "Enter task: ";

        int inp;
        std::cin >> inp;

        switch (inp) {
            case 0: return 0;
            case 1: run_task1(); break;
            case 2: run_task2(); break;
            case 3: run_task3(); break;
            case 4: run_task4(); break;
            case 5: run_task5(); break;
            case 6: run_task6(); break;
                
            default: 
                    std::cout << "Invalid option!" << std::endl;
        }
    }

    return 0;
}
