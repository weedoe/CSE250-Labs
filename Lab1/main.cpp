#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct type_flights{
    string flight_number;
    string departure_city;
    string arrival_city;
    string flight_cost;
};
int find_cheapest(type_flights flights_array[]);
int arrival_count(type_flights flights_array[]);
int main() {
    ifstream flights;
    flights.open("flights_10.dat");
    if(!flights.is_open()){
        cerr << "Error opening file" << endl;
        return 1;
    }
    string line;
    int count = 0;
    while(!flights.eof()){
        getline(flights, line);
        count++;
    }
    if(line.empty()){
        count--;
    }
    flights.close();
    auto* flights_array = new type_flights[count];
    flights.open("flights_10.dat");
    string tmp;
    for (int i = 0; i < count; i++) {
        getline(flights, tmp);
        stringstream ss(tmp);
        getline(ss, flights_array[i].flight_number, ',');
        getline(ss, flights_array[i].departure_city, ',');
        getline(ss, flights_array[i].arrival_city, ',');
        ss >> flights_array[i].flight_cost;
    }
    for (int i = 0; i < count; i++) {
        cout << flights_array[i].flight_number << " " << flights_array[i].departure_city << " " << flights_array[i].arrival_city << " " << flights_array[i].flight_cost << endl;
    }
    flights.close();
    int cheapest = find_cheapest(flights_array);
    cout << "Cheapest flight: " << flights_array[cheapest].flight_number << " " << flights_array[cheapest].departure_city << " " << flights_array[cheapest].arrival_city << " " << flights_array[cheapest].flight_cost << endl;
    return 0;
}
int find_cheapest(type_flights flights_array[]){
    int cheapest = 0;
    for (int i = 0; i < 10; i++) {
        if(stoi(flights_array[i].flight_cost) < stoi(flights_array[cheapest].flight_cost)){
            cheapest = i;
        }
    }
    return cheapest;
}
int arrival_count(type_flights flights_array[]){
    int count = 0;
    for (int i = 0; i < 10; i++) {
        if(flights_array[i].arrival_city == "Chicago"){
            count++;
        }
    }
    return count;
};
