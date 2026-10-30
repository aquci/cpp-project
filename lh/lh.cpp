#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>
#include <fstream>
#include <iostream>

std::string currentDate()
{
    const std::time_t now = std::time(nullptr);
    std::tm local{};

    if (localtime_r(&now, &local) == nullptr) {
        return {};
    }

    std::ostringstream out;
    out << std::put_time(&local, "%d.%m.%y");
    return out.str();
}

int main()
{
  int kill, miss, delay;
  const std::string date = currentDate();

    std::cout << "kill: ";
    std::cin >> kill;

    std::cout << "/n miss: ";
    std::cin >> miss;

    std::cout << "delay: ";
    std::cin >> delay;
    
    if (!std::cin || kill < 0 || miss < 0 || delay < 0) {
        std::cerr << "Invalid input.\n";
        return 1;
    }

}

