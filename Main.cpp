//
// Created by LAURA LARBI TIEKU on 11/29/2022.
//

#include "Main.h"
#include "Routes.cpp"
#include "Node.cpp"
#include "Airlines.cpp"
#include "Airports.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <list>
#include <bits/stdc++.h>
using namespace std;

class Main {
    //Hashmap to Store Airport Data with City&Country names as the key and an array list of IATA codes (Source airport code) as values
    static unordered_map<string, vector<string>> cityCountrytoAirportCodeMap;

    //Hashmap to Store Airport Data with IATA code (Source airport code) as key and City&Country names as values
    static unordered_map<string, string> airportCodetoCityCountryMap;

    //Hashmap to Store Route Data with IATA Code (Source Airport Code) as the key and a list of Route objects as values
    static unordered_map<string, vector<Routes>> routeHashmap;

    static vector<Routes> routesList;


public:
    bool Contains(queue <Node> structure, Node n);

    vector<string> breadthFirstSearch(string startingPoint, string endPoint);

    bool contains_List(list <string> explored_list, string airport_code);

    unordered_map<string, vector<Routes>> getHashmap(){
        return routeHashmap;
    }

    unordered_map<string, vector<string>> getCityandCountry(){
        return cityCountrytoAirportCodeMap;
    }

    unordered_map<string, string> GetAirportCodetoCityCountry(){
        return airportCodetoCityCountryMap;
    }



};

bool Main::Contains(queue<Node> structure, Node n) {
        while (!structure.empty()){
            if (structure.front().getAirportCode() == n.getAirportCode()){
                return true;
            }
            else{
                structure.pop();
            }
        }
        return false;
}

/**
 * This function takes in a list of strings and a string and returns true if the string is in the list and false if it is
 * not
 * @param explored_list a list of strings that represent the airport codes that have been explored
 * @param airport_code The airport code of the airport you want to find the shortest path to.
 * @return a boolean value.
 */
bool Main::contains_List(list<std::string> explored_list, std::string airport_code) {
    while (!explored_list.empty()){
        if (explored_list.front() == airport_code){
            return true;
        }
        else{
            explored_list.pop_front();
        }
    }
    return false;
}

 vector<string> Main:: breadthFirstSearch(string startingPoint, string endPoint) {
    queue <Node> frontier;
    list <string> exploredSet;

    vector<string> airportList = cityCountrytoAirportCodeMap[startingPoint];

    for (string airportCode: airportList) {
        frontier.push(*new Node(nullptr, nullptr, airportCode, 0));
    }
    while (frontier.size() > 0) {
        Node node = frontier.front();
        frontier.pop();
        exploredSet.push_back(node.getAirportCode());

        if (routeHashmap.count(node.getAirportCode()) > 0){
            routesList = routeHashmap.at(node.getAirportCode());
        }

        if (routesList.size() != 0) {
            for (Routes childStates: routesList) {
                Node *child = new Node(&node, childStates.getAirlineCode(),
                                       childStates.getDestinationAirportCode(), childStates.getStops());

                string endCityandCountry =
                        airportCodetoCityCountryMap.at(child->getAirportCode());
                if (endCityandCountry != "") {
                    if (!Contains(frontier, *child) && !contains_List(exploredSet, child->getAirportCode())) {
                        if (endCityandCountry == endPoint) {
                            return child->SolutionPath();
                        }
                        frontier.push(*child);
                    }
                }
            }
        }
    }
    vector <string> empty_vector;
    return empty_vector;
}


//Search algorithm; using breadth-first search to find the path



int main() {

    Main mainfile;
    try {
        //Reading the Routes file within a try block to handle any possible exceptions

        string temp;
        ifstream ReadRouteFile("routes.csv");

        while (getline(ReadRouteFile, temp)){

            stringstream temporary (temp);

            string airline_code;
            string airline_id;
            string src_airport_code;
            string dest_airport_code;
            string stops;

            getline(temporary, airline_code, ',');
            getline(temporary, airline_id, ',');
            getline(temporary, src_airport_code, ',');
            getline(temporary, dest_airport_code, ',');
            getline(temporary, stops, ',');

            //Creating a Route object
            Routes route(airline_code, airline_id, src_airport_code, dest_airport_code, stoi(stops));
            //casting stops to an integer since this array is an array of strings


            //Checking state of route array list to append route objects
            if (mainfile.getHashmap().count(src_airport_code) > 0){
                vector<Routes> route_list = mainfile.getHashmap().at(src_airport_code);
                route_list.push_back(route);
            }
            else{
                vector <Routes> new_route_list;
                new_route_list.push_back(route);
                mainfile.getHashmap().insert({src_airport_code,new_route_list});
            }
        }



        /*
         Reading the Airports file within a "try" to handle any possible exceptions
        */
        ifstream ReadAirportFile("airports.csv");

        while (getline(ReadAirportFile, temp)){

            stringstream temporary (temp);

            string airport_id;
            string airport_name;
            string city_name;
            string country;
            string iata_code;

            getline(temporary, airport_id, ',');
            getline(temporary, airport_name, ',');
            getline(temporary, city_name, ',');
            getline(temporary, country, ',');
            getline(temporary, iata_code, ',');

            string CityandCountry = city_name + "," + country;

            //Checking state of route array list to append route objects
            if (mainfile.getCityandCountry().count(iata_code) > 0){
                vector<string> city_country_list = mainfile.getCityandCountry().at(iata_code);
                city_country_list.push_back(iata_code);
            }
            else{
                vector<string> city_country_list;
                city_country_list.push_back(iata_code);
                mainfile.getCityandCountry().insert({iata_code,city_country_list});
            }

            mainfile.GetAirportCodetoCityCountry().insert({iata_code, CityandCountry});

        }



        //Reading the input file
        ifstream ReadInputFile("accra-ghana.txt");
        list<string> source_destination;


        while (getline(ReadAirportFile, temp)){

            stringstream temporary (temp);

            string city_name;
            string country_name;

            getline(temporary, city_name, ',');
            getline(temporary, country_name, ',');

            source_destination.push_back(city_name);
            source_destination.push_back(country_name);


        }

        string start_city = source_destination.front();
        source_destination.pop_front();
        string start_country = source_destination.front();
        source_destination.pop_front();
        string end_city = source_destination.front();
        string end_country = source_destination.back();
        //Testing breadth first search
        vector<string> Solution = mainfile.breadthFirstSearch(start_city+ "," + start_country, end_city+ "," + end_country);

        //Writing the output to the file
        fstream writtenOutput;
        string file_name = start_city + "-" + end_city+ "_output.txt";
        writtenOutput.open(file_name);
        if (!writtenOutput) {
            cout << "File not created";
        } else {
            cout << "File created successfully";
        }
        std::reverse(Solution.begin(), Solution.end());
        while (!Solution.empty()){
            writtenOutput << Solution.back() << endl;
            Solution.pop_back();
        }

//        for (int i = 0; i < Solution.size(); i++) {
//            writtenOutput.write((Solution.get(i)));
//            writtenOutput.write("\n");
//        }
        writtenOutput.close();

        cout << mainfile.getHashmap().size() << endl;
        cout << mainfile.GetAirportCodetoCityCountry().size() << endl;
        cout << mainfile.getCityandCountry().size() << endl;

    }
    catch (exception ie) {
        cout << "Exception found";
    }
}
