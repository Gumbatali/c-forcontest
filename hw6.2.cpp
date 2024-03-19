#include <iostream>
#include <map>
#include <string>
#include <vector>

std::vector<std::string> answer(std::vector<std::vector<int>>& values, std::vector<std::string>& keys)
{
    std::vector<std::string> itog;
    long long max_suma = -1000000010;


    for (size_t i = 1; i < values.size(); i++)
    {

        int suma = 0;
        for (size_t j = 0; j < values[0].size(); j++)
        {
            suma += values[0][j] * values[i][j];
        }
        if (suma > max_suma)
        {
            max_suma = suma;
            itog.clear();
            itog.push_back(keys[i]);
        }
        else if (suma == max_suma)
        {
            itog.push_back(keys[i]);
        }
    }
    return itog;
}

int main()
{
    int m, n;
    std::vector<std::string> keys;
    std::vector<std::vector<int>> values;
    std::string a;
    int b;


    std::cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        std::cin >> a;
        keys.push_back(a);
        values.push_back(std::vector<int>());

        for (int j = 0; j < n; j++)
        {
            std::cin >> b;
            values[i].push_back(b);
        }
    }

    std::vector<std::string> res = answer(values, keys);

    for (const auto& i: res)
    {
        std::cout << i << std::endl;
    }

    return 0;
}
