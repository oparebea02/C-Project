//
// Created by DANIEL LARBI TIEKU on 11/27/2022.
//
#include "Routes.h"
#include <iostream>
#include <rpcndr.h>
#include <bits/stdc++.h>

using namespace std;


class Routes{
private:
    string AirlineCode;
    string AirlineID;
    string sourceAirportCode;
    string destinationAirportCode;
    int stops;

    /**
     * Generating Constructors of Routes Class
     * */

public:
    Routes(const string &airlineCode, const string &airlineId, const string &sourceAirportCode,
           const string &destinationAirportCode, int stops) : AirlineCode(airlineCode), AirlineID(airlineId),
                                                              sourceAirportCode(sourceAirportCode),
                                                              destinationAirportCode(destinationAirportCode),
                                                              stops(stops) {}

    /**
     * Generating Getters and Setters
     * */

    const string &getAirlineCode() const {
        return AirlineCode;
    }

    void setAirlineCode(const string &airlineCode) {
        AirlineCode = airlineCode;
    }

    const string &getAirlineId() const {
        return AirlineID;
    }

    void setAirlineId(const string &airlineId) {
        AirlineID = airlineId;
    }

    const string &getSourceAirportCode() const {
        return sourceAirportCode;
    }

    void setSourceAirportCode(const string &sourceAirportCode) {
        Routes::sourceAirportCode = sourceAirportCode;
    }

    const string &getDestinationAirportCode() const {
        return destinationAirportCode;
    }

    void setDestinationAirportCode(const string &destinationAirportCode) {
        Routes::destinationAirportCode = destinationAirportCode;
    }

    int getStops() const {
        return stops;
    }

    void setStops(int stops) {
        Routes::stops = stops;
    }

    bool operator==(const Routes &rhs) const {
        return AirlineCode == rhs.AirlineCode &&
               AirlineID == rhs.AirlineID &&
               sourceAirportCode == rhs.sourceAirportCode &&
               destinationAirportCode == rhs.destinationAirportCode &&
               stops == rhs.stops;
    }


public:
    string toString(){
        return "Routes{",
               "AirlineCode='" + AirlineCode + '\'' +
               ", AirlineID='" + AirlineID + '\'' +
               ", SourceAirportCode= '" + sourceAirportCode + '\'' +
               ", DestinationAirportCode='" + destinationAirportCode + '\'' +
               ", Stops= " + to_string(stops) + "}";
    }
//
//public:
//    int hashCode() {
//        return Objects.hash(AirlineCode, AirlineID, sourceAirportCode, destinationAirportCode, stops);
//    }

};
