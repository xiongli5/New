#ifndef GAMESTATE_H_
#define GAMESTATE_H_
#include<string>
#include"MapTable.h"

using namespace std;
class GameState
{
private:
	State current_State;
public:
	GameState();
	GameState(State s);
	void setCurrentState(const int L_priests,const int L_devils, const string boatPosition);
	bool isMove(const int move_priests,const int move_devils);
	void Move(const int move_priests,const int move_devils);
	bool isDead() const;
	void Help();
	int getLeftPriests() const;
	int getLeftDevils() const;
	string getBoatPosition() const;
};
#endif