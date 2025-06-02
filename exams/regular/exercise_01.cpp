#include <iostream>
#include <iomanip>

int main() {
    int championshipDays, neededPoints, swimmersCount;
    double hotelPricePerDay, participationFee;
    std::cin >> championshipDays >> neededPoints >> swimmersCount >> hotelPricePerDay >> participationFee;

    const double totalExpenses = (championshipDays * hotelPricePerDay + participationFee) * swimmersCount;
    double currentPoints, previousPoints = 0, totalPoints = 0;
    bool isSuccessful = false;

    for (int i = 0; i < championshipDays; i++) {
        std::cin >> currentPoints;
        currentPoints += previousPoints * 0.05;

        totalPoints += currentPoints;

        if (totalPoints >= neededPoints) {
            isSuccessful = true;
            break;
        }

        previousPoints = currentPoints;
    }

    if (isSuccessful) {
        std::cout << "Money left to pay: " << std::fixed << std::setprecision(2) << totalExpenses * 0.75 <<" BGN." << std::endl;
        std::cout << "The championship was successful!" << std::endl;
    } else {
        std::cout << "Money left to pay: " << std::fixed << std::setprecision(2) << totalExpenses * 0.9 <<" BGN." << std::endl;
        std::cout << "The championship was not successful." << std::endl;
    }

    return 0;
}