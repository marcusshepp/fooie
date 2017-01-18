var card_numbers = [
    "A",
    "K",
    "J",
    "10",
    "9",
    "8",
    "7",
    "6",
    "5",
    "4",
    "3",
    "2"
];
var suits = [
    "C",
    "S",
    "H",
    "D"
];

// flat array of all cards on table
var cards_on_table = new Array();

// throw error messages
var error_dup = "Attepting to deal a card already in play";

function deal_card(card){
    // adds the card passed to the cards_on_table
    if(cards_on_table.length > 0){
        for(var i = 0; i < cards_on_table.length; i++){
            if(card === cards_on_table[i]){
                console.log(cards_on_table, card);
                throw(error_dup);
            }
        }
    }
    cards_on_table.push(card);
}

function rand(max, min){
    // returns a random number between
    // min (inclusive) and max (exclusive)
    return Math.floor(Math.random() * (max - min) + min);
}

function is_a_duplicate_card(card){
    // is this card already dealt?
    for(var i = 0; i < cards_on_table.length; i++){
        if(card === cards_on_table[i]){
            return true;
        }
    }
    return false;
}

function generate_card(){
    // returns one randomly generated card.
    // choose a random card number
    var rand_num = card_numbers[rand((card_numbers.length - 1), 0)];
    // choose a random suit
    var rand_suit = suits[rand((suits.length - 1), 0)];
    var card = rand_num + rand_suit;
    return card;
}

function hands(number_of_players){
    /* Returns an array of hands for each player.
     * ie. [["2H", "3C"], ["KD", "KS"]]
     */
    var hands_to_be_dealt = new Array();
    // for each player
    for(var i = 0; i < number_of_players; i++){
        var player_hand = new Array();
        // each player gets two cards
        for(var y = 0; y < 2; y++){
            var card = generate_card(); 
            if(cards_on_table.length > 0){
                while(is_a_duplicate_card(card)){
                    card = generate_card();
                }
            } 
            deal_card(card);
            player_hand.push(card);
        }
        hands_to_be_dealt.push(player_hand);
    }
    for(var i = 0; i < number_of_players; i++){
        console.log(hands_to_be_dealt[i]);
    }
    return hands_to_be_dealt;
}

function deal_flop(cards_on_table){
   // takes a flat array of cards on the table
   // returns a flop ie ['AS', 'QC', '2D']         
   var flop = new Array();
   for(var i = 0; i < 3; i++){
       var card = generate_card();
       
   }
}

hands(4);
