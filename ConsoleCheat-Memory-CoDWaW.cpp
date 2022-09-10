#include <iostream>
#include <Windows.h>

#define POLL_RATE 100

#define WINDOW_NAME "Call of Duty\xAE"
#define PONTOS_ADDRESS 0X018EF124
#define MUNICAO_ADDRESS 0X018ED67C
#define CARREGADOR_ADDRESS 0X018ED1FC
#define GRANADAS_ADDRESS 0X018ED674
#define VIDA_ADDRESS 0X0176C8B8
#define MONKEY_ADDRESS 0X018ED728

int main(int argc, char** argv)
{
	//OBTER JANELA DO JOGO
	std::cout << "Esperando o jogo..." << std::endl;
	HWND pegar_janela_do_jogo = NULL;
	while (pegar_janela_do_jogo == NULL)
	{
		pegar_janela_do_jogo = FindWindowA(NULL, WINDOW_NAME);
		Sleep(POLL_RATE);
	}
	std::cout << "Jogo identificado, comunicacao estabelecida." << std::endl;


	//Pegando ID do processo do jogo
	DWORD id_processo;
	GetWindowThreadProcessId(pegar_janela_do_jogo, &id_processo);
	if (id_processo != NULL)
	{
		std::cout << "ID do Processo Encontrado." << std::endl;
	}
	else
	{
		std::cout << "ID do Prcesso não Identificado" << std::endl;
		exit(1);
	}

	//Abrindo o processo
	HANDLE pegar_processo;
	pegar_processo = OpenProcess(PROCESS_ALL_ACCESS, FALSE, id_processo);
	if (pegar_processo != NULL)
	{
		std::cout << "Processo Aberto" << std::endl;
	}
	else
	{
		std::cout << "O Processo não foi aberto..." << std::endl;
		exit(1);
	}

	//iniciando hacking de memoria
	bool trava_pontos = false;
	bool trava_municao = false;
	bool trava_carregador = false;
	bool trava_granadas = false;
	bool trava_vida = false;
	bool trava_monkeys = false;

	//Display do menu e seleção de opçoes
	bool att_tela = true;
	while (true)
	{
		if (att_tela)
		{
			system("cls");
			std::cout << "Call of Duty Word at War Console Hacker de Memoria" << std::endl;
			std::cout << "==================================================" << std::endl;
			std::cout << "[F1] - (" << (trava_pontos ? "on " : "off") << ") Trava de Pontos para 100,000" << std::endl;
			std::cout << "[F2] - (" << (trava_municao ? "on " : "off") << ") Trava de Municao Colt M1911 para 1,000" << std::endl;
			std::cout << "[F3] - (" << (trava_carregador ? "on " : "off") << ") Trava de Carregador Colt M1911 para 10" << std::endl;
			std::cout << "[F4] - (" << (trava_granadas ? "on " : "off") << ") Trava de Granadas para 10" << std::endl;
			std::cout << "[F5] - (" << (trava_vida ? "on " : "off") << ") Trava de Vida para 10,000" << std::endl;
			std::cout << "[F6] - (" << (trava_monkeys ? "on " : "off") << ") Trava de Monkeys para 4" << std::endl;
			att_tela = false;
		}


		SHORT tecla_pressionada;

		//tecla para pontos
		tecla_pressionada = GetAsyncKeyState(VK_F1);
		if (tecla_pressionada)
		{
			trava_pontos = !trava_pontos;
			att_tela = true;
		}

		//tecla para municao
		tecla_pressionada = GetAsyncKeyState(VK_F2);
		if (tecla_pressionada)
		{
			trava_municao = !trava_municao;
			att_tela = true;
		}

		//tecla para carregador
		tecla_pressionada = GetAsyncKeyState(VK_F3);
		if (tecla_pressionada)
		{
			trava_carregador = !trava_carregador;
			att_tela = true;
		}

		//tecla para granadas
		tecla_pressionada = GetAsyncKeyState(VK_F4);
		if (tecla_pressionada)
		{
			trava_granadas = !trava_granadas;
			att_tela = true;
		}

		//tecla para vida
		tecla_pressionada = GetAsyncKeyState(VK_F5);
		if (tecla_pressionada)
		{
			trava_vida = !trava_vida;
			att_tela = true;
		}

		//tecla para monkeys
		tecla_pressionada = GetAsyncKeyState(VK_F6);
		if (tecla_pressionada)
		{
			trava_monkeys = !trava_monkeys;
			att_tela = true;
		}

		
		//Colocando configurações na memoria do jogo
		if (trava_pontos)
		{
			int valor_certo = 100000;
			WriteProcessMemory(pegar_processo, (LPVOID)PONTOS_ADDRESS, &valor_certo, sizeof(valor_certo), NULL);
		}

		if (trava_municao)
		{
			int valor_certo = 1000;
			WriteProcessMemory(pegar_processo, (LPVOID)MUNICAO_ADDRESS, &valor_certo, sizeof(valor_certo), NULL);
		}


		if (trava_carregador)
		{
			int valor_certo = 10;
			WriteProcessMemory(pegar_processo, (LPVOID)CARREGADOR_ADDRESS, &valor_certo, sizeof(valor_certo), NULL);
		}


		if (trava_granadas)
		{
			int valor_certo = 10;
			WriteProcessMemory(pegar_processo, (LPVOID)GRANADAS_ADDRESS, &valor_certo, sizeof(valor_certo), NULL);
		}


		if (trava_vida)
		{
			int valor_certo = 10000;
			WriteProcessMemory(pegar_processo, (LPVOID)VIDA_ADDRESS, &valor_certo, sizeof(valor_certo), NULL);
		}


		if (trava_monkeys)
		{
			int valor_certo = 4;
			WriteProcessMemory(pegar_processo, (LPVOID)MONKEY_ADDRESS, &valor_certo, sizeof(valor_certo), NULL);
		}

		

		Sleep(POLL_RATE);
	}

}