// https://open.kattis.com/problems/everywhere
/*
7/11/24 Kinda works, problems iterating resultArray. This is a good problem!

TASK:
    Alice travels a lot for her work. Each time she travels, she visits a single city before returning home.
        Someone recently asked her “how many different cities have you visited for work?” Thankfully Alice has kept a
        log of her trips. Help Alice figure out the number of cities she has visited at least once.

INPUT:
    The first line of input contains a single positive integer 'T'(<= 50) indicating the number of test cases. The
        first line of each test case also contains a single positive integer 'n' indicating the number of work trips
        Alice has taken so far. The following lines 'n' describe these trips. The 'i'th such line simply contains the
        name of the city Alice visited on her 'i'th trip.
    Alice’s work only sends her to cities with simple names: city names only contain lowercase letters, have at least
        one letter, and do not contain spaces.
    The number of trips is at most 100 and no city name contains more than 20 characters.

    Example1:
2
7
saskatoon
toronto
winnipeg
toronto
vancouver
saskatoon
toronto
3
edmonton
edmonton
delta

OUTPUT:
    For each test case, simply output a single line containing a single integer that is the number of distinct cities
        that Alice has visited on her work trips.
    
    Example1:
    4
    2
*/

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
        std::cout << resultArray[p] << " ";
        // std::cout << resultArray[p] << std::endl;
    }

    return 0;
}