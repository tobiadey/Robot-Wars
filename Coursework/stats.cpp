//
//  stats.cpp
//  Coursework
//
//  Created by O.F Adewumi on 14/12/2020.
//

#include "stats.hpp"
#include "robot.hpp"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

// Split a string (seperated by space)
// returns a vector of strings
vector<string> split_csv(const string &s) {
    vector<string> v;

    auto space = find(s.cbegin(), s.cend(), ' ');
    v.push_back(string(s.cbegin(), space));
    
    while (space != s.cend()) {
        auto start = ++space;
        space = find(start, s.cend(), ' ');
        v.push_back(string(start, space));
    }
    
    return v;
}




// read file function
// read and store robot data into robot class
void read_function(string file_name, vector<robot> &robots) {
    ifstream infile;
    infile.open(file_name);

    if(infile.fail()){
        cout << "File not found"<<endl;
    }else{
        int r,t,x_pos,y_pos;
        while (infile >> r >> t >> x_pos >> y_pos) {
            robots.push_back(robot(r,t,x_pos,y_pos));
        }
        infile.close();
        infile.clear();
    }
}

// read function
// read commands data and calls a function/method
void read_commands(string file_name, vector<robot> &robots) {
    ifstream infile;
    infile.open(file_name);

    if(infile.fail()){
        cout << "File not found"<<endl;
    }else{
        string line;
        while (getline(infile,line)){
            
            auto v = split_csv(line);
            // command type
            auto cmd = v[0];
            //adjacent number
            auto r = v[1];

            if(cmd == "show"){
                    show(robots);
            }else if(cmd == "within"){
                within(robots, r);
            }else if(cmd == "travelled"){
                travelled(robots);
            }else if(cmd == "turnleft"){
                turn_left(robots,r);
            }else if(cmd == "move"){
                move(robots,r);
            }else if(cmd == "turnright"){
                turn_right(robots,r);
            }
        }
        infile.close();
        infile.clear();
    }
}



