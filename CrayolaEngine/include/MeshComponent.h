#pragma once
#include "Prerequisites.h"
#include "DeviceContext.h"

// Representa una malla con v�rtices e �ndices.
class MeshComponent {
public:
    // Constructor que inicializa los contadores en cero.
    MeshComponent() : m_numVertex(0), m_numIndex(0) {}

    // Destructor por defecto.
    ~MeshComponent() = default;

public:
    std::string m_name;                      // Nombre de la malla (opcional para identificarla).
    std::vector<SimpleVertex> m_vertex;      // Lista de v�rtices del modelo.
    std::vector<unsigned int> m_index;       // Lista de �ndices para dibujar la malla.
    int m_numVertex;                         // Cantidad total de v�rtices.
    int m_numIndex;                          // Cantidad total de �ndices.
};
