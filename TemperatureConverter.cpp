#include <iostream>
#include <limits>

double CelsiusToFahrenheit(double temp);
double FahrenheitToCelsius(double temp);

int main()
{
    double temp;
    char cof;

    while (true)
    {
        std::cout << "Choose Celsius (C) Or Fahrenheit (F) Or Q (Quit): ";
        std::cin >> cof;
        cof = toupper(cof);

        if (std::cin.fail() || std::cin.peek() != '\n')
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid Input. Please Enter One Character.\n";
            continue;
        }

        if (cof == 'Q')
        {
            break;
        }

        std::cout << "Enter A Temperature: ";
        std::cin >> temp;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid Input. Please Enter A Number.\n";
            continue;
        }

        double result = 0;

        switch (cof)
        {
        case 'C':
            result = CelsiusToFahrenheit(temp);
            std::cout << "Your Temperature In Fahrenheit Is: " << result << '\n';
            break;
        case 'F':
            result = FahrenheitToCelsius(temp);
            std::cout << "Your Temperature In Celsius Is: " << result << '\n';
            break;
        case 'Q':
            break;
        default:
            std::cout << "Please Enter C, F Or Q.\n";
            continue;
        }
    }

    std::cout << "Thanks For Using My Calculator!\n";

    return 0;
}

double CelsiusToFahrenheit(double temp)
{
    double fahrenheitTemp = (temp * 1.8) + 32;

    return fahrenheitTemp;
}
double FahrenheitToCelsius(double temp)
{
    double celsiusTemp = (temp - 32) / 1.8;

    return celsiusTemp;
}