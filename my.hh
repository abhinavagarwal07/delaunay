#pragma once

#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cassert>
#include<cstring>
#define MAX_FORMATIONS 40
using namespace std;
typedef float real;
struct formation;struct triangle;

typedef struct del_point2d_t_tag{
	real	x, y;
	
	void read()
	{
		cin >> x >> y;
	}
	void print()
	{
		cout << x << ' ' << y << '\n';
	}
} del_point2d_t;

vector<formation> f;
vector<vector<del_point2d_t> > players; // players[player_id][formation_id] == position of a player in an formation
del_point2d_t ball_pos[MAX_FORMATIONS];
vector<triangle> tr;
int n,k;
int num_triangles;

struct triangle{
	int x[3];
	void print()
	{
		for(int i=0;i<3;++i)
			cout << x[i] << ' ';cout << '\n';
	}
};
struct point
{
	float x;
	float y;

}; //point;
struct formation
{
	del_point2d_t ballpos;
	vector <del_point2d_t> bot_pos;
	formation()
	{
		bot_pos.resize(MAX_FORMATIONS);
	}
	formation(int n)
	{
		bot_pos.resize(n);
	}
	
	void print()
	{
		cout << "Ball : "; ballpos.print();
		for(int i=0;i<bot_pos.size();++i)
			bot_pos[i].print();
		cout << '\n';
	}
} ;
