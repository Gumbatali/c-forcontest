#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

// https://en.cppreference.com/w/cpp/algorithm/accumulate
int totalSales(const std::vector<int> &sales) {
    return std::accumulate(sales.begin(), sales.end(), 0);
}
// https://en.cppreference.com/w/cpp/algorithm/max_element
// https://en.cppreference.com/w/cpp/iterator/distance
int maxSalesMonth(const std::vector<int> &sales) {
    auto max_sales_it = std::max_element(sales.begin(), sales.end());
    int max_sales_month = std::distance(sales.begin(), max_sales_it) + 1;
    return max_sales_month;
}

int main() {
    std::vector<int> sales = {12000, 15000, 13000, 19000, 17000, 16000,
                              18000, 21000, 20000, 17000, 22000, 19000};
    int total = totalSales(sales);
    std::cout << "total: " << total << std::endl;

    int maxMonth = maxSalesMonth(sales);
    std::cout << "max: " << maxMonth << std::endl;

    int average = total / sales.size();
    std::cout << average << std::endl;

    for (int sale : sales) {
        std::cout << (sale > average ? "true " : "false ");
    }
    std::cout << std::endl;
    // https://en.cppreference.com/w/cpp/algorithm/count
    int below_average_months =
            std::count_if(sales.begin(), sales.end(),
                          [average](int sale) { return sale < average; });

    std::cout << below_average_months;
    return 0;
}