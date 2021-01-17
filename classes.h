#pragma once
#include "Location.h"

//#include "tablica"

class Snake
{
 private:
	class Segment
    {
        protected:
            Location loc;
            Location direction;
            Color c;

        public:
            Location getLoc(){return loc;};
            Location get_dir(){return direction;};
            void set_dir(Location dir);
    };

    class Body : public Segment {
        public:
            void InitBody(Location in_loc, Location in_dir);
            void Follow(Segment next);
    };

    class Head : public Segment {
        public:
            void InitHead(Location loc);
            void set_dest (Location delta_dest);
            void go_to_dest();

        private:
            Location dest;
            
    };

public:
    Snake(Location loc, float spd, int FPS);

        //delta - przesunięcie węża
    void set_steps(float speed, int FPS);

    void step();
    void grow();

    int game_over(Board brd);
    void draw(Board* brd);

    float speed;




private:
    static constexpr Color headColor = Colors::Green;
    static constexpr Color bodyColor = Colors::Yellow;
    static constexpr int nSegmentsMax = 100; // zależy z ilu jednostek (elementów jest zbudowany) maksymalnie ma przyjmować wąż.
    
    Head head;
    Body segments[nSegmentsMax];
    int nSegments = 1;

    int steps, steps_i, step_threshold;
    
    void set_dest(Location d_loc);
    void move();

};

struct Board{
        int w,h,a;

        void draw_board();
        void draw_snake(Location* segments, int nSegments, float progress, Location* direction);
};

bool operator ==(Location a, Location b){
    return(a.x==b.x && a.y==b.y);
}   

bool operator !=(Location a, Location b){
    return !(a.x==b.x && a.y==b.y);
}  

Location operator +(Location a, Location b){
    a.x+=b.x;
    a.y+=b.y;

    return a;
}

Location operator * (Location a, int x){
    a.x*=x;
    a.y*=x;

    return a;
}

Location operator - (Location a, Location b){
    a.x-=b.x;
    a.y-=b.y;

    return a;
}
