#include "hfunc.h";

/*Esta função garante que o cavalo não terá outros Cavalos em sua zona de ataque. Retorna true se válido, false se não.*/
bool setZonaAtaque(Cavalo &c, int ** tab, int tam)
{
	/*Vetor de booleanos para testar as 8 possibilidades de ataque, essas 8 possibilidades formam uma zona*/
	bool ret[8] = {true,true,true,true,true,true,true,true};

	/*****************************************************/
	/*Setando todas as 8 posições de ataques no tabuleiro*/
	/*****************************************************/

	if(c.x - 2 >= 0 && c.y - 1 >= 0) /*Fazendo verificação para não correr o risco de acessar memória ilegal.*/
		if(tab[c.x - 2][c.y - 1] != 1) /*Cavalos podem compartilhar um campo de ataque, por isso não me preocupo com se o campo for 2.*/
		{
			if(tab[c.x - 2][c.y - 1] != -1) /*Para não alterar as células proibidas*/
				tab[c.x - 2][c.y - 1] = 2;
		} else /*Se a zona de ataque tiver um outro cavalo, esta operação é invalidada.*/
			ret[0] = false;

	if(c.x - 2 >= 0 && c.y + 1 <= tam-1) /*Fazendo verificação para não correr o risco de acessar memória ilegal.*/
		if(tab[c.x - 2][c.y + 1] != 1) /*Cavalos podem compartilhar um campo de ataque, por isso não me preocupo com se o campo for 2.*/
		{
			if(tab[c.x - 2][c.y + 1] != -1) /*Para não alterar as células proibidas*/
				tab[c.x - 2][c.y + 1] = 2;
		} else
			ret[1] = false;

	if(c.x + 2 <= tam-1 && c.y - 1 >= 0) /*Fazendo verificação para não correr o risco de acessar memória ilegal.*/
		if(tab[c.x + 2][c.y - 1] != 1) /*Cavalos podem compartilhar um campo de ataque, por isso não me preocupo com se o campo for 2.*/
		{
			if(tab[c.x + 2][c.y - 1] != -1) /*Para não alterar as células proibidas*/
				tab[c.x + 2][c.y - 1] = 2;
		} else
			ret[2] = false;

	if(c.x + 2 <= tam-1 && c.y + 1 <= tam-1) /*Fazendo verificação para não correr o risco de acessar memória ilegal.*/
		if(tab[c.x + 2][c.y + 1] != 1) /*Cavalos podem compartilhar um campo de ataque, por isso não me preocupo com se o campo for 2.*/
		{
			if(tab[c.x + 2][c.y + 1] != -1) /*Para não alterar as células proibidas*/
				tab[c.x + 2][c.y + 1] = 2;
		} else
			ret[3] = false;

	if(c.x - 1 >= 0 && c.y + 2 <= tam-1) /*Fazendo verificação para não correr o risco de acessar memória ilegal.*/
		if(tab[c.x - 1][c.y + 2] != 1) /*Cavalos podem compartilhar um campo de ataque, por isso não me preocupo com se o campo for 2.*/
		{
			if(tab[c.x - 1][c.y + 2] != -1) /*Para não alterar as células proibidas*/
				tab[c.x - 1][c.y + 2] = 2;
		} else
			ret[4] = false;

	if(c.x - 1 >= 0 && c.y - 2 >= 0) /*Fazendo verificação para não correr o risco de acessar memória ilegal.*/
		if(tab[c.x - 1][c.y - 2] != 1) /*Cavalos podem compartilhar um campo de ataque, por isso não me preocupo com se o campo for 2.*/
		{
			if(tab[c.x - 1][c.y - 2] != -1) /*Para não alterar as células proibidas*/
				tab[c.x - 1][c.y - 2] = 2;
		} else
			ret[5] = false;

	if(c.x + 1 <= tam-1 && c.y + 2 <= tam-1) /*Fazendo verificação para não correr o risco de acessar memória ilegal.*/
		if(tab[c.x + 1][c.y + 2] != 1) /*Cavalos podem compartilhar um campo de ataque, por isso não me preocupo com se o campo for 2.*/
		{
			if(tab[c.x + 1][c.y + 2] != -1) /*Para não alterar as células proibidas*/
				tab[c.x + 1][c.y + 2] = 2;
		} else
			ret[6] = false;

	if(c.x + 1 <= tam-1 && c.y - 2 >= 0) /*Fazendo verificação para não correr o risco de acessar memória ilegal.*/
		if(tab[c.x + 1][c.y - 2] != 1) /*Cavalos podem compartilhar um campo de ataque, por isso não me preocupo com se o campo for 2.*/
		{
			if(tab[c.x + 1][c.y - 2] != -1) /*Para não alterar as células proibidas*/
				tab[c.x + 1][c.y - 2] = 2;
		} else
			ret[7] = false;

	if(ret[0] && ret[1] && ret[2] && ret[3] && ret[4] && ret[5] && ret[6] && ret[7])
		return true;
	else
		return false;
}

/*Esta função tem como objetivo movimentar Cavalos, tendo como incremento nas posições x e y.*/
bool movimentarCavalo(Cavalo &c, int ** tab, int tam, int x, int y)
{
	bool ret = false;
	Cavalo temp;
	if((x == -2 || x == -1 || x == 1 || x == 2) && (y == -2 || y == -1 || y == 1 || y == 2)) /*Garantindo movimento em forma de L*/
		if(tab[c.x + x][c.y + y] == 0) /*Vendo se a posição está vazia.*/
			if(setZonaAtaque(c,tab,tam)) /*Garantindo que sua zona de ataque não terá outros Cavalos.*/
			{
				ret = true;
				temp.x = c.x + x;
				temp.y = c.y + y;
				setCavalo(temp,tab,tam); /*Setando cavalo! Movimentação válida! Quando movimentar a posição anterior certamente será setada em dois.*/
			}
	
	return ret;
}

/*Tem como objetivo adicionar um cavalo válido ao tabuleiro, essa função também faz o set da zona de ataque!1!! */
bool setCavalo(Cavalo &c, int ** tab, int tam)
{
	bool ret = false;
	if(tab[c.x][c.y] == 0) /*Só posso colocar Cavalos em posições vazias, somente!!!*/
		if(setZonaAtaque(c,tab,tam)) /*Aqui eu setarei sua zona de ataque se esse for válido.*/
		{
			ret = true;
			tab[c.x][c.y] = 1;
		}

	return ret;	
}

/*Aqui vou pegar a quantidade de cavalos distribuídos e suas posições.*/
Cavalo * getCavalo(int ** tab, int tam, int &tamCavalo)
{
	Cavalo * retorno;
	tamCavalo = 0;

	for(int i=0; i<tam; i++)
		for(int j=0; j<tam; j++)
			if(tab[i][j] == 1)
				tamCavalo++;

	retorno = new Cavalo[tamCavalo];

	int temp = 0;

	for(int i=0; i<tam; i++)
		for(int j=0; j<tam; j++)
			if(tab[i][j] == 1)
			{
				retorno[temp].x = i;
				retorno[temp].y = j;
				temp++;
			}

	return retorno;
}

/*************************************UTILIZAÇÃO DE MEMÓRIA********************************************/

int * alocarVetor(int n)
{
	int *v;
	if(n > 0)
		v = new int[n];
	else
		v = NULL;
	return v;
}

void liberarVetor(int *v)
{
	delete v;
	v = NULL;
}

int ** alocarTabuleiro(int n)
{
	int **v;
	if(n > 0)
	{
		v = new int*[n];
		for(int i=0; i<n; i++)
			v[i] = new int[n];
	} else
		v = NULL;
	return v;
}

/*Esta função recebe uma matriz estática e retorna uma nova matriz estática com a cara da recebida.*/
int ** copiarTabuleiro(int ** tab, int n)
{
	/*Alocando novo tabuleiro*/
	int ** ret = alocarTabuleiro(n);
	/*Copiando valores de um tabuleiro para outro*/
	for(int i=0; i<n; i++) 
		for(int j=0; j<n; j++)
			ret[i][j] = tab[i][j];
	/*Retornando matriz estática.*/
	return ret;
}

void liberarTabuleiro(int ** &v, int n)
{
	for(int i=0; i<n; i++)
		delete v[i];
	delete v;
	v = NULL;
}

/*Libera um vetor estático de cavalos.*/
void liberarCavalo(Cavalo * v)
{
	delete v;
	v = NULL;
}

void imprimirTabuleiro(int **matriz, int ordem)
{
	//cout << "Esse e seu tabuleiro de tamanho " << ordem << " : " << endl << endl; //exibindo a minha matriz
    for (int i=0; i<ordem; i++)
	{
        for (int j=0; j<ordem; j++)
            cout << "|" << matriz[i][j] << "|\t";
		cout << endl;
	}
}

/*****************************Função exigida*************************************/
int numeroMaximoDeCavalos(char *nomeArquivo)
{
	int x,y;
	int tam;
	int celulasProibidas;
	char celulaProibida[3];

	int ** tabuleiro;

	/*Declarando objeto arquivo.*/
	ifstream arquivo;
	/*Abrindo arquivo a ser lido.*/
	arquivo.open(nomeArquivo);

	/*Pegando tamanho do tabuleiro.*/
	arquivo >> tam;
	/*Pegando quantidade de células proibidas.*/
	arquivo >> celulasProibidas;

	tabuleiro = alocarTabuleiro(tam);

	for(int i=0; i<tam; i++) /*Deixando todas as posições livres para qualquer Cavalo.*/
		for(int j=0; j<tam; j++)
			tabuleiro[i][j] = 0;

	for(int i=0; i<celulasProibidas; i++) /*Setando posições proibidas.*/
	{
		arquivo >> celulaProibida;
		switch(celulaProibida[0])
		{
		case 'a':
			x = 0;
			break;
		case 'b':
			x = 1;
			break;
		case 'c':
			x = 2;
			break;
		case 'd':
			x = 3;
			break;
		case 'e':
			x = 4;
			break;
		case 'f':
			x = 5;
			break;
		case 'g':
			x = 6;
			break;
		case 'h':
			x = 7;
			break;
		case 'i':
			x = 8;
			break;
		default:
			cout << "Como asssim???" << endl;
		}

		switch(celulaProibida[1])
		{
		case '9':
			y = tam - 9;
			break;
		case '8':
			y = tam - 8;
			break;
		case '7':
			y = tam - 7;
			break;
		case '6':
			y = tam - 6;
			break;
		case '5':
			y = tam - 5;
			break;
		case '4':
			y = tam - 4;
			break;
		case '3':
			y = tam - 3;
			break;
		case '2':
			y = tam - 2;
			break;
		case '1':
			y = tam - 1;
			break;
		default:
			cout << "Como asssim???" << endl;
		}
		tabuleiro[y][x] = -1;
	} /*Fim do set de posições proibidas.*/

	/*Fechando arquivo.*/
	arquivo.close();

	
	Tabuleiro temp;
	temp.matriz = tabuleiro;
	temp.tam = tam;
	temp.i = 0;
	temp.j = 0;

	/*Declarando pilha de tabuleiros.*/
	stack<Tabuleiro> pilha;
	
	/*Empilhando o primeiro tabuleiro.*/
	pilha.push(temp);

	bool teste = false;

	int max = 0;

	Cavalo c;

	Tabuleiro z;

	int n = 0;

	bool casaVazia = false;

	/*Enquanto a pilha não estiver vazia*/
	while(!pilha.empty())
	{
		/*Re-setando isso vai acontecer para cada fim do ramo.*/
		teste = false;
		casaVazia = false;

		/*Pegando o topo para depois desempilhá-lo!*/
		temp = pilha.top();

		/*Verificação para garantir que não vou ramificar além do necessário.*/
		if(temp.i == temp.tam && temp.j == temp.tam)
			teste = true;

		/*Desempilhando!*/
		pilha.pop();

		/*Procurando casas vazias.*/
		for(int i=0; i<tam; i++)
			for(int j=0; j<tam; j++)
				if(temp.matriz[i][j] == 0)
					casaVazia = true;

		/*Se não tiver mais casas vazias é melhor eu sair dessa ramificação, pois, o que tinha que dar já deu,
		* assim é mais provável que sejamos mais rápidos na resolução do problema.*/
		if(!casaVazia)
			teste = true;
		if(teste)
		{
			n = 0;
			/*Aqui contarei o número de cavalos para essa situação.*/
			for(int i=0; i<tam; i++)
				for(int j=0; j<tam; j++)
					if(temp.matriz[i][j] == 1)
						n++;
			/*Se esse número for maior do que eu tinha antes, o maior passa a ser ele.*/
			if(n > max) {
				max = n;
				cout << "New max found: " << max << endl;
				imprimirTabuleiro(temp.matriz,tam);
			}
		} else
		{
			/*Copiando um segundo tabuleiro temporário, mas é preciso alocá-lo...*/
			z = temp;

			/*Para setar um cavalo usando a função setCavalo é necessário passar um cavalo uma matriz e o tamanho.*/
			c.x = z.i;
			c.y = z.j;
			
			/*Primeiro caso colocando um cavalo!!*/
			/*Mas, antes precisamos alocar um novo tabuleiro para podermos manipulá-lo*/
			int ** matriz = copiarTabuleiro(z.matriz,tam);
			
			/*Agora sim, setando o cavalo, lembrando que essa função seta também sua zona de ataque!*/
			setCavalo(c,matriz,z.tam);

			/*Passando o ponteiro para a matriz que copiei para uma variável do tipo Tabuleiro.
			* Isso porque só podemos empilhar Tabuleiro*/
			z.matriz = matriz;

			/*Garantindo que pularei uma célula.*/
			z.j = (z.j + 1)%z.tam;
			if(z.j == 0)
				z.i++;

			/*E então, empilhando o primeiro caso, onde coloco um cavalo!*/
			pilha.push(z);

			/*Repetindo o processo... Alocando uma matriz com a cara da que foi recebida do desempilhar e atribuída
			* ao temp, assim farei uma ramificação proibindo a célula.*/
			int ** mtemp = copiarTabuleiro(temp.matriz,tam);

			/*Proibindo...*/
			mtemp[c.x][c.y] = -1;

			/*Passando um ponteiro para uma matriz de um Tabuleiro, para assim podermos empilhar!*/
			z.matriz = mtemp;

			/*Por fim, empilhando!*/
			pilha.push(z);
		}
		/*Liberando memória alocada em cada Empilhar.*/
		liberarTabuleiro(temp.matriz,temp.tam);
	}	
	return max;
}