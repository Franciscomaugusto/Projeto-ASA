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
    int max_rela = 0, max_absol=0, ant_1, atual, i;
    int ant_2, varia;
    vector<int> h= v[0];
    int size = h.size();
    if(size == 0){
        return 0;
    }
    else{
        ant_1 = v[0][0];
        ant_2 = v[0][0];
        for(i= 1; i<= (size-1); i++){
            atual = v[0][i];
            if(atual > ant_1){
                if(atual > ant_2){
                    max_rela = max_absol;
                }
                max_rela++;
                if(max_rela > max_absol){
                    max_absol= max_rela;
                    ant_2 = ant_1;
                    varia = 0;
                }
                if(max_rela == max_absol){
                    varia++;
                }
            }
            if(atual < ant_1){
                max_rela = 1;
                ant_2 = ant_1;
            }             
            ant_1 = atual;
        }
    }
    return max_absol;
}


/**
 * 
 * 
 */
int main(){ 
    int num, number, ind = 0, res;
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
        }
        res = alg_1(_sequences);
        cout << res;
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