// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
    uint64_t max_val = num;

    while (num != 1) {
        if (num % 2 == 0) {
            num = num / 2;
        } else {
            num = 3 * num + 1;
        }
        if (num > max_val) {
            max_val = num;
        }
    }

    return max_val;
}

unsigned int collatzLen(uint64_t num) {
    static unordered_map<uint64_t, unsigned int> memo;

    if (num == 1) return 1;

    auto it = memo.find(num);
    if (it != memo.end()) return it->second;

    unsigned int length;
    if (num % 2 == 0) {
        length = 1 + collatzLen(num / 2);
    } else {

        uint64_t next = 3 * num + 1;
        length = 1 + collatzLen(next);
    }

    memo[num] = length;
    return length;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
    unsigned int max_length = 0;
    uint64_t best_number = lbound;
    uint64_t max_value_in_sequence = 0;

    for (uint64_t i = lbound; i <= rbound; i++) {
        unsigned int current_length = collatzLen(i);

        if (current_length > max_length) {
            max_length = current_length;
            best_number = i;
            max_value_in_sequence = collatzMaxValue(i);
        }
    }

    *maxlen = max_length;

    return static_cast<unsigned int>(best_number);
}
