#pragma once
#include "my.hh"

float sign (del_point2d_t p1, del_point2d_t p2, del_point2d_t p3)
{
    	return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
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

