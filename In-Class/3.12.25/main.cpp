// 1396. Design Underground System
#include <unordered_map>
#include <string>
#include <utility>
using namespace std;

class UndergroundSystem {
public:
    // <from, to> --> <sum travel times, number of travels>
    unordered_map<string, unordered_map<string, pair<int, int>>> travels;
    
    // customer --> <start time, station name>
    unordered_map<int, pair<int, string>> customer;

    UndergroundSystem() {
    }
    
    void checkIn(int id, string stationName, int t) {
        customer[id] = {t, stationName};
    }
    
    void checkOut(int id, string stationName, int t) {
        string startStation = customer[id].second;
        int startTime = customer[id].first;
        
        // Calculate the travel time
        int travelTime = t - startTime;
        
        // Update the travels map
        travels[startStation][stationName].first += travelTime;
        travels[startStation][stationName].second += 1;
        
        // Remove the customer from the 'customer' map after checkout
        customer.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        // Get the total travel time and number of travels for the route
        auto travelInfo = travels[startStation][endStation];
        int totalTime = travelInfo.first;
        int numTravels = travelInfo.second;
        
        // Return the average time
        return (double)totalTime / numTravels;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
