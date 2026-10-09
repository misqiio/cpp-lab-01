#include "labels.hpp"

std::string SignLabel(int value) {
    if (value > 0) {
        return "positive";
    }
    else if (value == 0) {
        return "zero";
    }
    else {
        return "negative";
    }
}

std::string ParityLabel(int value) {
    if (value % 2 == 0) {
        return "even";
    }
    else {
        return "odd";
    }
}

std::string GradeLabel(int score) {
    if (score < 0 || score > 100) {
        return "invalid";
    }
    if (score < 60) {
        return "fail";
    } else if (score < 75) {
        return "pass";
    } else if (score >= 90) {
        return "excellent";
    } else {
        return "good";
    }
}
