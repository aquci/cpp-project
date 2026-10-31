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

    std::cout << "miss: ";
    std::cin >> miss;

    std::cout << "delay: ";
    std::cin >> delay;
    
    if (!std::cin || kill < 0 || miss < 0 || delay < 0) {
        std::cerr << "Invalid input.\n";
        return 1;
    }
    
        const int total = kill + miss;
          if(total == 0) {
            return 1;
          }

        const double acc = 100.0 * kill / total;

        std::ofstream file("/home/onion/obsidian/dota/lh.md", std::ios::app);

    if (!file) {
        std::cerr << "Could not open the file.\n";
        return 1;
    }

    file << "1. " << date
         << " - " << kill << " kill"
         << ", " << miss << " miss"
         << ", " << delay << "ms delay"
         << ", " << std::fixed << std::setprecision(2)
         << acc << " acc\n";

    if (!file) {
        std::cerr << "Failed to write to the file.\n";
        return 1;
    }

    std::cout << "Training saved. Accuracy: "
              << std::fixed << std::setprecision(2)
              << acc << "%\n";

    return 0;  
}
