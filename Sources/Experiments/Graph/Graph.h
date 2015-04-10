#ifndef GRAPH_H
#define GRAPH_H

//#include <Experiments/Graph/Vertice.h>
#include <Experiments/Graph/Label.h>
#include <Experiments/Graph/Histograma.h>
#include <vector>
#include <iostream>
#include <memory>
#include <cstdlib>
#include <string.h>
#include <set>

using namespace std;

template<typename type1, typename type2>
class Graph{
	set<unique_ptr<Vertice>> Vertices;
	vector<Vertice*>indice;
	vector<vector<int> >Matriz_Adjacencia;
public:
	void printVertices(char *);
	void printGraph(char *);
	void ConstructEdges(type1, type2);
	//void ConstructEdges(Label, Hsv_DiscrY);
};

bool operator<(const unique_ptr<Vertice> &a, const unique_ptr<Vertice> &b){
	return *a < *b;
}

//variaveis auxiliares
char v[60];
char aux[60];

template<typename type1, typename type2>
void Graph<type1, type2>::printVertices(char *arquivo_vertices){
	strcpy(v, arquivo_vertices);
	strcpy(aux, arquivo_vertices);

	FILE *arq_g = fopen(strcat(v, ".txt"), "w"), *arq_gb = fopen(strcat(aux, "_ordem.bin"), "wb");

	vector<int>HistogramaI;
	vector<float>HistogramaF;

	for (int i = 0; i < indice.size(); i++){
		fprintf(arq_g, "[%d] = ", i);
		if (indice[i]->getType() == 2){
			fprintf(arq_gb, "1 ");
			HistogramaI = ((Hsv_DiscrY*)indice[i])->getHist_y();
			for (int j = 0; j < HistogramaI.size(); j++)
				fprintf(arq_g, "%d ", HistogramaI[j]);
		}
		else if (indice[i]->getType() == 1){
			fprintf(arq_gb, "1 ");
			HistogramaF = ((Hsv_Dist*)indice[i])->getHistDist();
			for (int j = 0; j < HistogramaF.size(); j++)
				fprintf(arq_g, "%.2f ", HistogramaF[j]);
		}
		else {
			fprintf(arq_gb, "0 ");
			fprintf(arq_g, "%s", ((Label*)indice[i])->getLabel().c_str());
		}

		fprintf(arq_g, "\n");
	}

	fclose(arq_g);
	fclose(arq_gb);
}

template<typename type1, typename type2>
void Graph<type1, type2>::printGraph( char *arquivo_grafo){
	char L = 'L';
	char H = 'H';

	strcpy(v, arquivo_grafo);
	strcpy(aux, arquivo_grafo);

	FILE *arq_g = fopen(strcat(aux, ".txt"), "w");
	FILE *arq_gb = fopen(strcat(v, ".bin"), "wb");


	fprintf(arq_g, "Matriz: %d\n\n", Matriz_Adjacencia.size());
	fprintf(arq_gb, "%d ", Matriz_Adjacencia.size());

	for (int i = 0; i < Matriz_Adjacencia.size(); i++){
		fprintf(arq_g, "%d-%c\t", i, indice[i]->getType() == 1 ? H : L);
		for (int j = 0; j < Matriz_Adjacencia.size(); j++){
			fprintf(arq_g, " %d ", Matriz_Adjacencia[i][j]);
			fprintf(arq_gb, "%d ", Matriz_Adjacencia[i][j]);
		}
		fprintf(arq_g, "\n");
		fprintf(arq_gb, "\n");
	}

	fclose(arq_g);
	fclose(arq_gb);
}

template<typename type1, typename type2>
void Graph<type1, type2>::ConstructEdges(type1 label, type2 hist){

	bool it_b;
	set<unique_ptr<Vertice>>::iterator it_l = Vertices.find(unique_ptr<Vertice>(new type1(label)));
	printf("passou find label\n");
	printf(it_l != Vertices.end() ? "achou L\n" : "nao achou L\n");

	//set<unique_ptr<Vertice>>::iterator it_h = Vertices.find(unique_ptr<Vertice>(new Hsv_DiscrY(h)));
	set<unique_ptr<Vertice>>::iterator it_h = Vertices.find(unique_ptr<Vertice>(new type2(hist)));
	printf("passou find Hist\n");
	printf(it_h != Vertices.end() ? "achou H\n" : "nao achou H\n");

	std::pair<std::set<unique_ptr<Vertice>>::iterator, bool> insert_result;

	if (it_l == Vertices.end()){
		printf("Entrei para criar Label\n");
		unique_ptr<Vertice> new_l(new type1(label));
		new_l->idx = indice.size();
		insert_result = Vertices.insert(move(new_l));
		it_l = insert_result.first;
		it_b = insert_result.second;
		indice.push_back(it_l->get());
		printf(it_b ? "cria vertice L\n" : "Erro ao criar\n");

		Matriz_Adjacencia.resize(Matriz_Adjacencia.size() + 1);
		for (int i = 0; i < Matriz_Adjacencia.size(); i++)
			Matriz_Adjacencia[i].resize(Matriz_Adjacencia.size(), 0);
	}


	if (it_h == Vertices.end()){
		printf("Entrei para criar Hist**************\n");
		unique_ptr<Vertice> new_h(new type2(hist));
		//unique_ptr<Vertice> new_h(new Hsv_DiscrY(h));
		new_h->idx = indice.size();
		insert_result = Vertices.insert(move(new_h));
		it_h = insert_result.first;
		it_b = insert_result.second;
		indice.push_back(it_h->get());
		printf(it_b ? "cria vertice H\n" : "Erro ao criar\n");

		Matriz_Adjacencia.resize(Matriz_Adjacencia.size() + 1);
		for (int i = 0; i < Matriz_Adjacencia.size(); i++)
			Matriz_Adjacencia[i].resize(Matriz_Adjacencia.size(), 0);
	}

	//cout << Matriz_Adjacencia.size() << endl;
	printf("iH =%d   iL = %d\n\n", it_h->get()->idx, it_l->get()->idx);
	Matriz_Adjacencia[it_h->get()->idx][it_l->get()->idx] += 1;
	Matriz_Adjacencia[it_l->get()->idx][it_h->get()->idx] += 1;
}



#endif