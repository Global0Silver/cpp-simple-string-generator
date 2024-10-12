#include <ctime>
#include <iostream>
#include <unistd.h>
#include <limits>

//TODO make it output to a txt file
std::string gen_random(int lenghts,const char* alphanum,int ar_size) {
    std::string tmp_s;
    tmp_s.reserve(lenghts);
    for (int i = 0; i < lenghts; ++i) {
        tmp_s += alphanum[rand() % (ar_size - 1)];
    }
    tmp_s += "\n";
    return tmp_s;
}



std::string char_type(){
    std::string str;
    int char_choice;
    std::cout << "select what type of letters you want to be in the string\n";
    std::cout << "Both      >1\n";
    std::cout << "Lowercase >2\n";
    std::cout << "Uppercase >3\n";
    std::cout << "None      >4\n";
    std::cout << ">";
    while (!(std::cin >> char_choice) || char_choice < 1 || char_choice > 4) {
        std::cout << "Invalid input. Please enter a valid positive integer(1-4) \n "; 
        std::cout << ">";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
    
    switch (char_choice){
    case 1:
        str += "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        break;
    case 2:
        str += "abcdefghijklmnopqrstuvwxyz";
        break;
    case 3:
        str += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        break;
    case 4:
        break;
    }
    std::string numb_choice;
    std::cout << "Include numbers (y/N)\n>";
    std::cin >> numb_choice;
    if (numb_choice == "y"){
        str += "0123456789";
    }
    return str;
}


using namespace std;
int get_amount(){
    int amount;
    std::cout << "Enter the amount of strings to be generated \n>";
    while (!(cin >> amount) || amount < 1) {
        std::cout << "Invalid input. Please enter a positive integer \n"; 
        std::cout << ">";
        std::cin.clear();
        std::cin.ignore( std::numeric_limits<int>::max(), '\n' );
    
      }
    return amount;
}

int get_lenght(){
    int lenght;
    std::cout << "Enter the string's length \n>";
    while (!(std::cin >> lenght) || lenght < 1 ) {
        std::cout << "Invalid input. Please enter a positive integer \n"; 
        std::cout << ">";
        std::cin.clear();
        std::cin.ignore( std::numeric_limits<int>::max(), '\n' );
        
    }
    return lenght;
}

int main() {
    std::cout << '\n';
    int amounts = get_amount();
    int lenghts = get_lenght();
    //convert string to char and get its size using strlen hacky solution
    std::string str = char_type();
    const char* alphanum = str.c_str(); 
    srand((unsigned)time(NULL) * getpid());;
    time_t start = time(NULL);
    int ar_size =  strlen(alphanum);
    int j = 0;
    for (int i = 0; i<amounts;i++){
            std::cout << gen_random(lenghts,alphanum,ar_size);
        }

    time_t taken = time(NULL) - start;
    std::cout << "It took " << taken << " Seconds to generate " << amounts << " strings"; // not very accurate
            
    return 0;
}
