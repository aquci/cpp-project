#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

void clearScreen() {
    std::cout << "\033[2J\033[1;1H";
    std::cout.flush();
}

class DotaItem {
private:
    std::string name;
    std::string slot;
    int cost;

public:
    DotaItem(std::string n, std::string s, int c = 0): name(n), slot(s), cost(c) {}

    std::string getName() const { return name; }
    std::string getSlot() const { return slot; }
    int getCost() const { return cost; }
};

class BuildGenerator {
private:
    std::vector<DotaItem> universalItems;
    std::vector<DotaItem> physicalItems;
    std::vector<DotaItem> magicalItems;

public:
    BuildGenerator() {
        initializeItems();
}
    void initializeItems() {
        
        //универссальные шмотки

        universalItems.push_back(DotaItem("power treads", "boots", 1400));
        universalItems.push_back(DotaItem("phase boots", "boots", 1500));
        universalItems.push_back(DotaItem("boots of travel 2", "boots", 4500));
        universalItems.push_back(DotaItem("boots of bearing", "boots", 4225));
        universalItems.push_back(DotaItem("guardian greaves", "boots", 5050));
        
        universalItems.push_back(DotaItem("swift blink", "mobility", 6800));
        universalItems.push_back(DotaItem("overwhelming blink", "mobility", 6800));
        universalItems.push_back(DotaItem("arcane blink", "mobility", 6800));
        universalItems.push_back(DotaItem("silver edge", "mobility", 5800));
        universalItems.push_back(DotaItem("disperser", "mobility", 6100));

        universalItems.push_back(DotaItem("bloodthorn", "accessory", 6625));
        universalItems.push_back(DotaItem("scythe of vyse", "accessory", 5200));
        universalItems.push_back(DotaItem("gleipnir", "accessory", 4550));
        universalItems.push_back(DotaItem("nullifier", "accessory", 4375));
        universalItems.push_back(DotaItem("abyssal blade", "accessory", 6250));

        //физ билд

        physicalItems.push_back(DotaItem("battle fury", "farm", 3900));
        physicalItems.push_back(DotaItem("mjollnir", "farm", 5500));
        physicalItems.push_back(DotaItem("hand of midas", "farm", 2200));
        physicalItems.push_back(DotaItem("radiance", "farm", 4700));

        physicalItems.push_back(DotaItem("daedalus", "weapon", 5100));
        physicalItems.push_back(DotaItem("revenant's brooch", "weapon", 3300));
        physicalItems.push_back(DotaItem("desolator", "weapon", 3500));
        physicalItems.push_back(DotaItem("divine rapier", "weapon", 5600));
        physicalItems.push_back(DotaItem("monkey king bar", "weapon", 4700));

        physicalItems.push_back(DotaItem("assault cuirass", "armor", 5125));
        physicalItems.push_back(DotaItem("linkens sphere", "armor", 4800));
        physicalItems.push_back(DotaItem("satanic", "armor", 5050));
        physicalItems.push_back(DotaItem("black king bar", "armor", 4050));
        physicalItems.push_back(DotaItem("heart of tarrasque", "armor", 5200));
        physicalItems.push_back(DotaItem("sange and yasha", "armor", 4200));

        //маг билд

        magicalItems.push_back(DotaItem("ethereal blade", "magic", 5375));
        magicalItems.push_back(DotaItem("octarine core", "magic", 4800));
        magicalItems.push_back(DotaItem("dagon", "magic", 7450));
        magicalItems.push_back(DotaItem("parasma", "magic", 5975));
        magicalItems.push_back(DotaItem("refresher orb", "magic", 5000));
        magicalItems.push_back(DotaItem("yasha and kaya", "magic", 4200));
        magicalItems.push_back(DotaItem("meteor hammer", "magic", 2850));
        magicalItems.push_back(DotaItem("khanda", "magic", 5600));

        magicalItems.push_back(DotaItem("shivas guard", "magicArmor", 5175));
        magicalItems.push_back(DotaItem("eternal shroud", "magicArmor", 3700));
        magicalItems.push_back(DotaItem("kaya and sange", "magicArmor", 4200));
        magicalItems.push_back(DotaItem("wind waker", "magicArmor", 6800));
        magicalItems.push_back(DotaItem("black king bar", "magicArmor", 4050));

    }

    DotaItem getRandomFromVectorBySlot(const std::vector<DotaItem>& items, const std::string& slot) {
        std::vector<DotaItem> available;
        for (const auto& item : items) {
            if (item.getSlot() == slot) {
                available.push_back(item);
            }
        }
        if (!available.empty()) {
            return available[std::rand() % available.size()];
        }
        return DotaItem("Empty slot", "none", 0);
    }

    DotaItem getTotallyRandomFromVector(const std::vector<DotaItem>&items) {
        if (!items.empty()) {
            return items[std::rand() % items.size()]; 
        }
        return DotaItem ("empty", "none", 0);
    }

    DotaItem getTotallyRandomFromAllItems() {
        std::vector<DotaItem>allItems;
        allItems.insert(allItems.end(), universalItems.begin(), universalItems.end());
        allItems.insert(allItems.end(), physicalItems.begin(), physicalItems.end());
        allItems.insert(allItems.end(), magicalItems.begin(), magicalItems.end());

        if (!allItems.empty()) {
            return allItems[std::rand() % allItems.size()];
        }
        return DotaItem("empty", "none", 0);
    }

    void generatePhysicalBuild() {
        std::vector<DotaItem>build;
        int totalCost = 0;

        clearScreen();
        std::cout << "Dota 2 physical build randomaizer" << std::endl;

        build.push_back(getRandomFromVectorBySlot(universalItems, "boots"));
        build.push_back(getRandomFromVectorBySlot(physicalItems, "farm"));
        build.push_back(getRandomFromVectorBySlot(physicalItems, "weapon"));
        build.push_back(getRandomFromVectorBySlot(physicalItems, "armor"));
        build.push_back(getRandomFromVectorBySlot(universalItems, "mobility"));
        build.push_back(getRandomFromVectorBySlot(universalItems, "accessory"));
        build.push_back(getTotallyRandomFromVector(physicalItems));

        for (int i = 0; i < build.size(); i++) {
            std::cout << i + 1 << ". " << build[i].getName() << " (" << build[i].getCost() << " gold)" << std::endl;
            totalCost += build[i].getCost();
        }
        std::cout << "\n Total Cost: " << totalCost << " gold" << std::endl; 
    }
    
    void generateMagicalBuild() {
        std::vector<DotaItem>build;
        int totalCost = 0;

        clearScreen(); 
        std::cout << "Dota 2 magical build randomaizer" << std::endl;

        build.push_back(getRandomFromVectorBySlot(universalItems, "boots"));
        build.push_back(getRandomFromVectorBySlot(magicalItems, "magic"));
        build.push_back(getRandomFromVectorBySlot(magicalItems, "magic"));
        build.push_back(getRandomFromVectorBySlot(magicalItems, "magicArmor"));
        build.push_back(getRandomFromVectorBySlot(universalItems, "mobility"));
        build.push_back(getRandomFromVectorBySlot(universalItems, "accessory"));
        build.push_back(getTotallyRandomFromVector(magicalItems));

        for (int i = 0; i < build.size(); i++) {
            std::cout << i + 1 << ". " << build[i].getName() << " (" << build[i].getCost() << " gold)" << std::endl;
            totalCost += build[i].getCost();
        }
        std::cout << "\nTotal Cost: " << totalCost << " gold" << std::endl;
    }

    void generateTotallyRandomBuild() {
        std::vector<DotaItem>build;
        int totalCost = 0;

        clearScreen();
        std::cout << "Dota 2 totally random build" << std::endl;

        for(int i = 0; i < 7; i++) {
            build.push_back(getTotallyRandomFromAllItems());
        }

        for (int i = 0; i < build.size(); i++) {
            std::cout << i + 1 << ". " << build[i].getName() << " (" << build[i].getCost() << " gold)" << std::endl;
            totalCost += build[i].getCost();
        }
        std::cout << "\nTotal Cost: " << totalCost << " gold" << std::endl;
    }

    void generateRandomBuild() {
        if (std::rand() % 2 == 0) {
            generatePhysicalBuild();
        } else {
            generateMagicalBuild();
        }
    }
};

int main() {
    std::srand(std::time(0));

    BuildGenerator generator;

    int choice;
    do {
        clearScreen();
        std::cout << "=== Dota 2 build randomaizer ===" << std::endl;
        std::cout << "1. Generate Physical Build" << std::endl;
        std::cout << "2. Generate Magical Build" << std::endl;
        std::cout << "3. Generate Random Build (50/50)" << std::endl;
        std::cout << "4. Generate Totally Random Build" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Choose option: ";
        std::cin >> choice;

        switch(choice) {
            case 1:
                generator.generatePhysicalBuild();
                break;
            case 2:
                generator.generateMagicalBuild();
                break;
            case 3:
                generator.generateRandomBuild();
                break;
            case 4:
                generator.generateTotallyRandomBuild();
                break;
            case 5:
                std::cout << "Goodbye! GL HF!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice! Please try again." << std::endl;
                break;
        }
        if (choice != 5) {
            std::cout << "\nPress Enter to continue...";
            std::cin.ignore();
            std::cin.get();
        }

    } while (choice != 5);

    return 0;
}
