#include <iostream>
#include <vector>
#include <string>

int timeStrToMins(const std::string& str) {
    const int hours = (str[0] - '0') * 10 + (str[1] - '0');
    const int mins = (str[2] - '0')  * 10 + (str[3] - '0');
    return hours * 60 + mins;
}

void readVector(std::vector<int>& v) {
    for (int& number : v) {
        std::string timeStr;
        std::cin >> timeStr;
        number = timeStrToMins(timeStr);
    }
}

int main() {
    int arrivalTimesCount;
    std::cin >> arrivalTimesCount;

    std::vector<int> arrivalTimesMins(arrivalTimesCount);
    readVector(arrivalTimesMins);

    std::string departureTimeStr;
    std::cin >> departureTimeStr;

    const int departureTimesMins = timeStrToMins(departureTimeStr);
    int minTimeDifferenceMins = departureTimesMins + 1, index = -1;

    for (int i = 0; i < arrivalTimesCount; i++) {
        const int timeDifferenceMinutes = departureTimesMins - arrivalTimesMins[i];

        if (timeDifferenceMinutes >= 0 && timeDifferenceMinutes < minTimeDifferenceMins) {
            minTimeDifferenceMins = timeDifferenceMinutes;
            index = i;
        }
    }

    std::cout << index + 1 << std::endl;
    return 0;
}