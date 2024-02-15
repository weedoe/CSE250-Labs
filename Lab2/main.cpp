//OCdt Paterson 30648
//Date: 2024-02-15
//Lab 2
//A program to read through a .dat file and to perform functions such as sorting
//based on the data within the file

#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>

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
int selection_sort_flights(type_flights flights_array[], int n);
void firstlast_flights(type_flights flights_array[], int n);
int merge_sort_flights(type_flights flights_array[], int L, int R);
int quick_sort_flights(type_flights flights_array[], int L, int R);
void binary_search_flight(type_flights flights_array[], int n, string flight_number);


int main() {
    ifstream flights;
    string file_name = "flights_all_fixed.dat";
    int count = open_file(flights, file_name);
    unsigned long total_time;
    auto* flights_array = new type_flights[count];
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

    //Question 1
    cout << "----------Question 1----------" << endl;
    firstlast_flights(flights_array, count); //print the first and last 5 flights
    clock_t start = clock();
    //sort the flights by flight number
    selection_sort_flights(flights_array, count);
    total_time = clock() - start;
    firstlast_flights(flights_array, count); //print the first and last 5 flights
    cout << "SELECTION sort took " << total_time /  CLOCKS_PER_SEC << " seconds" << endl << endl;

    start = clock();
    selection_sort_flights(flights_array, count); //sort the flights by flight number
    total_time = clock() - start;
    firstlast_flights(flights_array, count); //print the first and last 5 flights
    cout << "SELECTION REsort took " << total_time /  CLOCKS_PER_SEC << " seconds" << endl << endl;

    delete[] flights_array;

    //Question 2
    cout << "----------Question 2----------" << endl;
    open_file(flights, file_name);
    flights_array = new type_flights[count];
    flights.open(file_name);
    if (!flights.is_open()) {
        cerr << "Error opening file" << endl;
    }
    for (i = 0; i < count; i++) { //read the file and store the values in the array
        getline(flights, tmp);
        stringstream ss(tmp);
        getline(ss, flights_array[i].flight_number, ',');
        getline(ss, flights_array[i].departure_city, ',');
        getline(ss, flights_array[i].arrival_city, ',');
        ss >> flights_array[i].flight_cost;
    }
    flights.close();
    start = clock();
    merge_sort_flights(flights_array, 0, count - 1);
    total_time = clock() - start;
    firstlast_flights(flights_array, count); //print the first and last 5 flights
    cout << "MERGE sort took " << total_time /  CLOCKS_PER_SEC << " seconds" << endl << endl;

    start = clock();
    merge_sort_flights(flights_array, 0, count - 1);
    total_time = clock() - start;
    firstlast_flights(flights_array, count); //print the first and last 5 flights
    cout << "MERGE REsort took " << total_time /  CLOCKS_PER_SEC << " seconds" << endl << endl;

    delete[] flights_array;

    //Question 3
    cout << "----------Question 3----------" << endl;
    open_file(flights, file_name);
    flights_array = new type_flights[count];
    flights.open(file_name);
    if (!flights.is_open()) {
        cerr << "Error opening file" << endl;
    }
    for (i = 0; i < count; i++) { //read the file and store the values in the array
        getline(flights, tmp);
        stringstream ss(tmp);
        getline(ss, flights_array[i].flight_number, ',');
        getline(ss, flights_array[i].departure_city, ',');
        getline(ss, flights_array[i].arrival_city, ',');
        ss >> flights_array[i].flight_cost;
    }
    flights.close();
    start = clock();
    quick_sort_flights(flights_array, 0, count - 1);
    total_time = clock() - start;
    firstlast_flights(flights_array, count); //print the first and last 5 flights
    cout << "QUICK sort took " << total_time /  CLOCKS_PER_SEC << " seconds" << endl << endl;

    start = clock();
    quick_sort_flights(flights_array, 0, count - 1);
    total_time = clock() - start;
    firstlast_flights(flights_array, count); //print the first and last 5 flights
    cout << "QUICK REsort took " << total_time /  CLOCKS_PER_SEC << " seconds" << endl << endl;

    delete[] flights_array;

    cout << "----------Question 4----------" << endl;
    cout << "Quick sort is slower on a sorted array because it has to search through the whole array to find the pivot."
            " Then it has to perform the entire sort." << endl;

    cout << "----------Question 5----------" << endl;
    open_file(flights, file_name);
    flights_array = new type_flights[count];
    flights.open(file_name);
    if (!flights.is_open()) {
        cerr << "Error opening file" << endl;
    }
    for (i = 0; i < count; i++) { //read the file and store the values in the array
        getline(flights, tmp);
        stringstream ss(tmp);
        getline(ss, flights_array[i].flight_number, ',');
        getline(ss, flights_array[i].departure_city, ',');
        getline(ss, flights_array[i].arrival_city, ',');
        ss >> flights_array[i].flight_cost;
    }
    flights.close();
    string number;
    quick_sort_flights(flights_array, 0, count - 1); //sort the flights by flight number
    binary_search_flight(flights_array, count, "CZ0819");
    binary_search_flight(flights_array, count, "FL0044");
    binary_search_flight(flights_array, count, "GH2333");

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
int selection_sort_flights(type_flights flights_array[], int n) {
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
void firstlast_flights(type_flights flights_array[], int n) {
    cout << "The first 5 flights are: " << endl;
    for (int i = 0; i < 5; i++) { //print the array
        cout << flights_array[i].flight_number << " "
             << flights_array[i].departure_city << " "
             << flights_array[i].arrival_city << " "
             << flights_array[i].flight_cost << endl;
    }
    cout << "The last 5 flights are:" << endl;
    for (int i = n - 5; i < n; i++) { //print the array
        cout << flights_array[i].flight_number << " "
             << flights_array[i].departure_city << " "
             << flights_array[i].arrival_city << " "
             << flights_array[i].flight_cost << endl;
    }
    cout << endl;
}
int merge_sort_flights(type_flights flights_array[], int L, int R) {
    if (L < R) {
        int M = (L + R) / 2;
        merge_sort_flights(flights_array, L, M);
        merge_sort_flights(flights_array, M + 1, R);
        int i, j, k;
        int n1 = M - L + 1;
        int n2 = R - M;

        auto* L_arr = new type_flights[n1];
        auto* R_arr = new type_flights[n2];

        for (i = 0; i < n1; i++) {
            L_arr[i] = flights_array[L + i];
        }
        for (j = 0; j < n2; j++) {
            R_arr[j] = flights_array[M + 1 + j];
        }
        i = 0;
        j = 0;
        k = L;
        while (i < n1 && j < n2) {
            if (L_arr[i].flight_number <= R_arr[j].flight_number) {
                flights_array[k] = L_arr[i];
                i++;
            } else {
                flights_array[k] = R_arr[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            flights_array[k] = L_arr[i];
            i++;
            k++;
        }
        while (j < n2) {
            flights_array[k] = R_arr[j];
            j++;
            k++;
        }

        delete[] L_arr;
        delete[] R_arr;

    }
    return 0;
}
int quick_sort_flights(type_flights flights_array[], int L, int R) {
    if (L < R) {
        int pivot = L;
        int i = L;
        int j = R;
        while (i < j) {
            while (flights_array[i].flight_number <= flights_array[pivot].flight_number && i < R) {
                i++;
            }
            while (flights_array[j].flight_number > flights_array[pivot].flight_number) {
                j--;
            }
            if (i < j) {
                type_flights temp = flights_array[i];
                flights_array[i] = flights_array[j];
                flights_array[j] = temp;
            }
        }
        type_flights temp = flights_array[pivot];
        flights_array[pivot] = flights_array[j];
        flights_array[j] = temp;
        quick_sort_flights(flights_array, L, j - 1);
        quick_sort_flights(flights_array, j + 1, R);
    }
    return 0;
}
void binary_search_flight(type_flights flights_array[], int n, string flight_number) {
    int L = 0;
    int R = n - 1;
    while (L <= R) {
        int M = (L + R) / 2;
        if (flights_array[M].flight_number == flight_number) {
            cout << "The flight " << flight_number << " leaves " << flights_array[M].departure_city
                 << " for " << flights_array[M].arrival_city << " and costs " << flights_array[M].flight_cost
                 << endl;
            return;
        } else if (flights_array[M].flight_number < flight_number) {
            L = M + 1;
        } else {
            R = M - 1;
        }
    }
    cout << "The flight " << flight_number << " does not exist!" << endl;
}