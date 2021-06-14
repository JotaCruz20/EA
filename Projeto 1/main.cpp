#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

int minimum;
int checkDone = 0;

std::tuple<bool,bool> moveUp(std::vector<std::vector<int>> &board){
    int size = board.size();
    int i,j,line,nEles=0;
    bool flag = false,changes=false;
    for(j=0;j<size;j++){
        line=0; // row serve para sabermos o ultimo numero que ainda n foi atualizado e que é possivel atualizar
        for(i=0;i<size;i++){ // começa em no penultimo pois o ulitmo elemento so vai ser somado no maximo, nao se mexe
            if(board[i][j]!=0){ // mexer no board caso elemento n seja 0
                nEles+=1;
                if(i>0){
                    if(board[i-1][j]==0 || board[i-1][j]==board[i][j]){ // caso o seguinte,que ainda nao sofreu alteraçao, seja igual ou 0, podemos somar ou andar
                        changes = true;
                        if(board[line][j]==board[i][j]){ // se for igual somamos
                            board[line][j] = board[i][j] << 1;
                            flag=true;
                            board[i][j]=0;
                            ++line;
                            --nEles;
                        }
                        else{
                            if(board[line][j]==0){ // se for 0 andar com o numero para a esquerda
                                board[line][j]=board[i][j];
                                board[i][j]=0;
                            }
                            else{ //incrementar para testar o proximo
                                ++line;
                                board[line][j]=board[i][j];
                                board[i][j]=0;
                            }
                        }
                    }
                    else{ // no caso da coluna atual ser menor, ja nao podemos fazer nada com ela entao somamos
                        ++line;
                    }
                }
            }
        }
    }
    if(nEles==1){
        checkDone=1;
    }
    return std::make_tuple(flag,changes);
}

std::tuple<bool,bool> moveDown(std::vector<std::vector<int>> &board){
    int size = board.size();
    int i,j,line,nEles = 0;
    bool flag=false,changes = false;
    for(j=0;j<size;j++){
        line=size-1; // row serve para sabermos o ultimo numero que ainda n foi atualizado e que é possivel atualizar
        for(i=size-1;i>=0;i--){ // começa em no penultimo pois o ulitmo elemento so vai ser somado no maximo, nao se mexe
            if(board[i][j]!=0){ // mexer no board caso elemento n seja 0
                nEles+=1;
                if(i<size-1){
                    if(board[i+1][j]==0 || board[i+1][j]==board[i][j]){ // caso o seguinte,que ainda nao sofreu alteraçao, seja igual ou 0, podemos somar ou andar
                        changes= true;
                        if(board[line][j]==board[i][j]){ // se for igual somamos
                            board[line][j] = board[i][j] << 1;

                            flag=true;
                            --nEles;
                            board[i][j]=0;
                            --line;
                        }
                        else{
                            if(board[line][j]==0){ // se for 0 andar com o numero para a esquerda
                                board[line][j]=board[i][j];
                                board[i][j]=0;
                            }
                            else{ //incrementar para testar o proximo
                                --line;
                                board[line][j]=board[i][j];
                                board[i][j]=0;
                            }
                        }
                    }
                    else{ // no caso da coluna atual ser menor, ja nao podemos fazer nada com ela entao somamos
                        --line;
                    }
                }
            }
        }
    }
    if(nEles==1){
        checkDone=1;
    }
    return std::make_tuple(flag,changes);
}

std::tuple<bool,bool> moveLeft(std::vector<std::vector<int>> &board){
    int size = board.size();
    int i,j,row,nEles=0;
    bool flag= false,changes=false;
    for(i=0;i<size;i++){
        row=0; // row serve para sabermos o ultimo numero que ainda n foi atualizado e que é possivel atualizar
        for(j=0;j<size;j++){ // começa em 1 pois o 1º elemento,0, so vai ser somado no maximo, nao se mexe
            if(board[i][j]!=0){ // mexer no board caso elemento n seja 0
                nEles+=1;
                if(j>0){
                    if(board[i][j-1]==0 || board[i][j-1]==board[i][j]){ // caso o anterior,que ainda nao sofreu alteraçao, seja igual ou 0, podemos somar ou andar
                        changes= true;
                        if(board[i][row]==board[i][j]){ // se for igual somamos
                            board[i][row] = board[i][j] << 1;

                            flag= true;
                            board[i][j]=0;
                            --nEles;
                            ++row;
                        }
                        else{
                            if(board[i][row]==0){ // se for 0 andar com o numero para a esquerda
                                board[i][row]=board[i][j];
                                board[i][j]=0;
                            }
                            else{ //incrementar para testar o proximo
                                ++row;
                                board[i][row]=board[i][j];
                                board[i][j]=0;
                            }
                        }
                    }
                    else{ // no caso da coluna atual ser menor, ja nao podemos fazer nada com ela entao somamos
                        ++row;
                    }
                }
            }

        }
    }

    if(nEles==1){
        checkDone=1;
    }
    return std::make_tuple(flag,changes);
}

std::tuple<bool,bool> moveRight(std::vector<std::vector<int>> &board){
    int size = board.size();

    int i,j,row,nEles=0;
    bool flag= false;
    bool changes = false;
    for(i=0;i<size;i++){
        row=size-1; // row serve para sabermos o ultimo numero que ainda n foi atualizado e que é possivel atualizar
        for(j=size-1;j>=0;j--){ // começa em no penultimo pois o ulitmo elemento so vai ser somado no maximo, nao se mexe
            if(board[i][j]!=0){ // mexer no board caso elemento n seja 0
                nEles+=1;
                if(j<size-1){
                    if(board[i][j+1]==0 || board[i][j+1]==board[i][j]){ // caso o seguinte,que ainda nao sofreu alteraçao, seja igual ou 0, podemos somar ou andar
                        changes= true;
                        if(board[i][row]==board[i][j]){ // se for igual somamos
                            board[i][row] = board[i][j] << 1;

                            flag = true;
                            --nEles;
                            board[i][j]=0;
                            --row;
                        }
                        else{
                            if(board[i][row]==0){ // se for 0 andar com o numero para a esquerda
                                board[i][row]=board[i][j];
                                board[i][j]=0;
                            }
                            else{ //incrementar para testar o proximo
                                --row;
                                board[i][row]=board[i][j];
                                board[i][j]=0;
                            }
                        }
                    }
                    else{ // no caso da coluna atual ser menor, ja nao podemos fazer nada com ela entao somamos
                        --row;
                    }
                }
            }
        }
    }
    if(nEles==1){
        checkDone=1;
    }
    return std::make_tuple(flag,changes);
}

void matrixCalculator(const std::vector<std::vector<int>>& board,int max,int movesDone, int movesWithoutSum,
        char lastMove, char lLastMove, bool sumlLast, bool sumLast){

    std::vector<std::vector<int>> boardL,boardR,boardU,boardD;

    if(movesDone == max or movesDone >=minimum or movesWithoutSum==5){ // Se chegarmos ao numero maximos de move, ou os
        // moves feitos forem >= minimo ate ao momento, ou forem feitos 5 moves sem soma entao cortar
        return;
    }

    else {
        if((lLastMove!='R' or lastMove!='L' or sumlLast)){ // se for feito anteriormente Direita Esquerda e nao tiver
            //havido soma entao nao voltar a fazer para a direita
            boardR = board;
            sumlLast = sumLast;
            std::tuple moveFlags = moveRight(boardR);
            sumLast = std::get<0>(moveFlags);
            bool changes = std::get<1>(moveFlags);

            if(checkDone==1){ // caso haja so 1 elemento na matriz acabar
                checkDone = 0;
                if(movesDone+1<minimum){
                    minimum = movesDone+1;
                }
                return;
            }
            else if(changes) { // caso tenha havido mudanças continua, se nao segue para o proximo move
                lLastMove = lastMove;
                lastMove = 'R';
                if(!sumLast) { // para saber se houve move no atual e caso nao haja somar nos moves sem soma, de maneira
                    // a controlar o numero de moves sem soma
                    matrixCalculator(boardR, max, movesDone + 1,movesWithoutSum+1,lastMove,lLastMove,sumlLast, sumLast);
                }
                else{
                    matrixCalculator(boardR, max, movesDone + 1,0,lastMove,lLastMove, sumlLast, sumLast);
                }
            }
        }

        if(lLastMove!='U' or lastMove!='D' or sumlLast) {
            boardU = board;
            sumlLast = sumLast;
            std::tuple moveFlags= moveUp(boardU);
            sumLast = std::get<0>(moveFlags);
            bool changes = std::get<1>(moveFlags);

            if(checkDone==1){
                checkDone = 0;
                if(movesDone+1<minimum){
                    minimum = movesDone+1;
                }
                return;
            }
            else if(changes) {
                lLastMove = lastMove;
                lastMove = 'U';
                if(!sumLast) {
                    matrixCalculator(boardU, max, movesDone + 1,movesWithoutSum+1,lastMove,lLastMove, sumlLast, sumLast);
                }
                else{
                    matrixCalculator(boardU, max, movesDone + 1,0,lastMove,lLastMove, sumlLast, sumLast);
                }
            }
        }

        if(lLastMove!='L' or lastMove!='R' or sumlLast){
            boardL = board;
            sumlLast = sumLast;
            std::tuple moveFlags= moveLeft(boardL);
            sumLast = std::get<0>(moveFlags);
            bool changes = std::get<1>(moveFlags);

            if(checkDone==1){
                checkDone = 0;
                if(movesDone+1<minimum){
                    minimum = movesDone+1;
                }
                return;
            }
            else if(changes) {
                lLastMove = lastMove;
                lastMove = 'L';
                if(!sumLast) {
                    matrixCalculator(boardL, max, movesDone + 1,movesWithoutSum+1,lastMove,lLastMove, sumlLast, sumLast);
                }
                else{
                    matrixCalculator(boardL, max, movesDone + 1,0,lastMove,lLastMove, sumlLast, sumLast);
                }
            }
        }

        if(lLastMove!='D' or lastMove!='U' or sumlLast) {
            boardD = board;
            sumlLast = sumLast;
            std::tuple moveFlags= moveDown(boardD);
            sumLast = std::get<0>(moveFlags);
            bool changes = std::get<1>(moveFlags);

            if(checkDone==1){
                checkDone = 0;
                if(movesDone+1<minimum){
                    minimum = movesDone+1;
                }
                return;
            }
            else if(changes) {
                lLastMove = lastMove;
                lastMove = 'D';
                if(!sumLast) {
                    matrixCalculator(boardD, max, movesDone + 1,movesWithoutSum+1,lastMove,lLastMove, sumlLast, sumLast);
                }
                else{
                    matrixCalculator(boardD, max, movesDone + 1,0,lastMove,lLastMove, sumlLast, sumLast);
                }
            }
        }

    }
}

int main() {
    int n;
    std::cin >> n;
    for(int i=0;i<n;i++){
        int size, nTry;
        std::cin >> size >> nTry;
        std::vector<std::vector<int>> board(size, std::vector<int>(size, 0));
        int sumTotal =0, nEles=0;
        for (std::size_t j = 0; j < board.size(); ++j) {
            for(std::size_t k = 0; k < board.size(); ++k) {
                std::cin >> board[j][k];
                sumTotal+=board[j][k];
                if(board[j][k]!=0){
                    nEles+=1;
                }
            }
        }
        bool powerOfTwo = (sumTotal>0 && ((sumTotal & (sumTotal-1)) == 0)); // primeiro corte, se não for power of two então é impossivel
        minimum = nTry+1;
        if(nEles==0 or nEles==1){ // se o nº de elementos !=0 for 0 ou 1 entao a solução é 1
            std::cout << 0 << std::endl;
        }
        else if(!powerOfTwo){
            std::cout << "no solution" << '\n';
        }
        else {
            matrixCalculator(board, nTry, 0,0,' ',' ',false,false);
            if (minimum > nTry) {
                std::cout << "no solution" << '\n';
            } else {
                std::cout << minimum << '\n';
            }
        }
        board.clear();
    }
    return 0;
}