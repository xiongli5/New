#ifndef MAPTABLE_H_
#define MAPTABLE_H_
#include<iostream>
#include<string>
using namespace std;

struct State
{
	int num_Left_Priests;
	int num_Left_Devils;
	string boat_Position;
	State *next;
};
namespace {
	State state[26] = {
		{3,3,"left",&state[3]},
		{3,2,"right",NULL},
		{2,3,"right",NULL},
		{2,2,"right",&state[7]},
		{3,1,"right",&state[7]},
		{1,3,"right",NULL},
		{2,3,"left",NULL},
		{3,2,"left",&state[8]},
		{3,0,"right",&state[10]},
		{1,2,"right",NULL},
		{3,1,"left",&state[13]},
		{2,1,"right",NULL},
		{2,0,"right",NULL},
		{1,1,"right",&state[16]},
		{1,2,"left",NULL},
		{2,1,"left",NULL},
		{2,2,"left",&state[19]},
		{1,3,"left",NULL},
		{2,0,"right",NULL},
		{0,2,"right",&state[20]},
		{0,3,"left",&state[21]},
		{0,1,"right",&state[22]},
		{0,2,"left",&state[24]},
		{1,1,"left",&state[24]},
		{0,0,"right",NULL},
		{1,0,"right",NULL}
	};
}

#endif