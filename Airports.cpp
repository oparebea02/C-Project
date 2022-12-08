//
// Created by LAURA LARBI TIEKU on 11/28/2022.
//

#include "Airports.h"
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

class Airports{
private:
    static string AirportID;
    static string AirportName;
    static string CityName;
    static string Country;
    static string IATACode;

    /**
     * Generating Constructor of Airports Class
     * */

public:
    Airports() {}

public:

    /**
     * Accessor and Mutator methods for Airports Class
     * */

    const string &getAirportId() const {
        return AirportID;
    }

    void setAirportId(const string &airportId) {
        AirportID = airportId;
    }

    const string &getAirportName() const {
        return AirportName;
    }

    void setAirportName(const string &airportName) {
        AirportName = airportName;
    }

    const string &getCityName() const {
        return CityName;
    }

    void setCityName(const string &cityName) {
        CityName = cityName;
    }

    const string &getCountry() const {
        return Country;
    }

    void setCountry(const string &country) {
        Country = country;
    }

    const string &getIataCode() const {
        return IATACode;
    }

    void setIataCode(const string &iataCode) {
        IATACode = iataCode;
    }
};