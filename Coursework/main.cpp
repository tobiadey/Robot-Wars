//
//  main.cpp
//  Coursework
//
//  Created by O.F Adewumi on 13/12/2020.
//

#include "robot.hpp"
#include "stats.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {
    vector<robot> robots;
    
    // reads into start.txt file
    string _file = "start.txt";
    read_function(_file,robots);
    

    // read into commands.txt file
    string _cmdfile = "commands.txt";
    read_commands(_cmdfile,robots);
    

    return 0;
}
