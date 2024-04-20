#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;
class Universe
{
private:
    int rows, columns;
    vector < vector < bool>>grid;
public:
    Universe(const int& row, const int& column) :rows(row), columns(column)
    {
        grid.resize(rows, vector<bool>(columns, false));
    }
    void initialize()
    {
        grid[14][15] = true;
        grid[15][16] = true;
        grid[16][14] = true;
        grid[16][15] = true;
        grid[16][16] = true;
    }
    void reset()
    {
        grid.assign(rows, vector<bool>(columns, false));
    }
    bool can_move(const int& x, const int& y)const
    {
        return (x < rows && ~x && ~y && y < columns );
    }
    int count_neighbors(const int & x,const int & y)const
    {
        int dx[] = { 1 ,0,-1,0,1,1,-1 ,-1 };
        int dy[] = { 0 ,1,0,-1,1,-1,1,-1 };
        int count = 0;
        for (int i = 0; i < 8; i++)
        {
            int newx = x + dx[i];
            int newy = y + dy[i];
            if (can_move(newx, newy))
            {
                count += grid[newx][newy];
            }
        }
        return count;
    }
    void  next_generation()
   {
        vector<vector<bool>>tmp(rows, vector<bool>(columns, false));
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                int cnt = count_neighbors(i, j);
                if (grid[i][j] && (cnt>3 || cnt<2))
                {
                    tmp[i][j] = false;
                }
                else if (grid[i][j])
                {
                    tmp[i][j] = true;
                }
                else if (!grid[i][j] && cnt == 3)
                {
                    tmp[i][j] = true;
                }
            }
        }
        grid = tmp;
    }
    void display()const
    {
        system("cls");
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                cout << (grid[i][j] ?  char(254): '*');
            }
            cout << '\n';
        }
        this_thread::sleep_for(chrono::milliseconds(150));
        //system("PAUSE");
    }
    void run(const int& number_of_runs)
    {
        initialize();
        for (int i = 0; i < number_of_runs; i++)
        {
            display();
            Universe::next_generation();
        }
    }
   
};
int main() {
  
    Universe gameOfLife(30, 30);
    gameOfLife.run(50);
    return 0;
}
         