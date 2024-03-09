#include<iostream>
using namespace std;
int n, m , r, c, d, map[51][51], cnt, dis, nx, ny, nd;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

bool check(int x, int y) {
	for(int i=0; i<4; i++) {
		nx=x+dx[i], ny=y+dy[i];
		if(nx>=0 && nx<m && ny>=0 && ny<n && !map[ny][nx]) return 0;
	}
	return 1;
}

void func(int x, int y, int d) {
	if(dis) return;
	if(map[y][x]==1) { return; }
	if(!map[y][x]) { 
		cnt++;
		map[y][x]=2;  
	}

	if(check(x, y)) { 
		nd = (d+2)%4;
		nx=x+dx[nd];
		ny=y+dy[nd];
		if(map[ny][nx] == 1) { dis=1; return; }
		func(nx, ny, d);  
	} else {  
		nd=d;
		for(int i=1; i<=4; i++) {
			nd = (nd+3)%4;  
			nx=x+dx[nd];
			ny=y+dy[nd];
			if(!map[ny][nx]) {
				func(nx, ny, nd);
				break;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	cin >> r >> c >> d;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin >> map[i][j];
	func(c, r, d);
	cout << cnt;
}