#include <iostream>
#include <chrono>
#include <vector>
#include <cstdint>

class BigInt {

private:
    static const uint32_t BASE = 1000000000;

public:
    std::vector<uint32_t> digits;

    BigInt(uint64_t num = 0) {

        if (num == 0)
            digits.push_back(0);

        while (num > 0) {

            digits.push_back(num % BASE);

            num /= BASE;
        }
    }

    BigInt operator+(const BigInt& other) const {

        BigInt result;

        result.digits.clear();

        result.digits.reserve(
            std::max(
                digits.size(),
                other.digits.size()
            ) + 1
        );

        uint64_t carry = 0;

        size_t size =
            std::max(
                digits.size(),
                other.digits.size()
            );

        for (
            size_t i = 0;
            i < size || carry;
            i++
        ) {

            uint64_t sum = carry;

            if (i < digits.size())
                sum += digits[i];

            if (i < other.digits.size())
                sum += other.digits[i];

            result.digits.push_back(
                sum % BASE
            );

            carry =
                sum / BASE;
        }
        return result;
        }
        void print() const {
        for (int i = digits.size() - 1; i >= 0; i--)
        std::cout << digits[i];
}
};

int main() {

    BigInt first(0);

    BigInt second(1);

    int limit;

    std::cout
        << "Введите номер: ";

    std::cin
        >> limit;
        
    auto start =
    std::chrono::high_resolution_clock::now();

    for (
        int i = 1;
        i < limit;
        i++
    ) {

        BigInt next =
            first + second;

        first =
            std::move(second);

        second =
            std::move(next);
        }

    first.print();    
    auto end =
    std::chrono::high_resolution_clock::now();

    std::cout
    << "\nВремя: "
    << std::chrono::duration_cast<
    std::chrono::seconds
    >(
    end-start
    ).count()
    << " сек\n";
    std::cout
    << "Блоков: "
    << first.digits.size()
    << "\n";
}
