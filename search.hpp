#pragma once
#include "my.hh"
#define debug
float sign (del_point2d_t p1, del_point2d_t p2, del_point2d_t p3)
{
    	return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}
bool is_colinear(del_point2d_t x[3])
{
	if(x[1].x == x[2].x)
	{
		if(x[1].y == x[2].y)
			return false;
		else
			swap(x[1],x[0]);
	}
	if(x[1].y == x[2].y)
			swap(x[1],x[0]);

	return (x[2].y-x[1].y) * (x[1].x-x[0].x) == (x[1].y-x[0].y) * (x[2].x-x[1].x) ;
}
int remove_st_lines()
{
	vector<triangle>temp;temp.reserve(tr.size());
	for(int i=0;i<tr.size();++i)
	{
		del_point2d_t arr[3] ;//= {}
		for(int j=0;j<3;++j)arr[j] = ball_pos[tr[i].x[j]];
		if(is_colinear(arr)){
#ifdef debug
			cout << "Invalid triangle being removed:\n"; for(int j=0;j<3;++j) arr[j].print();	;	
#endif		
			continue;
		}
		temp.push_back(tr[i]);
	}
	int x = tr.size()-temp.size();
	tr = temp;
#ifdef debug
	cout  <<"Found "<< x << " invalid triangles\n";
#endif
	return x;
}
triangle& searchtri(del_point2d_t ball)
{
	bool b1, b2, b3;
	del_point2d_t v1, v2, v3;
		
	int sz,i;
	sz= tr.size();
	
	for(i=0;i<sz;i++){
		v1 = ball_pos[tr[i].x[0]];
		v2 = ball_pos[tr[i].x[1]];
		v3 = ball_pos[tr[i].x[2]]; 
		
		b1 = sign(ball, v1, v2) < 0.0f;
    		b2 = sign(ball, v2, v3) < 0.0f;
   		b3 = sign(ball, v3, v1) < 0.0f;
   		
   		if(b1==b2 && b2==b3){
   			return tr[i];
   		} 
	}
}

