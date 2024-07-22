# 0x06_Queue
## 1. 정의와 성질
> **정의** : 한쪽 끝에서 원소를 넣고 반대쪽 끝에서 원소를 뺄 수 있는 자료구조 
- ***FIFO(First In First Out)*** 이라고 하기도 한다.
### Queue의 성질
1. 원소의 추가/제거 - **O(1)**
    - 추가되는 곳 : rear , 제거되는 곳 : front 라고 한다.
2. 제일 앞/뒤의 원소 확인 - **O(1)**
3. 제일 앞/뒤가 아닌 나머지 원소들의 확인/변경이 원칙적으로 불가능함.
    - 배열을 이용하여 직접 큐를 구현하는 경우 이외에는 스택과 비슷하게 인덱스로 원소에 접근이 불가능함. STL queue에서도 마찬가지.

## 2. 기능과 구현
### 구조
- 배열 1개 , 앞/뒤 쪽을 가리킬 변수 두개 ( head/tail ).
- 초기 head/tail은 모두 배열의 0번지를 가리키고 있다.
- `push` : 새 값을 넣으면 head는 변함이 없고, tail은 한 칸 올라간다.
- `pop` : 맨 앞의 원소를 없애면 head가 한 칸 올라간다. 0번지의 값은 굳이 다른 값으로 덮지 않는다.

### 구현 
- `push()`
    ```cpp
    void push(int x){
        dat[tail++] = x;
    }
    ```
- `pop()`
    ```cpp
    void pop(){
        head++;
    }
    ```

- `back()`
    ```cpp
    int back(){
        return dat[tail-1];
    }
    ```

- `front()`
    ```cpp
    int front(){
        return dat[head];
    }
    ```
### ➕Circular Queue
- 위의 큐의 구조에서 알 수 있듯, `push`,`pop`을 반복할수록 배열의 원소들이 점점 오른쪽으로 밀릴 것이다. 
- 스택과 달리 큐는 삭제가 발생할 때 마다 앞쪽에 쓸모없는 공간이 계속 쌓인다.
- 이를 해결할 수 있는 큐의 구조가 ***원형큐***이다.
- 관념적으로 원형이고, 실제 구현은 tail이 배열끝에 도달하면 1이 더해질 때 다시 0이 되도록 만들면 된다.

## 3. STL Queue
### 예제코드
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    queue<int> Q;
    Q.push(10); // 10
    Q.push(20); // 10 20
    Q.push(30); // 10 20 30
    cout << Q.size() << '\n'; // 3
    if(Q.empty()) cout << "Q is empty\n";
    else cout << "Q is not empty\n"; // Q is not empty
    Q.pop(); // 20 30
    cout << Q.front() << '\n'; // 20
    cout << Q.back() << '\n'; // 30
    Q.push(40); // 20 30 40
    Q.pop(); // 30 40
    cout << Q.front() << '\n'; // 30
}
```
## 0x04 연습문제 - BOJ_10845 : 큐
