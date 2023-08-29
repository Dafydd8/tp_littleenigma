#include "utils.h"

int strLen(char* src) {
	int i = 0;
    	while(src[i]!='\0'){
    		i++;
    	}
    	return i;
}

char* strDup(char* src) {
	int len = strLen(src) + 1;
	int i = 0;
	char* res = (char*)malloc(sizeof(char)*len);
	while (i<len){
		res[i] = src[i];
		i++;
	}
  	return res;
}

struct littleEnigma* littleEnigmaNew(char** alphabetPermutation, int count){
	struct littleEnigma* res = (struct littleEnigma*)malloc(sizeof(struct littleEnigma));
	res->wheelsCount = count;

	res->wheels = (struct wheel**)malloc(sizeof(struct wheel*)*count);
	
	for (int i = 0; i < count; i++){
		(res->wheels)[i] = makeWheelFromString(alphabetPermutation[i]);
	}
	//wheelPrint((res->wheels)[0]);
	//wheelPrint((res->wheels)[1]);
	return res;
}

void littleEnigmaSet(struct littleEnigma* le, int* password) {
	int len = le->wheelsCount;
	int i = 0;
	struct wheel* curr;
	while (i < len){
		curr = (le->wheels)[i];
		setWheel(curr, password[i]);
		i++;
	}
    	return;
}

char* littleEnigmaEncrypt(struct littleEnigma* le, char* text){
	int len = strLen(text);
	int i = 0;
	char* res = strDup(text);
	while (i < len){
		res[i] = encryptOneLetter(le, text[i]);
		i++;
	}
	return res;
}

char* littleEnigmaDecrypt(struct littleEnigma* le, char* code) {
	char* res = strDup(code);
	int len = strLen(code);
	for (int i = 0; i < len; i++){
		res[i] = decryptOneLetter(le, code[i]);
	}
	
	return res;
}

void littleEnigmaDelete(struct littleEnigma* le) {
	int len = le->wheelsCount;
	struct wheel* curr;
	for (int i = 0; i < len; i++){
		curr = (le->wheels)[i];
		wheelDelete(curr);
	}
	free(le->wheels);
	free(le);
	return;
}

void littleEnigmaPrint(struct littleEnigma* le) {
    for(int i=0; i<le->wheelsCount; i++) {
        wheelPrint(le->wheels[i]);
        printf("\n");
    }
}

struct wheel* makeWheelFromString(char* alphabetPermutation) {
    	int len = strLen(alphabetPermutation);
	int i = 0;
	struct wheel* res = (struct wheel*)malloc(sizeof(struct wheel));
	res->alphabet = strDup(alphabetPermutation);
	res->count = len;
	
	struct letter* prev;
	struct letter* curr = (struct letter*)malloc(sizeof(struct letter));
	curr->letter = alphabetPermutation[i];
	curr->position = i;
	res->first = curr;
	prev = curr;
	i++;
	
	struct letter* primero = curr;
	
	while(i < len){
		curr = (struct letter*)malloc(sizeof(struct letter));
		curr->letter = alphabetPermutation[i];
		curr->position = i;
		prev->next = curr;
		prev = prev->next;
		i++;
	}
	prev->next = primero;
	

    return res;
}

void setWheel(struct wheel* w, int position) {
    struct letter* current = w->first;
    while(current->position != position) {
        current = current->next;
    }
    w->first = current;   
}

void rotateWheel(struct wheel* w, int steps) {
	int i = 0;
	struct letter* curr = w->first;
	while (i < steps){
		curr = curr->next;
		i++;
	}
	w->first = curr;
	return;
}

void rotateWheels(struct wheel** wheels, int wheelsCount) {
	int i = 0;
	int seguir = 1;
	struct wheel* curr_wheel;
	while (i < wheelsCount && seguir){
		curr_wheel = wheels[i];
		rotateWheel(curr_wheel, 1);
		if ((curr_wheel->first)->position != 0){
			seguir = 0;
		}
		i++;
	}
	
	return;
}

void wheelDelete(struct wheel* w) {
	struct letter* curr = w->first;
	struct letter* prev;
	for(int i = 0; i < w->count; i++){
		prev = curr;
		curr = curr->next;
		free(prev);
	}
	free(w->alphabet);
	free(w);
	return;
}

void wheelPrint(struct wheel* w) {
    printf("%s: ", w->alphabet);
    struct letter* current = w->first;
    int i = 0;
    while(i<w->count) {
        printf("(%c-%i)", current->letter, current->position);
        current = current->next;
        i++;
    }
    printf("\n");
}

int letterToIndex(char letter) {
    if('A' <= letter && letter <= 'Z') return letter-'A';
    return 0;
}

char indexToletter(int index) {
    if(0 <= index && index <= 25) return index+'A';
    return 0;
}

char encryptWheel(struct wheel* w, char letter) {
    int index =  letterToIndex(letter);
    struct letter* current = w->first;
    int i = 0;
    while(i<index) {
        current = current->next;
        i++;
    }
    return current->letter;
}

char decryptWheel(struct wheel* w, char letter) {
    struct letter* current = w->first;
    int i = 0;
    while(current->letter != letter) {
        current = current->next;
        i++;
    }
    return indexToletter(i);
}

char encryptOneLetter(struct littleEnigma* le, char letter) {
	int len = le->wheelsCount;
	struct wheel* curr;
	for (int i = 0; i < len; i++){
		curr = (le->wheels)[i];
		letter = encryptWheel(curr, letter);
	}
	rotateWheels(le->wheels, len);
	return letter;
}

char decryptOneLetter(struct littleEnigma* le, char letter) {
	int len = le->wheelsCount;
	struct wheel* curr;
	for (int i = len-1; i >= 0; i--){
		curr = (le->wheels)[i];
		letter = decryptWheel(curr, letter); 
	}
	rotateWheels(le->wheels, 1);
	return letter;
}

