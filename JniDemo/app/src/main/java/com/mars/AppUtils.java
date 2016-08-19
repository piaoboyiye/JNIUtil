package com.mars;


import android.text.TextUtils;

import java.security.MessageDigest;

public class AppUtils {

    public static String md5Encrypt(String string) {
        try {
            if (TextUtils.isEmpty(string)) {
                return null;
            }
            byte[] hash = null;
            hash = MessageDigest.getInstance("MD5").digest(string.getBytes("UTF-8"));
            StringBuilder hex = new StringBuilder(hash.length * 2);
            for (byte b : hash) {
                int i = (b & 0xFF);
                if (i < 0x10) hex.append('0');
                hex.append(Integer.toHexString(i));
            }
            return hex.toString();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return null;
    }
}
