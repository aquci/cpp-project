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
  int gems, krutki;
  const std::string date = currentDate();

    std::cout << "gems: ";
    std::cin >> gems;

    std::cout << "krutki: ";
    std::cin >> krutki;

        std::ofstream file("/home/onion/obsidian/gensh/gemi.md", std::ios::app);

    if (!file) {
        std::cerr << "Could not open the file.\n";
        return 1;
    }

    file << "1. " << date
         << " - " << gems << " гемов"
         << ", " << krutki << " круток \n"
         << std::fixed << std::setprecision(2);

    if (!file) {
        std::cerr << "Failed to write to the file.\n";
        return 1;
    }
    return 0;
}
