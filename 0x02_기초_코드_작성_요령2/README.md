# 0x02_기초 코드 작성 요령2
## 1. STL과 함수인자
### STL을 함수인자로 넘길 때 
```cpp
void func1(vector<int> v){
    v[10] = 7;
}
int main(void){
    vector<int> v(100);
    func1(v);
    std::cout << v[10];
}
```