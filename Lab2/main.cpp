//OCdt Paterson 30648
//Date: 2024-01-30
//Lab 1
//A program to read through a .dat file and to perform functions such as sorting
//based on the data within the file

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
//declaring struct
struct type_flights {
    string flight_number;
    string departure_city;
    string arrival_city;
    float flight_cost{};
};

//declaring functions
int find_cheapest(type_flights flights_array[]);

int arrivaldeparture_count(type_flights flights_array[], const string &query);

float average_price(type_flights flights_array[], const string &query);

int sort_flights(type_flights flights_array[], int n);

int main() {
    ifstream flights; //open file stream
    flights.open("flights_10.dat"); //open file
    if (!flights.is_open()) { //checks if file open fails
        cerr << "Error opening file" << endl;
        return 1;
    }
    string line;
    int count = 0;
    while (!flights.eof()) { //counts the number of lines in the file
        getline(flights, line);
        count++;
    }
    if (line.empty()) { //count -1 if the last line is empty
        count--;
    }
    flights.close(); //close file
    auto *flights_array = new type_flights[count]; //dynamically allocate memory for the array
    flights.open("flights_10.dat"); //open file
    string tmp; //temporary string to store the line
    for (int i = 0;
         i < count; i++) { //read the file and store the values in the array
        getline(flights, tmp);
        stringstream ss(tmp);
        getline(ss, flights_array[i].flight_number, ',');
        getline(ss, flights_array[i].departure_city, ',');
        getline(ss, flights_array[i].arrival_city, ',');
        ss >> flights_array[i].flight_cost;
    }
    cout << "The first 5 flights are: " << endl;
    for (int i = 0; i < 5; i++) { //print the array

        cout << flights_array[i].flight_number << " "
             << flights_array[i].departure_city << " "
             << flights_array[i].arrival_city << " "
             << flights_array[i].flight_cost << endl;
    }
    cout << "The last 5 flights are:" << endl;
    for (int i = count - 5; i < count; i++) { //print the array
        cout << flights_array[i].flight_number << " "
             << flights_array[i].departure_city << " "
             << flights_array[i].arrival_city << " "
             << flights_array[i].flight_cost << endl;
    }
    cout << endl;
    flights.close(); //close file
    int cheapest = find_cheapest(
            flights_array); //assign cheapest flight function result to variable
    cout << "Cheapest flight: " << flights_array[cheapest].flight_number << " "
         << flights_array[cheapest].departure_city << " "
         << flights_array[cheapest].arrival_city << " "
         << flights_array[cheapest].flight_cost << endl << endl;

    //print the number of flights to each city
    if (arrivaldeparture_count(flights_array, "Chicago") == 0) {
        cout << "There are no flights to/from Chicago" << endl;
    } else {
        cout << "There are " << arrivaldeparture_count(flights_array, "Chicago")
             << " flight(s) to/from Chicago" << endl;
    }
    if (arrivaldeparture_count(flights_array, "Taipei") == 0) {
        cout << "There are no flights to/from Taipei" << endl;
    } else {
        cout << "There are " << arrivaldeparture_count(flights_array, "Taipei")
             << " flight(s) to/from Taipei" << endl;
    }
    if (arrivaldeparture_count(flights_array, "Washington") == 0) {
        cout << "There are no flights to/from Washington" << endl;
    }
    else {
        cout << "There are "
             << arrivaldeparture_count(flights_array, "Washington")
             << " flight(s) to/from Washington" << endl;
    }
    if (arrivaldeparture_count(flights_array, "Kingston") == 0) {
        cout << "There are no flights to/from Kingston" << endl << endl;
    } else {
        cout << "There are "
             << arrivaldeparture_count(flights_array, "Kingston")
             << " flight(s) to/from Kingston" << endl << endl;
    }

    //print the average price of flights to each city
    if (average_price(flights_array, "Chicago") == 0) {
        cout << "There are no flights from Chicago" << endl;
    } else {
        cout << "The average price of flights from Chicago is $"
             << printf("%0.1f", average_price(flights_array, "Chicago")) << endl;
    }
    if (average_price(flights_array, "Paris") == 0) {
        cout << "There are no flights from Paris" << endl;
    } else {
        cout << "The average price of flights from Paris is $"
             << printf("%0.1f", average_price(flights_array, "Paris")) << endl;
    }
    if (average_price(flights_array, "Kingston") == 0) {
        cout << "There are no flights from Kingston" << endl << endl;
    } else {
        cout << "The average price of flights from Kingston is $"
             << printf("%0.1f", average_price(flights_array, "Kingston")) << endl << endl;
    }

    //sort the flights by flight number
    sort_flights(flights_array, count);
    cout << "The first 10 flights: " << endl;
    for (int i = 0; i < 10; i++) {
        cout << flights_array[i].flight_number << " "
             << flights_array[i].departure_city << " "
             << flights_array[i].arrival_city << " "
             << flights_array[i].flight_cost << endl;
    }
    cout << "The last 10 flights: " << endl;
    for (int i = count - 10; i < count; i++) {
        cout << flights_array[i].flight_number << " "
             << flights_array[i].departure_city << " "
             << flights_array[i].arrival_city << " "
             << flights_array[i].flight_cost << endl;
    }
    return 0;
}

//function to find the cheapest flight
int find_cheapest(type_flights flights_array[]) {
    int cheapest = 0; //initialize cheapest to 0
    int countline = 0;
    ifstream flights;
    flights.open("flights_10.dat");
    while (!flights.eof()) {
        string line;
        getline(flights, line);
        countline++;
    }
    for (int i = 0;
         i < countline - 1; i++) { //loop through the array and compare the flight cost
        if (flights_array[i].flight_cost < flights_array[cheapest].flight_cost) {
            cheapest = i; //assign the index of the cheapest flight to the variable
        }
    }
    flights.close();
    return cheapest; //return index
}

//function to count the number of flights to a city
int arrivaldeparture_count(type_flights flights_array[], const string &query) {
    int count = 0; //initialize count to 0
    int countline = 0;
    ifstream flights;
    flights.open("flights_10.dat");
    while (!flights.eof()) {
        string line;
        getline(flights, line);
        countline++;
    }
    for (int i = 0; i < countline - 1; i++) { //loop through the array and compare the arrival/dep city
        if (flights_array[i].arrival_city == query) {
            count++; //+1 count
        }
        if (flights_array[i].departure_city == query) {
            count++; //+1 count
        }
    }
    if (count == 0) { //if count is 0, return 0
        return 0;
    }
    flights.close();
    return count;
}

//function to find the average price of flights from a city
float average_price(type_flights flights_array[], const string &query) {
    float count = 0; //initialize count to 0
    float total = 0;
    int countline = 0;
    ifstream flights;
    flights.open("flights_10.dat");
    while(!flights.eof()){
        string line;
        getline(flights, line);
        countline++;
    }
    for (int i = 0;
         i < countline - 1; i++) { //loop through the array and compare the departure city
        if (flights_array[i].departure_city == query) {
            count++;
            total += flights_array[i].flight_cost; //add the flight cost to total
        }
    }
    if (count == 0) {
        return 0;
    }
    return total / count; //return the average
}

//function to sort the flights by flight number
int sort_flights(type_flights flights_array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (flights_array[j].flight_number <
                flights_array[min].flight_number) {
                min = j;
            }
        }
        type_flights temp = flights_array[min];
        flights_array[min] = flights_array[i];
        flights_array[i] = temp;
    }
    return 0;
}