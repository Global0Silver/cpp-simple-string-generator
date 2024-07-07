#include <ctime>
#include <iostream>
#include <unistd.h>
#include <limits>
#include <windows.h> 


std::string gen_random(int len) { 
    static char alphanum[] ="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    tmp_s.reserve(len);
    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    
    return tmp_s;
}


using namespace std;
int amount(){
    int amount;
    std::cout << "Enter the amount of strings to be generated \n>";
    while( ! ( std::cin >> amount || amount <= 0 ) ) {
        std::cin.clear();
        std::cin.ignore( std::numeric_limits<int>::max(), '\n' );
        std::cout << "Invalid input. Please enter a positive integer \n "; 
        std::cout << ">";
      }
    return amount;
}

int lenght(){
    int lenght;
    std::cout << "Enter the string's length \n>";
    while( ! ( std::cin >> lenght|| lenght <= 0 ) ) {
        std::cin.clear();
        std::cin.ignore( std::numeric_limits<int>::max(), '\n' );
        std::cout << "Invalid input. Please enter a positive integer \n "; 
        std::cout << ">";
    }
    return lenght;
}

int main() {
    std::cout << '\n';
    int amounts = amount();
    int lenghts = lenght();
    srand((unsigned)time(NULL) * getpid());
    time_t start = time(NULL);
    int progress = 0;
    for (int i = 0; i<amounts;i++){
        std::cout << "[GENERATED]" << gen_random(lenghts) << "\n";
        progress++;
    }
    time_t taken = time(NULL) - start;
    std::cout << "It took " << taken << " Seconds to generate " << amounts << " strings"; // not very accurate
            
    return 0;
}
