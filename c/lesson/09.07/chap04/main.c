#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

int Encrypted_file(){
    FILE *origin_file;
    FILE *temp_file;
    
    char line[1024];
    int modifiedLine =0;
    int key = 0;
    key = 3456;
    origin_file = fopen("plain.txt","r");
    temp_file = fopen("encrypt.txt","w");

    if (origin_file == NULL || temp_file == NULL){
        perror("fail");
        return 1;
    }
    while(fgets(line,sizeof(line),origin_file) !=NULL){
        modifiedLine = Encrypt_Text_Func(atoi(line),key);
        fprintf(temp_file, "%d\n", modifiedLine);
    }
    fclose(origin_file);
    fclose(temp_file);
    return 0;
}
 
int Decrypted_file(){
    FILE *origin_file;
    FILE *temp_file;
    
    char line[1024];
    int modifiedLine =0;
    int key = 0;
    key = 3456;
    origin_file = fopen("encrypt.txt","r");
    temp_file = fopen("decrypt.txt","w");

    if (origin_file == NULL || temp_file == NULL){
        perror("fail");
        return 1;
    }
    while(fgets(line,sizeof(line),origin_file) !=NULL){
        modifiedLine = Decrypt_Text_Func(atoi(line),key);
        fprintf(temp_file, "%d\n", modifiedLine);
    }

    fclose(origin_file);
    fclose(temp_file);
    return 0;
}

int main(void){
    Encrypted_file();
    Decrypted_file();
    return 0;
}
