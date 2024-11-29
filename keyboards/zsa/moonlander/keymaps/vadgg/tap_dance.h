// Define a type for as many tap dance states as you need
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

enum {
    MY_CMOD, // Our custom tap dance key; add any other tap dance keys to this enum 
    TD_BACKSPACE,
    TD_LEFT_BRACKET,

    TD_1F1,
    TD_2F2,
    TD_3F3,
    TD_4F4,
    TD_5F5,
    TD_6F6,
    TD_7F7,
    TD_8F8,
    TD_9F9,
    TD_0F10,
};

// Declare the functions to be used with your tap dance key(s)

// Function associated with all tap dances
td_state_t cur_dance(tap_dance_state_t *state);

// Functions associated with individual tap dances
void ql_finished(tap_dance_state_t *state, void *user_data);
void ql_reset(tap_dance_state_t *state, void *user_data);
