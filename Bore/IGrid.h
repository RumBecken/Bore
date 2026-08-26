#pragma once
#include <iostream>
#include <vector>

template<typename T> class IList {

};

class ICell {

};

class IMesh {
	IList<ICell> cells;
};

class Polynomial {

};

class Basis {
	Polynomial* localBasis;
	IMesh mesh;
};

class Symbol {
	
};

class Field {
	Symbol name;
};

class DGField : Field{
	Basis basis;
};

class VectorField : Array<Field>{
	Symbol name;
};

class DGVectorField : Array<DGField> {
	Symbol name;
};

template <typename T> class Array {
	int m;
	T* V;
};

struct Vector {
	int m;
	double* V;
};

struct Matrix {
	int m;
	int n;
	double* M;
};

class LinearForm {
	VectorField variables0;
	VectorField parameters;

	virtual double Evaluate(const Vector& u, const Matrix& du,
		const Vector& parameters);
};

class BiLinearForm {
	VectorField variables0;
	VectorField variables1;
	VectorField parameters;

	virtual double Evaluate(const Vector& u, const Matrix& du,
		const Vector& v, const Matrix& dv,
		const Vector& parameters);
};

class TriLinearForm {
	VectorField variables0;
	VectorField variables1;
	VectorField variables2;
	VectorField parameters;

	virtual double Evaluate(const Vector& u, const Matrix& du,
		const Vector& v, const Matrix& dv,
		const Vector& w, const Matrix& dw,
		const Vector& parameters);
};

class SurfaceForm {

};

class LineForm {

};

class VolumeForm {

};

class EquationSystem {
	IList<VectorField> variables;
	IList<VectorField> parameters;
	IList<LineForm> lineForms;
	IList<SurfaceForm> surfaceForms;
	IList<VolumeForm> volumeForms;
};

class Linearizer {
public:
	Matrix Allocate(EquationSystem e, Basis p);
	void Linearize(const EquationSystem forms, const Basis p, const IList<DGVectorField> parameters, Matrix& A, Vector& b);
};

