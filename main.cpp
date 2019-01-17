#include "hfunc.h";

int main ()
{
	char * nomeArquivo = new char[20];
	cout << "Entre com o nome do arquivo a ser lida as informacoes sobre o tabuleiro >> " << endl;
	cin >> nomeArquivo;
	cout << numeroMaximoDeCavalos(nomeArquivo) << endl;
	return 0;
}