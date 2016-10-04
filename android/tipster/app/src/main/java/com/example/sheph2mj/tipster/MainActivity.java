package com.example.sheph2mj.tipster;

import android.content.Intent;
import android.icu.text.DecimalFormat;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.AdapterView.OnItemSelectedListener;
import android.widget.Toast;
import android.view.View;
import android.view.KeyEvent;
import android.util.Log;
import android.widget.TextView;
import android.widget.Button;
import android.text.Editable;
import android.text.method.KeyListener;
import android.text.TextWatcher;
import android.content.Context;


public class MainActivity extends AppCompatActivity implements OnItemSelectedListener {

    private EditText bill_amount;
    private TextView final_bill_value;
    private CheckBox divide_bool;
    private EditText number_of_people;
    private Spinner percent_spinner;
    private Button submit_button;
    private double percent_divide;
    private double bill_amount_value_double;
    private String bill_amount_value_string;
    private String number_of_people_string;
    private int number_of_people_value;
    private static boolean divide_bill;
    private boolean submitted;

    private TextWatcher bill_amount_tw = new TextWatcher() {
        public void afterTextChanged(Editable s) {
            Log.d("TEXT WATCH", "after");
            bill_amount_value_double = Double.parseDouble(s.toString());
            bill_amount_value_string = s.toString();
            set_bill_display("Bill: " + bill_amount_value_string);
        }

        public void beforeTextChanged(CharSequence s, int start, int count, int after) {
            Log.d("TEXT WATCH", "before");
        }

        public void onTextChanged(CharSequence s, int start, int before, int count) {
            Log.d("TEXT WATCH", "changed");
        }
    };

    private TextWatcher number_of_people_tw = new TextWatcher() {
        public void afterTextChanged(Editable s) {
            if (s.toString().length() > 0) {
                number_of_people_string = s.toString();
                number_of_people_value = Integer.parseInt(s.toString());
            }

        }

        public void beforeTextChanged(CharSequence s, int start, int count, int after) {
            Log.d("TEXT WATCH", "before");
        }

        public void onTextChanged(CharSequence s, int start, int before, int count) {
            Log.d("TEXT WATCH", "changed");
        }
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        bill_amount = (EditText) findViewById(R.id.bill_amount);
        final_bill_value = (TextView) findViewById(R.id.final_bill_amount);
        divide_bool = (CheckBox) findViewById(R.id.divide_bool);
        number_of_people = (EditText) findViewById(R.id.number_of_people);
        percent_spinner = (Spinner) findViewById(R.id.percent_spinner);
        submit_button = (Button) findViewById(R.id.submit_btn);


        // set up spinner with default values
        ArrayAdapter<CharSequence> adapter = ArrayAdapter.createFromResource(
                this, R.array.tip_types, android.R.layout.simple_spinner_dropdown_item
        );
        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        percent_spinner.setAdapter(adapter);
        percent_spinner.setOnItemSelectedListener(this);


        // click checkbox
        divide_bool.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Log.d("BUTTON CLICK", "clicked");
                // Is the view now checked?
                boolean checked = ((CheckBox) v).isChecked();

                // Check which checkbox was clicked
                switch (v.getId()) {
                    case R.id.divide_bool:
                        if (checked)
                            divide_bill = true;
                        else
                            divide_bill = false;
                        break;
                }
                if (divide_bill) {
                    Log.d("CHECKBOX", "checked");
                } else {
                    Log.d("CHECKBOX", "Uunchecked");
                }
            }
        });

        // final submit action
        submit_button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                boolean valid = true;
                Log.d("BUTTON CLICK", "clicked");
                if (submitted) {
                    set_bill_display("0.00");
                }
                if (bill_amount.getText().toString().length() > 0) {
                    double foo = percent_divide / 100;
                    double _bill_amount_value_double = bill_amount_value_double * foo;
                    if (divide_bill){
                        if(number_of_people_string.length() > 0){
                            if(Integer.parseInt(number_of_people_string) > 20){
                                display_toast("Number of people must be less than twenty.");
                                valid = false;
                            } else {
                                _bill_amount_value_double = _bill_amount_value_double / number_of_people_value;
                            }

                        }
                    }
                    bill_amount_value_string = String.format("%.2f", _bill_amount_value_double);
                    if (divide_bill) {
                        bill_amount_value_string += " each";
                    }
                    if (valid) {
                        set_bill_display(bill_amount_value_string);
                    } else {
                        set_bill_display("Invalid Input!");
                    }

                } else {
                    display_toast("Please enter value greater than zero.");
                }
                submitted = true;
            }
        });

        // bill amount on key
        bill_amount.addTextChangedListener(bill_amount_tw);

        number_of_people.addTextChangedListener(number_of_people_tw);

    }


    @Override
    public void onItemSelected(AdapterView<?> parent, View view, int pos, long id) {

        String selected_value = parent.getItemAtPosition(pos).toString();
        selected_value = selected_value.replace("%", "");
        percent_divide = Integer.parseInt(selected_value);
        Log.d("onitemselect", selected_value);

    }


    @Override
    public void onNothingSelected(AdapterView<?> parent) {

        // foo
    }

    public void set_bill_display(String text) {
        final_bill_value.setText(text);
    }

    public void display_toast(String text) {
        Context context = getApplicationContext();
        int duration = Toast.LENGTH_SHORT;
        Toast toast = Toast.makeText(context, text, duration);
        toast.show();
    }
}
