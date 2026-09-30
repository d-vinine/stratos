#ifndef STATE_TABLE_H
#define STATE_TABLE_H

#include "states/state.h"
#include <stdint.h>

#define MAX_INPUT_FIELDS 3
#define WORDS ((MAX_INPUT_FIELDS + 7) / 8)

#define NO_OF_STATES 2
#define MAX_TRANSITIONS 2

typedef struct {
  const uint8_t bitmask1[WORDS];
  const uint8_t bitmask0[WORDS];
  const State *next ;
} Transition;

typedef struct {
  const State *state;
  const Transition transitions[MAX_TRANSITIONS];
  const int transition_count;
} StateEntry;

extern const StateEntry state_table[NO_OF_STATES];

extern const State state_stationary;
extern const State state_rotate;

#endif
