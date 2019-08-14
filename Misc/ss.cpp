void initSet(int n){
    fto(i, 1, n) pSet[i]=i;
}

int findSet(int x){
    return pSet[x] = (x==pSet[x]) ? x : findSet(pSet[x]);
}

void unionSet(int x, int y){
    pSet[findSet(x)] = findSet(y);
}

int main(){

}
