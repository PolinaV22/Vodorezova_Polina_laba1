#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Structure for the pipe
struct Pipe {
    string name{ "." }; // Pipe name (kilometer mark)
    int length{ 0 }; // Pipe length
    int diameter{ 0 }; // Pipe diameter
    bool isUnderRepair{ false };// "under repair" sign
};

// Function for reading pipe data
Pipe readPipe(Pipe& p) {
    cout << "Enter pipe name (km mark): ";
    cin >> ws;
    getline(cin, p.name);

    while (true) {
        cout << "Enter length (in km): ";
        cin >> p.length;
        if (cin.good() && p.length > 0 && cin.peek() == '\n') {
            break;
        }
        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer that is positive and greater than zero. " << endl;
        }
    }
    while (true) {
        cout << "Enter diameter (in m): ";
        cin >> p.diameter;
        if (cin.good() && p.diameter > 0 && cin.peek() == '\n') {
            break;
        }
        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer that is positive and greater than zero. " << endl;
        }
    }
    return p;
}

// Function to output pipe data
void display(Pipe& p) {
    if (p.name == "." || p.length <= 0 || p.diameter <= 0) {
        cout << "There is no pipe. Perhaps you entered the pipe data incorrectly or did not add it. Try again." << endl;
    }
    else {
        cout << "Pipe:" << p.name << ", Length: " << p.length << ", Diameter: " << p.diameter << ", Under repair: " << (p.isUnderRepair ? "Yes" : "No") << endl;
    }
}

// Function for editing the "under repair" state
void editRepairStatus(Pipe& p) {
    if (p.name == "." || p.length <= 0 || p.diameter <= 0) {
        cout << "There is no pipe, so this option does not work. Please enter the pipe details." << endl;
    }
    else {
        p.isUnderRepair = !p.isUnderRepair;// Changes the state to the opposite
        cout << "workshop condition" << endl;
        cout << (p.isUnderRepair ? "Yes" : "No") << endl;
    }
}

// Function to save data to file
void saveToFilepip(ofstream& file, Pipe& p) {
    file << p.name << endl;
    file << p.length << endl;
    file << p.diameter << endl;
    file << p.isUnderRepair << endl;
}

//Function for loading data from file
void loadFromFilepip(ifstream& file, Pipe& p) {
    file >> p.name;
    file >> p.length;
    file >> p.diameter;
    file >> p.isUnderRepair;
}



// Structure for compressor station
struct CompressorStation {
    string name{ "." }; // Station name
    int workshopCount{ 0 }; // Total number of workshops
    int workshopsInOperation{ 0 }; // Number of workshops in operation
    int efficiency{ 0 }; // Efficiency
};

// Function for reading CS data
CompressorStation readst(CompressorStation& st) {
    cout << "Enter compressor station name: ";
    cin >> ws;
    getline(cin, st.name);

    while (true) {
        cout << "Enter number of workshops: ";
        cin >> st.workshopCount;
        if (cin.good() && st.workshopCount > 0 && cin.peek() == '\n') {
            break;
        }
        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer that is positive and greater than zero. " << endl;
        }
    }
    while (true) {
        cout << "Enter number of workshops in operation: ";
        cin >> st.workshopsInOperation;
        if (cin.good() && st.workshopsInOperation > 0 && st.workshopsInOperation <= st.workshopCount && cin.peek() == '\n') {
            break;
        }
        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer that is positive and greater than zero. " << endl;
        }
    }
    while (true) {
        cout << "Enter efficiency: ";
        cin >> st.efficiency;
        if (cin.good() && st.efficiency > 0 && cin.peek() == '\n') {
            break;
        }
        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer that is positive and greater than zero. " << endl;
        }
    }
    return st;
}

// Function for outputting CS data
void displayst(CompressorStation& st) {
    if (st.name == "." || st.workshopCount <= 0 || st.workshopsInOperation <= 0 || st.efficiency <= 0) {
        cout << "There is no compressor station. Perhaps you entered the data incorrectly or did not make it. Try again." << endl;
    }
    else {
        cout << "Compressor Station:" << st.name << ", Workshops: " << st.workshopCount << ", In operation: " << st.workshopsInOperation << ", Efficiency: " << st.efficiency << endl;
    }
}

// Function for changing the state of the workshop
void toggleWorkshopStatus(CompressorStation& st) {
    int choice;
    if (st.name == "." || st.workshopCount <= 0 || st.workshopsInOperation <= 0 || st.efficiency <= 0) {
        cout << "There is no compressor station. Perhaps you entered the data incorrectly or did not make it. Try again." << endl;
    }
    else {
        cout << "1. launch a new workshop" << endl;
        cout << "2. Stop the workshop" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            if (st.workshopsInOperation < st.workshopCount) {
                st.workshopsInOperation++;
                cout << "Launched a new workshop. Now in operation " << st.workshopsInOperation << " workshop(s)." << endl;
            }
            else {
                cout << "All workshops are already running." << endl;
            }
            break;
        case 2:
            if (st.workshopsInOperation > 0) {
                st.workshopsInOperation--;
                cout << "One workshop was stopped. Now " << st.workshopsInOperation << " workshop(s) are in operation." << endl;
            }
            else {
                cout << "All workshops are already installed." << endl;
            }
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
            break;
        }
    }
}

// Function to save data to file
void saveToFilest(ofstream& file, CompressorStation& st) {
    file << st.name << endl;
    file << st.workshopCount << endl;
    file << st.workshopsInOperation << endl;
    file << st.efficiency << endl;
}

//Function for loading data from file
void loadFromFilest(ifstream& file, CompressorStation& st) {
    file >> st.name;
    file >> st.workshopCount;
    file >> st.workshopsInOperation;
    file >> st.efficiency;
}



// Function to save data to file
void saveToFile(Pipe& pipe, CompressorStation& station) {
    ofstream file("data.txt");
    if (file.is_open()) {
        saveToFilepip(file, pipe);
        saveToFilest(file, station);
        cout << "Data saved." << endl;
    }
    else {
        cout << "Unable to open file for saving." << endl;
    }
    file.close();
}

//Function for loading data from file
void loadFromFile(Pipe& pipe, CompressorStation& station)
{
    ifstream file("data.txt");
    if (file.is_open()) {
        loadFromFilepip(file, pipe);
        loadFromFilest(file, station);
        cout << "Data loaded." << endl;
    }
    else {
        cout << "Unable to open file for loading." << endl;
    }
    file.close();
}

// Main function
int main() {
    Pipe pipe;
    CompressorStation station;
    int choice; // Variable for selecting an action

    while (true) {
        cout << "Menu: " << endl;
        cout << "1. Add Pipe" << endl;
        cout << "2. Add Compressor Station" << endl;
        cout << "3. View all objects" << endl;
        cout << "4. Edit Pipe" << endl;
        cout << "5. Edit Compressor Station" << endl;
        cout << "6. Save" << endl;
        cout << "7. Load" << endl;
        cout << "0. Exit" << endl;
        cin >> choice;
        if (cin.fail() || choice < 0 || choice > 7 || cin.peek() != '\n') {
            cout << "Invalid input. Please enter an integer. " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
        case 1: {
            readPipe(pipe); // Reading data
            break;
        }
        case 2: {
            readst(station); // Reading data
            break;
        }
        case 3: {
            display(pipe); // Output data
            displayst(station); // Output data
            break;
        }
        case 4: {
            editRepairStatus(pipe); // Editing status
            break;
        }
        case 5: {
            toggleWorkshopStatus(station); // Change of workshop state
            break;
        }
        case 6: {
            saveToFile(pipe, station);// Saving data
            break;
        }
        case 7: {
            loadFromFile(pipe, station);// Loading data
            break;
        }
        case 0: {
            return 0; // Exit the program
        }
        default: {
            cout << "Invalid choice!. Try again." << endl; // Incorrect choice
        }
               return 0;
        }
    }
}