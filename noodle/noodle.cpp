#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <clocale>
#include <algorithm>

int main() 
{
  std::setlocale(LC_ALL, "");

    std::vector<std::string> tags = {"анал", "любители", "вагина", "молодые", "отец", "сын", "дочь", "мать", "порно", "правило34",
                                     "русское", "японское", "видео", "за деньги", "инцест", "куколд", "секс", "ебет", "милф", "сиськи",
                                     "жопа", "чурка" "коматоз"};

    std::vector<std::string> name = {"выебал", "выебала", "трахнул", "рвет туз", "сосед", "соседа", "негр", "негра", "школьница",
                                     "школьницу", "дочка", "дочку", "мамка друга", "мамку друга", "японка", "японку", "милфа", "милфу",
                                     "огромный хуй", "брат", "брата", "сестра", "сестру", "татарка", "узбечка", "армянка", "казашка" "киргизка";

      std::random_device rd;
      std::mt19937 gen(rd());

    std::uniform_int_distribution<> countDist(1, 7);
      int count = countDist(gen);

    std::shuffle(name.begin(), name.end(), gen);
    std::shuffle(tags.begin(), tags.end(), gen);      

    for (int i = 0; i < count; i++)
    {
        std::cout << name[i] << " ";
    }
    std::cout << "| ";
    for (int a = 0; a < count; a++)
    {
        std::cout << tags[a] << " ";
    }
    std::cout << std::endl;

  return 0;
}

