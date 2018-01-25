#pragma once
#include "c:\Users\Usuario\Git\uad_progra3\uad_progra3\Include\C3DModel.h"
 

class C3DModel_Obj : public C3DModel
{
protected:
	bool parseLine(std::string line, bool countOnly, int lineNumber); // Parse line
	bool readFile(const char * const filename, bool countOnly);       // Read object from file 
	bool loadFromFile(const char * const filename);


	CVector3 *m_vertices;                                             // Dynamically-allocated array of vertices
	CVector3 *m_normals;                                              // Dynamically-allocated array of normals
	CVector3 *m_UVCoords;                                             // Dynamically-allocated array of UV coords

	unsigned short *m_vertexIndices;                                  // Dynamically-allocated array of vertex indices for this model
	unsigned short *m_normalIndices;                                  // Dynamically-allocated array of normal indices for this model
	unsigned short *m_UVindices;                                      // Dynamically-allocated array of UV coord indices for this model

public:
	C3DModel_Obj();
	~C3DModel_Obj();
};

