package com.mars;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;

import com.mars.jniutils.R;

public class MainActivity extends Activity {
    TextView tv1, tv2;
    String value = "123456";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        tv1 = (TextView) findViewById(R.id.tv1);
        tv2 = (TextView) findViewById(R.id.tv2);
//        tv1.setText(AppUtils.md5Encrypt(value) + "\n" + AppUtils.md5Encrypt(value + "!WxtrkbcTrxwtfd$"));
        try {
//            tv2.setText(JniUtils.method1(value) + "\n" + JniUtils.method2(value));
            String xxtea = JniUtils.e1(value);
            tv1.setText(xxtea);
            tv2.setText(JniUtils.d1(xxtea));
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
