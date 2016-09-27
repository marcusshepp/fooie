package com.example.sheph2mj.tipster;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.AdapterView.OnItemSelectedListener;
import android.view.View;
import android.util.Log;
import android.widget.TextView;
import android.widget.Button;
import android.text.Editable;


public class MainActivity extends AppCompatActivity implements OnItemSelectedListener {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // set up spinner with default values
        Spinner spinner = (Spinner) findViewById(R.id.spinner);
        ArrayAdapter<CharSequence> adapter = ArrayAdapter.createFromResource(
                this, R.array.tip_types, android.R.layout.simple_spinner_dropdown_item
        );
        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        spinner.setAdapter(adapter);

        spinner.setOnItemSelectedListener(this);

        final Button submit_button = (Button) findViewById(R.id.submit);
        submit_button.setOnClickListener(new View.OnClickListener(){
              @Override
            public void onClick(View v){
                  Log.d("BUTTON CLICK", "clicked");
                  TextView tip_amount = (TextView) findViewById(R.id.tip_amount);
                  EditText bill_amount = (EditText) findViewById(R.id.bill_amount);
            }
        });
    }


    @Override
    public void onItemSelected(AdapterView<?> parent, View view, int pos, long id){

        String selected_value = parent.getItemAtPosition(pos).toString();
        Log.d("SELECTED", selected_value);
        TextView tip_amount = (TextView) findViewById(R.id.tip_amount);
        EditText bill_amount = (EditText) findViewById(R.id.bill_amount);
        if (bill_amount.getText().toString().length() > 0){
            double bill_amount_value = Double.parseDouble(bill_amount.getText().toString());
            Log.d("AMOUNT", String.valueOf(bill_amount_value));
        }
    }


    @Override
    public void onNothingSelected(AdapterView<?> parent){

        // foo
    }
}
