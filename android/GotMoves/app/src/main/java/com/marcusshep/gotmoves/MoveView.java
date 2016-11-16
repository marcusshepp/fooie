package com.marcusshep.gotmoves;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.content.Intent;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Toast;

import com.google.android.youtube.player.YouTubeBaseActivity;
import com.google.android.youtube.player.YouTubeInitializationResult;
import com.google.android.youtube.player.YouTubePlayer;
import com.google.android.youtube.player.YouTubePlayer.Provider;
import com.google.android.youtube.player.YouTubePlayerView;

public class MoveView extends YouTubeBaseActivity implements YouTubePlayer.OnInitializedListener {

    private static final int RECOVERY_REQUEST = 1;
    public static final String API_KEY = "AIzaSyBspiJmyI8K68YMeKFZ2R6XLDN6Wa0FWeg";

    private YouTubePlayerView youtube_view;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_move_view);

        youtube_view = (YouTubePlayerView) findViewById(R.id.player_view);
        youtube_view.initialize(API_KEY, this);
    }

    @Override
    public void onInitializationSuccess(Provider provider, YouTubePlayer player, boolean was_restored){
        if(!was_restored){
            player.cueVideo("fhWaJi1Hsfo");
        }
    }
    @Override
    public void onInitializationFailure(Provider provider, YouTubeInitializationResult errorReason) {
        if (errorReason.isUserRecoverableError()) {
            errorReason.getErrorDialog(this, RECOVERY_REQUEST).show();
        } else {
            String error = String.format("ERROR", errorReason.toString());
            Toast.makeText(this, error, Toast.LENGTH_LONG).show();
        }
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {

    }

    protected Provider getYouTubePlayerProvider() {
        return youtube_view;
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        return true;
    }

}
