#include <iostream>
#include <vector>
#include <string> 

using namespace std;

enum Piece
{
    EMPTY, 
    RED, 
    YELLOW
};

class Player
{
public:
    Player(const string in_name, const Piece in_piece) :
        name(in_name),
        piece(in_piece)
    {
        cout << "Created player (name: " << name << " | " << "piece: " << piece << ")" << endl; 
    }

    string get_player_name()
    {
        return name; 
    }

    Piece get_player_piece()
    {
        return piece; 
    } 

private:
    string name; 
    Piece piece; 
};

class Grid
{
public: 
    Grid(const int in_rows, const int in_cols, const int in_connect_win_num) : 
        rows(in_rows),
        cols(in_cols),
        connect_win_num(in_connect_win_num),
        grid_vec(0)
    {
        cout << "Creating a " << rows << " by " << cols << " grid" << endl; 
        init_grid(); 
    }

    void init_grid()
    {
        grid_vec = vector<vector<int>>(rows, vector<int>(cols, Piece::EMPTY));
    }

    // get_col_count
    int get_col_count()
    {
        return cols; 
    }

    // get_row_count
    int get_row_count()
    {
        return rows; 
    }

    vector<vector<int>> get_grid_vec()
    {
        return grid_vec; 
    }

    // place_piece 
    int place_piece(const int in_col, const Piece in_piece)
    {
        // check if col is valid
        if (in_col < 0 || in_col >= cols)
        {
            throw "Invalid column";
        }
        // check if piece is valid
        if (in_piece == Piece::EMPTY)
        {
            throw "Invalid piece";
        }

        for (int r = rows - 1; r >= 0; r--)
        {
            if (grid_vec[r][in_col] == Piece::EMPTY)
            {
                grid_vec[r][in_col] = in_piece;
                return r; 
            }
        }

        return -1; // col is full
    }

    // check_win
    bool check_win(Player &in_player, const int in_row, const int in_col)
    {
        int count = 0; 
        Piece player_piece = in_player.get_player_piece(); 

        // check horizontal
        vector<int> row_vec = grid_vec[in_row]; 
        for (int c = 0; c < cols; c++)
        {
            if (row_vec[c] == player_piece)
            {
                count++; 
            }
            else 
            {
                count = 0; 
            }

            if (count == connect_win_num) 
            {
                return true; 
            }
        }

        // check vertical 
        count = 0;
        for (int r = 0; r < rows; r++)
        {
            if (grid_vec[r][in_col] == player_piece)
            {
                count++; 
            }
            else 
            {
                count = 0; 
            }

            if (count == connect_win_num) 
            {
                return true; 
            }
        }

        // check diagonal (top right to bottom left)
        count = 0; 
        for (int r = 0; r < rows; r++)
        {
            int c = in_col + in_row - r; 
            if (c >= 0 && c < cols)
            {
                if (grid_vec[r][c] == player_piece)
                {
                    count++;
                }
                else 
                {
                    count = 0; 
                }

                if (count == connect_win_num) 
                {
                    return true; 
                }
            } 
        }

        // check diagonal (top left to bottom right)
        count = 0; 
        for (int r = 0; r < rows; r++)
        {
            int c = in_col - in_row + r; 
            if (c >= 0 && c < cols)
            {
                if (grid_vec[r][c] == player_piece)
                {
                    count++;
                }
                else 
                {
                    count = 0; 
                }

                if (count == connect_win_num) 
                {
                    return true; 
                }
            } 
        }

        return false; 
    }

private: 
    int rows; 
    int cols; 
    int connect_win_num;
    vector<vector<int>> grid_vec; 

}; 

class Game
{
public:
    Game(Player &in_player_1, Player &in_player_2, Grid &in_grid) :
        player_1(in_player_1), 
        player_2(in_player_2), 
        grid(in_grid)
    {
        std::cout << "Starting a game between " << in_player_1.get_player_name() << " and " << in_player_2.get_player_name() << std::endl;
        init_player_vec(); 
    }

    void init_player_vec()
    {
        player_vec.push_back(player_1);
        player_vec.push_back(player_2);
    }

    // print board
    void print_board()
    {
        vector<vector<int>> grid_vec = grid.get_grid_vec(); 
        int cols = grid.get_col_count(); 
        for (int r = 0; r < grid_vec.size(); r++)
        {
            string row = ""; 
            for (int c = 0; c < cols; c++)
            {
                if (grid_vec[r][c] == Piece::EMPTY)
                {
                    row += " ~ "; 
                }
                if (grid_vec[r][c] == Piece::RED)
                {
                    row += " R "; 
                }
                if (grid_vec[r][c] == Piece::YELLOW)
                {
                    row += " Y "; 
                }
            }
            cout << row << endl;
        }
    }

    // play move
    int play_move(Player &in_player, const int in_col)
    {
        Piece player_piece = in_player.get_player_piece();
        int row = grid.place_piece(in_col, player_piece); 
        return row;
    }

    // play round - add in future

    // play
    void play()
    {
        while (true)
        {
            for (auto &p : player_vec)
            {
                print_board(); 
                int select_col; 
                cout << p.get_player_name() << "'s turn. Input a column number from 0 to " << grid.get_col_count() - 1 << endl;  
                cin >> select_col; 

                int row = play_move(p, select_col); 
                
                if (grid.check_win(p, row, select_col))
                {
                    print_board(); 
                    cout << "Congrats " << p.get_player_name() << " for winning the game!!!" << endl; 
                    return; 
                }
            }
        }
    }

private:
    Player player_1; 
    Player player_2; 
    Grid grid;
    vector<Player> player_vec; 
}; 


int main()
{
    std::cout << "starting main" << std::endl;

    // call players
    Player swapnil("swapnil", Piece::RED); 
    Player grishma("grishma", Piece::YELLOW); 

    // call grid
    Grid grid(5, 8, 4); 

    // call game
    Game game(swapnil, grishma, grid); 
    game.play(); 

    cout << "Game has concluded." << endl; 
    return 0;
}