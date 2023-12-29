#include <iostream>
#include <algorithm>

using namespace std;

int num = 0;
int r = 0;
const int maxemp = 20;
const int maxroom = 20;
void adminControlPanel();
double CalculatePrice();
struct Employee {
    int ID;
    string Name;
    int age;
    char gender;
    string job;
    double salary;
    string phone;
    string address;
    string email;
};
Employee employees[maxemp];

struct Rooms {
    int RoomNumber;
    string status; // "available" or "occupied"
    string cleaningStatus; // "clean" or "dirty"
    double price;
    string bedType; // "single" or "double"
    double discountPercentage;
};
Rooms roomss[maxroom];

struct Booking {
    int date;
    double total;
    string name;
    int roomnum;
    int receipt;
    string bedtype;

};

Booking cus1={23122023,100,"Alex",123,rand() % 1000,"single"};
Booking cus2={23122023,400,"Ali",456,rand() % 1000,"single"};
Booking cus3={23102023,900,"Qwe",789,rand() % 1000,"double"};
Booking cus4={23082023,600,"Bryan",999,rand() % 1000,"single"};
Booking booking[] = {cus1, cus2, cus3, cus4};
int b = sizeof(booking) / sizeof(booking[0]);

bool compareByID(const Employee& a, const Employee& b) {
    return a.ID < b.ID;
}

double CalculatePrice(const Rooms& room) {
    return room.price - (room.price * room.discountPercentage / 100.0);
}

bool compareDate(const Booking& a, const Booking& b) {
    return a.date < b.date;
}


void AddEmployee(){
    cout << "\n\n****************************************************************\n";
    cout << "\t\t\tAdd Employee's Data";
    cout << "\n****************************************************************\n\n";

    if (num >= maxemp) {
        cout << "Employee list is full!" << endl;
        return;
    }

    Employee emp;
    cout << "\nEnter the ID of the employee: ";
    cin >> emp.ID;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

    cout << "Enter the name of the employee: ";
    getline(cin, emp.Name);

    cout << "Enter the age of the employee: ";
    cin >> emp.age;

    cout << "Enter the gender (M/F) of the employee: ";
    cin >> emp.gender;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

    cout << "Enter the job of the employee: ";
    getline(cin, emp.job);

    cout << "Enter the salary of the employee: ";
    cin >> emp.salary;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

    cout << "Enter the phone number of the employee: ";
    getline(cin, emp.phone);

    cout << "Enter the address of the employee: ";
    getline(cin, emp.address);

    cout << "Enter the email of the employee: ";
    getline(cin, emp.email);

    employees[num++] = emp;

    sort(employees, employees + num, compareByID);

    cout << "Employee added successfully!" << endl;

    char next ;
    cout << "Do you want to continue(Y for continue, N for Quit): ";//determine to continue or not
    cin >> next;
    if(next=='y'||next=='Y'){
        AddEmployee();
    }
    else{
        adminControlPanel();
    }

}

void AddRoom() {
    if (r >= maxroom) {
        cout << "Room list is full!" << endl;
        return;
    }

    Rooms room;
    cout << "\nEnter the room number: ";
    cin >> room.RoomNumber;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

    cout << "Enter status (available/occupied): ";
    getline(cin, room.status);

    cout << "Enter cleaning status (clean/dirty): ";
    getline(cin, room.cleaningStatus);

    cout << "Enter price: ";
    cin >> room.price;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

    cout << "Enter bed type (single/double): ";
    getline(cin, room.bedType);

    cout << "Enter discount percentage: ";
    cin >> room.discountPercentage;

    roomss[r++] = room;
    cout << "Room added successfully!" << endl;
    char next ;
    cout << "Do you want to continue(Y for continue, N for Quit): ";//determine to continue or not
    cin >> next;
    if(next=='y'||next=='Y'){
        AddRoom();
    }
    else{
        adminControlPanel();
    }
}

void EmployeeDetails(const Employee& emp) {
    cout << "Employee ID: " << emp.ID << endl;
    cout << "Name: " << emp.Name << endl;
    cout << "Age: " << emp.age << endl;
    cout << "Gender: " << emp.gender << endl;
    cout << "Job: " << emp.job << endl;
    cout << "Salary: " << emp.salary << endl;
    cout << "Phone: " << emp.phone << endl;
    cout << "Address: " << emp.address << endl;
    cout << "Email: " << emp.email << endl;
}

void RoomDetails(const Rooms& room) {
    cout << "\nRoom Number: " << room.RoomNumber << endl;
    cout << "Status: " << room.status << endl;  // "available" or "occupied"
    cout << "Cleaning Status: " << room.cleaningStatus << endl;  // "clean" or "dirty"
    cout << "Price: $" << room.price << endl;
    cout << "Bed Type: " << room.bedType << endl;  // "single" or "double"
    cout << "Discount Percentage: " << room.discountPercentage << "%" << endl;

     double DiscountPrice = CalculatePrice(room);
     cout << "Price after Discount: $" << DiscountPrice << endl;
}

int binarySearchEmployee(Employee employees[], int numElems, int target) {
    int low = 0;
    int high = numElems - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (employees[mid].ID == target) {
            return mid;
        } else if (employees[mid].ID < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // Not found
}

void SearchEmp(Employee employees[],int num){
    cout << "\n\n****************************************************************\n";
    cout << "\t\t\tSearching Employee's Data";
    cout << "\n****************************************************************\n\n";

    int s;
    cout << "Please Input ID of Employee you want to Search: " ;
    cin >> s;
    int found = binarySearchEmployee(employees,num,s);
    if(found != -1){
        cout << "Employee Found! " << endl;
        EmployeeDetails(employees[found]);
        char next ;
        cout << "Do you want to continue(Y for continue, N for Quit): ";//determine to continue or not
        cin >> next;
        if(next=='y'||next=='Y'){
            SearchEmp(employees, num);
        }
        else{
            adminControlPanel();
        }
    }
    else{
        cout << "Employee not Found!" << endl;
        char next ;
        cout << "Do you want to continue(Y for continue, N for Quit): ";//determine to continue or not
        cin >> next;
        if(next=='y'||next=='Y'){
            SearchEmp(employees, num);
        }
        else{
            adminControlPanel();
        }
    }
}

void EditEmp(Employee employees[],int num){
    cout << "\n\n****************************************************************\n";
    cout << "\t\t\tEdit Employee's Data";
    cout << "\n****************************************************************\n\n";

    int s;
    cout << "Please Input ID of Employee you want to Search: " ;
    cin >> s;
    int found = binarySearchEmployee(employees,num,s);
    if(found != -1){
        cout << "Employee Found! " << endl;
        Employee emp;
        cout << "\nEnter the ID of the employee: ";
        cin >> emp.ID;

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

        cout << "Enter the name of the employee: ";
        getline(cin, emp.Name);

        cout << "Enter the age of the employee: ";
        cin >> emp.age;

        cout << "Enter the gender (M/F) of the employee: ";
        cin >> emp.gender;

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

        cout << "Enter the job of the employee: ";
        getline(cin, emp.job);

        cout << "Enter the salary of the employee: ";
        cin >> emp.salary;

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

        cout << "Enter the phone number of the employee: ";
        getline(cin, emp.phone);

        cout << "Enter the address of the employee: ";
        getline(cin, emp.address);

        cout << "Enter the email of the employee: ";
        getline(cin, emp.email);

        employees[found] = emp;

        sort(employees, employees + num, compareByID);

        char next ;
        cout << "Do you want to continue(Y for continue, N for Quit): ";//determine to continue or not
        cin >> next;
        if(next=='y'||next=='Y'){
            SearchEmp(employees, num);
        }
        else{
            adminControlPanel();
        }
    }
    else{
        cout << "Employee not Found!" << endl;
        char next ;
        cout << "Do you want to continue(Y for continue, N for Quit): "; //determine to continue or not
        cin >> next;
        if(next=='y'||next=='Y'){
            SearchEmp(employees, num);
        }
        else{
            adminControlPanel();
        }
        adminControlPanel();
    }
}

void DeleteEmp() {
    cout << "\n\n****************************************************************\n";
    cout << "\t\t\tDelete Employee's Data";
    cout << "\n****************************************************************\n\n";

    int d;
    cout << "\nPlease Input ID of Employee you want to Delete: ";
    cin >> d;

    int foundIndex = -1;
    for (int i = 0; i < num; i++) {
        if (employees[i].ID == d) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        // Shift all elements after the found index to the left by one position
        for (int i = foundIndex; i < num - 1; i++) {
            employees[i] = employees[i + 1];
        }
        num--; // Decrease the count of employees
        cout << "Successfully Delete! " << endl;
        char next ;
        cout << "Do you want to continue(Y for continue, N for Quit): ";//determine to continue or not
        cin >> next;
        if(next=='y'||next=='Y'){
            DeleteEmp();
        }
        else{
            adminControlPanel();
        }
    }
    else {
        cout << "Employee not Found! " << endl;
        char next ;
        cout << "Do you want to continue(Y for continue, N for Quit): ";//determine to continue or not
        cin >> next;
        if(next=='y'||next=='Y'){
            DeleteEmp();
        }
        else{
            adminControlPanel();
        }
    }
}

int binarySearchRoom(Rooms room[], int numElems, int target) {
    int low = 0;
    int high = numElems - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (room[mid].RoomNumber == target) {
            return mid;
        } else if (room[mid].RoomNumber < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // Not found
}

void EditRoom(Rooms rooms[], int r){
    cout << "\n\n****************************************************************\n";
    cout << "\t\t\tEdit Room's Details";
    cout << "\n****************************************************************\n\n";

    int s;
    cout << "Please Input Room Number you want to Edit: " ;
    cin >> s;
    int found = binarySearchRoom(rooms,r,s);
    if(found != -1){
        cout << "Room Found! " << endl;
        Rooms room;
        cout << "\nEnter the room number: ";
        cin >> room.RoomNumber;

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

        cout << "Enter status (available/occupied): ";
        getline(cin, room.status);

        cout << "Enter cleaning status (clean/dirty): ";
        getline(cin, room.cleaningStatus);

        cout << "Enter price: ";
        cin >> room.price;

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

        cout << "Enter bed type (single/double): ";
        getline(cin, room.bedType);

        cout << "Enter discount percentage: ";
        cin >> room.discountPercentage;

        rooms[found] = room;
        cout << "Edit successfully!" << endl;
        char next ;
        cout << "Do you want to continue(Y for continue, N for Quit): ";//determine to continue or not
        cin >> next;
        if(next=='y'||next=='Y'){
            EditRoom(rooms, r);
        }
        else{
            adminControlPanel();
        }
    }
}

void Save(const Rooms rooms[], Rooms sorting[], int r) {
    for (int i = 0; i < r; ++i) {
        sorting[i] = rooms[i];
    }
}

void ShowUnsorted(const Rooms rooms[], int r) {
    cout << "\n\n****************************************************************\n";
    cout << "\t\t\tRoom Details(Unsorted)";
    cout << "\n****************************************************************\n\n";
    for (int i = 0; i < r; i++) {
        RoomDetails(rooms[i]);
    }
    adminControlPanel();
}

int partition(Rooms rooms[], int low, int high) {
    Rooms pivot = rooms[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (rooms[j].RoomNumber < pivot.RoomNumber) {
            i++;
            swap(rooms[i], rooms[j]);
        }
    }
    swap(rooms[i + 1], rooms[high]);
    return (i + 1);
}

void quickSort(Rooms rooms[], int low, int high) {
    if (low < high) {
        int p = partition(rooms, low, high);

        quickSort(rooms, low, p - 1);
        quickSort(rooms, p + 1, high);
    }
}

void SortRooms(Rooms rooms[], int r) {
    quickSort(rooms, 0, r - 1);
}

void ShowSorted(Rooms rooms[], int r) {
    cout << "\n\n****************************************************************\n";
    cout << "\t\t\tRoom Details(Sorted on Room Number)";
    cout << "\n****************************************************************\n\n";
    Rooms sorting[maxroom];
    Save(rooms, sorting, r);
    SortRooms(sorting, r);
    for (int i = 0; i < r; i++) {
        RoomDetails(sorting[i]);
    }
    adminControlPanel();
}



void BubbleSort(Rooms rooms[],int r) {
    bool swapped;
    for (int i = 0; i < r - 1; i++) {
        swapped = false;
        for (int j = 0; j < r - i - 1; j++) {
            if (CalculatePrice(rooms[j]) > CalculatePrice(rooms[j + 1])) {
                swap(rooms[j], rooms[j + 1]);
                swapped = true;
            }
        }
        // If no two elements were swapped in the inner loop, then break
        if (!swapped) {
            break;
        }
    }
}

void ShowPrice(Rooms rooms[], int r) {
    cout << "\n\n****************************************************************\n";
    cout << "\t\t\tRoom Details(Sorted on Room Number)";
    cout << "\n****************************************************************\n\n";

    Rooms sorting[maxroom];
    Save(rooms, sorting, r);
    BubbleSort(sorting, r);

    for (int i = 0; i < r; i++) {
        RoomDetails(sorting[i]);
    }
    adminControlPanel();
}

int binarySearchDate(Booking booking[], int numElems, int target) {
    int low = 0;
    int high = numElems - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (booking[mid].date == target) {
            return mid;
        } else if (booking[mid].date < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // Not found
}


//void bubbleSortDate(Booking booking[], int b) {
//    for (int i = 0; i < b - 1; i++) {
//        for (int j = 0; j < b - i - 1; j++) {
//            // This comparison works correctly for "DD-MM-YYYY" format
//            if (booking[j].date > booking[j + 1].date) {
//                // Swap bookings[j] and bookings[j + 1]
//                Booking temp = booking[j];
//                booking[j] = booking[j + 1];
//                booking[j + 1] = temp;
//            }
//        }
//    }
//}

void ShowBooking(Booking booking[], int b) {
    cout << "\n\n****************************************************************\n";
    cout << "\t\t\tSearching Customer Booking";
    cout << "\n****************************************************************\n\n";

    int d;

    cout << "Enter the date to search for bookings (DD-MM-YYYY): ";
    cin >> d;
    sort(booking, booking + b, compareDate);
    //bubbleSortDate(booking, b);
    int found = binarySearchDate(booking, b, d);
    if (found != -1) {
        double totalDayPrice = 0.0;
        // Display all bookings on the given date
        cout << "Bookings on " << d << ":" << endl;
        cout << "Booking Total Price: $" << booking[found].total << endl;
        cout << "Booking Customer Name: " << booking[found].name << endl;
        cout << "Booking Room Number: " << booking[found].roomnum << endl;
        cout << endl;
        totalDayPrice += booking[found].total;
        found++;
        cout << "Total Price for all bookings on " << d << ": $" << totalDayPrice << "\n";

        char next ;
        cout << "Do you want to continue(Y for continue, N for Quit): ";//determine to continue or not
        cin >> next;
        if(next=='y'||next=='Y'){
            ShowBooking(booking, b);
        }
        else{
            adminControlPanel();
        }

    } else {
        cout << "No bookings found on " << d << "\n";
        char next ;
        cout << "Do you want to continue(Y for continue, N for Quit): ";//determine to continue or not
        cin >> next;
        if(next=='y'||next=='Y'){
            ShowBooking(booking, b);
        }
        else{
            adminControlPanel();
        }
    }
}

void SelectionSort(Booking arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j].receipt < arr[min_idx].receipt)
                min_idx = j;

        swap(arr[min_idx], arr[i]);
    }
}

void Receipts() {
    SelectionSort(booking, b);

    for (int i = 0; i < b; i++) {
        cout << "\nReceipt Number: " << booking[i].receipt;
        cout << "\nDate: " << booking[i].date;
        cout << "\nRoom Number: " << booking[i].roomnum;
        cout << "\nRoom Type: " << booking[i].bedtype;
        cout << "\nTotal Amount: $" << booking[i].total << "\n";
    }
}


void adminControlPanel(){
      cout << "\n\n****************************************************************\n";
      cout << "\t\t\tAdmin Control Panel";
      cout << "\n****************************************************************\n\n";
      cout << "1.Add Employee" << endl;
      cout << "2.Add Room " << endl;
      cout << "3.Searching Employee " << endl;
    cout << "4.Modify Employee " << endl;
    cout << "5.Delete Employee " << endl;
    cout << "6.Modify Room " << endl;
    cout << "7.Show Room(Unsorted) " << endl;
    cout << "8.Show Room(Sorted on Room Number) " << endl;
    cout << "9.Show Room(Sorted on Price) " << endl;
    cout << "10.Booking Completed " << endl;
    cout << "11.Receipts " << endl;
    cout << "12.Quit " << endl;

    int choice;
    cout << "Please select a function: ";
    cin >> choice;

    switch (choice) {
        case 1:
            AddEmployee();
            break;
        case 2:
            AddRoom();
            break;
        case 3:
            SearchEmp(employees, num);
            break;
        case 4:
            EditEmp(employees, num);
            break;
        case 5:
            DeleteEmp();
            break;
        case 6:
            EditRoom(roomss, r);
            break;
        case 7:
            ShowUnsorted(roomss, r);
            break;
        case 8:
            ShowSorted(roomss, r);
            break;
        case 9:
            ShowPrice(roomss, r);
            break;
        case 10:
            ShowBooking(booking, b);
            break;
        case 11:
            Receipts();
            break;
        case 12:
            cout << "Exiting the system...\n";
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
    }
}

