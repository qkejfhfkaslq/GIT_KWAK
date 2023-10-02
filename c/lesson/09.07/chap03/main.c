#include <stdio.h>

int Encrypt_Text_Func(int plainText, int key){
    int encryptText =0;

    encryptText = plainText ^ key;

    return encryptText;
}
int Decrypt_Text_Func(int encryptText, int key){
    int decryptText =0;

    decryptText = encryptText ^ key;

    return decryptText;
}

int main(void){
    int plainText = 0;
    int encrypt_text =0;
    int decrypt_text =0;
    int key = 0;
    key = 23456;
    plainText = 12345;

    printf("plainText: %d\n",plainText);

    encrypt_text = Encrypt_Text_Func(plainText,key);
    printf("encrypt: %d\n",encrypt_text);

    decrypt_text = Decrypt_Text_Func(encrypt_text,key);
    printf("decrypt: %d\n",decrypt_text);

    return 0;
}
