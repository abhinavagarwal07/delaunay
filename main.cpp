#include "my.hh"
#include "delaun.hpp"
#include "interpolate.hpp"
vector<formation> f;
vector<vector<del_point2d_t> > players; // players[player_id][formation_id] == position of a player in an formation
del_point2d_t ball_pos[MAX_FORMATIONS];
vector<triangle> tr;
int n,k;
int num_triangles;
void update()
{
	int i,j;//,k,n;

	vector<del_point2d_t> temp(n);
	players.resize(k,temp);
	for(i=0;i<k;++i){
		for(j=0;j<n;++j){
			players[i][j] = f[j].bot_pos[i];
		}
	}
//	ball_pos.resize(n);
	for(i=0;i<n;++i){
		ball_pos[i] = f[i].ballpos;
	}
}
void read_formation()
{
	int i,j;//,k,n;
	cin >> n >> k;
	cout << "n = " << n << '\t' <<"k = " << k << '\n'; 
	f.resize(n,formation(k));
///	cout << "in read";
	for(i=0;i<n;++i){
		f[i].ballpos.read();
		for(j=0;j<k;++j){
			cout << i << ' ' << j << '\n';
			f[i].bot_pos[j].read();
		}
	}
	update();
}
void make_triangles()
{
	delaunay2d_t* ret1 = delaunay2d_from(ball_pos,n);
	tri_delaunay2d_t* re2 = tri_delaunay2d_from(ret1);
	num_triangles = re2->num_triangles;
	for (int i = 0; i < re2->num_triangles; ++i){
		for (int j = 0; j < 3; ++j){
			tr[i].x[j] = re2->tris[3 * i + j];
		}
	}
}
int main()
{
	int i,j;
	read_formation();
	cout << "Read Success";
	make_triangles();
	cout << "Give a ball position\n";
}
