#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

// class to store journal entry
struct Journal {

    string title;
    vector<string> entries;

    Journal(const string& title) : title(title) { }

    void addEntry(const string& entry) {
        static int count = 1;
        entries.push_back(to_string(count++) + ": " + entry);
    }

    // this is a wrong way to save a file since this is a seperate concern
    // in addition to storing journal entries. (persistence)
    /*
    void save(const string& filename) {
        ofstream ofs(filename);
        for (auto& e : entries)
            ofs << e << endl;
        ofs.close();
    }
    */
};

// seperation of concerns is applied. Journal class stores entries only
struct PersistenceManager {
    static void save(const Journal& j, const string& filename) {
        ofstream ofs(filename);
        for (auto& e : j.entries)
            ofs << e << endl;
        ofs.close();
    }
};

int main() {

    Journal j("Dear Diary");
    j.addEntry("I ate a bug");
    j.addEntry("I cried today");

    PersistenceManager pm;
    pm.save(j, "journal.txt");

    return 0;
}

/*
A class should have a single responsibility.
*/