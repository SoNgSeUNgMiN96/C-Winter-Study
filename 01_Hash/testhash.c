#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct bucket* hashTable = NULL; 
int BUCKET_SIZE = 1000;

struct keySet{      //keySet (숫자형 키)
    int key;
    struct keySet *next;
}typedef keySet;

struct stringKeySet{    //stringKeySet (문자형 키)
    char stringKey[100];
    struct stringKeySet *next;
}typedef stringKeySet;

keySet  *keySetHead=NULL;        //키셋 삽입삭제를 위한 헤더와 꼬리
keySet *keySetTail=NULL;
stringKeySet *stringKeySetHead=NULL;
stringKeySet *stringKeySetTail=NULL;

struct node {
    long long key; // 해시 함수에 사용될 키
    char stringKey[100];    //문자열 키를 다룰 stringkey
    int value; // key 가 가지고 있는 데이터
    struct node* next; // 다음 노드를 가르키는 포인터
}typedef node;

struct bucket{
    struct node* head; // 버켓 가장 앞에 있는 노드의 포인터
    int count; // 버켓에 들어있는 노드의 개수
}typedef bucket;

int hashFunction(long long key);        //hash변환함수 , 여러분들이 직접쓸일 X
node* createNode(long long key, int value);     //노드생성 함수 , 여러분들이 직접 쓸일 x
node* createNodeString(char *stringKey, int value); //노드생성 함수 , 여러분들이 직접 쓸일 x
void addHashMap(long long key, int value);      //addHashMap 에 요소를 추가함, long long key 와 value
void addHashMapString(char *stringKey, int value);      //addHashMap 에 요소를 추가함, string key 와 value
int hashValue(long long key);       //hash가 가진 long longkey에 value를 얻어옴.
long long getStringKey(char *key);  //hash가 가진 string key를 hash function 에 넣게 가공해줌 
int hashValueString(char *stringKey);   //hash가 가진 string key에 value를 얻어옴.
bool hasintKey(long long key);      //해당 롱롱 키를 포함하는가?
bool hasStringKey(char *stringKey);     //해당 스트링 키를 포함 하는가?
void addKeySet(int key);        //키셋 추가 
void addStringKeySet(char *stringKey);  //케셋 추가 (스트링)


int main(){

    int N, M, *answer;
    char temp[21];
    scanf("%d",&N);
    answer = (int*)malloc(sizeof(int)*N);

    for( int i=0;i<N;i++){
        stringKeySetHead =NULL;
        stringKeySetTail = NULL;
        hashTable = (struct bucket *)malloc(BUCKET_SIZE * sizeof(struct bucket));
        for(int j=0;j<BUCKET_SIZE;j++){
            hashTable[j].count = 0;
        }
        scanf("%d",&M);
        answer[i] = 1;
        for (int j=0;j<M;j++){
            scanf("%s",temp);
            scanf("%s",temp);
            if (hasStringKey(temp)){
                addHashMapString(temp,hashValueString(temp)+1);
            }
            else{
                addHashMapString(temp,1);
            }
        }
        stringKeySet *cursor = stringKeySetHead;
        while (cursor!=NULL)
        {
            answer[i] *= (hashValueString(cursor->stringKey)+1);
            cursor= cursor->next;
        }

    }
    for(int i=0;i<N;i++){
        printf("%d\n",answer[i]-1);
    }

    

}




int hashFunction(long long key){
    long double a;
    if ( key<1000){
        a = key / 23.0;
    }else if (key < 1000000){
        a = key / 997.0;
    }
    else if (key < 1000000000){
        a = key /8191.0;
    }else {
        a = key / 32767.0;
    }
    
    a *= 1000;
    long temp = a;
    int idx = temp%1000;
    if(idx <0)
        return -idx;
    return idx;
}

node* createNode(long long key, int value){
    node* newNode;
    // 메모리 할당
    newNode = (node*)malloc(sizeof(node));
    // 사용자가 전해준 값을 대입
    newNode->key = key;
    newNode->value = value;
    strcpy(newNode->stringKey,"");
    newNode->next = NULL; // 생성할 때는 next를 NULL로 초기화

    return newNode;
}


node* createNodeString(char *stringKey, int value){
    

    node* newNode;
    // 메모리 할당
    newNode = (node*)malloc(sizeof(node));
    
    // 사용자가 전해준 값을 대입
    newNode->key = getStringKey(stringKey);     //스트링키 깊은 복사
    strcpy(newNode->stringKey,stringKey);
    newNode->value = value;
    newNode->next = NULL; // 생성할 때는 next를 NULL로 초기화

    return newNode;
}


// 새로 키 추가하는 함수
void addHashMap(long long key, int value){
    // 어느 버켓에 추가할지 인덱스를 계산
    int hashIndex = hashFunction(key);
    // 새로 노드 생성
    node* newNode = createNode(key, value);
    // 계산한 인덱스의 버켓에 아무 노드도 없을 경우
    if (hashTable[hashIndex].count == 0){
        addKeySet(key);
        hashTable[hashIndex].count = 1;
        hashTable[hashIndex].head = newNode; // head를 교체
    }
    // 버켓에 다른 노드가 있을 경우 한칸씩 밀고 내가 헤드가 된다(실제로는 포인터만 바꿔줌)
    else{
        node * cursor = hashTable[hashIndex].head;
        while (cursor)
        {
           if(cursor->key==key){        //이미 데이터가 있는경우 데이터를 뭉갬
                cursor->value = value;
                return;
           }
           else cursor = cursor->next;
        }
        addKeySet(key);
        newNode->next = hashTable[hashIndex].head;
        hashTable[hashIndex].head = newNode;
        hashTable[hashIndex].count++;
    }
}

void addHashMapString(char *stringKey, int value){
    // 스트링 키를 인트형 키로 변환연산
    int hashIndex = hashFunction(getStringKey(stringKey));
  
    // 새로 노드 생성
    node* newNode = createNodeString(stringKey, value);
    // 계산한 인덱스의 버켓에 아무 노드도 없을 경우
    if (hashTable[hashIndex].count==0){
        addStringKeySet(stringKey);
        hashTable[hashIndex].count = 1;
        hashTable[hashIndex].head = newNode; // head를 교체
    }
    // 버켓에 다른 노드가 있을 경우 한칸씩 밀고 내가 헤드가 된다(실제로는 포인터만 바꿔줌)
    else{
        node * cursor = hashTable[hashIndex].head;
        while (cursor!=NULL)
        {
           if(strcmp(cursor->stringKey,stringKey)==0){        //이미 데이터가 있는경우 데이터를 뭉갬
                cursor->value = value;
                return;
           }
           else cursor = cursor->next;
           
        }
        addStringKeySet(stringKey);
        newNode->next = hashTable[hashIndex].head;
        hashTable[hashIndex].head = newNode;
        hashTable[hashIndex].count++;
    }
}


int hashValue(long long key){

    node * search = hashTable[hashFunction(key)].head;
    

    while (search!=NULL)
    {
        if(search->key == key){
            return search->value;
        }
        else search = search->next;
    }
    printf("cannot find key %lld\n", key);
    return -0xFFFFFF;
}

int hashValueString(char *stringKey){


    node * search = hashTable[hashFunction(getStringKey(stringKey))].head;


    while (search!=NULL)
    {
        if(strcmp(search->stringKey,stringKey)==0){
            return search->value;
        }
        else search = search->next;
    }
    printf("cannot find key %s\n", stringKey);
    return -0xFFFFFF;
}

long long getStringKey(char *key){
    
    char temp[100];
    strcpy(temp , key);

    long long intKey=0;


    for (int i=0;i<100;i++){
        if (temp[i]==0)
            break;
        if(temp[i]>99){
            intKey *= 1000;
            intKey += temp[i];
        }else if (temp[i]>9){
            intKey *=100;
            intKey += temp[i];
        }else{
            intKey *=10;
            intKey += temp[i];
        }
    }
    return intKey;

}

bool hasintKey(long long key){

    node * search = hashTable[hashFunction(key)].head;

    while (search!=NULL)
    {
        if(search->key == key){
            return true;
        }
        else search = search->next;
    }
    return false;
}

bool hasStringKey(char *stringKey){

    node * search = hashTable[hashFunction(getStringKey(stringKey))].head;


    while (search!=NULL)
    {
        if(strcmp(search->stringKey,stringKey)==0){
            return true;
        }
        else search = search->next;
    }
    return false;
}


void addKeySet(int key){
    keySet *temp =(keySet*)malloc(sizeof(keySet));
    temp->key = key;
    temp->next = NULL;
    if (keySetHead==NULL){
        keySetHead = temp;
        keySetTail = temp;
    }
    else{
        keySetTail->next = temp;
        keySetTail = temp;
    }
}

void addStringKeySet(char *stringKey){
    stringKeySet *temp =(stringKeySet*)malloc(sizeof(stringKeySet));
    strcpy(temp->stringKey,stringKey);
    temp->next = NULL;
    if (stringKeySetHead==NULL){
        stringKeySetHead = temp;
        stringKeySetTail = temp;
    }
    else{
        stringKeySetTail->next = temp;
        stringKeySetTail = temp;
    }
}