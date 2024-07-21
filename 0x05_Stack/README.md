# 0x05_Stack
## 1. 정의와 성질
> **정의** : 한 쪽 끝에서만 원소를 넣고 뺼 수 있는 자료구조
- **FILO(First In Last Out)** 자료구조라고 부르기도 한다.
- 특정위치에서만 원소를 넣거나 뺄 수 있는 제한이 걸려있는 자료구조를 **Restricted Structure** 라고 부르고 *스택,큐,덱* 이 이에 해당한다
## 2. 기능과 구현 
### 구현 

- 구조 : `dat[]`배열에 각 원소들이 들어있고, `pos`변수에 다음 원소가 추가될 위치(인덱스)를 담는다 (pos의 값이 곧 스택 내의 원소의 수와 같다.)

- `push()`
    - ```cpp
        void push(int x){
            dat[pos++] = x;
        }
        ```
- `pop()`
    - ```cpp
        void pop(){
            pos--;
        }
        ```
- `top()`
    - ```cpp
        void pop(){
            return dat[pos-1];
        }
        ```

## 3. STL stack
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  stack<int> S;
  S.push(10); // 10
  S.push(20); // 10 20
  S.push(30); // 10 20 30
  cout << S.size() << '\n'; // 3
  if(S.empty()) cout << "S is empty\n";
  else cout << "S is not empty\n"; // S is not empty
  S.pop(); // 10 20
  cout << S.top() << '\n'; // 20
  S.pop(); // 10
  cout << S.top() << '\n'; // 10
  S.pop(); // empty
  if(S.empty()) cout << "S is empty\n"; // S is empty
  cout << S.top() << '\n'; // runtime error 발생
}
```
> [!Warning]\
> stack이 비어있을 때 pop이나 top을 호출하면 runtime error가 발생한다.

## 4. 연습문제 - BOJ_10828:스택