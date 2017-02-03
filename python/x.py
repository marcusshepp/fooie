
"""
routine:
1. collect blinds
2. shuffle deck
3. deal hands
   * while no one has folded
4. collect bets
5. (muck one) deal flop
6. collect bets
7. (muck one) deal turn
8. collect bets
9. (muck one) deal river
"""
import random
import itertools

card_numbers = [
    "A",
    "K",
    "Q",
    "J",
    "T",
    "9",
    "8",
    "7",
    "6",
    "5",
    "4",
    "3",
    "2"
]
suits = [
    "C",
    "S",
    "H",
    "D"
]

game_state = {}

def all_cards():
    deck = []
    for num in card_numbers:
        for suit in suits:
            deck.append(num + suit)
    return deck

def pop_card(deck):
    card = deck.pop(random.randint(0, len(deck) - 1))
    return deck, card

def deal_hands(deck, num_players):
    hands = []
    for _ in range(num_players):
        hand = []
        for i in range(2):
            deck, card = pop_card(deck)
            hand.append(card)
        hands.append(hand)
    return deck, hands

def deal_flop(deck):
    flop = []
    for i in range(3):
        deck, card = pop_card(deck)
        flop.append(card)
    return deck, flop

def deal_turn(deck):
    deck, card = pop_card(deck)
    return deck, card

def deal_river(deck):
    deck, card = pop_card(deck)
    return deck, card

for _ in xrange(100):
    deck = all_cards()
    deck, hands = deal_hands(deck, 2)
    deck, flop = deal_flop(deck)
    deck, turn = deal_turn(deck)
    deck, river = deal_river(deck)

    print hands
    print flop
    print turn
    print river

    cards_in_play = flop + [river] + [turn] + list(itertools.chain(*hands))
    print list(set(cards_in_play))
    print cards_in_play
    assert sorted(list(set(cards_in_play))) == sorted(cards_in_play)
    print ""
