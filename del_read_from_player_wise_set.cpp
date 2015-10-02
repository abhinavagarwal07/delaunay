#include "my.hh"
int main()
{
	int n,k; 
	string s("");
	// n = number of formations
	// k = number of players 
	cin >> n >> k;
	cout << "n= "<<n<<"\tk= "<<k<<'\n';
	vector<formation> f(n,formation(k));
	for(int i=0;i<n;++i)
		f[i].ballpos.read();
	for(int i=0;i<k;++i){//iterating over players
		cin >> s; //wasting cin
		for(int j=0;j<n;++j){//iterating over formations
			f[j].bot_pos[i].read();
		}	
	}
	
	cout << "\n\n-=======-====Now printing Result-=======-====\n\n";
	
	for(int i=0;i<n;++i){
		f[i].ballpos.print();
		for(int j=0;j<k;++j){
			f[i].bot_pos[j].print();
		}
		cout << '\n';
	}
	return 0;
}
