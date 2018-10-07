#include <stdio.h>

int main(){
    int n;  //Quantidade de Caso de Testes
	int m;  //Quantidade de Enderecos-base na Tabela
	int c;  //Quantidade de Chaves Armazenadas

	int hashMap;
	int value;

    scanf("%d", &n);
    while(n--)
    {
        scanf("%d %d", &m,&c);
        int map[m][c];  //Mapa de Valores
        int collision[m];   //Numero de colisoes

        for(int i = 0; i < m; ++i) collision[i] = 0;


        for (int i = 0; i < c; ++i)
        {
            scanf("%d", &value);
            hashMap = value % m;
            map[hashMap][collision[hashMap]] = value;
            collision[hashMap] += 1;
        }


        for (int i = 0; i < m; ++i)
		{
            printf("%d -> ", i);
            for (int j = 0; j < collision[i]; ++j) printf("%d -> ", map[i][j]);
            printf("\\\n");
        }


        if(n) printf("\n");
        //n--;
    }
    return 0;
}