#include "journal.hpp"

#include <iomanip>
#include <iostream>
#include <string>

#ifdef _WIN32
#include <fcntl.h>
#include <io.h>
#endif

int main() {
#ifdef _WIN32
    _setmode(_fileno(stdout), _O_BINARY);
#endif

int main() {
    std::string name;
    int n = 0;
    if (!(std::cin >> name >> n)) {
        return 0;
    }

    if (n < 0) {
        std::cout << "invalid count\n";
        return 1;
    }

    long long sum = 0;
    int min_score = 0;
    int max_score = 0;
    int passed = 0;
    bool has_score = false;

    for (int i = 0; i < n; ++i) {
        int score = 0;
        std::cin >> score;
        if (!IsValidScore(score)) {
            std::cout << "invalid score\n";
            return 1;
        }
        sum = AddToSum(sum, score);
        min_score = NextMin(has_score, min_score, score);
        max_score = NextMax(has_score, max_score, score);
        passed = NextPassed(passed, score);
        has_score = true;
    }

    const int count = n;
    const int failed = count - passed;

    std::cout << "name: " << name << '\n';
    std::cout << "count: " << count << '\n';
    std::cout << "sum: " << sum << '\n';
    if (count == 0) {
        std::cout << "average: n/a\n";
        std::cout << "min: n/a\n";
        std::cout << "max: n/a\n";
    }
    else {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "average: " << Average(sum, count) << '\n';
        std::cout << "min: " << min_score << '\n';
        std::cout << "max: " << max_score << '\n';
    }
    std::cout << "passed: " << passed << '\n';
    std::cout << "failed: " << failed << '\n';
    std::cout << "verdict: " << Verdict(count, passed, min_score) << '\n';
    return 0;
}
