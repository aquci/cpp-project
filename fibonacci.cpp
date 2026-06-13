#include <iostream>
#include <vector>

class BigInt {
private:
    std::vector<int> digits;

public:
    BigInt(int num = 0) {
        if (num == 0)
            digits.push_back(0);

        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }
    }

    BigInt operator+(const BigInt& other) const {
        BigInt result;
        result.digits.clear();

        int carry = 0;

        size_t size =
            std::max(digits.size(), other.digits.size());

        for (size_t i = 0; i < size || carry; i++) {

            int sum = carry;

            if (i < digits.size())
                sum += digits[i];

            if (i < other.digits.size())
                sum += other.digits[i];

            result.digits.push_back(sum % 10);

            carry = sum / 10;
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
    std::cin >> limit;
    for (int i = 2; i <= limit; i++) {

        BigInt next = first + second;

        first = second;
        second = next;
    }
    first.print();
    std::cout << std::endl;    
}

