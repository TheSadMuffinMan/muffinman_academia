#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    std::size_t numTrips = 0;

    std::cin >> numTrips;
    std::size_t resultArray[numTrips]; // Holds the # of unique cities visited per trip.

    for (std::size_t i = 0; i < numTrips; i++)
    {
        std::size_t numCities = 0;
        std::cin >> numCities;

        std::string citiesArray[numCities];
        for (std::size_t x = 0; x < numCities; x++) // Populating array with "x"s.
        {
            citiesArray[x] = "x";
        }

        for (std::size_t j = 0; j < numCities; j++) // Loop to grab each input city.
        {
            std::string currCity;
            std::cin >> currCity;

            if (j == 0)
            {
                citiesArray[0] = currCity;
                resultArray[i] = 1;
                continue;
            }

            for (std::size_t k = 0; k < numCities; k++) // Compares currCity to ea string inside citiesArray.
            {
                if (citiesArray[k] == currCity)
                {
                    break;
                }
                else if (citiesArray[k] == "x")
                {
                    citiesArray[k] = currCity;
                    resultArray[i] = (resultArray[i] + 1);
                    break;
                }
            }
        }
    }

    for (std::size_t p = 0; p < numTrips; p++)
    {
        std::cout << resultArray[p] << std::endl;
    }

    return 0;
}