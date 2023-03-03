#include <iostream>
#include <map>
#include <utility>
#include <string>
#include <vector>
#include <deque>

using namespace std;

#define X first
#define Y second
#define A begin
#define B end
#define S1 100000


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifdef MONKE
#define debug(x...) cerr << "[" << #x << "] = [", _print(x)
#else
#define debug(x...)
#endif

#define pp pair<int,int> 

typedef map<int, deque<pp> > mm;

const int TIME_THRESHOLD = 100;


/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int height;
int width;
int my_flag_base_r;
int my_flag_base_c;
int opponent_flag_base_r;
int opponent_flag_base_c;	
string fire_name;
int fire_price;
int fire_damage;
string freeze_name;
int freeze_price;
int freeze_damage;
string mine_name;
int mine_price;
int mine_damage;
int my_flag_pos_r, my_flag_pos_c, my_flag_carrier;
int my_score, opponent_score;
int opponent_flag_pos_r, opponent_flag_pos_c, opponent_flag_carrier;

int ATTACKER_ID = 1;
int DEFENDER_ID = 0;

vector<string> rows;
pair<int,int> dt[] = { {1,0}, {0,-1}, {-1,0}, {0,1} };
map<int, map<int, deque<pp> > > opp_minion_pos;
map<int, tuple<pp, int, int> > my_minion, opp_minion;

// mm find_all_path( pp src, pp des ) {
//     mm paths;
    
//     if( src.X == des.X && src.Y == des.Y ) {
//         paths[0] = { des };
//         return paths;
//     }

//     for( int i=0; i<4; i++ ) {
        
//         if( rows[ src.X + dt[i].X ][ src.Y + dt[i].Y ] == '#' ) continue;

//         mm t_path;
//         t_path = find_all_path( make_pair( src.X + dt[i].X, src.Y + dt[i].Y ), des );
//         for ( auto i : t_path ) {
//             i.Y.push_front( { src.X, src.Y } );
//             paths[i.X + 1] = i.Y;
//         }
//     }

//     return paths;
// }

void predict_minion_pos( int id, int time ) {
    if ( time > TIME_THRESHOLD ) return;
    deque<pp> all_current_pos = opp_minion_pos[id][time];

    for( auto cpos : all_current_pos ) {
        for( int i=0; i<4; i++ ) {
            if( rows[ cpos.X + dt[i].X][ cpos.Y + dt[i].Y ] == '#' ) continue;
            opp_minion_pos[id][time+1].push_back( make_pair( cpos.X + dt[i].X, cpos.Y + dt[i].Y ) );
        }
    }
}

int check_if_minion(pp pos, bool check_for_my_minion) {
	for( auto i : ( check_for_my_minion ? my_minion : opp_minion ) ) {
		pp minion_pos;
		int health, timeout;
		tie(minion_pos, health, timeout) = i.Y;
		if( minion_pos.X == pos.X && minion_pos.Y == pos.Y ) return i.X;
	}

	return -1;
}

vector<int> check_minions_in_range(pp pos) {
	pp incrementor;
	vector<int> minions;
	for( int i=0; i<4; i++ ) {
		switch(i) {
			case 0: incrementor = {  1,  0 }; break;
			case 1: incrementor = {  0, -1 }; break;
			case 2: incrementor = { -1,  0 }; break;
			case 3: incrementor = {  0,  1 }; break;
		}
		pp cur_pos = pos;
		while( 1 ) {
			if( rows[cur_pos.X][cur_pos.Y] == '#' ) break;
			int min_chk = check_if_minion( cur_pos, false );
			if( min_chk != -1 ) minions.push_back( min_chk );
			cur_pos = { cur_pos.X + incrementor.X, cur_pos.Y + incrementor.Y };
		}
	}
	return minions;
}

vector<int> check_coins_in_range(pp pos) {
	pp incrementor;
	vector<int> coins;
	for( int i=0; i<4; i++ ) {
		switch(i) {
			case 0: incrementor = {  1,  0 }; break;
			case 1: incrementor = {  0, -1 }; break;
			case 2: incrementor = { -1,  0 }; break;
			case 3: incrementor = {  0,  1 }; break;
		}
		pp cur_pos = pos;
		while( 1 ) {
			if( check_if_minion( cur_pos, true ) != -1 ) break;
			if( rows[cur_pos.X][cur_pos.Y] == '#' ) break;
			else if( rows[cur_pos.X][cur_pos.Y] == '.' ) {
				coins.push_back( i );
				break;
			} else cur_pos = { cur_pos.X + incrementor.X, cur_pos.Y + incrementor.Y };
		}
	}
	return coins;
}

bool check_if_my_flag_in_range(pp pos) {
	pp incrementor;
	for( int i=0; i<4; i++ ) {
		switch(i) {
			case 0: incrementor = {  1,  0 }; break;
			case 1: incrementor = {  0, -1 }; break;
			case 2: incrementor = { -1,  0 }; break;
			case 3: incrementor = {  0,  1 }; break;
		}
		pp cur_pos = pos;
		while( 1 ) {
			if( rows[cur_pos.X][cur_pos.Y] == '#' ) break;
			else if( cur_pos.X == my_flag_pos_r && cur_pos.Y == my_flag_pos_c ) {
				return true;
			} else cur_pos = { cur_pos.X + incrementor.X, cur_pos.Y + incrementor.Y };
		}
	}
	return false;
}

bool check_if_attacker_dead() {
	pp pos;
	int health, timeout;
	tie(pos, health, timeout) = my_minion[ATTACKER_ID];
	if( health < 1 ) return false;
	else return true;
}


bool check_if_defender_dead() {
	pp pos;
	int health, timeout;
	tie(pos, health, timeout) = my_minion[DEFENDER_ID];
	if( health < 1 ) return false;
	else return true;
}

vector<string> commands;

void collect() {
	for( int i=2; i<5; i++ ) {
		if( my_minion.find(i) == my_minion.end() ) continue;

		pp pos;
		int health, timeout;
		tie(pos, health, timeout) = my_minion[i];

		if( health < 1 ) continue;

		if( check_if_attacker_dead() ) {
			ATTACKER_ID = i;
			continue;
		}
		if( check_if_defender_dead() ) {
			if( my_score < 7 ) continue;
			DEFENDER_ID = i;
			continue;
		}

		vector<int> coin_dirs = check_coins_in_range( pos );
		if( coin_dirs.size() == 0 ) commands.push_back( "MOVE " + to_string( i ) + " " + to_string( pos.X ) + " " + to_string( pos.Y + 1) );
		else commands.push_back( 
			"MOVE " + to_string( i ) + " " + to_string( pos.X + dt[coin_dirs[i]].X ) + " " + to_string( pos.Y + dt[coin_dirs[i]].Y ) 
		);
	}
} 

void defend() {
	pp pos;
	int health, timeout;
	tie(pos, health, timeout) = my_minion[DEFENDER_ID];
	vector<int> minions = check_minions_in_range( pos );
	
	if( !check_if_my_flag_in_range(pos) ) 
		commands.push_back( "MOVE " + to_string( DEFENDER_ID ) + " " + to_string( my_flag_pos_r ) + " " + to_string( my_flag_pos_c + 1 ) );
	
	if( minions.size() == 0 ) return;
	else {
		commands.push_back( "FIRE " + to_string(DEFENDER_ID) );
	}
}

void attack() {
	pp pos;
	int health, timeout;
	tie(pos, health, timeout) = my_minion[ATTACKER_ID];
	if( check_minions_in_range(pos).size() != 0 ) commands.push_back( "FIRE " + to_string(ATTACKER_ID) );
	else {
		cerr << opponent_flag_pos_r << " " << opponent_flag_base_c << endl;
		commands.push_back( "MOVE " + to_string(ATTACKER_ID) + " " + to_string( opponent_flag_base_r ) + " " + to_string( opponent_flag_base_c ) );
	}
}


int main()
{
    
    cin >> height >> width; cin.ignore();
    for (int i = 0; i < height; i++) {
        string row;
        cin >> row; cin.ignore();
        rows.push_back( row );
    }
    
    cin >> my_flag_base_r >> my_flag_base_c; cin.ignore();
    
    cin >> opponent_flag_base_r >> opponent_flag_base_c; cin.ignore();
    
    cin >> fire_name >> fire_price >> fire_damage; cin.ignore();
    
    cin >> freeze_name >> freeze_price >> freeze_damage; cin.ignore();
    
    cin >> mine_name >> mine_price >> mine_damage; cin.ignore();

    // game loop
    while (1) {
        cin >> my_score >> opponent_score; cin.ignore();

        cin >> my_flag_pos_r >> my_flag_pos_c >> my_flag_carrier; cin.ignore();
        
        cin >> opponent_flag_pos_r >> opponent_flag_pos_c >> opponent_flag_carrier; cin.ignore();

        int my_alive_minion_cnt;
        cin >> my_alive_minion_cnt; cin.ignore();

        for (int i = 0; i < my_alive_minion_cnt; i++) {
            int id, pos_r, pos_c, health, timeout;
            cin >> id >> pos_r >> pos_c >> health >> timeout; cin.ignore();
            my_minion[id] = make_tuple( make_pair( pos_r, pos_c ), health, timeout ); 
        }

        int visible_minion_cnt;
        cin >> visible_minion_cnt; cin.ignore();
        for (int i = 0; i < visible_minion_cnt; i++) {
            int id, pos_r, pos_c, health, timeout;
            cin >> id >> pos_r >> pos_c >> health >> timeout; cin.ignore();
            opp_minion[id] = make_tuple( make_pair( pos_r, pos_c ), health, timeout ); 
            opp_minion_pos[id].clear();
            opp_minion_pos[id][0] = { make_pair( pos_r, pos_c ) };
            predict_minion_pos( id, 0 );
        }

        int visible_coin_cnt;
        cin >> visible_coin_cnt; cin.ignore();
        for (int i = 0; i < visible_coin_cnt; i++) {
            int pos_r, pos_c;
            cin >> pos_r >> pos_c; cin.ignore();
            rows[pos_r][pos_c] = '.';
        }

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        commands.clear();
        collect();
        defend();
        attack();

        for( int i=0; i<commands.size(); i++ ) {
        	cout << commands[i];
        	if( i != commands.size()-1 ) cout << " | ";
        	else cout << endl;
        }
    }
}