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
int open_file(ifstream &flights, const string &file_name);
int sort_flights(type_flights flights_array[], int n);


int main() {
    ifstream flights;
    string file_name = "flights_10.dat";
    int count = open_file(flights, file_name);
    type_flights flights_array[count];
    flights.open(file_name);
    if (!flights.is_open()) {
        cerr << "Error opening file" << endl;
    }
    string line;
    string tmp; //temporary string to store the line
    int i;
    for (i = 0; i < count; i++) { //read the file and store the values in the array
        getline(flights, tmp);
        stringstream ss(tmp);
        getline(ss, flights_array[i].flight_number, ',');
        getline(ss, flights_array[i].departure_city, ',');
        getline(ss, flights_array[i].arrival_city, ',');
        ss >> flights_array[i].flight_cost;
    }
    flights.close();
    cout << "The first 5 flights are: " << endl;
    for (i = 0; i < 5; i++) { //print the array

        cout << flights_array[i].flight_number << " "
             << flights_array[i].departure_city << " "
             << flights_array[i].arrival_city << " "
             << flights_array[i].flight_cost << endl;
    }
    cout << "The last 5 flights are:" << endl;
    for  (i = count - 5; i < count; i++) { //print the array
        cout << flights_array[i].flight_number << " "
             << flights_array[i].departure_city << " "
             << flights_array[i].arrival_city << " "
             << flights_array[i].flight_cost << endl;
    }
    cout << endl;

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

int open_file(ifstream &flights, const string &file_name) {
    flights.open(file_name); //open file
    if (!flights.is_open()) { //checks if file open fails
        cerr << "Error opening file" << endl;
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
    flights.close();//close file
    return count;
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