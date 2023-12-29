#include <iostream>
#include <string>
#include <chrono>
# include <vector>
# include <fstream>
# include <sstream>
#  include <typeinfo>
# include <iomanip>
# include <memory>
#include <cstdlib>  
#include <ctime>
#include <string.h>
#include <algorithm>

using namespace std;
enum class RoomStatus {
    Vacant,
    Occupied
};

enum class Cleanliness {
    Clean,
    Dirty
};

enum class BedType {
    Single,
    Double
};


struct Room {
    //string roomNumber;
    RoomStatus status;
    double price;
    Cleanliness cleanliness;
    BedType bedType;
    double discountPercentage;
    int roomNumber;

    // Default constructor
    Room(){};

    Room(int roomNumber,RoomStatus status, double price, Cleanliness cleanliness, BedType bedType, double discountPercentage)
        : roomNumber(roomNumber), status(status), price(price), cleanliness(cleanliness), bedType(bedType), discountPercentage(discountPercentage) {}

};


vector<Room> hotelRooms(100);
vector<Room> rooms(100);
vector<string> roomVector;
vector<string> room_vec;
vector<Room> room;
vector<Room> singlebedroom;
vector<Room> doublebedrooms;
vector<Room> binary;

// diff data types, tbc

struct Customer {
    string idType;
    int idNumber;
    string name;
    string gender;
    string country;
    int roomNumber;
    string checkInDateTime;
    int stayingDays;
    double totalAmount;
    double initialPayment;
    double pendingAmount;
    double deposit;
    int roomBooked;

    // Default constructor
    Customer(){};
    Customer(string idType,int idNumber,string name,string gender,string country,int roomNumber,string checkInDateTime,int stayingDays,double totalAmount,double initialPayment,double pendingAmount,double deposit,int roomBooked)
            : idType(idType), idNumber(idNumber),name(name),gender(gender),country(country),roomNumber(roomNumber),checkInDateTime(checkInDateTime),stayingDays(stayingDays),totalAmount(totalAmount),initialPayment(initialPayment),pendingAmount(pendingAmount),deposit(deposit),roomBooked(roomBooked) {}
    
};
vector<Customer> customersRecord;
vector<Customer> customersinfo;

// Function prototypes
bool authenticateUser();
void systemPanel();
void receptionControlPanel();
void newCustomerForm();
void storeCustomerDetails(const Customer& newcustomer);
void displayCustomerDetails(const Customer& customer);
void loadCustomerDataFromFile(vector<Customer>& customersRecord);
void writeCustomerDetailsToFile(const string& fileName);
// void displayAllCustomerDetails(const Customer& customer);
void displayAllCustomersFromVector(const vector<Customer>& customers);
void readInputFile(const string& fileName);
void randomlyAssignRoomAttributes();
void showRoom();
void writeRoomInformationToFile(const string& fileName);
bool compareRooms(const Room& room1, const Room& room2);
// int sortandsearchRooms(vector<Room>& rooms);
void printAllRooms(const vector<Room>& rooms);
void printRoom(const Room& room);
void readRoomInformationFromFile(const string& fileName, vector<Room>& hotelRooms);
int binarySearchAvailableRooms(const vector<Room>& rooms, const string& targetStatus);
// void searchAvailableRooms(vector<Room>& hotelRooms, const string& targetStatus);
// void deleteRooms(vector<Room>& hotelRooms);
// bool shouldRemoveRoom(const Room& room);
Room parseRoom(const string& roomData);
vector<Room> readRoomData(const string& filename);
// void writeRoomInformationToVector(vector<string>& roomInfoVector);
void writeRoomInformationToFile(const string& fileName);
string roomStatusToString(RoomStatus status);
string cleanlinessToString(Cleanliness cleanliness);
string bedTypeToString(BedType bedType);
void printRoomInformationVector(const vector<string>& roomInfoVector);
// int binarySearchForVacantRoom(const vector<Room>& rooms);
bool isRoomVacant(const Room& room);
void sortRoomInfoVectorBasedOnPrice(vector<string>& roomInfoVector);
int binarySearchAvailableRooms(const vector<string>& roomInfoVector, int targetRoomNumber);
void readRoomInformationFromFile(const string& fileName, vector<string>& roomInfoVector);
void readRoomInformationFromFiles(const string& fileName, vector<string>& roomInfoVector, int linesPerRoom);
// void vectorToArray(const vector<string>& roomInfoVector, string roomInfoArray[][2]);
// void printRoomInfoArray(const string roomInfoArray[][2], int size);
void merge(vector<Room>& rooms, int left, int mid, int right);
void mergeSort(vector<Room>& rooms, int left, int right);
void bubbleSort(vector<Room>& rooms);
void bubbleSortCustomer(vector<Customer>& customers);
int binarySearchVacantRoom(const vector<Room>& rooms, int left, int right, int targetPrice);
int linearSearchCustomer(const vector<Customer>& customers, int CustomerID);
int binarySearchroom(const vector<Customer>& customers, int targetRoomNumber);
void customerSearch(const vector<Customer>& customers);
void roomSearch(const vector<Customer>& customers);
void displayRoomDetails (const Room& room);
void updateRoomStatus(vector<Room>& rooms, int roomNumber, int low, int high);
void updateCustomerInformation(vector<Customer>& customers, int customerID, int low, int high);
void showMinMaxPrice(vector<Room>& rooms, int low, int high);
void deleteCustomer(vector<Customer>& customers, int customerID, int low, int high);
void checkoutForm(vector<Customer>& customers, int customerID, int low, int high);
void showInvoice(vector<Customer>& customers, int customerID);
// void searchAvailableRooms();
void showSingleBedroomsByPrice();
void showDoublebedroomsByPrice();
void displayRoomInformation(const vector<Room>& rooms);
void displayCustomerInfo(const vector<Customer>& customers);

    Room room1(1,RoomStatus::Vacant, 126, Cleanliness::Clean, BedType::Single, 5);
    Room room3(3,RoomStatus::Vacant, 136, Cleanliness::Clean, BedType::Double, 14);
    Room room5(5,RoomStatus::Vacant, 170, Cleanliness::Dirty, BedType::Single, 28);
    Room room6(6,RoomStatus::Vacant, 105, Cleanliness::Clean, BedType::Double, 2);
    Room room2(2,RoomStatus::Occupied, 126, Cleanliness::Clean, BedType::Single, 5);
    Room room4(4,RoomStatus::Occupied, 136, Cleanliness::Clean, BedType::Double, 14);
    Room room7(7,RoomStatus::Occupied, 170, Cleanliness::Dirty, BedType::Single, 28);
    Room room8(8,RoomStatus::Occupied, 105, Cleanliness::Clean, BedType::Double, 2);
    Room room9(9,RoomStatus::Vacant, 126, Cleanliness::Clean, BedType::Single, 5);
    Room room10(10,RoomStatus::Vacant, 136, Cleanliness::Clean, BedType::Double, 14);
    Room room11(11,RoomStatus::Occupied, 170, Cleanliness::Dirty, BedType::Single, 28);
    Room room12(12,RoomStatus::Occupied, 105, Cleanliness::Clean, BedType::Double, 2);
    Room room13(13,RoomStatus::Vacant, 126, Cleanliness::Clean, BedType::Single, 5);

    Customer customer1("IC",234,"Ben","male","Malaysia",1,"12/12/2020",3,300,100,200,100,1);
    Customer customer2("IC",128,"Isac","male","Malaysia",2,"12/12/2020",3,300,100,200,100,1);
    Customer customer3("IC",534,"Alicia","female","Malaysia",3,"12/11/2020",3,300,100,200,100,1);
    Customer customer4("IC",674,"Chris","male","Malaysia",4,"11/12/2020",3,300,100,200,100,1);
    Customer customer5("IC",888,"TengCheng","male","Malaysia",5,"10/12/2020",3,300,100,200,100,1);
    Customer customer6("IC",263,"Gabe","male","Malaysia",6,"13/12/2020",3,300,100,200,100,1);
    Customer customer7("IC",536,"Alice","female","Malaysia",7,"11/12/2020",3,300,100,200,100,1);
    Customer customer8("IC",896,"XiuXiang","male","Malaysia",8,"9/12/2020",3,300,100,200,100,1);
    Customer customer9("IC",646,"Menghin","male","Malaysia",9,"8/12/2020",3,300,100,200,100,1);
    Customer customer10("IC",530,"Vincent","male","Malaysia",10,"12/12/2020",3,300,100,200,100,1);

void receptionControlPanel() {
    int vacantRoomIndex = -1;
    int roomindex;
    int id_index;
    int room_index;
    int number;
    int id_number;
    int room_number;
    int customerID;

    vector<Room> room = {room1, room3, room5, room6, room2, room4, room7, room8, room9, room10, room11, room12, room13};
    for (const auto& room : room) {
        if (room.bedType == BedType::Single) {
            singlebedroom.push_back(room);
        }
    }
    
    for (const auto& room : room) {
        if (room.bedType == BedType::Double) {
            doublebedrooms.push_back(room);
        }
    }



    vector<Customer> customersinfo = {customer1, customer2, customer3};

    cout << "***************************************************" << endl;
    cout << "      Welcome to the Reception Control Panel\n";
    cout << "***************************************************" << endl;
    // Add reception staff functionalities here
    
    int choice;
    cout << "1. New Customer Form\n";
    cout << "2. Show all rooms (unsorted)\n";
    cout << "3. Search for available rooms\n";
    cout << "4. Show single bedrooms by price\n";
    cout << "5. Show double bedrooms by price\n";
    cout << "6. Show information of all customers\n";
    cout << "7. Search customer by ID\n";
    cout << "8. Search customer by room number\n";
    cout << "9. Update room status\n";
    cout << "10. Update customer information\n";
    cout << "11. Show min and max price of rooms\n";
    cout << "12. Delete customer\n";
    cout << "13. Check out\n";
    cout << "14. Show invoice\n";
    cout << "15. Show all rooms (sorted)\n";
    cout << "16. Show all customers (sorted)\n";
    cout << "17. Quit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice) {
        case 1:
            newCustomerForm();
            break;
        case 2:
            randomlyAssignRoomAttributes();
            showRoom();
            writeRoomInformationToFile("room_data.txt");
            break;
        case 3:
            bubbleSort(room);
            vacantRoomIndex = binarySearchVacantRoom(room,0, room.size()-1, 126);
            if (vacantRoomIndex != -1) {
                cout << "Found a vacant room at index: " << vacantRoomIndex << endl;
                cout << "Room: " << room[vacantRoomIndex].roomNumber << " Found"<<endl;
                displayRoomDetails(room[vacantRoomIndex]);
                
            } else {
                cout << "No available room found.\n";
            }

            receptionControlPanel();
            break;
        case 4:
            showSingleBedroomsByPrice();
            break;
        case 5:
            showDoublebedroomsByPrice();
            break;
        case 6:
            readInputFile("customer_data.txt");
            break;
        case 7:
            customerSearch(customersinfo);
            break;
        case 8:
            roomSearch(customersinfo);
            break;
        case 9:
            cout << "Enter room number: ";
            cin >> room_number;
            updateRoomStatus(room, room_number, 0, room.size()-1);
            break;
        case 10:
            updateCustomerInformation(customersinfo, 1, 0, room.size()-1);
            break;
        case 11:
            showMinMaxPrice(room, 1, room.size()-1);
            break;
        case 12:
            bubbleSortCustomer(customersinfo);
            cout << "Enter Customer ID: ";
            cin >> customerID;
            deleteCustomer(customersinfo, customerID, 0, customersinfo.size()-1);
            break;
        case 13:
            bubbleSortCustomer(customersinfo);
            cout << "Enter Customer ID: ";
            cin >> customerID;
            checkoutForm(customersinfo, customerID, 0, customersinfo.size()-1);
            break;
        case 14:
            bubbleSortCustomer(customersinfo);
            cout << "Enter Customer ID: ";
            cin >> customerID;
            showInvoice(customersinfo, customerID);
            break;
        case 15:
            displayRoomInformation(room);
            break;
        case 16:
            displayCustomerInfo(customersinfo);
            break;
        case 17:
            cout << "Exiting the system...\n";
            break;
        default:
            cout << "Invalid choice. Exiting...\n";
    }
}

void showDoublebedroomsByPrice() {
    bubbleSort(doublebedrooms);
    for (const auto& room : doublebedrooms) {
        cout << "Room number "<< room.roomNumber << ", Price: $" << room.price << ", Bedtype " << ((room.bedType==BedType::Single)? "Single":"Double") << std::endl;
    }
    
    receptionControlPanel();
}

void showSingleBedroomsByPrice() {
    mergeSort(singlebedroom, 0, singlebedroom.size() - 1);
    for (const auto& room : singlebedroom) {
        cout << "Room number"<<room.roomNumber<< ", Price: $" << room.price << ", Bedtype " << ((room.bedType==BedType::Single)? "Single":"Double") << std::endl;
    }

    receptionControlPanel();
}


void newCustomerForm() {
    string idType, name, gender, country;
    int roomNumber, stayingDays, idNumber;
    double totalAmount, initialPayment, pendingAmount, deposit;

    cout << "New Customer Form\n";

    cout << "ID Type (passport, IC, etc.): ";
    cin >> idType;

    cout << "ID Number: ";
    cin >> idNumber;

    cout << "Name: ";
    //cin.ignore(); // Clear the newline character from the buffer
    //getline(cin, name);
    cin >> name;

    cout << "Gender: ";
    cin >> gender;

    cout << "Country: ";
    cin >> country;

    cout << "Allocated Room Number: ";
    cin >> roomNumber;

    cout << "Check-in Date and Time: ";
    //cin.ignore(); // Clear the newline character from the buffer
    auto currentTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
    string checkinDateandTime = ctime(&currentTime);
    cout << checkinDateandTime;

    cout << "Number of Staying Days: ";
    cin >> stayingDays;

    cout << "Total Amount: ";
    cin >> totalAmount;

    cout << "Initial Payment: ";
    cin >> initialPayment;

    // Calculate pending amount and deposit
    pendingAmount = totalAmount - initialPayment;

    cout << "Deposit: ";
    cin >> deposit;

    // Display the new customer information
    cout << "\nNew Customer Information:\n";
    cout << "ID Type: " << idType << "\n";
    cout << "ID Number: " << idNumber << "\n";
    cout << "Name: " << name << "\n";
    cout << "Gender: " << gender << "\n";
    cout << "Country: " << country << "\n";
    cout << "Allocated Room Number: " << roomNumber << "\n";
    cout << "Check-in Date and Time: " << checkinDateandTime;
    cout << "Number of Staying Days: " << stayingDays << "\n";
    cout << "Total Amount: " << totalAmount << "\n";
    cout << "Initial Payment: " << initialPayment << "\n";
    cout << "Pending Amount: " << pendingAmount << "\n";
    cout << "Deposit: " << deposit << "\n";

    // Add the customer to the vector
    Customer newcustomer;
    newcustomer.idType = idType;
    newcustomer.idNumber = idNumber;
    newcustomer.name = name;
    newcustomer.gender=gender;
    newcustomer.country=country;
    newcustomer.roomNumber=roomNumber;
    newcustomer.checkInDateTime=checkinDateandTime;
    newcustomer.stayingDays=stayingDays;
    newcustomer.totalAmount=totalAmount;
    newcustomer.initialPayment=initialPayment;
    newcustomer.pendingAmount=pendingAmount;
    newcustomer.deposit=deposit;
    newcustomer.roomBooked++;

    storeCustomerDetails(newcustomer);
    receptionControlPanel();
}

void storeCustomerDetails(const Customer& newcustomer) {
    customersRecord.push_back(newcustomer);
    cout << "Customer details stored successfully\n";
    cout << "returning to reception control panel\n";
    writeCustomerDetailsToFile("customer_data.txt");
    receptionControlPanel();
}
void displayCustomerDetails(const Customer& customer) {
    shared_ptr<Customer> customerPtr = std::make_shared<Customer>(customer);
    // Display customer details
    cout << "Customer Details:\n";
    cout << "ID Type: " << customerPtr->idType << "\n";
    cout << "ID Number: " << customerPtr->idNumber << "\n";
    cout << "Name: " << customerPtr->name << "\n";
    cout << "Gender: " << customerPtr->gender << "\n";
    cout << "Country: " << customerPtr->country << "\n";
    cout << "Room Number: " << customerPtr->roomNumber << "\n";
    cout << "Check-in Date and Time: " << customerPtr->checkInDateTime;
    cout << "\n";
    cout << "Staying Days: " << customerPtr->stayingDays << "\n";
    cout << "Total Amount: " << customerPtr->totalAmount << "\n";
    cout << "Initial Payment: " << customerPtr->initialPayment << "\n";
    cout << "Pending Amount: " << customerPtr->pendingAmount << "\n";
    cout << "Deposit: " << customerPtr->deposit << "\n";
}
// read from file 
void loadCustomerDataFromFile(vector<Customer>& customers) {
    ifstream inputFile("customer_data.txt");
    Customer loadedCustomer;
    if (inputFile.is_open()) {
        string line;
        //Customer loadedCustomer;
        while (getline(inputFile, line)) {
            istringstream iss(line);
            //Customer loadedCustomer;
            iss >> loadedCustomer.idType >> loadedCustomer.idNumber >> loadedCustomer.name
                      >> loadedCustomer.gender >> loadedCustomer.country >> loadedCustomer.roomNumber
                      >> loadedCustomer.checkInDateTime >> loadedCustomer.stayingDays
                      >> loadedCustomer.totalAmount >> loadedCustomer.initialPayment
                      >> loadedCustomer.pendingAmount >> loadedCustomer.deposit;

            //if (!inputFile.fail()) {
                // Add the loaded customer to the vector
                //displayAllCustomerDetails(loadedCustomer);
                //customers.push_back(loadedCustomer);
                //cout << "-------------------------\n";
            }
        }
        if (!inputFile.fail()) {
            // Add the loaded customer to the vector
            //displayAllCustomerDetails(loadedCustomer);
            customers.push_back(loadedCustomer);
            //cout << "-------------------------\n";
        }
        else {
            cout << "Error reading file\n";
        }

        inputFile.close();
    }
    
    
    
// write from vector to file
void writeCustomerDetailsToFile(const string& fileName) {
    ofstream outputFile(fileName, ios::app);
    //outputFile.open("customer_data.txt", ios::app);
    //read the file and append the new customer data to the end of the file

    if (outputFile.is_open()) {
        for (const auto& customer : customersRecord) {
            outputFile << customer.idType << "\n" << customer.idNumber << "\n" << customer.name
                       << "\n" << customer.gender << "\n" << customer.country << "\n" << customer.roomNumber
                       << "\n" << customer.checkInDateTime << "" << customer.stayingDays
                       << "\n" << customer.totalAmount << "\n" << customer.initialPayment
                       << "\n" << customer.pendingAmount << "\n" << customer.deposit << "\n";
        }

        outputFile.close();
        cout << "Customer information written to file: " << fileName << "\n";
    } else {
        cout << "Unable to open file: " << fileName << "\n";
    }
    
}

void displayAllCustomersFromVector(const vector<Customer>& customers) {
    cout << "All Customers:\n";

    // for (const auto& customer : customers) {
    //     displayCustomerDetails(customer);
    // }
    for (int i = 0; i < customers.size(); i++) {
        displayCustomerDetails(customers[i]);
    }
    //displayCustomerDetails(customers[0]);
}


void readInputFile(const string& fileName) {
    ifstream inputFile(fileName);

    if (inputFile.is_open()) {
        string line;

        while (getline(inputFile, line)) {
            cout << "ID Type: " << line << "\n";

            if (!getline(inputFile, line)) break;
            cout << "ID Number: " << line << "\n";

            if (!getline(inputFile, line)) break;
            cout << "Name: " << line << "\n";

            if (!getline(inputFile, line)) break;
            cout << "Gender: " << line << "\n";

            if (!getline(inputFile, line)) break;
            cout << "Country: " << line << "\n";

            if (!getline(inputFile, line)) break;
            cout << "Room Number: " << line << "\n";

            if (!getline(inputFile, line)) break;
            cout << "Check-in Date and Time: " << line << "\n";

            if (!getline(inputFile, line)) break;
            cout << "Staying Days: " << line << "\n";

            if (!getline(inputFile, line)) break;
            cout << "Total Amount: " << line << "\n";

            if (!getline(inputFile, line)) break;
            cout << "Initial Payment: " << line << "\n";

            if (!getline(inputFile, line)) break;
            cout << "Pending Amount: " << line << "\n";

            if (!getline(inputFile, line)) break;
            cout << "Deposit: " << line << "\n";

            cout << "-------------------------\n";
        }

        inputFile.close();
    } else {
        cout << "Unable to open file: " << fileName << "\n";
        receptionControlPanel();
    }

    receptionControlPanel();
}

void randomlyAssignRoomAttributes() {
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(0)));

    for (int roomNumber = 1; roomNumber <= 100; ++roomNumber) {
        // Randomly assign room status
        hotelRooms[roomNumber - 1].status = (rand() % 2 == 0) ? RoomStatus::Vacant : RoomStatus::Occupied;

        // Randomly assign room price between $50 and $200
        hotelRooms[roomNumber - 1].price = 50.0 + (rand() % 151);

        // Randomly assign cleanliness
        hotelRooms[roomNumber - 1].cleanliness = (rand() % 2 == 0) ? Cleanliness::Clean : Cleanliness::Dirty;

        // Randomly assign bed type
        hotelRooms[roomNumber - 1].bedType = (rand() % 2 == 0) ? BedType::Single : BedType::Double;

        // Randomly assign discount percentage between 0% and 30%
        hotelRooms[roomNumber - 1].discountPercentage = static_cast<double>(rand() % 31);
    }
}

void showRoom() {
    cout << "Room:\n";

    for (int roomNumber = 1; roomNumber <= 100; ++roomNumber) {
        cout << "Room " << roomNumber << ":\n";
        cout << "Status: " << ((hotelRooms[roomNumber - 1].status == RoomStatus::Vacant) ? "Vacant" : "Occupied") << "\n";
        cout << "Price: $" << hotelRooms[roomNumber - 1].price << "\n";
        cout << "Cleanliness: " << ((hotelRooms[roomNumber - 1].cleanliness == Cleanliness::Clean) ? "Clean" : "Dirty") << "\n";
        cout << "Bed Type: " << ((hotelRooms[roomNumber - 1].bedType == BedType::Single) ? "Single" : "Double") << "\n";
        cout << "Discount Percentage: " << hotelRooms[roomNumber - 1].discountPercentage << "%\n";
        cout << "-------------------------\n";
    }

    receptionControlPanel();
}

void writeRoomInformationToFile(const std::string& fileName) {
    ofstream outputFile(fileName);

    if (outputFile.is_open()) {
        //std::vector<std::string> roomVector;
        for (int roomNumber = 1; roomNumber <= 100; ++roomNumber) {
            outputFile << "Room " << roomNumber << ":\n";
            outputFile << "Status: " << ((hotelRooms[roomNumber - 1].status == RoomStatus::Vacant) ? "Vacant" : "Occupied") << "\n";
            outputFile << "Price: $" << hotelRooms[roomNumber - 1].price << "\n";
            outputFile << "Cleanliness: " << ((hotelRooms[roomNumber - 1].cleanliness == Cleanliness::Clean) ? "Clean" : "Dirty") << "\n";
            outputFile << "Bed Type: " << ((hotelRooms[roomNumber - 1].bedType == BedType::Single) ? "Single" : "Double") << "\n";
            outputFile << "Discount Percentage: " << hotelRooms[roomNumber - 1].discountPercentage << "%\n";
            
            // Write room information to vector
            ostringstream oss;
            oss << "Room " << roomNumber << ":\n";
            oss << "Status: " << ((hotelRooms[roomNumber - 1].status == RoomStatus::Vacant) ? "Vacant" : "Occupied") << "\n";
            oss << "Price: $" << hotelRooms[roomNumber - 1].price << "\n";
            oss << "Cleanliness: " << ((hotelRooms[roomNumber - 1].cleanliness == Cleanliness::Clean) ? "Clean" : "Dirty") << "\n";
            oss << "Bed Type: " << ((hotelRooms[roomNumber - 1].bedType == BedType::Single) ? "Single" : "Double") << "\n";
            oss << "Discount Percentage: " << hotelRooms[roomNumber - 1].discountPercentage << "%\n";
            roomVector.push_back(oss.str());

        }

        outputFile.close();
        cout << "Room information written to file: " << fileName << "\n";
        printRoomInformationVector(roomVector);
    } else {
        cout << "Unable to open file: " << fileName << "\n";
    }
}

// print content of roomInfoVector
void printRoomInformationVector(const vector<string>& roomInfoVector) {
    for (const auto& roomInfo : roomInfoVector) {
        cout << roomInfo;
    }
}


bool compareRooms(const Room& room1, const Room& room2) {
    return room1.roomNumber < room2.roomNumber;
}

void printRoom(const Room& room) {
    cout << "Room " << room.roomNumber << ":\n";
    cout << "Status: " << ((room.status == RoomStatus::Vacant) ? "Vacant" : "Occupied") << "\n";
    cout << "Price: $" << room.price << "\n";
    cout << "Cleanliness: " << ((room.cleanliness == Cleanliness::Clean) ? "Clean" : "Dirty") << "\n";
    cout << "Bed Type: " << ((room.bedType == BedType::Single) ? "Single" : "Double") << "\n";
    cout << "Discount Percentage: " << room.discountPercentage << "%\n";
    cout << "-------------------------\n";
}

void printAllRooms(const vector<Room>& rooms) {
    for (const auto& room : rooms) {
        printRoom(room);
    }
}

void readRoomInformationFromFile(const string& fileName, vector<Room>& hotelRooms) {
    ifstream inputFile(fileName);

    if (inputFile.is_open()) {
        string line;
        Room room;
        while (getline(inputFile, line)) {
            if (line.find("Room") != string::npos) {
                istringstream iss(line);
                iss.ignore(5);  // Skip "Room "
                iss >> room.roomNumber;
                iss.ignore(1);  // Ignore ":"
            } else if (line.find("Status") != string::npos) {
                istringstream iss(line);
                iss >> ws;
                getline(inputFile, line);
                if (line.find("Vacant") != string::npos) {
                    room.status = RoomStatus::Vacant;
                } else {
                    room.status = RoomStatus::Occupied;
                }
            } else if (line.find("Price") != string::npos) {
                istringstream iss(line);
                iss >> room.price;
            } else if (line.find("Cleanliness") != string::npos) {
                istringstream iss(line);
                iss >> ws;
                getline(inputFile, line);
                if (line.find("Clean") != string::npos) {
                    room.cleanliness = Cleanliness::Clean;
                } else {
                    room.cleanliness = Cleanliness::Dirty;
                }
            } else if (line.find("Bed Type") != string::npos) {
                istringstream iss(line);
                iss >> ws;
                getline(inputFile, line);
                if (line.find("Single") != string::npos) {
                    room.bedType = BedType::Single;
                } else {
                    room.bedType = BedType::Double;
                }
            } else if (line.find("Discount Percentage") != string::npos) {
                istringstream iss(line);
                iss >> room.discountPercentage;
                hotelRooms.emplace_back(room);
            }
        }
        inputFile.close();
        cout << "Room information read from file: " << fileName << "\n";
    } else {
        cerr << "Unable to open file: " << fileName << "\n";
    }
}

// read from file room by room
void readRoomsData(const string& filePath, vector<Room>& rooms) {
    ifstream inputFile(filePath);

    if (inputFile.is_open()) {
        //std::vector<Room> rooms;
        Room room;
        string line;
        while (getline(inputFile, line)) {
            if (line.find("Room") != string::npos) {
                istringstream iss(line);
                iss.ignore(5);  // Skip "Room "
                iss >> room.roomNumber;
                iss.ignore(1);  // Ignore ":"
            } else if (line.find("Status") != string::npos) {
                istringstream iss(line);
                iss >> ws;
                getline(inputFile, line);
                if (line.find("Vacant") != string::npos) {
                    room.status = RoomStatus::Vacant;
                } else {
                    room.status = RoomStatus::Occupied;
                }
            } else if (line.find("Price") != string::npos) {
                istringstream iss(line);
                iss >> room.price;
            } else if (line.find("Cleanliness") != string::npos) {
                istringstream iss(line);
                iss >> ws;
                getline(inputFile, line);
                if (line.find("Clean") != string::npos) {
                    room.cleanliness = Cleanliness::Clean;
                } else {
                    room.cleanliness = Cleanliness::Dirty;
                }
            } else if (line.find("Bed Type") != string::npos) {
                istringstream iss(line);
                iss >> std::ws;
                getline(inputFile, line);
                if (line.find("Single") != string::npos) {
                    room.bedType = BedType::Single;
                } else {
                    room.bedType = BedType::Double;
                }
            } else if (line.find("Discount Percentage") != string::npos) {
                istringstream iss(line);
                iss >> room.discountPercentage;
                rooms.emplace_back(room);
            }
        }
        inputFile.close();
        //return rooms;
    } else {
        cerr << "Unable to open file: " << filePath << endl;
        //return {};
    }
}

Room parseRoom(const string& roomData) {
    istringstream iss(roomData);
    Room room;

    // Assuming the input format is consistent
    iss >> room.roomNumber;
    string statusStr, cleanlinessStr, bedTypeStr;



    iss >> statusStr;
    room.status = (statusStr == "Vacant") ? RoomStatus::Vacant : RoomStatus::Occupied;

    iss>>room.price;
    
    iss >> cleanlinessStr;
    room.cleanliness = (cleanlinessStr == "Clean") ? Cleanliness::Clean : Cleanliness::Dirty;

    
    iss >> bedTypeStr;
    room.bedType = (bedTypeStr == "Single") ? BedType::Single : BedType::Double;

    iss >> room.discountPercentage;

    return room;
}

vector<Room> readRoomData(const string& filename) {
    vector<Room> rooms;
    ifstream file(filename);

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            if (line.empty()) continue; // Skip empty lines
            if (line == "-------------------------") continue; // Skip separators
            rooms.push_back(parseRoom(line));
        }
        file.close();
    } else {
        cerr << "Unable to open file: " << filename << endl;
    }

    return rooms;
}

int binarySearchVacantRooms(const vector<Room>& rooms) {
    int low = 0;
    int high = rooms.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (rooms[mid].status == RoomStatus::Vacant) {
            return mid; // Found a vacant room
        } else if (rooms[mid].status == RoomStatus::Occupied) {
            // Search in the left half
            high = mid - 1;
        } else {
            // Search in the right half
            low = mid + 1;
        }
    }

    return -1; // No vacant room found
}


string roomStatusToString(RoomStatus status) {
    return (status == RoomStatus::Vacant) ? "Vacant" : "Occupied";
}

string cleanlinessToString(Cleanliness cleanliness) {
    return (cleanliness == Cleanliness::Clean) ? "Clean" : "Dirty";
}

string bedTypeToString(BedType bedType) {
    return (bedType == BedType::Single) ? "Single" : "Double";
}

bool isRoomVacant(const Room& room) {
    return room.status == RoomStatus::Vacant;
}



// sort the string vector based on price of rooms
void sortRoomInfoVectorBasedOnPrice(vector<string>& roomInfoVector) {

    sort(roomInfoVector.begin(), roomInfoVector.end(), [](const string& roomInfo1, const string& roomInfo2) {
        istringstream iss1(roomInfo1);
        istringstream iss2(roomInfo2);

        string price1, price2;
        getline(iss1, price1);
        getline(iss2, price2);

        // Skip "Price: $" and "\n"
        price1 = price1.substr(8, price1.size() - 9);
        price2 = price2.substr(8, price2.size() - 9);

        return stod(price1) < stod(price2);
    });
}

// apply binary search on the sorted vector to find vacant room
int binarySearchAvailableRooms(const vector<string>& roomInfoVector, const string& targetRoomStatus) {
    int low = 0;
    int high = roomInfoVector.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        istringstream iss(roomInfoVector[mid]);
        string status;
        getline(iss, status);
        getline(iss, status);

        // Skip "Status: " and "\n"
        status = status.substr(8, status.size() - 9);

        if (status == targetRoomStatus) {
            return mid;  // Found a vacant room
        } else if (status < targetRoomStatus) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;  // No available room found
}

// read content of file line by line and store in vector
void readRoomInformationFromFile(const string& fileName, vector<string>& roomInfoVector) {
    ifstream inputFile(fileName);

    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            roomInfoVector.push_back(line);
        }
        inputFile.close();
        cout << "Room information read from file: " << fileName << "\n";
    } else {
        cerr << "Unable to open file: " << fileName << "\n";
    }
}

void readRoomInformationFromFiles(const string& fileName, vector<string>& roomInfoVector, int linesPerRoom) {
    ifstream inputFile(fileName);

    if (inputFile.is_open()) {
        string line;
        string roomInfo;
        int linesRead = 0;

        while (getline(inputFile, line)) {
            // append every line to roomInfo until the required number of lines for a room has been read
            roomInfo += line+" " ;
            linesRead++;
            // Check if the required number of lines for a room has been read
            if (linesRead == linesPerRoom) {
                // Add the complete room information to the vector
                roomInfoVector.push_back(roomInfo);

                // Reset for the next room
                roomInfo.clear();
                linesRead = 0;
            }
        }

        inputFile.close();
        cout << "Room information read from file: " << fileName << "\n";
    } else {
        cerr << "Unable to open file: " << fileName << "\n";
    }
}

// apply binary search on the sorted vector to find vacant room by room number
int binarySearchAvailableRooms(const vector<string>& roomInfoVector, int targetRoomNumber) {
    int low = 0;
    int high = roomInfoVector.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        istringstream iss(roomInfoVector[mid]);
        string roomNumber;
        getline(iss, roomNumber);

        // Skip "Room " and ":\n"
        roomNumber = roomNumber.substr(5, roomNumber.size() - 7);

        if (stoi(roomNumber) == targetRoomNumber) {
            return mid;  // Found a vacant room
        } else if (stoi(roomNumber) < targetRoomNumber) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;  // No available room found
}


void merge(vector<Room>& rooms, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<Room> left_half(n1);
    vector<Room> right_half(n2);

    for (int i = 0; i < n1; i++)
        left_half[i] = rooms[left + i];
    for (int j = 0; j < n2; j++)
        right_half[j] = rooms[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (left_half[i].price < right_half[j].price) {
            rooms[k] = left_half[i];
            i++;
        } else {
            rooms[k] = right_half[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        rooms[k] = left_half[i];
        i++;
        k++;
    }

    while (j < n2) {
        rooms[k] = right_half[j];
        j++;
        k++;
    }
}

void mergeSort(vector<Room>& rooms, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(rooms, left, mid);
        mergeSort(rooms, mid + 1, right);

        merge(rooms, left, mid, right);
    }
}

void bubbleSort(vector<Room>& rooms) {
    int n = rooms.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (rooms[j].price > rooms[j + 1].price) {
                // Swap if the current room has a higher price than the next room
                swap(rooms[j], rooms[j + 1]);
            }
        }
    }
}

void bubbleSortCustomer(vector<Customer>& customers) {
    int n = customers.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (customers[j].idNumber > customers[j + 1].idNumber) {
                // Swap if the current room has a higher price than the next room
                swap(customers[j], customers[j + 1]);
            }
        }
    }
}

int binarySearchVacantRoom(const vector<Room>& rooms, int left, int right, int targetPrice) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (rooms[mid].status == RoomStatus::Vacant && rooms[mid].price == targetPrice) {
            return mid; // Found a vacant room
        } else if (rooms[mid].status == RoomStatus::Occupied || rooms[mid].price > targetPrice) {
            
            right = mid - 1;
        } else {
            
            left = mid + 1;
        }
    }

    return -1; // No vacant room found
}

void readCustomerData(vector<Customer>& customers, istringstream& iss) {
    Customer customer;
    iss >> customer.idType >> customer.idNumber >> customer.name >> customer.gender >> customer.country
        >> customer.roomNumber >> customer.checkInDateTime >> customer.stayingDays >> customer.totalAmount
        >> customer.initialPayment >> customer.pendingAmount >> customer.deposit;

    customersinfo.push_back(customer);
}

int linearSearchCustomer(const vector<Customer>& customers, int CustomerID) {
    for (int i = 0; i < customers.size(); i++) {
        if (customers[i].idNumber== CustomerID) {
            return i;
        }
    }

    return -1;
}

int binarySearchroom(const vector<Customer>& customers, int targetRoomNumber) {
    int low = 0;
    int high = customers.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (customers[mid].roomNumber == targetRoomNumber) {
            return mid;  
        } else if (customers[mid].roomNumber < targetRoomNumber) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;  
}

void customerSearch(const vector<Customer>& customers) {
    int CustomerID;
    cout << "Enter Customer ID: ";
    cin >> CustomerID;

    int result = linearSearchCustomer(customers, CustomerID);

    if (result != -1) {
        cout << "Customer found.\n";
        displayCustomerDetails(customers[result]);
        receptionControlPanel();
    } else {
        cout << "Customer not found.\n";
        receptionControlPanel();
    }
}

void roomSearch(const vector<Customer>& customers) {
    int targetRoomNumber;
    cout << "Enter Room Number: ";
    cin >> targetRoomNumber;

    int result = binarySearchroom(customers, targetRoomNumber);

    if (result != -1) {
        cout << "Customer found.\n";
        displayCustomerDetails(customers[result]);
        receptionControlPanel();
    } else {
        cout << "Customer not found.\n";
        receptionControlPanel();
    }
}

void displayRoomDetails (const Room& room) {
    cout << "Room " << room.roomNumber << ":\n";
    cout << "Status: " << ((room.status == RoomStatus::Vacant) ? "Vacant" : "Occupied") << "\n";
    cout << "Price: $" << room.price << "\n";
    cout << "Cleanliness: " << ((room.cleanliness == Cleanliness::Clean) ? "Clean" : "Dirty") << "\n";
    cout << "Bed Type: " << ((room.bedType == BedType::Single) ? "Single" : "Double") << "\n";
    cout << "Discount Percentage: " << room.discountPercentage << "%\n";
    
}

void updateRoomStatus(vector<Room>& rooms, int roomNumber, int low, int high) {

    // cout << "Enter room number: ";
    // cin >> roomNumber;

    if (low <= high) {
        int mid = low + (high - low) / 2;

        if (rooms[mid].roomNumber == roomNumber) {
            cout << "Room " << roomNumber << " found.\n";

            int choice;
            cout << "Enter new room status (0 = Vacant, 1 = Occupied): ";
            cin >> choice;
            if (choice) {
                rooms[mid].status = RoomStatus::Occupied;
            } else {
                rooms[mid].status = RoomStatus::Vacant;
            }

            cout << "Room status updated successfully.\n" << ((rooms[mid].status == RoomStatus::Vacant) ? "Vacant" : "Occupied") << "\n";
        }

        if (rooms[mid].roomNumber > roomNumber) {
            return updateRoomStatus(rooms, roomNumber, low, mid - 1);
        }

        return updateRoomStatus(rooms, roomNumber, mid + 1, high);
    }

    receptionControlPanel();
}

void updateCustomerInformation(vector<Customer>& customers, int customerID, int low, int high) {
    vector<int> customerIDs; // Declare the customerIDs vector

    if (low <= high) {
        int mid = low + (high - low) / 2;

        if (customers[mid].idNumber == customerID) {
            cout << "Customer " << customerID << " found.\n";
            cout << "Enter new customer information:\n";

            cout << "ID Type (passport, IC, etc.): ";
            cin >> customers[mid].idType;

            cout << "ID Number: ";
            cin >> customers[mid].idNumber;

            cout << "Name: ";
            //cin.ignore(); // Clear the newline character from the buffer
            //getline(cin, name);
            cin >> customers[mid].name;

            cout << "Gender: ";
            cin >> customers[mid].gender;

            cout << "Country: ";
            cin >> customers[mid].country;

            cout << "Allocated Room Number: ";
            cin >> customers[mid].roomNumber;

            cout << "Check-in Date and Time: ";
            //cin.ignore(); // Clear the newline character from the buffer
            auto currentTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
            string checkinDateandTime = ctime(&currentTime);
            cout << checkinDateandTime;

            cout << "Number of Staying Days: ";
            cin >> customers[mid].stayingDays;

            cout << "Total Amount: ";
            cin >> customers[mid].totalAmount;

            cout << "Initial Payment: ";
            cin >> customers[mid].initialPayment;

            // Calculate pending amount and deposit
            customers[mid].pendingAmount = customers[mid].totalAmount - customers[mid].initialPayment;

            cout << "Deposit: ";
            cin >> customers[mid].deposit;

            // Display the new customer information
            cout << "\nNew Customer Information:\n";
            cout << "ID Type: " << customers[mid].idType << "\n";
            cout << "ID Number: " << customers[mid].idNumber << "\n";
            cout << "Name: " << customers[mid].name << "\n";
            cout << "Gender: " << customers[mid].gender << "\n";
            cout << "Country: " << customers[mid].country << "\n";
            cout << "Allocated Room Number: " << customers[mid].roomNumber << "\n";
            cout << "Check-in Date and Time: " << checkinDateandTime;
            cout << "Number of Staying Days: " << customers[mid].stayingDays << "\n";
            cout << "Total Amount: " << customers[mid].totalAmount << "\n";
            cout << "Initial Payment: " << customers[mid].initialPayment << "\n";
            cout << "Pending Amount: " << customers[mid].pendingAmount << "\n";
            cout << "Deposit: " << customers[mid].deposit << "\n";
        }

        if (customerIDs[mid] > customerID) {
            return updateCustomerInformation(customers, customerID, low, mid - 1);
        }

        return updateCustomerInformation(customers, customerID, mid + 1, high);
    }

    receptionControlPanel();
}

void showMinMaxPrice(vector<Room>& rooms, int low, int high) {
    int minPrice = 999999;
    int maxPrice = -1;

    int minIndex, maxIndex;

    for (int i = low; i <= high; i++) {
        // Room is available
        if (rooms[i].price < minPrice) {
            minPrice = rooms[i].price;
            minIndex = i;
        }

        if (rooms[i].price > maxPrice) {
            maxPrice = rooms[i].price;
            maxIndex = i;
        }
    }

        std::cout << "Min price: " << minPrice << " (Room " << minIndex << ")" << std::endl;
        std::cout << "Max price: " << maxPrice << " (Room " << maxIndex << ")" << std::endl;

        receptionControlPanel();
}

void deleteCustomer(vector<Customer>& customers, int customerID, int low, int high) {
    if (low <= high) {
        int mid = low + (high - low) / 2;

        if (customers[mid].idNumber == customerID) {
            cout << "Customer " << customerID << " found.\n";
            cout << "Deleting customer information...\n";
            customers.erase(customers.begin() + mid); // Delete customer at index mid
            cout << "Customer information deleted successfully.\n";
            receptionControlPanel();
        }

        if (customers[mid].idNumber > customerID) {
            deleteCustomer(customers, customerID, low, mid - 1);
        } else {
            deleteCustomer(customers, customerID, mid + 1, high);
        }
    } else {
        cout << "Customer with ID " << customerID << " not found.\n";
    }

    // Reception control panel after all operations are done
    receptionControlPanel();
}


void checkoutForm(vector<Customer>& customers, int customerID, int low, int high) {
    // cout << "Enter Customer ID: ";
    // cin >> customerID;

    if (low <= high) {
        int mid = low + (high - low) / 2;

        if (customers[mid].idNumber == customerID) {
            cout << "Customer " << customerID << " found.\n";
            cout << "Checking out customer...\n";
            customers.erase(customers.begin() + mid);
            cout << "Customer checked out successfully.\n";
        }

        if (customers[mid].idNumber > customerID) {
            return checkoutForm(customers, customerID, low, mid - 1);
        }

        return checkoutForm(customers, customerID, mid + 1, high);
    }

    rooms[customerID].status = RoomStatus::Vacant;
    rooms[customerID].cleanliness = Cleanliness::Clean;

    receptionControlPanel();
}

void selectionSortRooms(vector<Customer>& customers) {
    for (size_t i = 0; i < customers.size(); ++i) {
        for (size_t j = i + 1; j < customers.size(); ++j) {
            if (customers[j].pendingAmount < customers[i].pendingAmount) {
                swap(customers[i], customers[j]);
            }
        }
    }
}

void showInvoice(vector<Customer>& customers, int customerID) {
    cout << "Invoice for Customer ID: " << customerID << "\n";

    vector<int> bookedRooms; // To store room numbers booked by the customer

    for (const Customer& customer : customers) {
        if (customer.idNumber == customerID) {
            cout << "Name: " << customer.name << "\n";
            cout << "Allocated Room Number: " << customer.roomNumber << "\n";
            cout << "Check-in Date and Time: " << customer.checkInDateTime << "\n";
            cout << "Initial Payment: " << customer.initialPayment << "\n";
            cout << "Pending Amount: " << customer.pendingAmount << "\n";
            cout << "Deposit: " << customer.deposit << "\n";

            bookedRooms.push_back(customer.roomNumber); // Store booked room numbers
        }
    }

    // Check if the customer booked multiple rooms
    if (bookedRooms.size() > 1) {
        // Sorting booked room numbers by price
        cout << "Allocated Room Numbers (sorted by price):\n";
        selectionSortRooms(customers);

        for (const Customer& customer : customers) {
            if (customer.idNumber == customerID) {
                cout << "Room Number: " << customer.roomNumber << ", Price: " << customer.pendingAmount << "\n";
            }
        }

        int totalAmount = 0;
        
        for (const Customer& customer : customers) {
            if (customer.idNumber == customerID) {
                cout << "Total Amount: " << customer.totalAmount << "\n";
                totalAmount += customer.totalAmount;
            }

            if (customer.pendingAmount > 0) {
                cout << "Pay: " << endl;
                int payment;
                cin >> payment;
                totalAmount -= payment;
                cout << "Paid: " << payment << endl;
            }
        }
    }

    

    cout << "End of invoice.\n";

    deleteCustomer(customers, customerID, 0, customers.size() - 1);

    receptionControlPanel();

}

// display the room information in the vector
void displayRoomInformation(const vector<Room>& rooms)   {
    for (const auto& roomInfo : rooms) {
        cout << "Room " << roomInfo.roomNumber << ":\n";
        cout << "Status: " << ((roomInfo.status == RoomStatus::Vacant) ? "Vacant" : "Occupied") << "\n";
        cout << "Price: $" << roomInfo.price << "\n";
        cout << "Cleanliness: " << ((roomInfo.cleanliness == Cleanliness::Clean) ? "Clean" : "Dirty") << "\n";
        cout << "Bed Type: " << ((roomInfo.bedType == BedType::Single) ? "Single" : "Double") << "\n";
        cout << "Discount Percentage: " << roomInfo.discountPercentage << "%\n";
        cout << "-------------------------\n";
    }
    receptionControlPanel();
}

// display the customer information in the vector
void displayCustomerInfo(const vector<Customer>& customers){
    for(const auto& customer : customers){
        cout << "ID Type: " << customer.idType << "\n";
        cout << "ID Number: " << customer.idNumber << "\n";
        cout << "Name: " << customer.name << "\n";
        cout << "Gender: " << customer.gender << "\n";
        cout << "Country: " << customer.country << "\n";
        cout << "Room Number: " << customer.roomNumber << "\n";
        cout << "Check-in Date and Time: " << customer.checkInDateTime << "\n";
        cout << "Staying Days: " << customer.stayingDays << "\n";
        cout << "Total Amount: " << customer.totalAmount << "\n";
        cout << "Initial Payment: " << customer.initialPayment << "\n";
        cout << "Pending Amount: " << customer.pendingAmount << "\n";
        cout << "Deposit: " << customer.deposit << "\n";
        cout << "-------------------------\n";

    }
    receptionControlPanel();
}
