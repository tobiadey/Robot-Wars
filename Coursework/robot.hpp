//
//  robot.hpp
//  Coursework
//
//  Created by O.F Adewumi on 14/12/2020.
//

#ifndef robot_hpp
#define robot_hpp

//record of a robots
class robot {
    
    int r; //Robot number
        
    int t; //Robot team
    
    int x_pos; //Robots x-position
    
    int y_pos; //Robots y-position
    
    int travelled; //Amount of moves made (call of move())
    
    int direct; //Robots direction
        
    public:
    //Initialize robot info
    robot( const int &r_number, const int &t_number, int &x_position, int &y_position);
        
    //The number of the robot
    const int &r_number() const { return r; }
    
    //The team of the robot
    const int &t_number() const { return t; }
    
    //The Xposition of the robbot
    int &x_position() { return x_pos; }
       
    //The Yposition of the robbot
    int &y_position() { return y_pos; }
    
    //The amount of moves taken by a robot
    int &_travelled() { return travelled; }
    
    //The direction robot is facing north=1 east=2 south=3 west=4
    int &_direction() { return direct;}
    
};

#endif /* robot_hpp */
