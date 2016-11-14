package com.marcusshep.gotmoves;

import android.content.Context;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

public class MoveList extends AppCompatActivity {

    private static final String CATEGORY_EXTRA = "com.marcusshep.gotmoves.category_id";

    public static void start(Context context, String category_id){
        Intent intent = new Intent(context, MoveList.class);
        intent.putExtra(CATEGORY_EXTRA, category_id);
        context.startActivity(intent);
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_move_list);
        Intent intent = this.getIntent();
        String category_id = intent.getStringExtra(CATEGORY_EXTRA);
        Log.d("CATEGORY ID: ", category_id);
        TextView title = (TextView) findViewById(R.id.title);
        title.setText(category_id);
    }



}
