//
//  robot.cpp
//  Coursework
//
//  Created by O.F Adewumi on 14/12/2020.
//

#include "robot.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//Initialize robot info
robot::robot(const int &r_number, const int &t_number, int &x_position, int &y_position)
    : r(r_number), t(t_number), x_pos(x_position), y_pos(y_position),travelled(0), direct(1) {}


//Validate move
bool validateMove(vector<robot> &robots, const int &x,const  int &y, const int &z){
    auto p = robots.begin();
    while (p != robots.end()){
        if ((*p).x_position() == x && (*p).y_position() == y && (*p).t_number() == z){
            return false;
        }else if((*p).x_position() == x && (*p).y_position() == y && (*p).t_number() != z){
//            cout<< "this robot is deleted, r number " << (*p).r_number() <<endl;
            p = robots.erase(p);
            return true;
            break;
        }else{
            p++;
        }
    }
    return true;
}

//Compare robots distace
bool compare_distance(robot& x, robot& y) {
    auto compare = x._travelled() < y._travelled();
    return compare;
}

//Compare robots numbers
bool compare_robot_number(robot& x, robot& y) {
    auto compare = x.r_number() < y.r_number();
    return compare;
}

//Show function
//Write the name, team, x-pos & y-pos of the robots
//Arrange vector in ascending order of robots
void show(std::vector<robot> &robots){
    sort(robots.begin(), robots.end(), compare_robot_number);
    for (robot &s : robots) {
        cout << s.r_number()<< " " << s.t_number() << " " << s.x_position()<< " " << s.y_position()<< " " << endl;
    }
}


//Move function
//Changes robots x or y pos by a factor of +/- 1 depending on the direction its facing (moves robot forward by +1)
void move(vector<robot> &robots, string &r){
    for (robot &s : robots) {
        if (s.r_number() == stoi(r) && s._direction() == 1 && (validateMove(robots,s.x_position(), s.y_position()+1, s.t_number()) == true)) {
            //change postion
            s.y_position() += 1;
            //increased travelled distance
            s._travelled() += 1;
            
        }else if (s.r_number() == stoi(r) && s._direction() == 2 && (validateMove(robots,s.x_position()+1, s.y_position(), s.t_number()) == true)) {
            // change postion
            s.x_position() += 1;
            //increased travelled distance
            s._travelled() += 1;
        }else if (s.r_number() == stoi(r) && s._direction() == 4 && (validateMove(robots,s.x_position()-1, s.y_position(), s.t_number()) == true)) {
            // change postion
            s.x_position() -= 1;
            //increased travelled distance
            s._travelled() += 1;
        }else if (s.r_number() == stoi(r) && s._direction() == 3 && (validateMove(robots,s.x_position(), s.y_position()-1, s.t_number()) == true)) {
            // change postion
            s.y_position() -= 1;
            //increased travelled distance
            s._travelled() += 1;
        }
    }
}


//Turn left function
//Changes the direction of the robot west of where the robot is currently facing
void turn_left(vector<robot> &robots, string &r){
    for (robot &s : robots) {
        //if direction is 1 (north) and we need to turn left change to 4 (west)
        if (s.r_number()== stoi(r) && s._direction() == 1) {
            //change direction to west
            s._direction() = 4;
        }else if (s.r_number()== stoi(r)) {
            // change direction to west of current direction
            s._direction() -= 1;
        }
    }
}

//Turn right function
//Changes the direction of the robot east of where the robot is currently facing
void turn_right(vector<robot> &robots, string &r){
    for (robot &s : robots) {
        //if direction is 4 (west) and we need to turn right go back to 1 (north)
        if (s.r_number()== stoi(r) && s._direction() == 4) {
            //change direction to north
            s._direction() = 1;
        }else if (s.r_number()== stoi(r)){
            //change direction to east of current direction
            s._direction() +=  1;
        }
    }
}

//Travelled function
//Order in increasing order of distance travelled
//Returns robot number & distance travelled
void travelled(vector<robot> &robots){
    sort(robots.begin(), robots.end(), compare_distance);
    for (robot &s : robots) {
        cout<< s.r_number() <<" "<< s._travelled()<< endl;
    }
}

//Within function
//Returns number of robots that are less than r distance away from the origin (0,0)
void within(vector<robot> &robots, string &r){
    int count = 0;
    for (robot &s : robots) {
        auto x = s.x_position();
        auto y = s.y_position();
        auto sumD = abs(x) + abs(y);    //  abs() convers negative int to postive int
        if (sumD <= stoi(r)) {         //   stoi() convers string to int
            count = count+ 1;
        }
    }
    cout<< count<< endl;
}
