# 0x07_Deque
## 1.정의와 성질

> **정의** : ***Double Ended Queue***라는 뜻으로 양쪽에서 삽입과 삭제가 모두 가능한 자료구조이다. 
- 스택과 큐를 덱의 특수한 예시라고 생각해도 된다.

### Deque의 성질
1. 원소의 추가/제거 - ***O(1)***
2. 제일 앞/뒤 원소 확인 - ***O(1)***
3. 제일 앞/뒤가 아닌 다른 원소들의 확인/변경이 원칙적으로 불가능함.
    - 그러나 , **STL Deque**에서는 특이하게 인덱스로 원소에 접근이 가능!

## 2. 기능과 구현

### 구현 구조 

- 원소를 담을 큰 배열 1개 , 앞/뒤를 가리킬 변수 2개 
- `head`는 가장 앞에 있는 원소의 인덱스 , `tail`은 가장 뒤에 있는 원소의 인덱스 + 1
- 덱은 양쪽에서 모두 원소의 삽입이 가능하기에 배열의 중간 지점을 시작지점으로 둔다.
- 따라서 배열의 크기는 `2*MX+1` , `head` 와 `tail`의 초기값은 `MX`이다.

### 구현 코드 

```cpp
const int MX = 1000005;
int dat[2*MX+1];
int head = MX, tail = MX;

void push_front(int x){
    dat[head-1] = x;
    head--; 
    //dat[--head] = x; 랑 똑같음.
}

void push_back(int x){
    dat[tail++] = x;
}

void pop_front(){
    head++;
}

void pop_back(){
    tail--;
}

int front(){
    return dat[head];
}

int back(){
    return dat[tail-1];
}
```
## 3. STL Deque
- STL Deque의 기능을 살펴보면, STL vector에서 제공해주는 기능을 다 가지고 있음과 동시에 front에서도 O(1)에 원소의 추가와 제거까지 가능하다는 점을 알 수 있다.
- 그래서, 덱이 벡터의 상위호환이 아닌가? 라고 생각할 수 있으나 덱은 벡터와 달리 원소들이 메모리상에 연속하게 배치되어 있지 않다는 점이 다르다. 

> [!Note] 
> 앞/뒤에서 추가와 제거가 모두 필요하다 → STL Deque 사용 \
> 배열처럼만 쓰면 된다 → STL Vector 사용

## 4. 연습문제 - BOJ_10866 : 덱 
