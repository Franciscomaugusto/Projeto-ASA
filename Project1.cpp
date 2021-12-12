/**
 * 
 * ASA 2021/2022 - IST
 * Projeto 1
 * 
 * 99218 - Francisco Augusto
 * 95908 - Rita Costa
 * 
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
using namespace std;

/**
 * 
 * 
 */
int alg_1(vector<vector<int>> v){
    int max = 1, ant_1, atual, i;
    vector<int> h= v[0];
    int size = h.size();
    printf("dei o size\n");

    if(size == 0){
        printf("Mal feito\n");
        return 0;
    }
    else{
        ant_1 = v[0][0];
        for(i= 1; i<= (size-1); i++){
            atual = v[0][i];
            if(atual > ant_1){
                max++;
                ant_1 = atual;
            }
        }
    }
    return max;
}

/**
 * 
 * 
 */
int main(){ 
    int num, number, ind = 0, n=1;
    string line;
    stringstream ss;
    cin >> num;
    cin.ignore();
    vector<vector<int>> _sequences;
    _sequences.push_back(vector<int>(1));
    if(num== 1){
        getline(cin, line);
        ss << line;
        while(ss >> number){
            _sequences[0].push_back(number);
            printf("%d ", n);
            n++;
        }
        alg_1(_sequences);
    }
    if(num == 2){
        getline(cin, line);
        ss << line;
        while(ss >> number){
            _sequences[ind].push_back(number);
        }
        ind++;
        getline(cin, line);
        ss <<line;
        while(ss >> number){
            _sequences[ind].push_back(number);
        }
        //alg_2(_sequences);
    }
    return 0;
}