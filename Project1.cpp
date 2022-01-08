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
 * Find_vector, função responsável por encontrar
 * os alagrismos na string introduzida pelo utilizador
 * @param string s
 * @return vector<int>> 
 */
vector<int> find_vector(string s){
    string number = "";
    int num;
    vector<int> h;
    int size = s.size();
    for (int i=0; i<=size; i++){
        if (s[i] <= '9' && s[i] >= '0'){
            number = number + s[i];
        }
        if(s[i] == ' ' || s[i] == '\n' || s[i] == '\0'){
            num = stoi(number);
            h.push_back(num);
            number = "";
        }
    } 
    return h;
}


/**
 * Função alg_1, procura encontrar o tamanho da maior sequencia crescente
 * de inteiros da sequencia, bem como o numero de sequencias desse mesmo tamanho
 * @param vector<vector<int>> v
 * @return vector<int> 
 */
vector<int> alg_1(vector<vector<int>> v){
    int max_rela = 0, max_absol, varia;
    vector<int> k= v[0];
    vector<int> _results = vector<int> (2);
    int size = k.size();
    vector<vector<int>> _matriz (size, vector<int>(2, 0));
    for(int i= 0; i< size; i++){
        _matriz[i][0] = v[0][i];
    }
    for(int i= 0; i< size; i++){
        max_rela = 0;
        varia = 1;
        for(int h = 0; h < i; h++){
            if(k[i] > k[h]){
                if(_matriz[h][0] == max_rela){
                    varia+= _matriz[h][1];
                }
                if(_matriz[h][0] > max_rela){
                    max_rela = _matriz[h][0];
                    varia = _matriz[h][1];
                }
            }
        }
        _matriz[i][0] = max_rela + 1;
        _matriz[i][1] = varia;
    }
    max_absol = 0;
    varia = 0;
    for(int i = 0; i <size; i++){
        if(_matriz[i][0] >= max_absol){
            max_absol = _matriz[i][0];
        }
    }
    for(int i = 0; i< size; i++){
        if(_matriz[i][0] == max_absol){
            varia += _matriz[i][1];
        }
    }
    _results[0] = max_absol;
    _results[1] = varia;
    return _results;
}


/**
 * Função alg_2, procura encontrar a maior sequencia crescente
 * de inteiros comum a duas sequencias de algarismos
 * @param vector<int> v2 
 */
void alg_2(vector <int> v1, vector<int> v2){
    long s1 = v1.size(), s2 = v2.size();
    int max_rela, max_absol, index;
    vector<int> _comuns1, _comuns2;
    bool exist;
    for(long i = 0; i < s1; i++){
        exist = false;
        for(long h = 0; h < s2; h++){
            if(v1[i] == v2[h]){
                exist = true;
            } 
        }
        if(exist){
            _comuns1.push_back(v1[i]);
        }
    }
    for(long h = 0; h < s2; h++){
        exist = false;
        for(long i = 0; i < s1; i++){
            if(v1[i] == v2[h]){
                exist = true;
            } 
        }
        if(exist){
            _comuns2.push_back(v2[h]);
        }
    }
    s1 = _comuns1.size();
    s2 = _comuns2.size();
    vector<vector<int>> _matriz (s1,vector<int> (2, 0));
    for(long i = 0; i< s1; i++){
        if(i == 0){
            _matriz[i][0] = 1;
            for(long h = 0; h< s2; h++){
                if(_comuns2[h] == _comuns1[i]){
                    _matriz[i][1] = h;
                    break;
                }
            }
        }
        else{
            max_rela = 0;
            index = 0;
            for(long h = 0; h < i; h++){
                if(_comuns1[i] > _comuns1[h]){
                    if(_matriz[h][0] > max_rela){
                        for(long k = 0; k < s2; k++){
                            if( k > _matriz[h][1] && _comuns2[k] == _comuns1[i]){
                                max_rela = _matriz[h][0];
                                index = k;
                                break;
                            }
                        }
                    }
                }
                if( index == 0){
                    for(long k = 0; k < s2; k++){
                        if( _comuns2[k] == _comuns1[i]){
                            index = k;
                            break;
                        }
                    }
                }
                _matriz[i][0] = max_rela + 1;
                _matriz[i][1] = index;
            }
        }
    }
    max_absol = 0;
    for(long i = 0; i < s1; i++){
        if(_matriz[i][0] > max_absol){
            max_absol = _matriz[i][0];
        }
    }
    printf("%d\n", max_absol);

}


/**
 * Main do programa
 * @return int 
 */
int main(){ 
    int num;
    string line;
    cin >> num;
    cin.ignore();
    vector<vector<int>> _sequences;
    _sequences.push_back(vector<int>(0));
    if(num == 1){
        getline(cin, line);
        _sequences[0] = find_vector(line);
        vector<int> _results = alg_1(_sequences);
        printf("%d %d\n", _results[0], _results[1]);
    }
    if(num == 2){
        getline(cin, line);
        _sequences[0] = find_vector(line);
        getline(cin, line);
        _sequences.push_back(vector<int>(0));
        _sequences[1] = find_vector(line);
        alg_2(_sequences[0], _sequences[1]);
    }
    return 0;
}