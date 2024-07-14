#include <iostream>
#include <vector>
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> v(n);

    for ( int i = 0; i < n; i++ ){
        std::cin >> v[i];
    }
    int feeY = 0;
    for (int i = 0 ; i < n; i++){
        feeY = feeY + ((v[i]/30)+1)*10;
    }

    int feeM = 0;
    for ( int i = 0; i<n ; i++) {
        feeM = feeM + ((v[i]/60)+1)*15;
    }
    if (feeY > feeM) std::cout << "M "<< feeM;
    else if (feeY < feeM) std::cout << "Y " << feeY;
    else std::cout << "Y M " << feeY;
}