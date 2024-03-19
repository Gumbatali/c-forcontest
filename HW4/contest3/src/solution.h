#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

int main()
{
    int M, N;
    cin >> M >> N;

    string first_word;
    vector<int> first_vector(N);
    cin >> first_word;
    for (int i = 0; i < N; ++i)
    {
        cin >> first_vector[i];
    }

    int max_scalar_product = numeric_limits<int>::min();
    string closest_word;
    for (int i = 0; i < M - 1; ++i)
    {
        string word;
        vector<int> vector(N);

        cin >> word;
        int scalar_product = 0;
        for (int j = 0; j < N; ++j)
        {
            cin >> vector[j];
            scalar_product += vector[j] * first_vector[j];
        }
        if (scalar_product > max_scalar_product)
        {
            max_scalar_product = scalar_product;
            closest_word = word;
        }
    }
    cout << closest_word << endl;

    return 0;
}
