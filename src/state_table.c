#include "state_table.h"

const StateEntry state_table[NO_OF_STATES] = {
    {
        .state = &state_stationary,
        .transition_count = 2,
        .transitions =
            {
                {.bitmask1 = {0xff}, .bitmask0 = {0x01}, .next = &state_rotate},

                {.bitmask1 = {0xFF}, .bitmask0 = {0x00}, .next = &state_rotate},
            },
    },

    {
        .state = &state_rotate,
        .transition_count = 2,
        .transitions =
            {
                {.bitmask1 = {0xFF}, .bitmask0 = {0x01}, .next = &state_stationary},

                {.bitmask1 = {0xFF}, .bitmask0 = {0x00}, .next = &state_stationary},
            },
    },
};
