#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>
using namespace std;

class Hash {
    vector<int> table;
    enum class STATUS : char {OPEN, FILLED};
    vector<STATUS> status;
    size_t count = 0;

public:
    Hash(size_t size) {
        table.resize(size, 0);
        status.resize(size, STATUS::OPEN);
    }
    void insert(size_t insertboi) {
        size_t bucket = insertboi % table.size();
        while (status[bucket] == STATUS::FILLED) bucket = (bucket + 1) % table.size();
        table[bucket] = insertboi;
        status[bucket] = STATUS::FILLED;
        count++;
    }

    bool search(size_t searchboi) {
        size_t bucket = searchboi % table.size();
        for (int i = 0; i < table.size(); i++) {
            if (i == searchboi && status[i] == STATUS::FILLED) return true;
            if (status[bucket] == STATUS::OPEN) return false;
            bucket = (bucket + 1) % table.size();
        }
        return true;
    }
    bool searchHash(size_t searchboi) {
        size_t bucket = searchboi % table.size();
        for (int i = 0; i < table.size(); i++) {
            if (table[bucket] == searchboi && status[bucket] == STATUS::FILLED) return true;
            if (status[bucket] == STATUS::OPEN) return false;
            bucket = (bucket + 1) % table.size();
        }
        return true;
    }

    void tableSize() {
        cout << table.size() << endl;
    }

    void displayStatus(size_t index) {
        search(index);
        if(search(index) == true) {
            cout << table.at(index) << endl;
        }
        else cout << "Empty" << endl;

    }

};

int main() {

    int input = 0, commands = 0;
    string user, results;

    cin >> input;

    Hash table(input);

    cin >> commands;

    for (int i = 0; i < commands; i++) {
        cin >> user;

        if (user[0] == 'i') {
            string temp;
            cin >> temp;
            int num = stoi(temp);
            table.insert(num);
            results += to_string(num);
        }

        else if (user[0] == 's') {
            string temp;
            cin >> temp;
            int num = stoi(temp);
            table.searchHash(num);
            if (table.searchHash(num) == true) {
                cout << num << " Found" << endl;
            }
            else cout << num << " Not Found" << endl;
        }

        else if (user == "displayStatus") {
            string temp;
            cin >> temp;
            int num = stoi(temp);
            table.displayStatus(num);
        }

        else if (user == "tableSize") {
            table.tableSize();
        }
    }




}
