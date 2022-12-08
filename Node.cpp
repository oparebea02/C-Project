//
// Created by LAURA LARBI TIEKU on 11/28/2022.
//

#include "Node.h"
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <bits/stdc++.h>
using namespace std;

class Node{
private:
    Node *Parent;
    string AirportCode; //the airport code is the state
    string AirlineCode;
    int Stops;

public:
    Node(Node *parent, const string &airportCode, const string &airlineCode, int stops) : Parent(parent),
                                                                                          AirportCode(airportCode),
                                                                                          AirlineCode(airlineCode),
                                                                                          Stops(stops) {}

    const string &getAirportCode() const {
        return this->AirportCode;
    }

public:

    const Node &getParent() const {
        return *this->Parent;
    }


    void setAirportCode(const string &airportCode) {
        this->AirportCode = airportCode;
    }

    const string &getAirlineCode() const {
        return this->AirlineCode;
    }

    void setAirlineCode(const string &airlineCode) {
        this->AirlineCode = airlineCode;
    }


    int getStops() {
        return this->Stops;
    }

public:
    vector<string> SolutionPath(){
        //To-Do: Implement this method to generate the solution path
        vector<string> sequenceList;
        vector<string> stopsList;
        vector<string> airportCodesList;
        vector<string> airlineCodesList;

        Node *currentNode = this;

        while (currentNode != nullptr){
            stopsList.push_back(to_string(currentNode->getStops()));
            airlineCodesList.push_back(currentNode->getAirlineCode());
            airportCodesList.push_back(currentNode->getAirportCode());

            currentNode = currentNode->Parent;
        }
        //Reversing each list to generate the items from start to finish instead of the other way round
        std::reverse(stopsList.begin(), stopsList.end());
        std::reverse(airlineCodesList.begin(), airlineCodesList.end());
        std::reverse(airportCodesList.begin(), airportCodesList.end());

        for (int i = 0; i < airlineCodesList.size() - 1; i++){
            string resultingStatement = i+1 + ". " + airlineCodesList[i+1] + " from " + airportCodesList[i] +
                    " to " + (airportCodesList[i+1]) + " " + stopsList[i] + " stops.";
            sequenceList.push_back(resultingStatement);
        }
        return sequenceList;
    }



};