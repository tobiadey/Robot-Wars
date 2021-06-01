//
//  stats.hpp
//  Coursework
//
//  Created by O.F Adewumi on 14/12/2020.
//

#ifndef stats_hpp
#define stats_hpp

#include <vector>
#include "robot.hpp"

void read_function(std::string file_name, std::vector<robot> &robots);

void read_commands(std::string file_name, std::vector<robot> &robots);

void show(std::vector<robot> &robots);

void within(std::vector<robot> &robots, std::string &r);

void travelled(std::vector<robot> &robots);

void turn_right(std::vector<robot> &robots, std::string &r);

void turn_left(std::vector<robot> &robots,std::string &r);

void move(std::vector<robot> &robots,std::string &r);

bool validateMove(std::vector<robot> &robots, const int &x,const int &y, const int &z);


#endif /* stats_hpp */
