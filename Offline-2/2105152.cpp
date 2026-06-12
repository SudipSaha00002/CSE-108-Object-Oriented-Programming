#include <iostream>
#include <cmath>
#include <sstream>
#include<fstream>

using namespace std;

#define GRIDSIZE 4
#define UP       0
#define DOWN     2
#define LEFT     3
#define RIGHT    1
#define MAX_SHOTS 3


// string to_string(int x)
// {
//     std::string out_string;
//     std::stringstream ss;
//     ss << x;
//     return ss.str();
// }


class Position
{

    int x, y;

public:

    Position (int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    Position() {}

    // Modify the following four so that the resulting position does not leave the grid
    void moveRight()
    {   
        if(x<GRIDSIZE-1){
        x++;
        }
    }

    void moveLeft()
    {   
        if(x>0){
        x--;
        }
    }

    void moveUp()
    {   
        if(y<GRIDSIZE-1){
        y++;
        }
    }

    void moveDown()
    {
        if(y>0){
        y--;
        }
    }

    bool isAdjacent(Position p)
    {
        //implement the function
        
        if((abs(this->getX()-p.getX())+abs(this->getY()-p.getY()))==1){
            return true;
        }
        else{
            return false;
        }

    }

    bool isSamePoint(Position p)
    {
        //implement the function
        return (this->getX()==p.getX() && this->getY()==p.getY());
    }

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }

};


class Wumpus
{

    bool killed;
    Position p;

public:

    Wumpus(int x, int y)
    {
        p = Position(x, y);
        killed = false;
    }

    Wumpus()
    {
        //...
        int x,y;
        x=rand()%4;
        y=rand()%4;
        p=Position(x,y);
        killed=false;
    }

    void kill()
    {
        killed = true;
        p=Position();
    }

    Position getPosition()
    {
        return p;
    }

};


class Player
{

    int direction;
    int total_shots;
    bool killed;
    Position p;

public:

    Player()
    {
        //...
        p=Position(0,0);
        total_shots=MAX_SHOTS;
        killed=false;
        direction=UP;
    }

    void turnLeft()
    {
        //...
        if(direction==UP){
            direction=LEFT;
        }
        else if(direction==LEFT){
            direction=DOWN;
        }
        else if(direction==DOWN){
            direction=RIGHT;
        } 
        else if(direction==RIGHT){
            direction=UP;
        }
    }

    void turnRight()
    {
        //...
         if(direction==UP){
            direction=RIGHT;
        }
        else if(direction==RIGHT){
            direction=DOWN;
        }
        else if(direction==DOWN){
            direction=LEFT;
        } 
        else if(direction==LEFT){
            direction=UP;
        }
    }

    void moveForward()
    {
        //...
        if(direction==UP){
            p.moveUp();
        }
        else if(direction==DOWN){
            p.moveDown();
        }
        else if(direction==LEFT){
            p.moveLeft();
        }
        else if(direction==RIGHT){
            p.moveRight();
        }
    }

    bool isAdjacent(Position pos)
    {
        return p.isAdjacent(pos);
    }

    bool isSamePoint(Position pos)
    {
        return p.isSamePoint(pos);
    }

    void kill()
    {
        killed = true;
    }

    string getPositionInfo()
    {
        return "Player is now at " + to_string(p.getX()) + ", " + to_string(p.getY());
    }

    string getDirectionInfo()
    {
        string s;
        if (direction == UP) s = "up";
        if (direction == DOWN) s = "down";
        if (direction == LEFT) s = "left";
        if (direction == RIGHT) s = "right";
        return "Player is moving at direction: " + s;
    }

};

class Pit{
    public:
    Position p;

    Pit(){
        int x=rand()%GRIDSIZE;
        int y=rand()%GRIDSIZE;
        p=Position(x,y);
    }
    Pit (int x,int y){
        p=Position(x,y);
    }
    Position getPosition(){
        return p;
    }

};

int arrow_count=0;

class WumpusWorld
{

private:

    Player player;
    Wumpus wumpus;
    Position gold_position;
    Pit pit;
    bool ended;

public:

    WumpusWorld()
    {
        //...
        wumpus=Wumpus();
        int gold_x=rand()%4;
        int gold_y=rand()%4;
        gold_position=Position(gold_x,gold_y);
        ended=false;

    }

    WumpusWorld(int wumpus_x, int wumpus_y)
    {
        //...
        wumpus=Wumpus(wumpus_x,wumpus_y);
        int gold_x=rand()%4;
        int gold_y=rand()%4;
        gold_position=Position(gold_x,gold_y);
        ended=false;

    }

    WumpusWorld(int wumpus_x, int wumpus_y, int gold_x, int gold_y)
    {
        //...
        wumpus=Wumpus(wumpus_x,wumpus_y);
        gold_position=Position(gold_x,gold_y);
        ended= false;
    }

    WumpusWorld(int wumpus_x, int wumpus_y, int gold_x, int gold_y, int pit_x, int pit_y)
    {
        //...
        wumpus=Wumpus(wumpus_x,wumpus_y);
        gold_position=Position(gold_x,gold_y);
        pit=Pit(pit_x,pit_y);
        ended= false;
    }

    void moveForward()
    {
        player.moveForward();
        return showGameState();
    }

    void turnLeft()
    {
        player.turnLeft();
        return showGameState();
    }

    void turnRight()
    {
        player.turnRight();
        return showGameState();
    }

    void shoot()
    {
        if(arrow_count==MAX_SHOTS){
            cout<<"no arrow !"<<endl;
            return;
        }
        arrow_count++;
        Player Sudip=player;
        int count ;
        for (count =0;count <GRIDSIZE;count++){    
        Sudip.moveForward();
        if(Sudip.isSamePoint(wumpus.getPosition())){
            cout<<"You killed the wumpus !"<<endl;
            wumpus.kill();
            break;
        }
        }
            cout<<"You missed"<<endl;
        }

        
    

    void showGameState()
    {
        cout << player.getPositionInfo() << endl;
        cout << player.getDirectionInfo() << endl;

        if (player.isAdjacent(wumpus.getPosition()))
        {
            cout << "stench!" << endl;
        }
        if (player.isAdjacent(pit.getPosition()))
        {
            cout << "breeze!" << endl;
        }
        if (player.isSamePoint(pit.getPosition()))
        {
            cout << "Player is killed!" << endl;
            player.kill();
            cout << "Game over!" << endl;
            ended = true;
        }

        if (player.isSamePoint(wumpus.getPosition()))
        {
            cout << "Player is killed!" << endl;
            player.kill();
            cout << "Game over!" << endl;
            ended = true;
        }

        if (player.isSamePoint(gold_position))
        {
            cout << "Got the gold!" << endl;
            cout << "Game ended, you won!" << endl;
            ended = true;
        }
    }

    bool isOver()
    {
        return ended;
    }

};


int main()
{
    int c, wumpus_x, wumpus_y, gold_x, gold_y, pit_x, pit_y;
    // take the six integers input from file
    ifstream input("input.txt");
    if(input.is_open()){
        input>>wumpus_x>>wumpus_y>> gold_x>> gold_y>>pit_x>> pit_y;
        input.close();
    }
    WumpusWorld w(wumpus_x, wumpus_y, gold_x, gold_y, pit_x, pit_y);
    w.showGameState();
    while (!w.isOver())
    {
        cout << "1: move forward" << endl;
        cout << "2: Turn left" << endl;
        cout << "3: Turn right" << endl;
        cout << "4: Shoot" << endl;
        cin >> c;
        if (c == 1)
        {
            w.moveForward();
        }
        else if (c == 2)
        {
            w.turnLeft();
        }
        else if (c == 3)
        {
            w.turnRight();
        }
        else if (c == 4)
        {
            w.shoot();
        }
    }
    return 0;
}
