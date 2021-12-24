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
vector<int> find_vector(string s,vector<vector<int>> v){
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
 * @brief 
 * 
 * @param v 
 * @return int 
 */
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
void alg_2(vector <int> v1, vector<int> v2){
    int s1 = v1.size();
    int s2 = v2.size();
    int maior = 0;
    int t[s1][s2];
    for(int i = 0; i <s1; i++){
        if(v1[i] == v2[0]){
                t[i][0] = 1;
            }
        else{
            t[i][0] = t[i-1][0];
        }
    }
    for(int j = 0; j< s2; j++){
        if(v1[0] == v2[j]){
                t[0][j] = 1;
            }
        else{
            t[0][j] = t[0][j-1];
        }
    }

    for (int i = 1; i<s1 ; i ++){
        for (int j = 1; j<s2 ; j ++){
            if (v1[i] == v2[j] && i != 0 && j != 0){
                t[i][j] = t[i-1][j-1] + 1;
                maior = t[i][j];
            }
            else{
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
        }
    }

    printf("%d\n", maior);

}



/**
 * @brief 
 * 
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
        _sequences[0] = find_vector(line,_sequences);
        alg_1(_sequences);
    }
    if(num == 2){
        getline(cin, line);
        _sequences[0] = find_vector(line, _sequences);
        getline(cin, line);
        _sequences.push_back(vector<int>(0));
        _sequences[1] = find_vector(line, _sequences);
        alg_2(_sequences[0], _sequences[1]);
    }
    return 0;
}
