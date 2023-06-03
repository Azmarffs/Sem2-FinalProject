/*
Name: Azmar Kashif
Section: B
Roll no: 22i-2716
*/


#include <iostream> // standard input-output library
#include <windows.h> // Windows API library
#include <iomanip>  //for setw
#include <stdlib.h> // standard library
#include <string> // string handling library
#include <conio.h> // console input-output library
#include <cstdlib> // standard library
#include <ctime> // time handling library
#include <fstream> // file input-output library
using namespace std;

const int MAX_USERS = 10; // defining a constant integer variable with a value of 10
struct LoginInfo // defining a structure named LoginInfo
{
    string name; // data member to store name of user
    string password; // data member to store password of user
    char c; // character variable
    string cnic; // data member to store CNIC of user
    int user_num = 0; // data member to store user number
    int forNew; // integer variable
    string country[5] = {"Dubai", "Australia", "Canada", "America", "China"}; // string array to store names of countries
    string city[5] = {"Islamabad", "Lahore", "Quetta", "Peshawar", "Karachi"}; // string array to store names of cities
    string arrive[5] = {"01:00", "03:00", "06:00", "08:00", "11:00"}; // string array to store arrival times
    string depart[5] = {"3:00", "5:00", "8:00", "14:00", "13:00"}; // string array to store departure times
};


const int MAX_FLIGHTS = 10;
struct Flight {
    string arrival_time;
    string depart_time;
};


class LoginAndReg // defining a class named LoginAndReg
{
protected:
    LoginInfo l; // data member of type LoginInfo
public:
    LoginAndReg() {} // default constructor
    LoginAndReg(string n, string p) // constructor with parameters
    {
        l.name = n; // setting value of name
        l.password = p; // setting value of password
    }
    bool isValid() // function to check if username and password are valid
    {
        return l.name.length() <= 8 && l.password.length() <= 8; // returns true if length of name and password are less than or equal to 8
    }
    bool checkPassword(string pass) // function to check if password matches
    {
        return l.password == pass; // returns true if password matches
    }
    string getName() // function to get name of user
    {
        return l.name; // returns name of user
    }
    void setName(string n) // function to set name of user
     {
        l.name = n; // sets name of user
    }
    string getPassword() // function to get password of user
    {
        return l.password; // returns password of user
    }
    void setPassword(string p) // function to set password of user
    {
        l.password = p; // sets password of user
    }
};




// This function takes in three string arguments - name, password, and CNIC and writes them to a file named "file.txt"
void writefile(string name, string password, string cnic)
{
    LoginInfo I; // Creating an object of LoginInfo structure
    ofstream ofile; // Creating an object of ofstream
    ofile.open("UserInfo.txt", ios::app); // Opening file "file.txt" in append mode
    if(ofile.is_open()){ // If file is open
        ofile << "Name: " << name << endl; // Write name to file
        ofile << "Passoword: " << password << endl; // Write password to file
        ofile << "CNIC: " << cnic << endl; // Write CNIC to file
    }
    ofile.close(); // Close the file
}

// This is a Payment struct which contains different payment related properties
struct Payment
{
    // Constructor to initialize random seed
    Payment()
    {
        srand(time(NULL));
    }

    double T_Amount = 200000; // Total amount to be paid

    // Arrays to store the hours for different flight types
    int InternationalFlightHours[6] = {'\0', 8, 10, 12, 15, 20}; // For international flights
    int LocalFlightHours[6] = {'\0', 1, 2, 3, 4, 5}; // For local flights

    // Payment for different flight types
    int PaymentForDirect[2] = {20000, 10000}; // For direct flights
    int PaymentForIndirect[2] = {17000, 7000}; // For indirect flights

    int res; // Result
    double purchase = 0; // Purchase amount
    int T_Seats = 50; // Total number of seats
    string flightType[3] = {"", "International", "Local"}; // Array of flight types
    int priceForFlightType[2] = {20000, 10000}; // Price for each flight type
    int refDeduct[2] = {10, 5}; // Reference deduction amount
    int choice; // User's choice
    int ch; // User's choice
};



class Booking
{
private:
    // Define private member variables for the Booking class
    LoginInfo i; // instance of LoginInfo struct
    Payment p; // instance of Payment class
    int total_seats; // total number of seats
    int res_seats; // number of reserved seats
    char chForFl; // char for flight
    string dateTime; // date and time of flight
    int year, month, day; // year, month, and day of flight
    int hr, min; // hour and minute of flight
    string from; // departure city
    string to; // arrival city
    string country[5] = {"Dubai", "Australia", "Canada", "America", "China"}; // array of countries
    string city[5] = {"Islamabad", "Lahore", "Quetta", "Peshawar", "Karachi"}; // array of cities
    string arrive[5] = {"01:00", "03:00", "06:00", "08:00", "11:00"}; // array of arrival times
    string depart[5] = {"3:00", "5:00", "8:00", "14:00", "13:00"}; // array of departure times
    string creditCards[3] = {"Paypal", "Visa", "MasterCard"}; // array of credit card types
public:
    Booking()
    {
        total_seats = 0;
        res_seats = 0;
        from = "";
        to = "";
    }
    Booking(int total_seats, int res_seats, string dateTime, int year, int month, int day, int hr, int min, string from, string to){
        // Constructor that sets the private member variables
        this->total_seats = total_seats;
        this->res_seats = res_seats;
        this->dateTime = dateTime;
        this->year = year; 
        this->month = month;
        this->day = day;
        this->hr = hr;
        this->min = min;
        this->from = from;
        this->to = to;
    }
    void setFrom(string f)
    {
        // Setter for the departure city
        from = f;
    }
    void setTo(string t)
    {
        // Setter for the arrival city
        to = t;
    }
    string getFrom()
    {
        // Getter for the departure city
        return from;
    }
    string getTo()
    {
        // Getter for the arrival city
        return to;
    }
    void displayAvailableFlights(); // Function to display available flights
    void payment(); // Function to handle payment
    void reserveSeat(); // Function to reserve a seat
    void Refund(); // Function to handle refunds
public:
    // Define public member functions for the Booking class
    void displayMenu(); // Function to display the booking menu
    friend ostream& operator << (ostream& out, const Booking& B); // Overloaded << operator
    Booking(const Booking& myBook); // Copy constructor
};


void writeFileToAddFlights(){
    ofstream ofile;
    ofile.open("flights.txt", ios::app);
    if(ofile.is_open()){

    }
}

class FlightSchedule
{
    LoginInfo l; // instance of LoginInfo struct
    string *addCountries; // pointer to array of added countries
    string *addCities; // pointer to array of added cities
    string *remCountries; // pointer to array of removed countries
    string *remCities; // pointer to array of removed cities
    string *Addflights;
    int sizeForFlight; // size for flight

    public:
    // Constructor with parameter to set sizeForFlight variable
    FlightSchedule(int size){
        sizeForFlight = size;
    }

    // Default constructor to allocate memory for string arrays using sizeForFlight variable
    FlightSchedule(){
        addCountries = new string[sizeForFlight];
        addCities = new string[sizeForFlight];
        remCountries = new string[sizeForFlight];
        remCities = new string[sizeForFlight];
        Addflights = new string[sizeForFlight];
    }

    // Display menu options for admin
    void display()
    {

        cout << endl << setw(10) << left << "Option" << setw(30) << "Description" << endl;
        cout << setw(10) << left << "1" << setw(30) << "Check the flight status" << endl;
        cout << setw(10) << left << "2" << setw(30) << "Check available seats" << endl;
        cout << setw(10) << left << "3" << setw(30) << "Change schedule for flight" << endl;
        cout << setw(10) << left << "4" << setw(30) << "Add Countries" << endl;
        cout << setw(10) << left << "5" << setw(30) << "Remove Countries" << endl;
        cout << setw(10) << left << "6" << setw(30) << "Add More Flights" << endl;

        cout << endl << "Enter choice: ";
    }

    // Function to get login credentials for admin
    void AdminLogin()
    {
        cout << "Login credentials for Admin " << endl;
        cout << "Enter your name: ";
        cin >> l.name;
        cout << "Enter your password: ";

        while((l.c = getch()) != '\r') 
        {
            if(l.c == '\b') { // Backspace key
                if(l.password != "") 
                {
                    cout << "\b \b"; // Remove character from console
                    l.password = l.password.substr(0, l.password.size()-1); // Remove last character from password
                }
            }
            else 
            {
                if(l.password.length() < 8) 
                {
                    l.password += l.c;
                    cout << '*'; // Print asterisks instead of password characters
                }
            }
        }
    }

    // Function to display seat availability status
    void checkingSeats()
    {
        cout << "Checking how many seats are not occupied " << endl;
        int r, c ;
        char arr[10][10];

        // Initialize array with '0' and 'X' values for occupied and unoccupied seats
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                if(i == 1 || i == 5 || i ==7 || j == 2 || j == 6 || j == 10)
                {
                    arr[i][j] = 'X';
                }
                else
                {
                    arr[i][j] = '0';
                }
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        cout << "X -> Occupied " << endl;
        cout << "0 -> Not Occupied " << endl;

    }
    void DisplayAvailableSeats()
    {
        int xCoords[] = {2, 4, 6, 8, 5}; // array to store X coordinates
        int yCoords[] = {3, 5, 4, 7, 2}; // array to store Y coordinates
        cout << "Following are the flights available on the platform " << endl;

        while (!kbhit()) 
        { // loop until a key is pressed
            system("CLS"); // clear console screen

            for(int i = 0; i < 10; i++) 
            {
                for(int j = 0; j < 10; j++) 
                {
                    bool isX = false;
                    for(int k = 0; k < 5; k++) {
                        if(i == xCoords[k] && j == yCoords[k]) 
                        {
                            cout << "X ";
                            isX = true;
                            break;
                        }
                    }
                    if(!isX) 
                    {
                        if(i==0 || j==0 || i==9 || j==9)
                        {
                            cout << '*' << ' ';
                        } else 
                        {
                            cout << ' ' << ' ';
                        }
                    }
                }
                cout << endl;
            }

            // update X coordinates
            for(int k = 0; k < 5; k++) 
            {
                xCoords[k] += rand() % 3 - 1; // add random value between -1 and 1 to X coordinate
                yCoords[k] += rand() % 3 - 1; // add random value between -1 and 1 to Y coordinate
                // make sure coordinates stay within bounds
                xCoords[k] = max(1, min(xCoords[k], 8));
                yCoords[k] = max(1, min(yCoords[k], 8));
            }

            // sleep for a short time to control speed of movement
            for(int i = 0; i < 800000000; i++);
        }
    }
    void changeSchedule() {
        int change; // declare variable to store the flight number user wants to change
        string newTimeForArr; // declare variable to store the new arrival time
        string newTimeForDep; // declare variable to store the new departure time
        char AorD; // declare variable to store whether user wants to change arrival or departure time
        cout << "Which flight schedule you wanna change from the following? " << endl;
        for(int i=0;i<4;i++) {
            // display the current arrival and departure time for each of the 4 flights
            cout << "Flight "<< i+1 << ". " << "Arrival time -> " << l.arrive[i] << " " << "depart time -> " << l.depart[i] << endl;
        }
        cout << "Enter choice: ";
        cin >> change; // read the user's choice of flight to change
        if(change == 1) { // if user wants to change flight 1
            cout << "Do you want to change the arrival time or depart time? (a/d/b) " << endl;
            cin >> AorD; // read whether user wants to change arrival or departure time
            if(AorD == 'a') { // if user wants to change arrival time
                cout << "Enter new time: ";
                cin >> newTimeForArr; // read the new arrival time
                l.arrive[1] = newTimeForArr; // assign the new arrival time to the corresponding flight
            } else if(AorD == 'd') { // if user wants to change departure time
                cout << "Enter new time: ";
                cin >> newTimeForArr; // read the new departure time
                l.depart[1] = newTimeForDep; // assign the new departure time to the corresponding flight
            } else if(AorD == 'b') { // if user wants to change both arrival and departure time
                cout << "Enter new time for arrival " << endl;
                cin>>newTimeForArr; // read the new arrival time
                cout << "Enter new time for Depart " << endl;
                cin >>newTimeForDep; // read the new departure time
                l.arrive[1] = newTimeForArr; // assign the new arrival time to the corresponding flight
                l.depart[1] = newTimeForDep; // assign the new departure time to the corresponding flight
            } else { // if user inputs an invalid option
                cout << "Invalid";
            }
        }else if(change == 2) { // repeat the same process for flight 2
            cout << "Do you want to change the arrival time or depart time? (a/d/b) " << endl;
            cin >> AorD;
            if(AorD == 'a') {
                cout << "Enter new time: ";
                cin >> newTimeForArr;
                l.arrive[2] = newTimeForArr;
            } else if(AorD == 'd') {
                cout << "Enter new time: ";
                cin >> newTimeForArr;
                l.depart[2] = newTimeForArr;
            } else if(AorD == 'b') {
                cout << "Enter new time for arrival " << endl;
                cin>>newTimeForArr;
                cout << "Enter new time for Depart " << endl;
                cin >>newTimeForDep;
                l.arrive[2] = newTimeForArr;
                l.depart[2] = newTimeForDep;
            }
                else
                {
                    cout << "Invalid";
                }
            }
        else if(change == 3) // repeat the same process for flight 3
        {
            cout << "Do you want to change the arrival time or depart time? (a/d/b) " << endl;
            cin >> AorD;
            if(AorD == 'a')
            {
                cout << "Enter new time: ";
                cin >> newTimeForArr;
                l.arrive[3] = newTimeForArr;
            }
            else if(AorD == 'd')
            {
                cout << "Enter new time: ";
                cin >> newTimeForArr;
                l.depart[3] = newTimeForArr;
            }
            else if(AorD == 'b')
            {
                cout << "Enter new time for arrival " << endl;
                cin>>newTimeForArr;
                cout << "Enter new time for Depart " << endl;
                cin >>newTimeForDep;
                l.arrive[3] = newTimeForArr;
                l.depart[3] = newTimeForDep;
            }
            else{
                cout << "Invalid";
            }

        }
        else if(change == 4) // repeat the same process for flight 4
        {
            cout << "Do you want to change the arrival time or depart time? (a/d/b) " << endl;
            cin >> AorD;
            if(AorD == 'a')
            {
                cout << "Enter new time: ";
                cin >> newTimeForArr;
                l.arrive[4] = newTimeForArr;
            }
            else if(AorD == 'd')
            {
                cout << "Enter new time: ";
                cin >> newTimeForArr;
                l.depart[4] = newTimeForArr;
            }
            else if(AorD == 'b')
            {
                cout << "Enter new time for arrival " << endl;
                cin>>newTimeForArr;
                cout << "Enter new time for Depart " << endl;
                cin >>newTimeForDep;
                l.arrive[4] = newTimeForArr;
                l.depart[4] = newTimeForDep;
            }
            else
            {
                cout << "Invalid ";
            }
        }
        else if(change == 5) // repeat the same process for flight 5
        {
            cout << "Do you want to change the arrival time or depart time? (a/d/b) " << endl;
            cin >> AorD;
            if(AorD == 'a')
            {
                cout << "Enter new time: ";
                cin >> newTimeForArr;
                l.arrive[5] = newTimeForArr;
            }
            else if(AorD == 'd')
            {
                cout << "Enter new time: ";
                cin >> newTimeForArr;
                l.depart[5] = newTimeForArr;
            }
            else if(AorD == 'b')
            {
                cout << "Enter new time for arrival " << endl;
                cin>>newTimeForArr;
                cout << "Enter new time for Depart " << endl;
                cin >>newTimeForDep;
                l.arrive[5] = newTimeForArr;
                l.depart[5] = newTimeForDep;
            }
            else
            {
                cout << "Invalid";
            }
        }
        else
        {
            cout << "Invalid choice " << endl;
        }
        if(AorD == 'a')
        { 
            cout << "New time at Flight # " << change << " is: " << endl;
            cout << "Arrival Time: " << l.arrive[change] << endl;
        }
        else if(AorD == 'd')
        {
            cout << "New time at Flight # " << change << " is: " << endl;
            cout << "Depart Time: " << l.depart[change] << endl;
        }
        else if(AorD == 'b')
        {
            cout << "New time at Flight # " << change << " is: " << endl;
            cout << "Arrival Time: " << l.arrive[change] << endl;
            cout << "Depart Time: " << l.depart[change] << endl;
        }
    }
    void AddCountries(){
        const int  MAX_COUNTRIES = 10;
        const int MAX_CITIES = 10;
        string AdminCh;
        char ChA;
        string countries[MAX_COUNTRIES] = {"Dubai", "Australia", "Canada", "America", "China"};
        int numCountries = 5;
        string *newCountry = new string[numCountries];
        string cities[MAX_CITIES] = {"Islamabad", "Lahore", "Quetta", "Peshawar", "Karachi"};
        int numCities = 5;
        string *newCity = new string[numCities];
        
        cout << "Do you want to add countries or cities? " << endl;
        cin >> AdminCh;
        if(AdminCh == "countries")
        {
            char ans;
            do {
                cout << "Do you want to add more countries? (y/n): ";
                cin >> ans;

                if (ans == 'y') {
                    if (numCountries >= MAX_COUNTRIES) {
                        cout << "Sorry, the array is full." << endl;
                        break;
                    }

                    cout << "Enter the name of the country: ";
                    cin >> countries[numCountries];
                    numCountries++;

                    // write the newly added country to file
                    ofstream outFile;
                    outFile.open("AddCountry.txt", ios::app); // append to file
                    if (outFile.is_open()) {
                        outFile << countries[numCountries-1] << endl;
                        outFile.close();
                    } else {
                        cout << "Unable to open file." << endl;
                    }
                }
            } while (ans == 'y');

            cout << "The countries are:" << endl;
            for (int i = 0; i < numCountries; i++) {
                cout << i+1 << ". " << countries[i] << endl;
            }
            for(int i=0;i<numCountries;i++){
                newCountry = new string[numCountries];
            }
        }
        else if(AdminCh == "cities"){
            char ans;
            do {
                cout << "Do you want to add more cities? (y/n): ";
                cin >> ans;

                if (ans == 'y') {
                    if (numCities >= MAX_CITIES) {
                        cout << "Sorry, the array is full." << endl;
                        break;
                    }

                    cout << "Enter the name of the city: ";
                    cin >> cities[numCities];
                    numCities++;
                }
            } while (ans == 'y');

            cout << "The cities are:" << endl;
            for (int i = 0; i < numCities; i++) {
                cout << i+1 << ". " << cities[i] << endl;
            }
            for(int i=0;i<numCities;i++){
                newCity = new string[numCities];
            }
        }
        delete addCountries;
        delete remCountries;
    }
    void RemCountries(){

        const int  MAX_COUNTRIES = 10;
        const int MAX_CITIES = 10;
        string AdminCh;
        char ChA;
        string countries[MAX_COUNTRIES] = {"Dubai", "Australia", "Canada", "America", "China"};
        int numCountries = 5;
        string *remCountry = new string[numCountries];
        string cities[MAX_CITIES] = {"Islamabad", "Lahore", "Quetta", "Peshawar", "Karachi"};
        int numCities = 5;
        string *remCity = new string[numCities];
        cout << "Do you want to remove countries or cities? " << endl;
        cin >> AdminCh;
        if(AdminCh == "countries")
        {
            char ans;
            do {
                cout << "Do you want to remove countries? (y/n): ";
                cin >> ans;

                if (ans == 'y') {
                    if (numCountries == 0) {
                        cout << "Sorry, the array is empty." << endl;
                        break;
                    }

                    cout << "Enter the name of the country to remove: ";
                    string name;
                    cin >> name;

                    bool found = false;
                    for (int i = 0; i < numCountries; i++) {
                        if (countries[i] == name) {
                            found = true;
                            for (int j = i; j < numCountries-1; j++) {
                                countries[j] = countries[j+1];
                            }
                            numCountries--;
                            break;
                        }
                    }

                    if (!found) {
                        cout << "Country not found." << endl;
                    }
                }
            } while (ans == 'y');

            cout << "The countries are:" << endl;
            for (int i = 0; i < numCountries; i++) {
                cout << countries[i] << endl;
            }
            for(int i=0;i<numCountries;i++){
                remCountries = new string[numCountries];
            }
        }
        else if(AdminCh == "cities"){
            char ans;
            do {
                cout << "Do you want to remove cities? (y/n): ";
                cin >> ans;

                if (ans == 'y') {
                    if (numCities == 0) {
                        cout << "Sorry, the array is empty." << endl;
                        break;
                    }

                    cout << "Enter the name of the city to remove: ";
                    string name;
                    cin >> name;

                    bool found = false;
                    for (int i = 0; i < numCities; i++) {
                        if (countries[i] == name) {
                            found = true;
                            for (int j = i; j < numCities-1; j++) {
                                cities[j] = cities[j+1];
                            }
                            numCities--;
                            break;
                        }
                    }

                    if (!found) {
                        cout << "City not found." << endl;
                    }
                }
            } while (ans == 'y');

            cout << "The cities are:" << endl;
            for (int i = 0; i < numCities; i++){
                cout << cities[i] << endl;
            }
            for(int i=0;i<numCities;i++){
                remCities = new string[numCities];
            }
        }
        
    }

    void addMoreFlights(Flight flights[], int &num_flights) 
    {
        if (num_flights >= MAX_FLIGHTS) {
            cout << "Cannot add more flights. Maximum limit reached." << endl;
            return;
        }
        
        cout << "Enter arrival time: ";
        cin >> flights[num_flights].arrival_time;
        cout << "Enter departure time: ";
        cin >> flights[num_flights].depart_time;

        num_flights++;

        ofstream outfile("AddFlight.txt", ios::app);
        outfile << "Flight " << num_flights << ": " << "Arrival time -> " << flights[num_flights-1].arrival_time << " " << "Departure time -> " << flights[num_flights-1].depart_time << endl;
        outfile.close();
        cout << "Flight details saved to AddFlight.txt" << endl;

        delete Addflights;
    }
};

class MenuForAdmin
{
    LoginInfo l; // object for login information
    Payment p; // object for payment information
    Booking b; // object for booking information
    public:
    void displayMenuForAdmin()
    {
        cout << endl << "1.Check the flight status" << endl;
        cout << "2.Check available seats" << endl;
        cout << "Enter choice: ";   
    }
    void AdminLogin()
    {
        cout << "Login credentials for Admin " << endl;
        cout << "Enter your name: ";
        cin >> l.name;
        cout << "Enter your password: ";
        while((l.c = getch()) != '\r') 
        {
            if(l.c == '\b') 
            { // backspace key
                if(l.password != "") 
                {
                    cout << "\b \b"; // remove character from console
                    l.password = l.password.substr(0, l.password.size()-1); // remove last character from password
                }
            }
            else 
            {
                if(l.password.length() < 8) 
                {
                    l.password += l.c;
                    cout << '*';
                }
            }
        }
    }
    void checkingSeats()
    {
        system("CLS"); // clear console screen
        int r, c ;
        char arr[10][10];
        // initialize the seat map
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                if(i == 1 || i == 5 || i ==7 || j == 2 || j == 6 || j == 10)
                { // mark seats as occupied
                    arr[i][j] = 'X';
                }
                else
                { // mark seats as available
                    arr[i][j] = '0';
                }
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        cout << "X -> Occupied " << endl;
        cout << "0 -> Not Occupied " << endl;
        cout << "Select your seat: " << endl;
        cout << "r: ";
        cin >> r;
        cout << "c: ";
        cin >> c;
        // update the seat map
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                if(i == 1 || i == 5 || i ==7 || j == 2 || j == 6 || j == 10)
                { // mark seats as occupied
                    arr[i][j] = 'X';
                }
                else if(i == r || j == c)
                { // mark the selected seat as occupied
                    arr[i][j] = 'X';
                }
                else
                { // mark seats as available
                    arr[i][j] = '0';
                }
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        cout << "You have successfully booked your seat at row number " << r << " and col number " << c << endl;
    }
    void FlightSchedule()
    {
    int xCoords[] = {2, 4, 6, 8, 5}; // array to store X coordinates
    int yCoords[] = {3, 5, 4, 7, 2}; // array to store Y coordinates
    cout << "Following are the flights available on the platform " << endl;

    while (!kbhit()) { // loop until a key is pressed
        system("CLS"); // clear console screen

        // Draw platform and moving dots
        for(int i = 0; i < 10; i++) 
        {
            for(int j = 0; j < 10; j++) 
            {
                bool isX = false;
                for(int k = 0; k < 5; k++) {
                    if(i == xCoords[k] && j == yCoords[k]) 
                    {
                        cout << "X ";
                        isX = true;
                        break;
                    }
                }
                if(!isX) 
                {
                    if(i==0 || j==0 || i==9 || j==9)
                    {
                        cout << '*' << ' '; // border of platform
                    } else 
                    {
                        cout << ' ' << ' '; // empty space on platform
                    }
                }
            }
            cout << endl;
        }

        // update X and Y coordinates of the dots
        for(int k = 0; k < 5; k++) 
        {
            xCoords[k] += rand() % 3 - 1; // add random value between -1 and 1 to X coordinate
            yCoords[k] += rand() % 3 - 1; // add random value between -1 and 1 to Y coordinate
            // make sure coordinates stay within bounds
            xCoords[k] = max(1, min(xCoords[k], 8));
            yCoords[k] = max(1, min(yCoords[k], 8));
        }

        // sleep for a short time to control speed of movement
        for(int i = 0; i < 800000000; i++);

        // Wait for user input to reserve a seat or select a new schedule
    }
    char isAv;
    cout << "Available? (y/n) " << endl;
    cin >> isAv;
    if(isAv == 'y')
    {
        b.reserveSeat();
    }
    else if(isAv == 'n')
    {
        cout << "Select a new schdeule for your flight " << endl;

        // Display available flight schedules
        for(int i=0;i<4;i++)
        {
            cout << "Flight "<< i+1 << ". " << "Arrival time -> " << l.arrive[i] << " " << "depart time -> " << l.depart[i] << endl;
        }

        // Get user's choice for new schedule
        int chForArr;
        cout << "Enter new choice: ";
        cin >> chForArr;

        // Display selected schedule
        if(p.choice == 1)
        {
            if(p.ch == 1)
            {
                if(chForArr == 1)
                {
                    cout << "Now you chose " << "Arrival time -> " << l.arrive[0] << " " << "depart time -> " << l.depart[0] << endl;
                }
                else if(chForArr == 2)
                {
                    cout << "Now you chose " << "Arrival time -> " << l.arrive[1] << " " << "depart time -> " << l.depart[1] << endl;
                    }
                    else if(chForArr == 3)
                    {
                        cout << "Now you chose " << "Arrival time -> " << l.arrive[2] << " " << "depart time -> " << l.depart[2] << endl;
                    }
                    else if(chForArr == 4)
                    {
                        cout << "Now you chose " << "Arrival time -> " << l.arrive[3] << " " << "depart time -> " << l.depart[3] << endl;
                    }
                    else
                    {
                        cout << "Invalid choice " << endl;
                    }
                }
                // Display selected schedule
                else if(p.ch == 2)
                {
                    if(chForArr == 1)
                    {
                        cout << "You chose " << "Arrival time -> " << l.arrive[0] << " " << "depart time -> " << l.depart[0] << endl;
                    }
                    else if(chForArr == 2)
                    {
                        cout << "You chose " << "Arrival time -> " << l.arrive[1] << " " << "depart time -> " << l.depart[1] << endl;
                    }
                    else if(chForArr == 3)
                    {
                        cout << "You chose " << "Arrival time -> " << l.arrive[2] << " " << "depart time -> " << l.depart[2] << endl;
                    }
                    else if(chForArr == 4)
                    {
                        cout << "You chose " << "Arrival time -> " << l.arrive[3] << " " << "depart time -> " << l.depart[3] << endl;
                    }
                    else
                    {
                        cout << "Invalid choice " << endl;
                    }
                }
                // Display selected schedule
                else if(p.ch == 3)
                {
                    if(chForArr == 1)
                    {
                        cout << "You chose " << "Arrival time -> " << l.arrive[0] << " " << "depart time -> " << l.depart[0] << endl;
                    }
                    else if(chForArr == 2)
                    {
                        cout << "You chose " << "Arrival time -> " << l.arrive[1] << " " << "depart time -> " << l.depart[1] << endl;
                    }else if(chForArr == 3)
                    {
                        cout << "You chose " << "Arrival time -> " << l.arrive[2] << " " << "depart time -> " << l.depart[2] << endl;
                    }
                    else if(chForArr == 4)
                    {
                        cout << "You chose " << "Arrival time -> " << l.arrive[3] << " " << "depart time -> " << l.depart[3] << endl;
                    }
                    else
                    {
                        cout << "Invalid choice " << endl;
                    }
                }
                // Display selected schedule
                else if(p.ch == 4)
                {
                    if(chForArr == 1)
                    {
                        cout << "You chose " << "Arrival time -> " << l.arrive[0] << " " << "depart time -> " << l.depart[0] << endl;
                    }
                    else if(chForArr == 2)
                    {
                        cout << "You chose " << "Arrival time -> " << l.arrive[1] << " " << "depart time -> " << l.depart[1] << endl;
                    }
                    else if(chForArr == 3)
                    {
                        cout << "You chose " << "Arrival time -> " << l.arrive[2] << " " << "depart time -> " << l.depart[2] << endl;
                    }
                    else if(chForArr == 4)
                    {
                        cout << "You chose " << "Arrival time -> " << l.arrive[3] << " " << "depart time -> " << l.depart[3] << endl;
                    }
                    else
                    {
                        cout << "Invalid choice " << endl;
                    }
                }
            }
            // Display selected schedule
            else if(p.choice == 2)
            {
                if(p.ch == 1){
                    if(chForArr == 1)
                    {
                        cout << "You chose " << "Arrival time -> " << l.arrive[0] << " " << "depart time -> " << l.depart[0] << endl;
                    }
                    else if(chForArr == 2)
                    {
                        cout << "You chose " << "Arrival time -> " << l.arrive[1] << " " << "depart time -> " << l.depart[1] << endl;
                    }
                    else if(chForArr == 3)
                    {
                        cout << "You chose " << "Arrival time -> " << l.arrive[2] << " " << "depart time -> " << l.depart[2] << endl;
                    }
                    else if(chForArr == 4)
                    {
                        cout << "You chose " << "Arrival time -> " << l.arrive[3] << " " << "depart time -> " << l.depart[3] << endl;
                    }
                    else
                    {
                        cout << "Invalid choice " << endl;
                    }
                }
                else if(p.ch == 2)
                {
                    if(chForArr == 1)
                    {
                        cout << "You chose " << "Arrival time -> " << l.arrive[0] << " " << "depart time -> " << l.depart[0] << endl;
                    }
                    else if(chForArr == 2)
                    {
                        cout << "You chose " << "Arrival time -> " << l.arrive[1] << " " << "depart time -> " << l.depart[1] << endl;
                    }
                    else if(chForArr == 3)
                    {
                        cout << "You chose " << "Arrival time -> " << l.arrive[2] << " " << "depart time -> " << l.depart[2] << endl;
                    }
                    else if(chForArr == 4)
                    {
                        cout << "You chose " << "Arrival time -> " << l.arrive[3] << " " << "depart time -> " << l.depart[3] << endl;
                    }
                    else
                    {
                        cout << "Invalid choice " << endl;
                    }
                }
                else if(p.ch == 3)
                {
                    if(chForArr == 1){
                        cout << "You chose " << "Arrival time -> " << l.arrive[0] << " " << "depart time -> " << l.depart[0] << endl;
                    }
                    else if(chForArr == 2)
                    {
                        cout << "You chose " << "Arrival time -> " << l.arrive[1] << " " << "depart time -> " << l.depart[1] << endl;
                    }
                    else if(chForArr == 3)
                    {
                        cout << "You chose " << "Arrival time -> " << l.arrive[2] << " " << "depart time -> " << l.depart[2] << endl;
                    }
                    else if(chForArr == 4)
                    {
                        cout << "You chose " << "Arrival time -> " << l.arrive[3] << " " << "depart time -> " << l.depart[3] << endl;
                    }
                    else{
                        cout << "Invalid choice " << endl;
                    }
                }
                else if(p.ch == 4)
                {
                    if(chForArr == 1)
                    {
                        cout << "You chose " << "Arrival time -> " << l.arrive[0] << " " << "depart time -> " << l.depart[0] << endl;
                    }
                    else if(chForArr == 2)
                    {
                        cout << "You chose " << "Arrival time -> " << l.arrive[1] << " " << "depart time -> " << l.depart[1] << endl;
                    }
                    else if(chForArr == 3)
                    {
                        cout << "You chose " << "Arrival time -> " << l.arrive[2] << " " << "depart time -> " << l.depart[2] << endl;
                    }
                    else if(chForArr == 4)
                    {
                        cout << "You chose " << "Arrival time -> " << l.arrive[3] << " " << "depart time -> " << l.depart[3] << endl;
                    }
                    else
                    {
                        cout << "Invalid choice " << endl;
                    }
                }
                else if(p.ch == 5)
                {
                    if(chForArr == 1)
                    {
                        cout << "You chose " << "Arrival time -> " << l.arrive[0] << " " << "depart time -> " << l.depart[0] << endl;
                    }
                    else if(chForArr == 2)
                    {
                        cout << "You chose " << "Arrival time -> " << l.arrive[1] << " " << "depart time -> " << l.depart[1] << endl;
                    }
                    else if(chForArr == 3)
                    {
                        cout << "You chose " << "Arrival time -> " << l.arrive[2] << " " << "depart time -> " << l.depart[2] << endl;
                    }
                    else if(chForArr == 4)
                    {
                        cout << "You chose " << "Arrival time -> " << l.arrive[3] << " " << "depart time -> " << l.depart[3] << endl;
                    }
                    else
                    {
                        cout << "Invalid choice " << endl;
                    }
                }
            }
            b.reserveSeat();
        }
    }
    void checkingVisa(){
        cout << "Checking the expiring date for your visa.. " << endl;
        Sleep(3000);
        cout << "Checking your visa type.. " << endl;
        Sleep(3000);
        cout << "Checking the visa number.. " << endl;
        Sleep(3000);
    }
    void checkingPassport(){
        cout << "Checking the expiring date for your passport.. " << endl;
        Sleep(3000);
        cout << "Checking the passport number.. " << endl;
        Sleep(3000);
        cout << "Checking the signs of damage or alteration on the passport.. " << endl;
        Sleep(3000);
    }
};

void Booking::reserveSeat()
{
    MenuForAdmin m;
    char AdminAns;
    char chForType;
    char chForTick;
    char seat;
    cout << "Total Seats are " << p.T_Seats << " seats" << endl;
    cout << "How many tickets you wanna book? " << endl;
    cin >> p.res;
    cout << "Do you want seats in business or economy class? (b/e) " << endl;
    cin >> seat;
    cout << "Contacting admin for available seats..." << endl;
    Sleep(10000);
    m.AdminLogin();
    for(int i=0;i<p.res;i++)
    {
        m.checkingSeats();
    }
    cout << "Do you have your passport available with you? (y/n)" << endl;
    cin >> chForTick;
    if(chForTick == 'y'){
        cout << "Enter your flight type: " << endl;
        cout << "[I]nternational" << endl;
        cout << "[L]ocal" << endl;
        cin >> chForType;
        if(chForType == 'i'){
            cout << "Admin checking your visa before issuing you tickets... " << endl;
            Sleep(5000);
            m.checkingPassport();
            Sleep(5000);
            cout << "Now Admin checking your passport... " << endl;
            m.checkingVisa();
        }
        else if(chForType == 'l'){
            cout << "Admin checking your passport before issuing you tickets... " << endl;
            Sleep(5000);
            m.checkingPassport();
        }
    }else if(chForTick == 'n'){ 
        cout << "You can't get on the flight without your passport. " << endl;
        displayMenu();
    }
    cout << "All Good? (y/n)" << endl;
    cin >> AdminAns;
    if(AdminAns == 'y'){
        cout << "ALLOWED!" << endl;
        payment();  
    }else if(AdminAns == 'n'){
        cout << "NOT ALLOWED!" << endl;
        displayMenu();
    }
}

// Function to set a password for a new user
string setPasswordForNewuser1() {
    string actualPassword, hiddenPassword; // actualPassword will hold the password in plain text, hiddenPassword will hold the password with asterisks replacing the characters
    char c;
    cout << "Rules for writing password: " << endl;
    cout << "=> Must have one uppercase letter " << endl;
    cout << "=> Must have one lower case letter " << endl;
    cout << "=> Must have one special symbol " << endl; 
    cout << "=> Must have one numeric digit " << endl;
    cout << "Enter password: ";
    while ((c = getch()) != '\r') { // read characters until the enter key is pressed
        if (c == '\b') { // if the backspace key is pressed
            if (!actualPassword.empty()) {
                cout << "\b \b"; // remove character from console
                actualPassword = actualPassword.substr(0, actualPassword.size() - 1); // remove last character from actual password
                hiddenPassword = hiddenPassword.substr(0, hiddenPassword.size() - 1); // remove last character from hidden password
            }
        }
        else {
            actualPassword += c;
            hiddenPassword += '*';
            cout << '*'; // print asterisk instead of the actual character
        }
    }
    char ch;
    cout << endl << "Show password (y/n): ";
    cin >> ch;
    if(ch == 'y'){
        cout << endl << "Password is: " << actualPassword << endl;
    }else if(ch == 'n'){
        cout << "Password entered: " << hiddenPassword << endl;
    }
    cout << endl << "Password entered: " << hiddenPassword << endl;
    return actualPassword;
}

string setPasswordForNewuser2()
{
    string actualPassword, hiddenPassword;
    char c;
    cout << "Enter password again: ";
    while((c = getch()) != '\r') 
    {
        if(c == '\b') { // backspace key
            if(!actualPassword.empty()) 
            {
                cout << "\b \b"; // remove character from console
                actualPassword = actualPassword.substr(0, actualPassword.size()-1); // remove last character from actual password
                hiddenPassword = hiddenPassword.substr(0, hiddenPassword.size()-1); // remove last character from hidden password
            }
        }
        else 
        {
            actualPassword += c;
            hiddenPassword += '*';
            cout << '*';
        }
    }
    cout << endl << "Password entered: " << hiddenPassword << endl;
    return actualPassword;
}
// Function to check if a given CNIC number is valid
bool is_valid_cnic(const string& cnic) {
    if (cnic.length() != 13) { // CNIC should be 13 digits long
        return false;
    }
    else if (cnic[0] < '1' || cnic[0] > '9') { // first digit should be between 1 and 9
        return false;
    }
    for (int i = 1; i < 13; i++) {
        if (!isdigit(cnic[i])) { // the rest of the digits should be digits
            return false;
        }
        else if (cnic[i] < '0' || cnic[i] > '9') { // each digit should be between 0 and 9
            return false;
        }
    }
    return true;
}
void Booking::Refund(){
    int cForRef;
    double ref = 0.0;
    // Prompt user for refund
    cout << "If you want refund of your amount (Press r) " << endl;
    // Get user input
    if((cForRef = getch()) == 114)
    {
        // Display refund policy
        cout << "As per Gov policy " << p.refDeduct[p.ch] << " %" << " will be deducted as according to your " << p.flightType[p.ch] << " flight. " << endl;
        char refA;
        // Confirm refund request
        cout << "Are you sure you want the refund for your purchase? (y/n) " << endl;
        cin >> refA;
        cout << "REFUND SUCCESSFUL " << endl;
        if(refA == 'y')
        {
            if(chForFl == 'd')
            {
                // Calculate refund amount for direct flight type 1
                ref = p.res*p.PaymentForDirect[0] * (25/100);
                cout << "Here is your refund amount " << "Rs " << ref << endl;
            }
            else if(chForFl == 'd')
            {
                // Calculate refund amount for direct flight type 2
                ref = p.res*p.PaymentForIndirect[1] * (25/100);
                cout << "Here is your refund amount " << "Rs " << ref << endl;
            }
            else if(chForFl == 'i' && p.choice == 1)
            {
                // Calculate refund amount for indirect flight type 1
                ref = p.res*p.PaymentForDirect[0] * (25/100);
                cout << "Here is your refund amount " << "Rs " << ref << endl;
            }
            else if(chForFl == 'i' && p.choice == 2)
            {
                // Calculate refund amount for indirect flight type 2
                ref = p.res*p.PaymentForDirect[1] * (25/100);
                cout << "Here is your refund amount " << "Rs " << ref << endl;
            }
        }
        else if(refA = 'n')
        {
            cout << "";
        }
    }
    else
    {
        exit(1);
    }
}

void Booking::payment()
{
    char chForFl; // variable to store choice of direct or indirect flight
    int select; // variable to store selected payment method
    cout << "Do you want a direct or indirect flight? (d/i) ";
    cin >> chForFl; // get user input for flight choice
    if(chForFl == 'd') // if direct flight is chosen
    {
        if(p.choice == 1) // if international flight is chosen
        {
            cout << "You wish to go for " << "Rs " << p.PaymentForDirect[0] << " ticket" << " which is a " << p.flightType[p.choice] << " flight ticket and its time lapse is " << p.InternationalFlightHours[p.ch] << " hrs" << endl; // display ticket information
        } else if(p.choice == 2) // if local flight is chosen
        {
            cout << "You wish to go for " << "Rs " << p.PaymentForDirect[0] << " ticket" << " which is a " << p.flightType[p.choice] << " flight ticket and its time lapse is " << p.LocalFlightHours[p.ch] << " hrs" << endl; // display ticket information
        }
        int chForCard; // variable to store selected payment method
        cout << "Enter a payment method: " << endl;
        for(int i=0;i<3;i++) // loop through available payment methods
        {
            cout << i+1 << ". " << creditCards[i] << endl; // display payment method options
        }
        cin >> chForCard; // get user input for payment method
        string pin; // variable to store user's PIN
        cout << "Enter Pin: (4 digit) ";
        cin >> pin; // get user input for PIN
        for(int i=0;i!=pin.length();i++) // loop through PIN characters
        {
            pin[i] = '*'; // replace each character with an asterisk
        }
        cout << "Your pin: " << pin << endl; // display masked PIN
        char con; // variable to store confirmation choice
        cout << "Your account balance is " << "Rs " << p.T_Amount << endl; // display user's account balance
        cout << "Are you sure you want to confirm your purchase? (y/n) " << endl;
        cin >> con; // get user input for confirmation
        if(con == 'y') // if user confirms purchase
        {
            int cForEnter; // variable to store enter key press
            cout << "Your total bill for " << p.res << " tickets is " << "Rs " << p.res*p.PaymentForDirect[select] << endl; // display total cost of tickets
            cout << "Press enter to confirm your purchase..." << endl;
            if((cForEnter = getch()) == 13) // if user presses enter key
            {
                p.purchase = p.T_Amount - (p.res*p.PaymentForIndirect[select]); // calculate user's remaining account balance after purchase
                cout << "Your remaining account balance is " << "Rs " << p.purchase << endl; // display user's remaining account balance
                cout << "Thank you for the booking " << endl; // display thank you message
                cout << "HAVE A SAFE FLIGHT!" << endl; // display have a safe flight message
            }
        }
        else if(con == 'n') // If user chooses not to confirm purchase
        {
            cout << "Please rerun the program" << endl; // Inform user to rerun the program
        }
    }
    else if(chForFl == 'i') // If user selects an international flight
    {
        if(p.choice == 1) // If user selects an indirect flight
        {
            cout << "You wish to go for " << "Rs " << p.PaymentForIndirect[0] << " ticket" << " which is a " << p.flightType[p.choice] << " flight ticket and its time lapse is " << p.InternationalFlightHours[p.ch] << " hrs" << endl; // Display the details of the selected flight
        }
        else if(p.choice == 2) // If user selects a direct flight
        {
            cout << "You wish to go for " << "Rs " << p.PaymentForIndirect[0] << " ticket" << " which is a " << p.flightType[p.choice] << " flight ticket and its time lapse is " << p.LocalFlightHours[p.ch] << " hrs" << endl; // Display the details of the selected flight
        }

        int chForCard; // To store user's choice of payment method
        cout << "Enter a payment method: " << endl; 
        for(int i=0;i<3;i++) // Display the available payment methods
        {
            cout << i+1 << ". " << creditCards[i] << endl;
        }
        cin >> chForCard; // Take user's choice of payment method as input
        string pin; 
        cout << "Enter Pin: (4 digit) "; // Ask for user's PIN
        cin >> pin; // Take user's PIN as input
        for(string::iterator i=pin.begin();i!=pin.end();i++) // Hide the user's PIN by replacing each digit with an asterisk
        {
            *i = '*';
        }
        cout << "Your pin: " << pin << endl; // Display the user's PIN with asterisks
        char con; 
        cout << "Your account balance is " << "Rs " << p.T_Amount << endl; // Display the user's account balance
        cout << "Are you sure you want to confirm your purchase? (y/n) " << endl; 
        cin >> con; // Take user's confirmation as input
        if(con == 'y') // If user confirms purchase
        {
            int cForEnter; 
            cout << "Your total bill for " << p.res << " tickets is " << "Rs " << p.res*p.PaymentForIndirect[select] << endl; // Display the total bill for the selected flight
            cout << "Press enter to confirm your purchase..." << endl;
            if((cForEnter = getch()) = 10) // Wait for user to press Enter to confirm purchase
            {
                p.purchase = p.T_Amount - (p.res*p.PaymentForIndirect[select]); // Calculate the remaining balance after purchase
                cout << "Your remaining account balance is " << "Rs " << p.purchase << endl; // Display the remaining balance
                cout << "Thankyou for the booking " << endl; // Display thank you message
                cout << "HAVE A SAFE FLIGHT!" << endl; // Display have a safe flight message
            }
        }
        else if(con == 'n')
        {
            cout << "Please rerun the program" << endl;
        }
    }
    else 
    {
        cout << "Invalid choice " << endl;
    }
    Refund();
}



void Booking::displayAvailableFlights()
{
    MenuForAdmin m;
    system("CLS");
    cout << "Enter you country name: ";
    cin >> from;
    setFrom(from);
    cout << "Enter the date and time for which you want to see available flights (YYYY-MM-DD HH:MM): ";
    cin >> year >> month >> day >> hr >> min;
    cout << "Where do you wanna travel from the following: " << endl;
    cout << "1.Country " << endl;
    cout << "2.City" << endl;
    cin >> p.choice;
    if(p.choice == 1)
    {
        cout << "From the following countries which " << p.flightType[p.choice] << " flight you want to go for? " << endl;
        cout <<"1.Dubai" << endl;
        cout <<"2.Australia" << endl;
        cout <<"3.Canada" << endl;
        cout <<"4.America" << endl;
        cout <<"5.China" << endl;
        cin >> p.ch;
        if(p.ch == 1)
        {
            char c;
            cout << "Following are the flights available for " << country[0] << " country at date  " << year << "-" << month << "-" << day << " " << "and time "<< hr << " hr"<< ":" << min << " min" << endl;
            setTo(country[0]);
            cout << "Want to see Flight schedule? (y/n)" << endl;
            cin >> c;
            if(c == 'y')
            {
                cout << "Following is the flight schedule avalable:" << endl; 
                for(int i=0;i<4;i++)
                {
                    cout << "Flight "<< i+1 << ". " << "Arrival time -> " << arrive[i] << " " << "depart time -> " << depart[i] << endl;
                }
                int chForArr;
                cout << "Enter choice: ";
                cin >> chForArr;
                if(chForArr == 1)
                {
                    cout << "You chose " << "Arrival time -> " << i.arrive[0] << " " << "depart time -> " << i.depart[0] << endl;
                }
                else if(chForArr == 2)
                {
                    cout << "You chose " << "Arrival time -> " << i.arrive[1] << " " << "depart time -> " << i.depart[1] << endl;
                }
                else if(chForArr == 3)
                {
                    cout << "You chose " << "Arrival time -> " << i.arrive[2] << " " << "depart time -> " << i.depart[2] << endl;
                }
                else if(chForArr == 4)
                {
                    cout << "You chose " << "Arrival time -> " << i.arrive[3] << " " << "depart time -> " << i.depart[3] << endl;
                }
                else
                {
                    cout << "Invalid choice " << endl;
                }
                cout << "This is a " << p.InternationalFlightHours[p.ch] << " hr flight "<< endl;
                cout << "Contacting Admin if that flight is available... " << endl;
                Sleep(10000);
                m.AdminLogin();
                m.FlightSchedule();
            }
        }
        else if(p.ch == 2)
        {
            char c;
            cout << "Following are the flights available for " << country[1] << " country at date and time " << year << "-" << month << "-" << day << " " << "and time "<< hr << " hr"<< ":" << min << " min" << endl;
            setTo(country[1]);
            cout << "Want to see Flight schedule? (y/n)" << endl;
            cin >> c;
            if(c == 'y')
            {
                cout << "Following is the flight schedule avalable:" << endl; 
                for(int i=0;i<4;i++)
                {
                    cout << "Flight " << i+1 << ". " << "Arrival time -> " << arrive[i] << " " << "depart time -> " << depart[i] << endl;
                }
                int chForArr;
                cout << "Enter choice: ";
                cin >> chForArr;
                if(chForArr == 1)
                {
                    cout << "You chose " << "Arrival time -> " << i.arrive[0] << " " << "depart time -> " << i.depart[0] << endl;
                }
                else if(chForArr == 2)
                {
                    cout << "You chose " << "Arrival time -> " << i.arrive[1] << " " << "depart time -> " << i.depart[1] << endl;
                }
                else if(chForArr == 3)
                {
                    cout << "You chose " << "Arrival time -> " << i.arrive[2] << " " << "depart time -> " << i.depart[2] << endl;
                }
                else if(chForArr == 4)
                {
                    cout << "You chose " << "Arrival time -> " << i.arrive[3] << " " << "depart time -> " << i.depart[3] << endl;
                }
                else
                {
                    cout << "Invalid choice " << endl;
                }
                cout << "This is a " << p.InternationalFlightHours[p.ch] << " hr flight "<< endl;
                cout << "Contacting Admin if that flight is available... " << endl;
                Sleep(10000);
                m.AdminLogin();
                m.FlightSchedule();
            }
        }
        else if(p.ch == 3)
        {
            char c;
            cout << "Following are the flights available for " << country[2] << " country at date and time " << year << "-" << month << "-" << day << " " << "and time "<< hr << " hr"<< ":" << min << " min" << endl;
            setTo(country[2]);
            cout << "Want to see Flight schedule? (y/n)" << endl;
            cin >> c;
            if(c == 'y')
            {
                cout << "Following is the flight schedule avalable:" << endl; 
                for(int i=0;i<4;i++){
                    cout << "Flight "  << i+1 << ". " << "Arrival time -> " << arrive[i] << " " << "depart time -> " << depart[i] << endl;
                }
                int chForArr;
                cout << "Enter choice: ";
                cin >> chForArr;
                if(chForArr == 1)
                {
                    cout << "You chose " << "Arrival time -> " << i.arrive[0] << " " << "depart time -> " << i.depart[0] << endl;
                }
                else if(chForArr == 2)
                {
                    cout << "You chose " << "Arrival time -> " << i.arrive[1] << " " << "depart time -> " << i.depart[1] << endl;
                }
                else if(chForArr == 3)
                {
                    cout << "You chose " << "Arrival time -> " << i.arrive[2] << " " << "depart time -> " << i.depart[2] << endl;
                }
                else if(chForArr == 4)
                {
                    cout << "You chose " << "Arrival time -> " << i.arrive[3] << " " << "depart time -> " << i.depart[3] << endl;
                }
                else
                {
                    cout << "Invalid choice " << endl;
                }
                cout << "This is a " << p.InternationalFlightHours[p.ch] << " hr flight "<< endl;
                cout << "Contacting Admin if that flight is available... " << endl;
                Sleep(10000);
                m.FlightSchedule();
            }
        }
        else if(p.ch == 4)
        {
            char c;
            cout << "Following are the flights available for " << country[3] << " country at date and time " << year << "-" << month << "-" << day << " " << "and time "<< hr << " hr"<< ":" << min << " min" << endl;
            setTo(country[3]);
            cout << "Want to see Flight schedule? (y/n)" << endl;
            cin >> c;
            if(c == 'y'){
                cout << "Following is the flight schedule avalable:" << endl; 
                for(int i=0;i<4;i++){
                    cout << "Flight "  << i+1 << ". " << "Arrival time -> " << arrive[i] << " " << "depart time -> " << depart[i] << endl;
                }
                int chForArr;
                cout << "Enter choice: ";
                cin >> chForArr;
                if(chForArr == 1)
                {
                    cout << "You chose " << "Arrival time -> " << i.arrive[0] << " " << "depart time -> " << i.depart[0] << endl;
                }
                else if(chForArr == 2)
                {
                    cout << "You chose " << "Arrival time -> " << i.arrive[1] << " " << "depart time -> " << i.depart[1] << endl;
                }
                else if(chForArr == 3)
                {
                    cout << "You chose " << "Arrival time -> " << i.arrive[2] << " " << "depart time -> " << i.depart[2] << endl;
                }
                else if(chForArr == 4)
                {
                    cout << "You chose " << "Arrival time -> " << i.arrive[3] << " " << "depart time -> " << i.depart[3] << endl;
                }
                else{
                    cout << "Invalid choice " << endl;
                }
                cout << "This is a " << p.InternationalFlightHours[p.ch] << " hr flight "<< endl;
                cout << "Contacting Admin if that flight is available... " << endl;
                Sleep(10000);
                m.AdminLogin();
                m.FlightSchedule();
            }
        }
        else if(p.ch == 5)
        {
            char c;
            cout << "Following are the flights available for " << country[4] << " country at date and time " << year << "-" << month << "-" << day << " " << "and time "<< hr << " hr"<< ":" << min << " min" << endl;
            setTo(country[3]);
            cout << "Want to see Flight schedule? (y/n)" << endl;
            cin >> c;
            if(c == 'y'){
                cout << "Following is the flight schedule avalable:" << endl; 
                for(int i=0;i<4;i++){
                    cout << "Flight "  << i+1 << ". " << "Arrival time -> " << arrive[i] << " " << "depart time -> " << depart[i] << endl;
                }
                int chForArr;
                cout << "Enter choice: ";
                cin >> chForArr;
                if(chForArr == 1)
                {
                    cout << "You chose " << "Arrival time -> " << i.arrive[0] << " " << "depart time -> " << i.depart[0] << endl;
                }
                else if(chForArr == 2)
                {
                    cout << "You chose " << "Arrival time -> " << i.arrive[1] << " " << "depart time -> " << i.depart[1] << endl;
                }
                else if(chForArr == 3)
                {
                    cout << "You chose " << "Arrival time -> " << i.arrive[2] << " " << "depart time -> " << i.depart[2] << endl;
                }
                else if(chForArr == 4)
                {
                    cout << "You chose " << "Arrival time -> " << i.arrive[3] << " " << "depart time -> " << i.depart[3] << endl;
                }
                else{
                    cout << "Invalid choice " << endl;
                }
                cout << "This is a " << p.InternationalFlightHours[p.ch] << " hr flight "<< endl;
                cout << "Contacting Admin if that flight is available... " << endl;
                Sleep(10000);
                m.AdminLogin();
                m.FlightSchedule();
            }
        }
        else
        {
            cout << "Invalid choice" << endl;
        }
    }
    else if(p.choice == 2)
    {
        cout << "From the following countries which " << p.flightType[p.choice] << " flight you want to go for? " << endl;
        cout << "1.Islamabad" << endl;
        cout << "2.Lahore" << endl;
        cout << "3.Quetta" << endl;
        cout << "4.Peshawar" << endl;
        cout << "5.Karachi" << endl;
        cin >> p.ch;
        if(p.ch == 1)
        {
            cout << "Following are the flights available for the " << city[1] << " city at date and time " << year << "-" << month << "-" << day << " " << "and time "<< hr << " hr"<< ":" << min << " min" << endl;
            setTo(city[0]);
            char c;
            cout << "Want to see Flight schedule? (y/n)" << endl;
            cin >> c;
            if(c == 'y')
            {
                cout << "Following is the flight schedule avalable:" << endl; 
                for(int i=0;i<5;i++)
                {
                    cout << "Flight "  << i+1 << ". " << "Arrival time -> " << arrive[i] << " " << "depart time -> " << depart[i] << endl;
                }
                int chForArr;
                cout << "Enter choice: ";
                cin >> chForArr;
                if(chForArr == 1)
                {
                    cout << "You chose " << "Arrival time -> " << i.arrive[0] << " " << "depart time -> " << i.depart[0] << endl;
                }
                else if(chForArr == 2)
                {
                    cout << "You chose " << "Arrival time -> " << i.arrive[1] << " " << "depart time -> " << i.depart[1] << endl;
                }
                else if(chForArr == 3)
                {
                    cout << "You chose " << "Arrival time -> " << i.arrive[2] << " " << "depart time -> " << i.depart[2] << endl;
                }else if(chForArr == 4)
                {
                    cout << "You chose " << "Arrival time -> " << i.arrive[3] << " " << "depart time -> " << i.depart[3] << endl;
                }else
                {
                    cout << "Invalid choice " << endl;
                }
                cout << "This is a " << p.LocalFlightHours[p.ch] << " hr flight "<< endl;
                cout << "Contacting Admin if that flight is available... " << endl;
                Sleep(10000);
                m.AdminLogin();
                m.FlightSchedule();
            }
        }
        else if(p.ch == 2)
        {
            cout << "Following are the flights available for the " << city[2] << " city at date and time " << year << "-" << month << "-" << day << " " << "and time "<< hr << " hr"<< ":" << min << " min" << endl;
            setTo(city[1]);
            char c;
            cout << "Want to see Flight schedule? (y/n)" << endl;
            cin >> c;
            if(c == 'y'){
                cout << "Following is the flight schedule avalable:" << endl; 
                for(int i=0;i<5;i++)
                {
                    cout << "Flight "  << i+1 << ". " << "Arrival time -> " << arrive[i] << " " << "depart time -> " << depart[i] << endl;
                }
                int chForArr;
                cout << "Enter choice: ";
                cin >> chForArr;
                if(chForArr == 1)
                {
                    cout << "You chose " << "Arrival time -> " << i.arrive[0] << " " << "depart time -> " << i.depart[0] << endl;
                }
                else if(chForArr == 2)
                {
                    cout << "You chose " << "Arrival time -> " << i.arrive[1] << " " << "depart time -> " << i.depart[1] << endl;
                }
                else if(chForArr == 3)
                {
                    cout << "You chose " << "Arrival time -> " << i.arrive[2] << " " << "depart time -> " << i.depart[2] << endl;
                }
                else if(chForArr == 4)
                {
                    cout << "You chose " << "Arrival time -> " << i.arrive[3] << " " << "depart time -> " << i.depart[3] << endl;
                }
                else
                {
                    cout << "Invalid choice " << endl;
                }
                cout << "This is a " << p.LocalFlightHours[p.ch] << " hr flight "<< endl;
                cout << "Contacting Admin if that flight is available... " << endl;
                Sleep(10000);
                m.AdminLogin();
                m.FlightSchedule();
            }
        }
        else if(p.ch == 3)
        {
            cout << "Following are the flights available for the " << city[3] << " city at date and time " << year << "-" << month << "-" << day << " " << "and time "<< hr << " hr"<< ":" << min << " min" << endl;
            setTo(city[2]);
            char c;
            cout << "Want to see Flight schedule? (y/n)" << endl;

            cin >> c;
            if(c == 'y')
            {
                cout << "Following is the flight schedule avalable:" << endl; 
                for(int i=0;i<5;i++)
                {
                    cout << "Flight "  << i+1 << ". " << "Arrival time -> " << arrive[i] << " " << "depart time -> " << depart[i] << endl;
                }
                int chForArr;
                cout << "Enter choice: ";
                cin >> chForArr;
                if(chForArr == 1)
                {
                    cout << "You chose " << "Arrival time -> " << i.arrive[0] << " " << "depart time -> " << i.depart[0] << endl;
                }
                else if(chForArr == 2)
                {
                    cout << "You chose " << "Arrival time -> " << i.arrive[1] << " " << "depart time -> " << i.depart[1] << endl;
                }
                else if(chForArr == 3)
                {
                    cout << "You chose " << "Arrival time -> " << i.arrive[2] << " " << "depart time -> " << i.depart[2] << endl;
                }
                else if(chForArr == 4)
                {
                    cout << "You chose " << "Arrival time -> " << i.arrive[3] << " " << "depart time -> " << i.depart[3] << endl;
                }
                else
                {
                    cout << "Invalid choice " << endl;
                }
                cout << "This is a " << p.LocalFlightHours[p.ch] << " hr flight "<< endl;
                cout << "Contacting Admin if that flight is available... " << endl;
                Sleep(10000);
                m.AdminLogin();
                m.FlightSchedule();
            }
        }else if(p.ch == 4){
            cout << "Following are the flights available for the " << city[4] << " city at date and time " << year << "-" << month << "-" << day << " " << "and time "<< hr << " hr"<< ":" << min << " min" << endl;
            setTo(city[3]);
            char c;
            cout << "Want to see Flight schedule? (y/n)" << endl;

            cin >> c;
            if(c == 'y'){
                cout << "Following is the flight schedule avalable:" << endl; 
                for(int i=0;i<5;i++){
                    cout << "Flight "  << i+1 << ". " << "Arrival time -> " << arrive[i] << " " << "depart time -> " << depart[i] << endl;
                }
                int chForArr;
                cout << "Enter choice: ";
                cin >> chForArr;
                if(chForArr == 1)
                {
                    cout << "You chose " << "Arrival time -> " << i.arrive[0] << " " << "depart time -> " << i.depart[0] << endl;
                }
                else if(chForArr == 2)
                {
                    cout << "You chose " << "Arrival time -> " << i.arrive[1] << " " << "depart time -> " << i.depart[1] << endl;
                }
                else if(chForArr == 3)
                {
                    cout << "You chose " << "Arrival time -> " << i.arrive[2] << " " << "depart time -> " << i.depart[2] << endl;
                }
                else if(chForArr == 4)
                {
                    cout << "You chose " << "Arrival time -> " << i.arrive[3] << " " << "depart time -> " << i.depart[3] << endl;
                }
                else
                {
                    cout << "Invalid choice " << endl;
                }
                cout << "This is a " << p.LocalFlightHours[p.ch] << " hr flight "<< endl;
                cout << "Contacting Admin if that flight is available... " << endl;
                Sleep(10000);
                m.AdminLogin();
                m.FlightSchedule();
            }
        }else if(p.ch == 5)
        {
            cout << "Following are the flights available for the " << city[5] << " city at date and time " << year << "-" << month << "-" << day << " " << "and time "<< hr << " hr"<< ":" << min << " min" << endl;
            setTo(city[4]);
            char c;
            cout << "Want to see Flight schedule? (y/n)" << endl;
            cin >> c;
            if(c == 'y')
            {
                cout << "Following is the flight schedule avalable:" << endl; 
                for(int i=0;i<5;i++)
                {
                    cout << "Flight " << i+1 << ". " << "Arrival time -> " << arrive[i] << " " << "depart time -> " << depart[i] << endl;
                }
                int chForArr;
                cout << "Enter choice: ";
                cin >> chForArr;
                if(chForArr == 1)
                {
                    cout << "You chose " << "Arrival time -> " << i.arrive[0] << " " << "depart time -> " << i.depart[0] << endl;
                }
                else if(chForArr == 2)
                {
                    cout << "You chose " << "Arrival time -> " << i.arrive[1] << " " << "depart time -> " << i.depart[1] << endl;
                }
                else if(chForArr == 3)
                {
                    cout << "You chose " << "Arrival time -> " << i.arrive[2] << " " << "depart time -> " << i.depart[2] << endl;
                }
                else if(chForArr == 4)
                {
                    cout << "You chose " << "Arrival time -> " << i.arrive[3] << " " << "depart time -> " << i.depart[3] << endl;
                }
                else
                {
                    cout << "Invalid choice " << endl;
                }
                cout << "This is a " << p.LocalFlightHours[p.ch] << " hr flight "<< endl;
            }
        }
        else
        {
            cout << "Invalid choice" << endl;
        }
    }
}

class Passenger : public LoginAndReg
{
    bool isRegistered = false;
    LoginAndReg users[MAX_USERS];
    int numUsers = 0;
    Booking* b;
    public:
    Passenger(){}
    Passenger(bool isRegistered, int numUsers, Booking* b){
        this->isRegistered =isRegistered;
        this->numUsers = numUsers;
        this->b = b;
    }
    void oldUser()
    {
        cout << endl << "Enter your name: ";
        cin >> l.name;
        cout << "Enter your password: ";
        while((l.c = getch()) != '\r') 
        {
            if(l.c == '\b') 
            { // backspace key
                if(l.password != "") 
                {
                    cout << "\b \b"; // remove character from console
                    l.password = l.password.substr(0, l.password.size()-1); // remove last character from password
                }
            }
            else 
            {
                if(l.password.length() < 8) 
                {
                    l.password += l.c;
                    cout << '*';
                }
            }
        }
        writefile(l.name, l.password, "No cnic for old user");
        system("CLS");
    }
    void newUser()
    {
        bool flag = false;
        cout << endl << "Enter your name (limit 8 characters): ";
        cin >> l.name;
        string pass1, pass2;
        do
        {
            pass1 = setPasswordForNewuser1();
            pass2 = setPasswordForNewuser2();
            if(pass1 == pass2)
            {
                flag = true;
            }else
            {
                cout << "Password does not match " << endl;
            }
        } while(!flag);
        while (true) 
        {
            cout << "Enter your CNIC number (max 13 digits): ";
            cin >> l.cnic;

            cout << "Thanks for entering your CNIC number: " << l.cnic << endl;
            break;
        }
        writefile(l.name, pass1, l.cnic);
        
        cout << "Now enter your login credentials" << endl;
        cout << endl << "Enter your name: ";
        cin >> l.name;
        cout << "Enter your password: ";
        
        l.password = "";
        char c;
        while((c = getch()) != '\r') 
        {
            if(c == '\b') { // backspace key
                if(l.password != "") 
                {
                    cout << "\b \b"; // remove character from console
                    l.password = l.password.substr(0, l.password.size()-1); // remove last character from password
                }
            }
            else 
            {
                if(l.password.length() < 8) 
                {
                    l.password += c;
                    cout << '*';
                }
            }
        }
        system("CLS");
    }
};
void Booking::displayMenu()
{
    cout << "Welcome to NUCES Airline Flight System!" << endl << endl;
    cout << setw(10) << left << "Option" << setw(20) << "Description" << endl;
    cout << setw(10) << left << "1" << setw(20) << "Display available flights" << endl;
    cout << setw(10) << left << "2" << setw(20) << "Reserve a Seat" << endl;
    cout << setw(10) << left << "3" << setw(20) << "Refund" << endl;
    cout << setw(10) << left << "4" << setw(20) << "Quit" << endl;
    int choice;
}

Booking::Booking(const Booking& myBook)
{
    res_seats = myBook.res_seats; // Copy the reserved seats from the original booking
}


ostream& operator << (ostream& out, const Booking& b)
{
    out << b.res_seats; // Output the reserved seats of the booking
    return out;
}


int main() 
{
    LoginInfo L;
    LoginInfo *users = new LoginInfo[L.user_num];
    for(int i=0;i<L.user_num;i++)
    {
        L.user_num++;
    }
    int chForB;
    int c;
    Booking b;
    string userOradmin;
    cout << setw(29) << setfill('.') << "" << endl;
    cout << setw(16) << setfill('.') << "WELCOME TO" << setw(13) << setfill('.') << "" << endl;
    cout << setw(28) << setfill('.') << "" << endl;
    cout << setw(17) << setfill('.') << "NAFS AIRLINE" << setw(12) << setfill('.') << "" << endl;
    cout << setw(29) << setfill('.') << "" << endl;
    cout << "Press Enter to start..." << endl;
    getline(cin, userOradmin); // wait for user to input a full line
    while (userOradmin.empty())
    { // check if line is empty (user only pressed enter)
        cout << "Are you a User or Admin" << endl;
        cout << "[U]ser " << endl;
        cout << "[A]dmin " << endl;
        getline(cin, userOradmin); // wait for user to input a full line again
    }
    if(userOradmin == "u"){
        int chForB;
        Booking b;

        do {
            cout << "[L]ogin" << endl;
            cout << "[R]egister" << endl;
            char choice;
            cin >> choice;

            if(choice == 'l')
            {
                Passenger p;
                p.oldUser();
            }else if(choice == 'r')
            {
                Passenger p;
                p.newUser();
            }

            b.displayMenu();
            cin >> chForB;

            while (chForB != 1 && chForB != 2 && chForB != 4)
            { // check if user entered a valid choice
                cout << "Invalid choice. Please try again." << endl;
                b.displayMenu();
                cin >> chForB;
            }

            if(chForB == 1)
            {
                b.displayAvailableFlights();
                // Provide the user with the menu again after completing option 1
                b.displayMenu();
                cin >> chForB;
            }else if(chForB == 2)
            {
                b.reserveSeat();
                // Provide the user with the menu again after completing option 2
                b.displayMenu();
                cin >> chForB;
            }
            else if(chForB == 4)
            {
                exit(1);
            }

        } while(chForB != 4);

    }
    else if(userOradmin == "a")
    {
        int chForAdmin;
        FlightSchedule m;

        do {
            m.AdminLogin();
            m.display();
            cin >> chForAdmin;

            while(chForAdmin != 1 && chForAdmin != 2 && chForAdmin != 3 && chForAdmin != 4 && chForAdmin != 5 && chForAdmin != 6)
            {
                cout << "Invalid choice. Please try again. " << endl;
                m.display();
                cin >> chForAdmin;
            }

            if(chForAdmin == 1)
            {
                m.DisplayAvailableSeats();
                m.display();
                cin >> chForAdmin;
            }
            else if(chForAdmin == 2)
            {
                m.checkingSeats();
                m.display();
                cin >> chForAdmin;
            }else if(chForAdmin == 3)
            {
                m.changeSchedule();
                // Provide the user with the menu again after completing option 3
                m.display();
                cin >> chForAdmin;
            }
            else if(chForAdmin == 4)
            {
                m.AddCountries();
                m.display();
                cin >> chForAdmin;
            }
            else if(chForAdmin == 5)
            {
                m.RemCountries();
                m.display();
                cin >> chForAdmin;
            }
            else if(chForAdmin == 6)
            {
                Flight flights[MAX_FLIGHTS];
                int num_flights = 5;

                // initialize 5 available flights
                flights[0] = {"01:00", "03:00"};
                flights[1] = {"03:00", "05:00"};
                flights[2] = {"06:00", "08:00"};
                flights[3] = {"08:00", "14:00"};
                flights[4] = {"11:00", "13:00"};

                char yesORno;
                do {
                    cout << "These are the available flights. " << endl;
                    for(int i=0; i<num_flights; i++) {
                        cout << "Flight "<< i+1 << ". " << "Arrival time -> " << flights[i].arrival_time << " " << "Departure time -> " << flights[i].depart_time << endl;
                    }
                    cout << "Want to add more? (y/n)" << endl;
                    cin >> yesORno;
                    if(yesORno == 'y') {    
                        m.addMoreFlights(flights, num_flights);
                    }
                } while (yesORno != 'n');
                    m.display();
                    cin >> chForAdmin;
            }
        }while(chForAdmin != 6);
        }
        cout << b;
    return 0;
}
