#include "journal.hpp"
#include <string> 
#ifdef _WIN32
#include <fcntl.h>
#include <io.h>
#endif

int main() {
#ifdef _WIN32
    _setmode(_fileno(stdout), _O_BINARY);
#endif

bool IsValidScore(int score) {
    if (score >= 0 && score <= 100) {
        return true;
    } else {
        return false;
    }
}

long long AddToSum(long long sum, int score) {
    return sum + score;
}

int NextMin(bool has_score, int current_min, int score) {
    if (has_score == false) {
        return score;
    } else {
        if (current_min < score) {
            return current_min;
        } else {
            return score;
        }
    }
}

int NextMax(bool has_score, int current_max, int score) {
    if (has_score == false) {
        return score;
    } else {
        if (current_max > score) {
            return current_max;
        } else {
            return score;
        }
    }
}

int NextPassed(int passed, int score) {
    if (score >= 60) {
        passed++;
    }
    return passed;
}

double Average(long long sum, int count) {
    double sum_dub = sum;
    return sum_dub / count;
}

std::string Verdict(int count, int passed, int min_score) {
    if (count == 0) {
        return "empty";
    }
    if (passed != count) {
        return "debt";
    }
    if (min_score >= 90) {
        return "excellent";
    }
    return "ok";
}
