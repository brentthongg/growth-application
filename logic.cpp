// Imports
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include <sstream>
using namespace std;

void write_to_file(string file_name, string contents) {
    ofstream file_stream;
    file_stream.open(file_name, ios_base::app); // allows appending to end of file
    file_stream << contents << endl;
    file_stream.close();
}

int main() {
    bool done = false;
    string prompt_text;
    unsigned int count = 0; // can't have negative count!
    while (!done) {
        string goal;
        if (count > 0) prompt_text = "What else did you do today? ";
        else prompt_text = "What did you do today? ";
        cout << prompt_text << endl;
        getline(cin, goal);
        // Now goal has the string from get line.
        time_t current_time = time(0);
        string datetime = string(ctime(&current_time)); // type cast to char pointer
        string contents = "Time: " + datetime + " Goal accomplished: " + goal + ".";
        write_to_file("goals.txt", contents);
        count++;
        cout << "Anything else? Enter y/n: " << endl;
        string answer;
        getline(cin, answer);
        if (answer == "n") {
            string total;
            stringstream ss;
            ss << count;
            total = ss.str();
            string accomplishments = "accomplishment!";
            if (count > 1) accomplishments = "accomplishments!";
            cout << "Great job! You added " + total + " " + accomplishments << endl;
            done = true;
        } 
    }
    return 0;
}