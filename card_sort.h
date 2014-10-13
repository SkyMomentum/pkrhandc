#ifndef RD_CARD_SORT
#define RD_CARD_SORT

card_list* sortInputHand(card_list *input_cards);
card_list* mergesortCardLists(card_list *left, card_list *right);
card_list* find_value_sets(card_list* sorted_cards);

#endif // RD_CARD_SORT
