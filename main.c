#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main() {

    // strLen
    printf("✅TESTS strLen()\n");
    int len = strLen("");
    int len2 = strLen("h");
    int len3 = strLen("123456789qwertyuiopasdfghjklzxcvbnm,.;:");
    printf("🔹 strLen(\"\") -> \"%i\"\n", len);
    printf("🔹 strLen(\"h\") -> \"%i\"\n", len2);
    printf("🔹 strLen(\"123456789qwertyuiopasdfghjklzxcvbnm,.;:\") -> \"%i\"\n", len3);
    printf("\n");

    // strDup
    printf("✅TESTS strDup()\n");
    char* dup = strDup("");
    char* dup2 = strDup("h");
    char* dup3 = strDup("123456789qwertyuiopasdfghjklzxcvbnm,.;:");
    printf("🔹 strDup(\"\") -> \"%s\"\n", dup);
    printf("🔹 strDup(\"h\") -> \"%s\"\n", dup2);
    printf("🔹 strDup(\"123456789qwertyuiopasdfghjklzxcvbnm,.;:\") -> \"%s\"\n", dup3);
    free(dup);
    free(dup2);
    free(dup3);
    printf("\n");

    // wheel
    printf("✅TESTS makeWheelFromString()\n");
    struct wheel* w = makeWheelFromString("Q");
    struct wheel* w1 = makeWheelFromString("QWERTYUIOP");
    struct wheel* w2 = makeWheelFromString("QWERTYUIOPASDFGHJKLMNBVCXZ");
    struct wheel* w3 = makeWheelFromString("SUTIL");
    printf("🔹");
    wheelPrint(w);
    printf("🔹");
    wheelPrint(w1);
    printf("🔹");
    wheelPrint(w2);
    printf("🔹");
    wheelPrint(w3);
    printf("\n");
    
    printf("✅TESTS setWheel()\n");
    setWheel(w1, 5);
    printf("🔹");
    wheelPrint(w1);
    printf("\n");
    
    printf("✅TESTS rotateWheel()\n");
    rotateWheel(w2, 1);
    printf("🔹");
    wheelPrint(w2);
    setWheel(w2, 0);
    rotateWheel(w2, 26);
    printf("🔹");
    wheelPrint(w2);
    setWheel(w2, 0);
    rotateWheel(w3, 26);
    printf("🔹");
    wheelPrint(w3);
    setWheel(w3, 0);
    rotateWheel(w, 26);
    printf("🔹");
    wheelPrint(w);
    
    printf("\n");
    

    wheelDelete(w);
    wheelDelete(w1);
    wheelDelete(w2);
    wheelDelete(w3);

    // littleEnigma
    //printf("✅TESTS littleEnigmaNew\n");
    char* alphabetPermutation1[2];
    char* alphabetPermutation2[1];
    char* alphabetPermutation3[3];
    char* alphabetPermutation4[5];
    char* alphabetPermutation5[8];
    alphabetPermutation1[0] = "JGDQOXUSCAMIFRVTPNEWKBLZYH";
    alphabetPermutation1[1] = "NTZPSFBOKMWRCJDIVLAEYUXHGQ";
    
    alphabetPermutation2[0] = "JGDQOXUSCAMIFRVTPNEWKBLZYH";
    
    for (int i = 0; i < 3; i++){
    	alphabetPermutation3[i] = "JGDQOXUSCAMIFRVTPNEWKBLZYH";
    }
    
    for (int i = 0; i < 5; i++){
    	alphabetPermutation4[i] = "JGDQOXUSCAMIFRVTPNEWKBLZYH";
    }
    
    for (int i = 0; i < 8; i++){
    	alphabetPermutation5[i] = "JGDQOXUSCAMIFRVTPNEWKBLZYH";
    }
    struct littleEnigma* le1 = littleEnigmaNew(alphabetPermutation1, 2);
    struct littleEnigma* le2 = littleEnigmaNew(alphabetPermutation2, 1);
    struct littleEnigma* le3 = littleEnigmaNew(alphabetPermutation3, 3);
    struct littleEnigma* le4 = littleEnigmaNew(alphabetPermutation4, 5);
    struct littleEnigma* le5 = littleEnigmaNew(alphabetPermutation5, 8);
    printf("\n");
    
    //printf("✅TEST littleEnigmaSet()\n");
    int password1[2] = { 3, 5 };
    int password2[1] = { 0 };
    int password3[3] = { 3, 5, 6 };
    int password4[5] = { 3, 5, 6, 7, 8 };
    int password5[8] = { 3, 5, 6, 7, 8, 9, 10, 11 };
    
    littleEnigmaSet(le1, password1);
    littleEnigmaSet(le2, password2);
    littleEnigmaSet(le3, password3);
    littleEnigmaSet(le4, password4);
    littleEnigmaSet(le5, password5);
    /*
    littleEnigmaPrint(le1);
    littleEnigmaPrint(le2);
    littleEnigmaPrint(le3);
    littleEnigmaPrint(le4);
    littleEnigmaPrint(le5);
    */
    //printf("\n\n");
    
    printf("✅TESTS littleEnigmaEncrypt() \n");
    char* text1 = "";
    char* text2 = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
    char* text3 = "ARBOLITOSS";
    char* text4 = "ARBOLITOSS";
    char* text5 = "ARBOLITOSS";
    char* code1 = littleEnigmaEncrypt(le1, text1);
    char* code2 = littleEnigmaEncrypt(le2, text2);
    char* code3 = littleEnigmaEncrypt(le3, text3);
    char* code4 = littleEnigmaEncrypt(le4, text4);
    char* code5 = littleEnigmaEncrypt(le5, text5);
    printf("🔹 %s -> %s\n\n", text1, code1);
    printf("🔹 %s -> %s\n\n", text2, code2);
    printf("🔹 %s -> %s\n\n", text3, code3);
    printf("🔹 %s -> %s\n\n", text4, code4);
    printf("🔹 %s -> %s\n\n", text5, code5);

    littleEnigmaSet(le1, password1);
    littleEnigmaSet(le2, password2);
    littleEnigmaSet(le3, password3);
    littleEnigmaSet(le4, password4);
    littleEnigmaSet(le5, password5);
    //printf("\n\n");

    printf("✅TESTS littleEnigmaDecrypt()\n");
    char* decode1 = littleEnigmaDecrypt(le1, code1);
    char* decode2 = littleEnigmaDecrypt(le2, code2);
    char* decode3 = littleEnigmaDecrypt(le3, code3);
    char* decode4 = littleEnigmaDecrypt(le4, code4);
    char* decode5 = littleEnigmaDecrypt(le5, code5);
    printf("🔹 %s -> %s -> %s\n\n", text1, code1, decode1);
    printf("🔹 %s -> %s -> %s\n\n", text2, code2, decode2);
    printf("🔹 %s -> %s -> %s\n\n", text3, code3, decode3);
    printf("🔹 %s -> %s -> %s\n\n", text4, code4, decode4);
    printf("🔹 %s -> %s -> %s\n\n", text5, code5, decode5);
/*
    if(code) free(code);
    if(decode) free(decode);

    littleEnigmaDelete(le);
*/    
    littleEnigmaDelete(le1);
    littleEnigmaDelete(le2);
    littleEnigmaDelete(le3);
    littleEnigmaDelete(le4);
    littleEnigmaDelete(le5);
    
    free(code1);
    free(code2);
    free(code3);
    free(code4);
    free(code5);
    free(decode1);
    free(decode2);
    free(decode3);
    free(decode4);
    free(decode5);
    
    
    return 0;
}
