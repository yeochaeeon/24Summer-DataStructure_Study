#include <iostream>
#include <vector>
#include <numeric> // accumulate
#include <algorithm> // min_element
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> total;
    std::vector<int> odd;

    for (int i = 0; i < 7 ; i++) {
        int a;
        std::cin >> a;
        total.push_back(a);
    }
    for (int i:total){
        if ( i%2 != 0 ) odd.push_back(i);
    }
    if (odd.size() == 0) {std::cout << "-1" ; return 0;}
    else { 
        int sum = 0;
        sum = std::accumulate(odd.begin(),odd.end(),0);
        int min = *min_element(odd.begin(),odd.end());
        std::cout << sum << "\n" << min ;
    }
}
