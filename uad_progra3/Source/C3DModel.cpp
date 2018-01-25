#include "../stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

#include "../Include/C3DModel.h"

/* */
C3DModel::C3DModel()
	
{
}

/* */
C3DModel::~C3DModel()
{
	cout << "Destructor: C3DModel()" << endl;
	reset();
}

C3DModel* C3DModel::load(wchar_t * filename)
{
	C3DModel * newObject = nullptr;
	
	if (".obj") {
		newObject = new C3DModel_Obj();
	}
	if (".stl") {
		newObject = new C3DModel_Stl();
	}
	newObject->loadFromFile();

}

/*
*/
void C3DModel::reset()
{
	if (m_vertexIndices != NULL)
	{
		cout << "deleting vertex indices" << endl;
		delete[] m_vertexIndices;
		m_vertexIndices = NULL;
	}
	if (m_normalIndices != NULL)
	{
		cout << "deleting normal indices" << endl;
		delete[] m_normalIndices;
		m_normalIndices = NULL;
	}
	if (m_UVindices != NULL)
	{
		cout << "deleting UV indices" << endl;
		delete[] m_UVindices;
		m_UVindices = NULL;
	}
	/*if (m_vertices != NULL)
	{
		cout << "deleting vertices" << endl;
		delete[] m_vertices;
		m_vertices = NULL;
	}*/
	if (m_verticesRaw != NULL)
	{
		cout << "deleting vertices (float)" << endl;
		delete[] m_verticesRaw;
		m_verticesRaw = NULL;
	}
	/*if (m_normals != NULL)
	{
		cout << "deleting normals" << endl;
		delete[] m_normals;
		m_normals = NULL;
	}*/
	if (m_normalsRaw != NULL)
	{
		cout << "deleting normals (float)" << endl;
		delete[] m_normalsRaw;
		m_normalsRaw = NULL;
	}
	/*if (m_UVCoords != NULL)
	{
		cout << "deleting UV coords" << endl;
		delete[] m_UVCoords;
		m_UVCoords = NULL;
	}*/
	if (m_uvCoordsRaw != NULL)
	{
		cout << "deleting uvCoords (float)" << endl;
		delete[] m_uvCoordsRaw;
		m_uvCoordsRaw = NULL;
	}

	m_numVertices = 0;
	m_numNormals = 0;
	m_numUVCoords = 0;
	m_numFaces = 0;
	
	m_Initialized = false;

	m_currentVertex = 0;
	m_currentNormal = 0;
	m_currentUV = 0;
	m_currentFace = 0;

	m_graphicsMemoryObjectId = 0;
	m_shaderProgramId = 0;
}

/*
*/

/*
*/

/*
 * NOTE: This code reads the .obj file format and can skip normal/UV coords information if the file doesn't have it, 
 * 
 * BUT !
 * 
 * The renderer code assumes the object will have vertices AND normals AND UV coords. So this code or the renderer code needs to be updated for the case
 * where the object doesn't have them...
 * TO-DO...
 * Also, this reads files with triangles, not quads. This is also a TO-DO...
*/
