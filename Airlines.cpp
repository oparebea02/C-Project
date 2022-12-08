#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <bits/stdc++.h>
using namespace std;

class Airlines {
public:
    string AirlineID;
    string AirlineName;
    string Alias;
    string Country;

    Airlines(const string &airlineId, const string &airlineName, const string &alias, const string &country)
            : AirlineID(airlineId), AirlineName(airlineName), Alias(alias), Country(country) {}

    const string &getAirlineId() const {
        return AirlineID;
    }

    const string &getAirlineName() const {
        return AirlineName;
    }

    const string &getAlias() const {
        return Alias;
    }

    const string &getCountry() const {
        return Country;
    }

    void setAirlineId(const string &airlineId) {
        AirlineID = airlineId;
    }

    void setAirlineName(const string &airlineName) {
        AirlineName = airlineName;
    }

    void setAlias(const string &alias) {
        Alias = alias;
    }

    void setCountry(const string &country) {
        Country = country;
    }
    int main()
    try{
        ifstream AirlineFile("airports.csv");
    }
    catch (exception io){
        cout << "Input/Output Error";
    }

};

