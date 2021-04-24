#pragma once

template<class TL>
class Lista
{
public:

	Lista();
	~Lista();
	void incluirInfo(TL* info);
	void excluirInfo(TL* info);
	TL* getInfo(int i);
	int getTamanho() { return cont; };

private:

	template<class TE>
	class Elemento
	{

	private:
		int ID;
		Elemento<TE>* pProx;
		Elemento<TE>* pAnt;
		TE* pInfo;

	public:
		Elemento(int i = -1);
		~Elemento();
		void setpProx(Elemento<TE>* next);
		Elemento<TE>* getpProx() { return pProx; };
		void setpAnt(Elemento<TE>* previous);
		Elemento<TE>* getpAnt() { return pAnt; };
		void setInfo(TE* info);
		TE* getInfo() { return pInfo; };
		int getId() { return ID; }
	};

	Elemento<TL>* pPrim;
	Elemento<TL>* pAtual;
	int cont;
};

//Funcoes classe Elemento

template<class TL>
template<class TE>
Lista<TL>::Elemento<TE>::Elemento(int i):
ID(i)
{
	pProx = NULL;
	pAnt = NULL;
	pInfo = NULL;
}

template<class TL>
template<class TE>
Lista<TL>::Elemento<TE>::~Elemento()
{
	delete pInfo;
}

template<class TL>
template<class TE>
void Lista<TL>::Elemento<TE>::setpProx(Elemento<TE>* next)
{
	if (next != NULL)
	{
		pProx = next;
	}
}

template<class TL>
template<class TE>
void Lista<TL>::Elemento<TE>::setpAnt(Elemento<TE>* previous)
{
	if (previous != NULL)
	{
		pAnt = previous;
	}
}

template<class TL>
template<class TE>
void Lista<TL>::Elemento<TE>::setInfo(TE* info)
{
	if (info != NULL)
	{
		pInfo = info;
	}
	else
	{
		cout << "ERRO: Nao foi possivel setar info ao elemento pois o ponteiro eh nulo" << endl;
		exit(90);
	}
}

//Funcoes classe Lista

template<class TL>
Lista<TL>::Lista():
cont(0)
{
	pPrim = NULL;
	pAtual = NULL;
}

template<class TL>
Lista<TL>::~Lista()
{
	Elemento<TL>* pAux = pPrim;

	while (pPrim != NULL)
	{
		pAux = pAux->getpProx();
		delete pPrim;
		pPrim = pAux;
	}

	pPrim = NULL;
	pAtual = NULL;
}


template<class TL>
void Lista<TL>::incluirInfo(TL* info)
{
	if (info != NULL)
	{
		Elemento<TL>* pAux = new Elemento<TL>(cont++);
		pAux->setInfo(info);

		if (pPrim == NULL)
		{
			pPrim = pAux;
			pAtual = pPrim;
		}
		else
		{
			pAtual->setpProx(pAux);
			pAux->setpAnt(pAtual);
			pAtual = pAux;
		}

	}
	else
	{
		cout << "ERRO: Ponteiro recebido para ser inserido na lista eh nulo" << endl;
		exit(48);
	}
}

template<class TL>
void Lista<TL>::excluirInfo(TL* info)
{
	Elemento<TL>* pAux = pPrim;

	while (pAux->getInfo() != info)
	{
		pAux = pAux->getpProx();
	}
	
	pAux->getpAnt()->setpProx(pAux->getpProx());
	pAux->getpProx()->setpAnt(pAux->getpAnt());
	delete pAux;

}

template<class TL>
TL* Lista<TL>::getInfo(int i)
{
	if (i >= 0 && i < cont)
	{
		Elemento<TL>* pAux = pPrim;

		while (pAux->getId() != i)
		{
			pAux = pAux->getpProx();
		}

		return pAux->getInfo();
	}
	else
	{
		cout << "ERRO: Acesso indevido de memoria na lista" << endl;
		exit(94);
	}
}
