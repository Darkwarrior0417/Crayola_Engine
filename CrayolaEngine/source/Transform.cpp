#include "ECS/Transform.h"
#include "DeviceContext.h"

/**
 * @brief Inicializa los valores por defecto del Transform (escala en 1, matriz identidad).
 */
void
Transform::init() {
    // Establecer escala a (1,1,1)
    scale.oneVal();

    // Inicializar la matriz como identidad
    matrix = XMMatrixIdentity();
}

/**
 * @brief Actualiza la matriz de transformación combinando escala, rotación y posición.
 * @param deltaTime Tiempo transcurrido desde el último frame (no se usa en este caso).
 */
void
Transform::update(float deltaTime) {
    // Apply Scale
    XMMATRIX scaleMatrix = XMMatrixScaling(scale.x, scale.y, scale.z);
    // Aplicar rotation
    XMMATRIX rotationMatrix = XMMatrixRotationRollPitchYaw(rotation.x, rotation.y, rotation.z);
    // Aplicar translation
    XMMATRIX translationMatrix = XMMatrixTranslation(position.x, position.y, position.z);

    // Compose the final matrix in the next orden: scale -> rotation -> translation
    matrix = scaleMatrix * rotationMatrix * translationMatrix;
}

/**
 * @brief Establece una nueva posición, rotación y escala para el Transform.
 * @param newPos Nueva posición (Vector3).
 * @param newRot Nueva rotación en radianes (Vector3).
 * @param newSca Nueva escala (Vector3).
 */
void
Transform::setTransform(const EngineUtilities::Vector3& newPos,
    const EngineUtilities::Vector3& newRot,
    const EngineUtilities::Vector3& newSca) {
    position = newPos;
    rotation = newRot;
    scale = newSca;
}