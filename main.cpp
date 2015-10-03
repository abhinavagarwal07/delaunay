#include "my.hh"
#include "delaun.hpp"
#include "interpolate.hpp"
void update()
{
	int i,j;//,k,n;
//	cout <<"In update()\n";
	vector<del_point2d_t> temp(n);
	players.resize(k,temp);
	for(i=0;i<k;++i){
		for(j=0;j<n;++j){
			players[i][j] = f[j].bot_pos[i];
		}
	}
//	ball_pos.resize(n);
	for(i=0;i<n;++i){
//		cout << i << '\t';
		ball_pos[i] = f[i].ballpos;
	}
//	cout << "exit update()\n";
}
void read_formation()
{
	int i,j;//,k,n;
	cin >> n >> k;
//	cout << "n = " << n << '\t' <<"k = " << k << '\n'; 
	f.resize(n,formation(k));
///	cout << "in read";
	for(i=0;i<n;++i){
		f[i].ballpos.read();
		for(j=0;j<k;++j){
//			cout << i << ' ' << j << '\n';
			f[i].bot_pos[j].read();
		}
//		getchar();getchar();
	}
	update();
//	cout << "done read\n";
}
void make_triangles()
{
	delaunay2d_t* ret1 = delaunay2d_from(ball_pos,n);
	tri_delaunay2d_t* re2 = tri_delaunay2d_from(ret1);
	num_triangles = re2->num_triangles;
	tr.resize(num_triangles);
	for (int i = 0; i < re2->num_triangles; ++i){
		for (int j = 0; j < 3; ++j){
			tr[i].x[j] = re2->tris[3 * i + j];
		}
		tr[i].print();
	}

}
int main()
{
	int i,j;
	system("clear");
	read_formation();
	cout << "Read Success\n";
	make_triangles();
	cout << "Give a ball position\n";
	
	vector<formation> f2;
	system("clear");

//	cout <<"f.size() "<<f.size() <<'\n';
//	f[4].print();
	cin >> i >> j;
	int x;//[3];
	
	cout << "Interpolating Using: \n";	
	for(int it=0;it<3;++it) 
	{
		cin >> x;//[i];	
		f2.push_back(f[x]);//f2.push_back(f[1]);f2.push_back(f[4]);
		f[x].print();
	}
//	for(i=0;i<3;++i)
///		f2[i].print();
	
	del_point2d_t ball;ball.x=i;ball.y=j;
	formation gg  = interpolation(f2,ball);
	
	cout << "Result : \n";
		gg.print();
	
}
