package com.marcusshep.gotmoves;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.Button;
import android.widget.LinearLayout;

import com.google.gson.Gson;
import com.google.gson.reflect.TypeToken;

import java.io.IOException;
import java.io.InputStream;
import java.net.URL;
import java.net.URLConnection;
import java.util.ArrayList;
import java.util.List;


public class MainActivity extends AppCompatActivity {

    public class Category {
        String date_created;
        String description;
        String name;
    }


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Log.d("FOOOO", this.load_json());
        ArrayList<Category> categories = this.categories();
        int cate_length = categories.size();
        LinearLayout layout = (LinearLayout) findViewById(R.id.layout);
        Button[] category_btns = new Button[cate_length];
        int i = 0;
        for(Category c : categories){
            category_btns[i] = new Button(this);
            category_btns[i].setText(c.name);
            layout.addView(category_btns[i]);
            i++;
        }
    }

    public String load_json(){
        String json = null;
        try{
            InputStream is = this.getAssets().open("categories.json");
            int size = is.available();
            byte[] buffer = new byte[size];
            is.read(buffer);
            is.close();
            json = new String(buffer, "UTF-8");
        }catch(IOException e){
            e.printStackTrace();
            return null;
        }
        return json;
    }

    public ArrayList<Category> categories(){
        String json = this.load_json();
        Gson gson = new Gson();
        ArrayList<Category> categories = null;
        try{
            categories = gson.fromJson(json, new TypeToken<List<Category>>(){}.getType());
            Log.d("CATEGORIES: ", categories.toString());
        } catch (Exception e){
            e.printStackTrace();
        }
        return categories;
    }

}
