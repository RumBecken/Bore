# Bore

Bore is a library for solving partial differential equations (PDEs). 
The library provides the necessary tools for discretizing PDEs using a discontinous Galerkin (DG) method.
For the sake of clarity, Bore mimics common mathematical notation.

Bore can be used to solve flow problems with multiple phases, fluid and solid, 
and allows for constitutive equations defined in volumes,on surfaces and on lines. 
Moreover, it supports moving meshes. 

## Fields

Bore supports three types of fields:
- Volume fields. 
They are continuous within the cells of the mesh and discontinuous at the cell surfaces. 
- Surface fields. 
Surface fields are defined on the cell surfaces between adjacent cells.
They are continuous within the surfaces but discontinuous on the lines between the adjacent surfaces.
- Line fields. Line fields are defined on the lines between adjacent surfaces.
They are continuous within the line but discontinous on the points between adjacent lines.   

Each field can be defined on all cells, surfaces or lines, or on respective subsets.

## Mesh

The mesh is dynamic and structured like a linked list.


## Structure

Bore consists of the following components:
- IGrid : Structured and unstructured grids, Voronoi 
- IBasis : Polynomials Basis
- IForm : Functions: Spatial operator, integral forms
- Linearizer: numerical quadrature, create matrix from forms of differential equation
- IMatrix, IVector, Linear Algebra, LAPACK

The user may use the tools of Bore to solve partial differential equations. 
```cpp
IGrid grid;
IBasis basis = ;
IForm laplace = ; 
//Create your own timestepper for example: 
Operator op = Linearizer(laplace, basis, grid);
IMatrix A = op.Linearize();
IVector u0;
IVector u1 = A * u0 + b;
```

## Examples 

The folder examples contains a number of applications of Bore.

A laplace problem on a structured grid.

A Navier Stokes flow on a structured grid. 

A simple implicit discontinous galerkin method on a Voronoi grid. 
It targets multiple phases which can be coupled on surfaces and lines.

## Libraries

- oneMKL
- intel MPI