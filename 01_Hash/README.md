# Hash


- 해쉬는 내부적으로 배열(Hash Table)을 사용하여 데이터를 저장하기 때문에 빠른 검색 속도를 갖는다.
- 그리고 데이터의 삽입과 삭제 시, 기존 데이터를 밀어내거나 채우는 작업이 필요 없도록 특별한 알고리즘을 이용하여 데이터와 연관된 고유한 숫자를 만들어 낸 뒤 이를 인덱스로 사용한다.
- 즉, 삽입 삭제 시 데이터의 이동이 없도록 만들어진 구조.

## 💎 Tips
해쉬(Hash)가 내부적으로 사용하는 배열을 Hash Table 이라고 하며 그 크기에 따라서 성능 차이가 많이 날 수 있다.


## 🏷️ Manual
```c
int hashFunction(long long key);        //hash변환함수 , 여러분들이 직접쓸일 X
node* createNode(long long key, int value);     //노드생성 함수 , 여러분들이 직접 쓸일 x
void addHashMap(long long key, int value);      //addHashMap 에 요소를 추가함, long long key 와 value
int hashValue(long long key);       //hash가 가진 long longkey에 value를 얻어옴.
long long getStringKey(char* key);  //hash가 가진 string key를 hash function 에 넣게 가공해줌 
bool hasintKey(long long key);      //해당 롱롱 키를 포함하는가?
void addKeySet(int key);        //키셋 추가 
```

## 📚 References
