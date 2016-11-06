package com.marcusshep.gotmoves;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;

import com.mashape.unirest.http.Unirest;
import com.mashape.unirest.http.exceptions.UnirestException;

import org.json.simple.parser.JSONParser;

import java.io.InputStream;
import java.net.URL;
import java.net.URLConnection;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        String urlString = "https://jsonplaceholder.typicode.com/posts/1";
        try {
            Unirest.get(urlString).asJson();
        } catch (UnirestException e) {
            e.printStackTrace();
        }
    }



}
