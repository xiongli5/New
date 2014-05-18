#include"GameState.h"
#include<iostream>

GameState::GameState()
{
	current_State = state[0];
}

GameState::GameState(State s)
{
	current_State = s;
}

void GameState::setCurrentState(const int L_priests,const int L_devils, const string boatPosition)
{
	current_State.num_Left_Priests = L_priests;
	current_State.num_Left_Devils = L_devils;
	current_State.boat_Position = boatPosition;
}

bool GameState::isMove(const int move_priests,const int move_devils)
{
	if (current_State.boat_Position=="left")
	{
		return current_State.num_Left_Priests>=move_priests && current_State.num_Left_Devils>=move_devils;
	}
	else
	{
		return (3-current_State.num_Left_Priests)>=move_priests && (3-current_State.num_Left_Devils)>=move_devils;
	}
}

void GameState::Move(const int move_priests,const int move_devils)
{
	if (isMove(move_priests,move_devils))
	{
		if (current_State.boat_Position=="left")
		{
			for (int i=0; i<26; i++)
			{
				if ((current_State.num_Left_Priests-move_priests)==state[i].num_Left_Priests&&(current_State.num_Left_Devils-move_devils)==state[i].num_Left_Devils&&state[i].boat_Position=="right")
				{
					current_State = state[i];
					break;
				}
				else
					continue;
			}
		}
		else
		{
			for (int i=0; i<26; i++)
			{
				if ((current_State.num_Left_Priests+move_priests)==state[i].num_Left_Priests&&(current_State.num_Left_Devils+move_devils)==state[i].num_Left_Devils&&state[i].boat_Position=="left")
				{
					current_State = state[i];
					break;
				}
				else
					continue;
			}
		}
	}
}

bool GameState::isDead() const
{
	if (current_State.num_Left_Priests==0 || current_State.num_Left_Priests==3)
		return false;
	else if (current_State.num_Left_Priests>=current_State.num_Left_Devils && (3-current_State.num_Left_Priests)>=(3-current_State.num_Left_Devils))
		return false;
	return true;
}

void GameState::Help()
{
	for (int i=0; i<26; i++)
	{
		if ((current_State.num_Left_Priests==state[i].num_Left_Priests)&&(current_State.num_Left_Devils==state[i].num_Left_Devils)&&(current_State.boat_Position==state[i].boat_Position))
		{
			current_State = *(state[i].next);
			break;
		}
	}
}

int GameState::getLeftPriests() const
{
	return current_State.num_Left_Priests;
}

int GameState::getLeftDevils() const
{
	return current_State.num_Left_Devils;
}
string GameState::getBoatPosition() const
{
	return current_State.boat_Position;
}
/*
int main()
{
	GameState game;
	game.Move(1,1);
	game.Move(1,0);
	game.setCurrentState(1,1,"left");
	game.Help();
	
	cout<<game.getLeftPriests()<<","<<game.getLeftDevils()<<","<<game.getBoatPosition()<<endl;
	int i;
	cin >>i; 
}*/