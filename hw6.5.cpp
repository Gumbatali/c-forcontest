#include <iostream>
#include <vector>
 
using std::vector;
 
class Minesweeper
{
private:
    size_t M, N;
    vector<vector<int>> Table;
 
public:
    Minesweeper(size_t m, size_t n) : M(m), N(n)
    {
        Table = vector<vector<int>>(M, vector<int>(N, 0));
    }
 
    size_t Rows() const
    {
        return M;
    }
 
    size_t Columns() const
    {
        return N;
    }
 
    void SetMine(size_t i, size_t j)
    {
        if (i < M && j < N)
        {
            Table[i][j] = -1;
        }
    }
 
    int operator()(size_t i, size_t j) const
    {
        if (i < M && j < N)
        {
            return Table[i][j];
        }
        return -2;
    }
 
    void CheckForMinesAround()
    {
        for (size_t i = 0; i < M; ++i)
        {
            for (size_t j = 0; j < N; ++j)
            {
                if (Table[i][j] != -1)
                {
                    Table[i][j] = minesAround(i, j);
                }
            }
        }
    }
 
private:
    int minesAround(size_t i, size_t j) const
    {
        int counter = 0;
        for (int dx = -1; dx <= 1; ++dx)
        {
            for (int dy = -1; dy <= 1; ++dy)
            {
                if (0 <= i + dx && i + dx < M &&
                    0 <= j + dy && j + dy < N &&
                    Table[i + dx][j + dy] == -1)
                {
                    ++counter;
                }
            }
        }
        return counter;
    }
};
 
std::ostream& operator<<(std::ostream& out, const Minesweeper& ms)
{
    for (size_t i = 0; i < ms.Rows(); ++i)
    {
        for (size_t j = 0; j < ms.Columns(); ++j)
        {
            if (ms(i, j) == -1)
                out << '*';
            else
                out << ms(i, j);
        }
        out << "\n";
    }
    return out;
}
