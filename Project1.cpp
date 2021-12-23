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
 * @brief 
 * 
 * @param s 
 * @param v 
 * @param ind 
 * @return vector<vector<int>> 
 */
//Added - meant to process input, creating a vector of ints as a result
vector<vector<int>> find_vector(string s,vector<vector<int>> v, int ind){
    string number = "";
    int num;
    int size = s.size();
    for (int i=0; i<=size; i++){
        if (s[i] <= '9' && s[i] >= '0'){
            number = number + s[i];
        }
        if(s[i] == ' ' || s[i] == '\n' || s[i] == '\0'){
            num = stoi(number);
            v[ind].push_back(num);
            number = "";
        }
    } 
    return v;
}


/**
 * @brief 
 * 
 * @param v 
 * @return int 
 */
//Optimized
void alg_1(vector<vector<int>> v){
    int max_rela = 0, max_absol, varia;
    vector<int> h= v[0];
    int size = h.size();
    vector<vector<int>> _matriz (size, vector<int>(3, 0));
    if(size == 0){
        printf("0 0");
    }
    else{
        for(int i= 0; i< size; i++){
            _matriz[i][0] = v[0][i];
        }
        for(int i= 0; i< size; i++){
            max_rela = 0;
            varia = 0;
            for(int h = 0; h < i; h++){
                if(_matriz[i][0] > _matriz[h][0]){
                    if(_matriz[h][1] > max_rela){
                        max_rela = _matriz[h][1];
                        varia = 0;
                    }
                    if(_matriz[h][1] == max_rela){
                        varia++;
                    }
                }
            }
            _matriz[i][1] = max_rela + 1;
            _matriz[i][2] = varia;
        }
        max_absol = 0;
        varia = 0;
        for(int i = 0; i <size; i++){
            if(_matriz[i][1] >= max_absol){
                max_absol = _matriz[i][1];
                if(_matriz[i][2] > varia){
                    varia = _matriz[i][2];
                }
            }
        }
        printf("%d %d\n",max_absol, varia);
    }
}
/**
 * @brief 
 * 
 * @param v 
 */
void alg_2(vector<vector<int>> v){

}


/**
 * @brief 
 * 
 * @return int 
 */
//Altered in order to use the first function, the name of which I can't remember
int main(){ 
    int num, ind = 0;
    string line;
    vector<int> h;
    stringstream ss;
    cin >> num;
    cin.ignore();
    vector<vector<int>> _sequences;
    _sequences.push_back(vector<int>(0));
    if(num == 1){
        getline(cin, line);
        _sequences = find_vector(line,_sequences, ind);
        alg_1(_sequences);
    }
    if(num == 2){
        getline(cin, line);
        _sequences = find_vector(line, _sequences, ind);
        ind++;
        getline(cin, line);
        _sequences = find_vector(line, _sequences, ind);
        //alg_2(_sequences);
    }
    return 0;
}
