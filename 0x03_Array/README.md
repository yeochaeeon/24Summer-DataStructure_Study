# 0x03_Array
## 1. 배열의 정의와 성질
> **배열** : 메모리 상에 원소를 연속하게 배치한 자료구조

### 배열의 성질 
1. O(1)에 k번째 원소를 확인/변경 가능
2. 추가적으로 소모되는 메모리의 양(=overhead)가 거의 없음
3. Cache hit rate가 높음
4. 메모리 상에 연속한 구간을 잡아야 해서 할당에 제약이 걸림
---
## 2. 기능과 구현
### 임의의 위치에 있는 원소를 확인/변경
- 너무나 자명하게 시간복잡도는 ***O(1)*** 이다.
### 끝에 원소를 추가 / 마지막 원소를 제거 
- 이 경우도 마찬가지로 시간복잡도는 ***O(1)*** 이다.
### 임의의 위치에 원소를 추가
- 이 경우는 ***O(N)*** 의 시간 복잡도를 가진다.
    - 배열의 중간에 원소를 삽입하고자 할 때 뒤에 있는 원소들을 한 칸씩 밀어줘야 한다. 
    - 삽입하고자 하는 위치가 끝에 가까울수록 시간은 줄겠지만 평균적으로 `N/2`개를 밀어야 하기에 ***O(N)*** 이라 할 수 있다.

---
### 구현 - insert함수 
- 추가적인 임시 배열을 써서 값을 잠시 옮겨두는 방법 이외에 더 간단한 방법이 있다. 
- 맨 끝(오른쪽)에서 부터 옮기는 방법이다.
```c
void insert(int idx, int num, int arr[],int& len) {
    for(int i = len; i > idx; i--){
        arr[i] = arr[i-1];
    }
    arr[idx] = num;
    len++;
}
```
> [!Warning]\
> `i > idx` 가 아닌 `i >= idx`로 작성 했을때 `idx == 0`인 경우 `arr[0] = arr[-1]`명령이 수행되어 ***runtime error***가 발생할 수 있다.

### 구현 - erase함수 
- 이 경우에서도 마찬가지로 원소들을 한 칸 씩 당겨오면 된다.
```cpp
void erase(int idx, int arr[],int& len){
    len--;
    for(int i = 0 ;i < len ;i++){
        arr[i] = arr[i+1];
    }
}
```
---
### 배열 값 초기화 
1. `cstring` 헤더 파일의 `memset`을 활용한다.
    - 0 혹은 -1이 아닌 다른 값을 넣으면 오작동 하거나, 2차원 배열을 함수의 인자로 넘겨 거기서 `memset`을 하면 잘못들어감 -> ***비추!!***
2. `for`문을 활용한다 .
    - 배열의 전 요소를 돌며 하나하나 바꾸는 방식이다. 무난하다!
3. `algorithm`헤더의 `fill`함수를 이용한다.
    - `fill`함수는 실수할 여지도 없고 코드도 짧아진다 -> ***익숙해지면 좋은 방법!***
```cpp
int a[21];
int b[21][21];

// 1. memset
memset(a,0,sizeof a);
memset(b,0,sizeof b);

// 2. for
for (int i = 0; i < 21; i++){
    a[i] = 0;
}
for (int i = 0; i < 21; i++){
    for(int j = 0; j < 21; j++){
        b[i][j] = 0;
    }
}

// 3. fill
fill(a, a+21,0);
for ( int i = 0 ; i < 21 ; i++){
    fill(b[i],b[i]+21,0);
}
```
## 3. STL vector 
```cpp
std::vector<int> v1 = {1,2,3,4,5,6};
// 1. range-based for loop
for (int e:v1){
    std::cout << e << ' ';
}

// 2. not bad
for (int i = 0; i <v1.size(); i++ ){
    std::cout << v1[i] << ' ';
}
// 3.***WRONG***
for (int i = 0; i <= v1.size()-1; i++){
    std::cout << v1[i] << ' ' ;
} 
```
### range-based for loop
- `range-based for loop`는 반복문을 돌 때 v1으로부터 복사된 값이 e에 들어가게 된다.
- 따라서 for문 안에서 e를 바꾸어도 v1에는 영향을 미치지 않는다.
- 위 코드는 출력만 하는 코드라 상관이 없지만, 벡터내 요소의 값을 바꾸고 싶다면 `int& e:v1`으로 쓰면 v1의 실제 원소값을 건드릴 수 있다.

### `v1.size()-1` , unsigned int overflow
- `size()`메소드는 `unsigned int` 혹은 `unsigned long long`을 반환한다. 따라서 v1이 빈 벡터일 경우 `v1.size()-1`는 unsigned int 0에서 int 1을 빼는 것이 된다.
- unsigned int와 int를 연산하면 unsigned int로 자동 형변환이 발생하기 때문에 (unsigned int)0 - (int)1은 -1이 아니라 4294967295이 된다. 
- 이렇게 되면 i가 계속 커지다가 runtime error 가 발생할 수 있다.

## 4. 연습문제 
### BOJ 10808: 알파벳 개수
> **방법 1** :'a'부터 'z'까지 각각의 알파벳에 대해 문자에 해당 알파벳이 몇번 등장하는 지 확인 -> 주어진 문자열을 ***26번(a-z)*** 돌아야 함 

> **방법 2** : 26개의 그릇을 만들어 놓고 단어를 돌면서 각 단어가 나타내는 그릇에 1을 추가하는 방법 -> 주어진 문자열을 ***단 한 번만*** 돌아도 됨!! 
```cpp
//방법 2 코드
#include <bits/stdc++.h>
using namespace std;

int freq[26]; 
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  for(auto c : s)
    freq[c-'a']++;
  for(int i = 0; i < 26; i++)
    cout << freq[i] << ' ';
}
```
- `freq`배열을 선언할 때 전역에 선언하면 알아서 배열내의 요소들이 0으로 초기화 되지만 지역변수로 선언하면 쓰레기 값이 채워지기에 `fill(freq, freq+26, 0);`와 같은 작업이 필요함.

### 0x01강 연습문제 
>  주어진 배열에서 원소의 합이 100인 서로 다른 이치의 두 원소가 존재하면 1, 아니면 0을 반환하는 함수를 구하는 문제 
- 기존에 이중 for문 (**O(N^2)**)으로 해결했었다.

- **O(N)** 으로 해결하는 알고리즘을 찾아보자.
    - 포인트는 나와 합해서 100이 되는 수의 존재 여부를 ***O(N)이 아닌 O(1)에*** 알아차리는 것이다.
    - 이전 문제와 동일하게 101칸(0부터 100까지)의 배열을 만들어 놓고 0으로 초기화 해둔다. 
    - 첫번째 원소부터 도는데, 예를 들어 첫번째 원소가 5라면, 5번째 인덱스의 값을 1로 바꾼다. 
    - 그리고 5와 더해서 100이 되는 수, 95가 이전에 등장했는지 확인하기 위해 95번째 인덱스의 값을 확인한다. 이런 방식이면 인덱스에 한 번에 접근하기에 ***O(1)에*** 알아차리는 것이 가능해진다.

```cpp
int func2(int arr[], int N){
  int occur[101] = {};
  for(int i = 0; i < N; i++){
    if(occur[100-arr[i]] == 1)
      return 1;
    occur[arr[i]] = 1;
  }
  return 0;
}
```
