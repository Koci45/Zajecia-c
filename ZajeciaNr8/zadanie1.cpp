#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

// Deklaracja mapy globalnej
std::unordered_map<std::string, char> wordToDigitMap = {
    {"one", '1'}, {"two", '2'}, {"three", '3'}, {"four", '4'}, {"five", '5'},
    {"six", '6'}, {"seven", '7'}, {"eight", '8'}, {"nine", '9'}, {"zero", '0'}
};

// Funkcja dekodująca słowa na cyfry
char wordToDigit(const std::string& word) {
    return wordToDigitMap.at(word);
}

// Funkcja dekodująca linię tekstu
int decipherLine(const std::string& line) {
    size_t pos = 0;
    char firstNumber = '\0', lastNumber = '\0';

    // Szukanie pierwszej liczby
    while ((pos = line.find_first_of("0123456789", pos)) != std::string::npos) {
        firstNumber = line[pos];
        break;
    }

    // Szukanie pierwszego słowa liczby
    for (const auto& [word, digit] : wordToDigitMap) {
        if ((pos = line.find(word)) != std::string::npos) {
            if (firstNumber == '\0' || pos < line.find_first_of("0123456789")) {
                firstNumber = wordToDigit(word);
                break;
            }
        }
    }

    // Szukanie ostatniej liczby
    pos = line.size() - 1;
    while ((pos = line.find_last_of("0123456789", pos)) != std::string::npos) {
        lastNumber = line[pos];
        break;
    }

    // Szukanie ostatniego słowa liczby
    for (const auto& [word, digit] : wordToDigitMap) {
        if ((pos = line.find_last_of(word)) != std::string::npos) {
            if (lastNumber == '\0' || pos > line.find_last_of("0123456789")) {
                lastNumber = wordToDigit(word);
                break;
            }
        }
    }

    return (firstNumber - '0') * 10 + (lastNumber - '0');
}

// Funkcja dekodująca cały tekst
int decipher(const std::vector<std::string>& lines) {
    int result = 0;
    for (const auto& line : lines) {
        result += decipherLine(line);
    }
    return result;
}

int main() {
    std::ifstream file("szyfr.txt");
    if (!file.is_open()) {
        std::cerr << "Unable to open file\n";
        return 1;
    }

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    file.close();

    int result = decipher(lines);
    std::cout << result << std::endl;

    return 0;
}
