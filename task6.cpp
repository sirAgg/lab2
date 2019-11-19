#include <iostream>
#include <vector>
#include <string>

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

void main_loop( std::vector<std::string>& names )
{
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

int main(void)
{
    std::vector<std::string> names = std::vector<std::string>();

    main_loop(names);

    return 0;
}
