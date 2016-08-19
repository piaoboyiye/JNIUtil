package com.mars;


public class JniUtils {
    static {
        try {
            System.loadLibrary("JniUtils");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    //md5加密
    public static native String method1(String str);

    //md5加密 加盐
    public static native String method2(String str);

    //xxtea加密
    public static native String d1(String str);

    //xxtea解密
    public static native String e1(String str);


}
