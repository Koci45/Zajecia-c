#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

// Funkcja konwertująca znak na liczbę całkowitą
int charToInt(char digit) {
    if (isdigit(digit)) {
        return digit - '0';
    } else {
        return -1;
    }
}

// Funkcja czytająca zawartość pliku
std::string readFile(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Unable to open file\n";
        return "";
    }

    std::string fileContent((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    return fileContent;
}

// Funkcja obliczająca moc linii
int calculatePowerOfLine(const std::string& line) {
    int minGreen = 0, minBlue = 0, minRed = 0;
    int finalMinGreen = 0, finalMinBlue = 0, finalMinRed = 0;
    int gameNr = 0, digitCounter = 0;

    for (size_t i = 0; i < line.length(); ++i) {
        if (isdigit(line[i]) && digitCounter != 0) {
            int number = 0;
            size_t j = i;

            while (isdigit(line[j])) {
                number = number * 10 + charToInt(line[j]);
                ++j;
                i = j;
            }

            if (line[j + 1] == 'z') {
                minGreen += number;
            } else if (line[j + 1] == 'c') {
                minRed += number;
            } else if (line[j + 1] == 'n') {
                minBlue += number;
            }
        }

        if (line[i] == ';' || line[i] == '\0') {
            finalMinBlue = std::max(finalMinBlue, minBlue);
            finalMinRed = std::max(finalMinRed, minRed);
            finalMinGreen = std::max(finalMinGreen, minGreen);
            minBlue = 0;
            minGreen = 0;
            minRed = 0;
        }

        if (isdigit(line[i]) && digitCounter == 0) {
            gameNr = charToInt(line[i]);
            digitCounter++;
        }
    }

    std::cout << "Gra nr " << gameNr << ", Min zielonych: " << finalMinGreen << "  Min niebieskich: " << finalMinBlue << "  Min czerwonych: " << finalMinRed << std::endl;

    return finalMinBlue * finalMinGreen * finalMinRed;
}

// Funkcja obliczająca moc wszystkich linii
int calculatePower(const std::string& games) {
    int result = 0;
    size_t startOfLine = 0;

    for (size_t i = 0; i < games.length(); ++i) {
        if (games[i] == '\n' || games[i] == '\0') {
            std::string line = games.substr(startOfLine, i - startOfLine);
            int lineResult = calculatePowerOfLine(line);
            result += lineResult;
            startOfLine = i + 1;
        }
    }

    return result;
}

int main() {
    std::string fileContent = readFile("gry.txt");
    int result = calculatePower(fileContent);

    std::cout << "Koncowa moc wynosi: " << result << std::endl;

    return 0;
}
