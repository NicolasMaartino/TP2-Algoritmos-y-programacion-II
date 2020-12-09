//
// Created by alfon on 12/7/2020.
//
#include "Celula.h"
#include "Tablero.h"
Celula::Celula(int x,int y){
	this-> x = x;
	this-> y = y;
    this->condicion = MUERTA;
    this->informacionGenetica = new InformacionGenetica();
    this-> vecinasVivas = 0;
}


void Celula::revivirCelula(){
    this->condicion = VIVA;
}
int Celula::obtenerCantidadDeVecinasVivas(int x , int y,Tablero* tablero){
	if ((this->obtenerCondicion()) == VIVA && (x-1) != -1 && (y-1) != -1){
	    this->vecinasVivas ++;
	      }
	if ((this->obtenerCondicion())== VIVA && (x+1) != tablero->contarFilas() && (y+1) != tablero->contarColumnas()){
	      this->vecinasVivas ++;
	    }
	if ((this->obtenerCondicion())== VIVA && (y+1) != tablero->contarColumnas()){
	    this->vecinasVivas ++;
	    }
	if ((this->obtenerCondicion())== VIVA && (y-1) != -1){
		this->vecinasVivas ++;
	}
	if ((this->obtenerCondicion())== VIVA && (x+1) != tablero->contarFilas()){
		this->vecinasVivas ++;
	      }
	if ((this->obtenerCondicion())== VIVA && (x-1) != -1){
		this->vecinasVivas ++;
	        }
	if ((this->obtenerCondicion())== VIVA && (x-1) != -1 && (y+1) != tablero->contarColumnas()){
		this->vecinasVivas ++;
	        }
	if ((this->obtenerCondicion())== VIVA && (x+1) != tablero->contarFilas() && (y-1) != -1){
		this->vecinasVivas ++;
	        }
	}

}
void Celula::matarCelula(){
    this->condicion = MUERTA;
}

bool Celula::estaMuerta(){
    return (this->condicion==MUERTA);
}

bool Celula::estaViva(){
    return (this->condicion==VIVA);
}
EstadoDeLaCelula Celula::obtenerCondicion(){
	return (this->condicion);
}
Celula::~Celula(){
    delete this->informacionGenetica;
}
