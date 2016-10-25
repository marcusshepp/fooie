package com.marcusshep.tictactoe;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.*;
import android.util.Log;


public class MainActivity extends AppCompatActivity {

    private static Button top_left_btn;
    private static Button top_mid_btn;
    private static Button top_right_btn;

    private static Button mid_left_btn;
    private static Button mid_mid_btn;
    private static Button mid_right_btn;

    private static Button bot_left_btn;
    private static Button bot_mid_btn;
    private static Button bot_right_btn;

    private static Button new_game_btn;

    private static TextView game_status_text;
    private static String winner;

    private static String player_mark = "X";
    private static String other_player_mark = "O";

    private static boolean player_turn = true;
    private static boolean endgame;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        top_left_btn = (Button) findViewById(R.id.top_left_btn);
        top_mid_btn = (Button) findViewById(R.id.top_mid_btn);
        top_right_btn = (Button) findViewById(R.id.top_right_btn);

        mid_left_btn = (Button) findViewById(R.id.mid_left_btn);
        mid_mid_btn = (Button) findViewById(R.id.mid_mid_btn);
        mid_right_btn = (Button) findViewById(R.id.mid_right_btn);

        bot_left_btn = (Button) findViewById(R.id.bot_left_btn);
        bot_mid_btn = (Button) findViewById(R.id.bot_mid_btn);
        bot_right_btn = (Button) findViewById(R.id.bot_right_btn);


        game_status_text = (TextView) findViewById(R.id.game_status_text);
        game_status_text.setText("");
        new_game_btn = (Button) findViewById(R.id.new_game_btn);

        top_left_btn.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v){
                if(top_left_btn.getText().toString().isEmpty()){
                    if(!endgame){
                        if (player_turn){
                            top_left_btn.setText(player_mark);
                        } else {
                            top_left_btn.setText(other_player_mark);
                        }
                        change_turn();
                    }
                }
            }
        });

        top_mid_btn.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v){
                if(top_mid_btn.getText().toString().isEmpty()){
                    if(!endgame){
                        if (player_turn){
                            top_mid_btn.setText(player_mark);
                        } else {
                            top_mid_btn.setText(other_player_mark);
                        }
                        change_turn();
                    }
                }
            }
        });

        top_right_btn.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v){
                if(top_right_btn.getText().toString().isEmpty()){
                    if(!endgame){
                        if (player_turn){
                            top_right_btn.setText(player_mark);
                        } else {
                            top_right_btn.setText(other_player_mark);
                        }
                        change_turn();
                    }
                }
            }
        });

        mid_left_btn.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v){
                if(mid_left_btn.getText().toString().isEmpty()){
                    if(!endgame){
                        if (player_turn){
                            mid_left_btn.setText(player_mark);
                        } else {
                            mid_left_btn.setText(other_player_mark);
                        }
                        change_turn();
                    }
                }
            }
        });

        mid_mid_btn.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v){
                if(mid_mid_btn.getText().toString().isEmpty()){
                    if(!endgame){
                        if (player_turn){
                            mid_mid_btn.setText(player_mark);
                        } else {
                            mid_mid_btn.setText(other_player_mark);
                        }
                        change_turn();
                    }
                }
            }
        });

        mid_right_btn.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v){
                if(mid_right_btn.getText().toString().isEmpty()){
                    if(!endgame){
                        if (player_turn){
                            mid_right_btn.setText(player_mark);
                        } else {
                            mid_right_btn.setText(other_player_mark);
                        }
                        change_turn();
                    }
                }
            }
        });

        bot_left_btn.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v){
                if(bot_left_btn.getText().toString().isEmpty()){
                    if(!endgame){
                        if (player_turn){
                            bot_left_btn.setText(player_mark);
                        } else {
                            bot_left_btn.setText(other_player_mark);
                        }
                        change_turn();
                    }
                }
            }
        });

        bot_mid_btn.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                if(bot_mid_btn.getText().toString().isEmpty()){
                    if(!endgame){
                        if (player_turn){
                            bot_mid_btn.setText(player_mark);
                        } else {
                            bot_mid_btn.setText(other_player_mark);
                        }
                        change_turn();
                    }
                }
            }
        });

        bot_right_btn.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v){
                if(bot_right_btn.getText().toString().isEmpty()){
                    if(!endgame){
                        if (player_turn){
                            bot_right_btn.setText(player_mark);
                        } else {
                            bot_right_btn.setText(other_player_mark);
                        }
                        change_turn();
                    }
                }
            }
        });

        new_game_btn.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v){
                top_left_btn.setText("");
                top_mid_btn.setText("");
                top_right_btn.setText("");
                mid_left_btn.setText("");
                mid_mid_btn.setText("");
                mid_right_btn.setText("");
                bot_left_btn.setText("");
                bot_mid_btn.setText("");
                bot_right_btn.setText("");
                endgame = false;
                set_display("New Game");
            }
        });
    }

    public static boolean is_a_line(String one, String two, String three){
        boolean boo = false;
        if (one != "" && two != "" && one == two){
            if (three != "" && two == three){
                boo = true;
            }
        }
        return boo;
    }

    public static String[] all_btn_texts(){
        String a1 = top_left_btn.getText().toString();
        String a2 = top_mid_btn.getText().toString();
        String a3 = top_right_btn.getText().toString();
        String b1 = mid_left_btn.getText().toString();
        String b2 = mid_mid_btn.getText().toString();
        String b3 = mid_right_btn.getText().toString();
        String c1 = bot_left_btn.getText().toString();
        String c2 = bot_mid_btn.getText().toString();
        String c3 = bot_right_btn.getText().toString();
        String[] texts = {
                a1,
                a2,
                a3,
                b1,
                b2,
                b3,
                c1,
                c2,
                c3
        };
        return texts;
    }

    public static boolean tie_game(){
        String[] texts = all_btn_texts();
        int empties = 9;
        boolean is_tie = false;
        for(int i = 0; i < texts.length; i++){
            if(texts[i] == "X" || texts[i] == "O"){
                empties -= 1;
            }
        }
        if (empties < 2 ){
            if (!endgame){
                is_tie = true;
                endgame = true;
            }
        }
        return is_tie;
    }

    public static void check_for_endgame(){
        String a1 = top_left_btn.getText().toString();
        String a2 = top_mid_btn.getText().toString();
        String a3 = top_right_btn.getText().toString();
        String b1 = mid_left_btn.getText().toString();
        String b2 = mid_mid_btn.getText().toString();
        String b3 = mid_right_btn.getText().toString();
        String c1 = bot_left_btn.getText().toString();
        String c2 = bot_mid_btn.getText().toString();
        String c3 = bot_right_btn.getText().toString();
        if(is_a_line(a1, b1, c1)){
            endgame = true;
            winner = a1;
        }
        if(is_a_line(a1, b2, c3)){
            endgame = true;
            winner = a1;
        }
        if(is_a_line(a1, a2, a3)){
            endgame = true;
            winner = a1;
        }
        if(is_a_line(b1, b2, b3)){
            endgame = true;
            winner = b1;
        }
        if(is_a_line(c1, c2, c3)){
            endgame = true;
            winner = c1;
        }
        if(is_a_line(c1, b2, a3)){
            endgame = true;
            winner = c1;
        }
        if(is_a_line(a2, b2, c2)){
            endgame = true;
            winner = a2;
        }
        if(is_a_line(a3, b3, c3)){
            endgame = true;
            winner = a3;
        }
    }

    public static void change_turn(){
        if (player_turn){
            set_display("Turn: O");
        } else { set_display("Turn: X"); }
        check_for_endgame();
        if (tie_game()){
            set_display("Tie\nGame!");
        }
        if (endgame){
            set_display(String.format("winner is: %s", winner));
        }

        player_turn = !player_turn;
    }

    public static void set_display(String text){
        game_status_text.setText(text);
    }

}
