// Player -> id, name, rank.
// Board -> ( n, m ) -> dimensions, vector<vector<int>> board.
// BoardInstance -> id, vector<Player> , methods : play(playerId, columnId) -> bool (win or not), winCheck : private (board). 

#include <bits/stdc++.h>
using namespace std;


class Player {
public:
    int id, rank;
    string name;
    Player(int id, int rank, string name) : id(id), rank(rank), name(name) {}
};

class Board {
public:
    int n,m;
    vector<vector<int>> board;
    Board(int n, int m) {
        this->n = n;
        this->m = m;
        board.resize(n);
    }
};

class BoardInstance : public Board{
private:
    bool winCheck() {
        for(int i = 0;i < n;i++) {
            int same = 1;
            for(int j = 1; i < m;j++) {
                if(this->board[i][j] == this->board[i][j-1]) {
                    same++;
                } else {
                    same = 1;
                }
                if(same == 4) {
                    cout<<"Player "<<this->board[i][j]<<" wins!!!"<<endl;
                    return true;
                }
            }
        }
        for(int i = 0;i < m;i++) {
            int same = 1;
            for(int j = 1; i < n;j++) {
                if(this->board[j][i] == this->board[j - 1][i]) {
                    same++;
                } else {
                    same = 1;
                }
                if(same == 4) {
                    cout<<"Player "<<this->board[j][i]<<" wins!!!"<<endl;
                    return true;
                }
            }
        }
    }
public:
    int id;
    vector<Player*> players;
    BoardInstance(int n, int m, int id, vector<Player*> players) : id(id), players(players), Board(n,m) {}
    bool player(int playerId, int columnId) {
        if(columnId < 0 || columnId >= this->m) {
            cout<<"Invalid Column"<<endl;
            return false;
        } 
        for(int i = n - 1; i >= 0;i--) {
            if(this->board[i][columnId] != -1) {
                this->board[i][columnId] = playerId;
                break;
            }
        }
        cout<<"Win check : "<<endl;
        return true;
    }
};