// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
    uint64_t max_val = num;
    uint64_t current = num;

    while (current != 1) {
        if (current % 2 == 0) {
            current = current / 2;
        } else {
            current = 3 * current + 1;
        }
        if (current > max_val) {
            max_val = current;
        }
    }

    return max_val;
}

unsigned int collatzLen(uint64_t num) {
    unsigned int length = 1;
    uint64_t current = num;

    while (current != 1) {
        if (current % 2 == 0) {
            current = current / 2;
        } else {
            current = 3 * current + 1;
        }
        length++;
    }

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
