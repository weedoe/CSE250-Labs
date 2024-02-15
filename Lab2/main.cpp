//OCdt Paterson 30648
//Date: 2024-02-15
//Lab 2
//A program to read through a .dat file and to perform functions such as sorting and searching
//based on the data within the file. The program uses iterative and recursive types of sorting.
//The program also includes answers to Part 2 which displays the first 12 F numbers computed recursively and iteratively
//and a recursive function to list all binary strings.

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

//declare global variables
int additions = 0;

//declaring functions
int open_file(ifstream &flights, const string &file_name);

int selection_sort_flights(type_flights flights_array[], int n);

void firstlast_flights(type_flights flights_array[], int n);

int merge_sort_flights(type_flights flights_array[], int L, int R);

int quick_sort_flights(type_flights flights_array[], int L, int R);

void binary_search_flight(type_flights flights_array[], int n, string flight_number);

void list_binary_strings(int n, string s = "");

int RecurF(int n);

int IterF(int n);


int main() {
    ifstream flights; //declare file stream
    string file_name = "flights_all_fixed.dat"; //declare file name
    int count = open_file(flights, file_name); //open file and count the number of lines
    unsigned long total_time; //declare variable to store the time taken to sort the array
    auto *flights_array = new type_flights[count]; //declare array of type_flights
    flights.open(file_name); //open file
    if (!flights.is_open()) { //checks if file open fails
        cerr << "Error opening file" << endl;
    }
    string line; //declare string to store the line
    string tmp; //temporary string to store the line
    int i;
    for (i = 0; i < count; i++) { //read the file and store the values in the array
        getline(flights, tmp);
        stringstream ss(tmp); //declare stringstream to store the line
        getline(ss, flights_array[i].flight_number, ','); //store the values in the array
        getline(ss, flights_array[i].departure_city, ',');
        getline(ss, flights_array[i].arrival_city, ',');
        ss >> flights_array[i].flight_cost;
    }
    flights.close(); //close file

    //Question 1
    cout << "----------Question 1----------" << endl;
    firstlast_flights(flights_array, count); //print the first and last 5 flights
    clock_t start = clock(); //start the clock
    selection_sort_flights(flights_array, count); //call the selection sort function
    total_time = clock() - start; //gets value of clock at end of sort
    firstlast_flights(flights_array, count); //print the first and last 5 flights
    //print the time taken to sort the array
    cout << "SELECTION sort took " << total_time / CLOCKS_PER_SEC << " seconds" << endl << endl;

    start = clock(); //start the clock
    selection_sort_flights(flights_array, count); //call the selection sort function
    total_time = clock() - start; //gets value of clock at end of sort
    firstlast_flights(flights_array, count); //print the first and last 5 flights
    //print the time taken to sort the array
    cout << "SELECTION REsort took " << total_time / CLOCKS_PER_SEC << " seconds" << endl << endl;

    delete[] flights_array; //delete the array to clear memory

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
    merge_sort_flights(flights_array, 0, count - 1); //call the merge sort function
    total_time = clock() - start;
    firstlast_flights(flights_array, count); //print the first and last 5 flights
    cout << "MERGE sort took " << total_time / CLOCKS_PER_SEC << " seconds" << endl << endl;

    start = clock();
    merge_sort_flights(flights_array, 0, count - 1); //call the merge sort function
    total_time = clock() - start;
    firstlast_flights(flights_array, count); //print the first and last 5 flights
    cout << "MERGE REsort took " << total_time / CLOCKS_PER_SEC << " seconds" << endl << endl;

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
    quick_sort_flights(flights_array, 0, count - 1); //call the quick sort function
    total_time = clock() - start;
    firstlast_flights(flights_array, count); //print the first and last 5 flights
    cout << "QUICK sort took " << total_time / CLOCKS_PER_SEC << " seconds" << endl << endl;

    start = clock();
    quick_sort_flights(flights_array, 0, count - 1); //call the quick sort function
    total_time = clock() - start;
    firstlast_flights(flights_array, count); //print the first and last 5 flights
    cout << "QUICK REsort took " << total_time / CLOCKS_PER_SEC << " seconds" << endl << endl;

    delete[] flights_array;

    //Question 4
    cout << "----------Question 4----------" << endl;
    cout << "Quick sort is slower on a sorted array because it has to search through the whole array to find the pivot."
            " Then it has to perform the entire sort." << endl;

    //Question 5
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
    //to use binary search the array must be sorted...
    quick_sort_flights(flights_array, 0, count - 1); //sort the flights by flight number
    binary_search_flight(flights_array, count, "CZ0819"); //search for the flight number
    binary_search_flight(flights_array, count, "FL0044");
    binary_search_flight(flights_array, count, "GH2333");

    //PART 2

    //Question 6
    cout << "----------Question 6----------" << endl;
    list_binary_strings(5); //list all binary strings of length 5

    //Question 7
    cout << "----------Question 7----------" << endl;
    cout << "The first 12 F numbers computed recursively are ";
    int n = 12;
    //below seems very messy and can be improved
    for (int x = 0; x < n; x++) { //print the first 12 F numbers computed recursively
        if (x == 0) { //if x is 0 print 0
            cout << "0";
        } else if (x == 1) { //if x is 1 print 1
            cout << ", 1";
        } else { //else print the F number
            cout << ", " << RecurF(x);
        }
    }
    cout << " it used " << additions << " additions" << endl; //print the number of additions
    additions = 0; //reset the number of additions
    cout << "The first 12 F numbers computed iteratively are "; //print the first 12 F numbers computed iteratively
    //below seems very messy and can be improved
    for (int x = 0; x < n; x++) {
        if (x == 0) {
            cout << "0";
        } else if (x == 1) {
            cout << ", 1";
        } else {
            cout << ", " << IterF(x);
        }
    }
    cout << " it used " << additions << " additions" << endl; //print the number of additions
    cout << "The recursive function uses more additions because it is calculating the same value in the sequence "
            "multiple times. This is because the function is not storing the values it has already calculated." << endl;

    return 0;
}

//function to open the file and count the number of lines
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

//function to print the first and last 5 flights
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

//function to sort the flights by flight number with merge sort
int merge_sort_flights(type_flights flights_array[], int L, int R) {
    if (L < R) { //if L is less than R
        int M = (L + R) / 2; //find the middle
        merge_sort_flights(flights_array, L, M); //sort the left side
        merge_sort_flights(flights_array, M + 1, R); //sort the right side
        int i, j, k; //declare variables
        int n1 = M - L + 1; //find the size of the left array
        int n2 = R - M; //find the size of the right array

        auto *L_arr = new type_flights[n1]; //declare left array
        auto *R_arr = new type_flights[n2]; //declare right array

        for (i = 0; i < n1; i++) { //store the left array
            L_arr[i] = flights_array[L + i];
        }
        for (j = 0; j < n2; j++) { //store the right array
            R_arr[j] = flights_array[M + 1 + j];
        }
        i = 0; //reset i
        j = 0; //reset j
        k = L; //set k to L
        while (i < n1 && j < n2) { //merge the arrays
            if (L_arr[i].flight_number <=
                R_arr[j].flight_number) { //if the left array value is less than or equal to the right array
                flights_array[k] = L_arr[i]; //store the left array value
                i++; //increment i
            } else {
                flights_array[k] = R_arr[j]; //store the right array value
                j++; //increment j
            }
            k++; //increment k
        } //store the remaining values
        while (i < n1) {
            flights_array[k] = L_arr[i]; //store the left array value
            i++; //increment i
            k++;   //increment k
        }
        while (j < n2) { //store the right array value
            flights_array[k] = R_arr[j];
            j++; //increment j
            k++; //increment k
        }

        delete[] L_arr; //delete the left array
        delete[] R_arr; //delete the right array

    }
    return 0;
}

//function to sort the flights by flight number with quick sort
int quick_sort_flights(type_flights flights_array[], int L, int R) {
    if (L < R) {
        int pivot = R; //set the pivot to the last value
        int i = L; //set i to L
        int j = R - 1; //set j to R-1
        while (i <= j) { //while i is less than or equal to j
            while (flights_array[i].flight_number < flights_array[pivot].flight_number && i < R) { //find the left value
                i++; //increment i
            }
            while (flights_array[j].flight_number > flights_array[pivot].flight_number &&
                   j > L) { //find the right value
                j--; //decrement j
            }
            if (i <= j) { //if i is less than or equal to j
                type_flights temp = flights_array[i]; //swap the values (i is now in the correct position)
                flights_array[i] = flights_array[j]; //swap the values (i is now in the correct position)
                flights_array[j] = temp; //swap the values (j is now in the correct position)
                i++; //increment i
                j--; //decrement j
            }
        }
        type_flights temp = flights_array[i]; //swap the values
        flights_array[i] = flights_array[pivot]; //swap the values
        flights_array[pivot] = temp; //swap the values (pivot is now in the correct position)
        quick_sort_flights(flights_array, L, i - 1); //sort the left side
        quick_sort_flights(flights_array, i + 1, R); //sort the right side
    }
    return 0;
}

//function to search for a flight number using binary search (array must be sorted before calling this function)
void binary_search_flight(type_flights flights_array[], int n, string flight_number) {
    int L = 0; //declare L
    int R = n - 1; //declare R
    while (L <= R) { //while L is less than or equal to R
        int M = (L + R) / 2; //find the middle
        if (flights_array[M].flight_number == flight_number) { //if the middle value is the flight number
            cout << "The flight " << flight_number << " leaves " << flights_array[M].departure_city
                 << " for " << flights_array[M].arrival_city << " and costs " << flights_array[M].flight_cost
                 << endl; //print the flight details
            return; //exit the function
        } else if (flights_array[M].flight_number <
                   flight_number) { //if the middle value is less than the flight number
            L = M + 1; //set L to M+1
        } else { //if the middle value is greater than the flight number
            R = M - 1; //set R to M-1
        }
    }
    cout << "The flight " << flight_number << " does not exist!"
         << endl; //print that the flight does not exist if not found
}

//function to list all binary strings of length n
void list_binary_strings(int n, string s) {
    if (n == 0) { //if n is 0 print the string
        cout << s << endl;
    } else {
        list_binary_strings(n - 1, s + "0"); //append 0 to empty string
        list_binary_strings(n - 1, s + "1"); //append 1 to empty after a zero has been put
    }
}

//recursive function to compute the F number
int RecurF(int n) {
    if (n <= 1) { //if n is less than or equal to 1 return n
        return n;
    }
    additions++; //increment the number of additions
    return RecurF(n - 1) + RecurF(n - 2); //return the F number using recursion (F(n-1) + F(n-2))
}

//iterative function to compute the F number
int IterF(int n) {
    int a = 0; //declare a
    int b = 1; //declare b
    int c; //declare c
    for (int i = 2; i <= n; i++) { //for i from 2 to n
        c = a + b; //set c to a+b (c is the F number)
        a = b; //set a to b
        b = c; //set b to c (b is now the F number)
        additions++; //increment the number of additions
    }
    return b; //return the F number
}