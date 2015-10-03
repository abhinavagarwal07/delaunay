#include "my.hh"

float dist(del_point2d_t a, del_point2d_t b)
{
	return sqrt(pow((a.y-b.y),2)+ pow((a.x-b.x),2));
}

formation interpolation (vector<formation> &vec, const del_point2d_t& actballpos)
{
	del_point2d_t inter;
	float x1, y1, x2, y2, x3, y3, x4, y4, a1, b1, a2, b2;
	int i,j;
	
	x1= vec[0].ballpos.x;
	y1= vec[0].ballpos.y;
	x2= vec[1].ballpos.x;
	y2= vec[1].ballpos.y;
	x3= vec[2].ballpos.x;
	y3= vec[2].ballpos.y;
	x4= actballpos.x;
	y4= actballpos.y;
	
	if(x1==x4 && x2!=x3){
		inter.x	= x1*(y1- y4);
		b2= (y3*x2- y2*x3)/(x3- x2);
		a2= (y3- y2)/(x3- x2);
		inter.y = a2*(inter.x) + b2;
	}
	
	else if(x1!=x4 && x2==x3){
		inter.x	= x2*(y2- y3);
		b1= (y4*x1- x4*y1)/(x4- x1);
		a1= (y4- y1)/(x4- x1);
		inter.y = a1*(inter.x) + b1;
	}
	
	else if(x1==x4 && x2==x3){
		formation final_pos;
		if(y4== y1)
			final_pos = vec[0];
		else if(y4== y2)
			final_pos = vec[1];
		else if(y4== y3)
			final_pos = vec[2];		
		final_pos.ballpos= actballpos;
		return final_pos;
	}
	
	else if( x1!=x4 && x2!=x3){
		a1= (y4- y1)/(x4- x1);
		a2= (y3- y2)/(x3- x2);
		b1= (y4*x1- x4*y1)/(x4- x1);
		b2= (y3*x2- y2*x3)/(x3- x2);
	
		inter.x= (b1- b2)/(a1- a2);
		inter.y= (a2*b1- a1*b2)/(a1- a2);
	}
	
	float m1, m2, n1, n2;
	m1= dist(inter, vec.at(1).ballpos);
	n1= dist(inter, vec.at(2).ballpos);
	
	formation interm, final_pos(10);
	
	interm.ballpos= inter;
	for(i=0;i<10;i++){
		interm.bot_pos[i].x= vec[1].bot_pos.at(i).x+ (vec[2].bot_pos[i].x- vec[1].bot_pos[i].x)*m1/(m1+n1);
		interm.bot_pos[i].y= vec[1].bot_pos.at(i).y+ (vec[2].bot_pos[i].y- vec[1].bot_pos[i].y)*m1/(m1+n1);
	}
	
	m2= dist(inter, vec.at(0).ballpos);
	n2= dist(inter, interm.ballpos);
	
	final_pos.ballpos= actballpos;
	for(i=0;i<10;i++){
		final_pos.bot_pos.at(i).x= vec.at(0).bot_pos.at(i).x+ (interm.bot_pos.at(i).x- vec.at(0).bot_pos.at(i).x)*m2/(m2+n2);
		final_pos.bot_pos.at(i).y= vec.at(0).bot_pos.at(i).y+ (interm.bot_pos.at(i).y- vec.at(0).bot_pos.at(i).y)*m2/(m2+n2);
	}
	
	return final_pos;
}


