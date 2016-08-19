#include "com_mars_JniUtils.h"
#include "md5.h"
#include "xxtea.h"
#include "base64.h"
#include <stdio.h>

#define MD5_KEY "!WxtrkbcTrxwtfd$"
#define XXTEA_KEY "sfe023f_9fd&fwfl"

JNIEXPORT jstring JNICALL Java_com_mars_JniUtils_d1
        (JNIEnv *env, jclass obj, jstring str) {
    char *jstr = (char *) (*env)->GetStringUTFChars(env, str, JNI_FALSE);
    size_t len, len2;
    unsigned char *base64_data = base64_decode(jstr, &len);
    char *decrypt_data = xxtea_decrypt(base64_data, len, XXTEA_KEY, &len2);
    free(base64_data);
    free(jstr);
    return (*env)->NewStringUTF(env, decrypt_data);
}

JNIEXPORT jstring JNICALL Java_com_mars_JniUtils_e1
        (JNIEnv *env, jclass obj, jstring str) {
    char *jstr = (char *) (*env)->GetStringUTFChars(env, str, JNI_FALSE);
    size_t len;
    unsigned char *encrypt_data = xxtea_encrypt(jstr, strlen(jstr), XXTEA_KEY, &len);
    char *base64_data = base64_encode(encrypt_data, len);
    free(encrypt_data);
    free(jstr);
    return (*env)->NewStringUTF(env, base64_data);
}

JNIEXPORT jstring JNICALL Java_com_mars_JniUtils_method1
        (JNIEnv *env, jclass obj, jstring str) {
    char *jstr = (char *) (*env)->GetStringUTFChars(env, str, JNI_FALSE);
    MD5 md5;
    unsigned char digest[16];
    MD5Open(&md5);
    MD5Digest(&md5, jstr, strlen(jstr));
    MD5Close(&md5, digest);
    int i = 0;
    char buf[33];
    for (i = 0; i < 16; i++) {
        sprintf(buf + i * 2, "%02x", digest[i]);
    }
    free(digest);
    free(jstr);
    return (*env)->NewStringUTF(env, buf);
}

JNIEXPORT jstring JNICALL Java_com_mars_JniUtils_method2
        (JNIEnv *env, jclass obj, jstring str) {
    char *jstr = (char *) (*env)->GetStringUTFChars(env, str, JNI_FALSE);
    strcat(jstr, MD5_KEY);
    MD5 md5;
    unsigned char digest[16];
    MD5Open(&md5);
    MD5Digest(&md5, jstr, strlen(jstr));
    MD5Close(&md5, digest);
    int i = 0;
    char buf[33];
    for (i = 0; i < 16; i++) {
        sprintf(buf + i * 2, "%02x", digest[i]);
    }
    free(digest);
    free(jstr);
    return (*env)->NewStringUTF(env, buf);
}

