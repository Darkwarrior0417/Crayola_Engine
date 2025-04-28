#pragma once
#include "Prerequisites.h"
#include "Utilities/Vectors/Vector3.h"
#include "ECS/Component.h"

class
Transform : public Component
{
public:
    /**
     * @brief Constructor que inicializa posición, rotación, escala y matriz en valores por defecto.
     */
    Transform() : position(),
        rotation(),
        scale(),
        matrix(),
        Component(ComponentType::TRANSFORM) {}

    /**
    * @brief Destructor virtual.
    */
    virtual
    ~Transform();

    /**
     * @brief Inicializa valores predeterminados del transform (puede ser usado para reiniciar valores).
     */
    void
    init();

    /**
     * @brief Actualiza el componente de transformación cada frame (por ejemplo, recalculando la matriz de transformación).
     * @param deltaTime Tiempo transcurrido desde la última actualización.
     */
    void
    update(float deltaTime)override;

    /**
     * @brief Renderiza el componente (Transform normalmente no necesita renderizado directo).
     * @param deviceContext Contexto del dispositivo de renderizado.
     */
    void
    render(DeviceContext& deviceContext)override {};

    /**
     * @brief Libera o limpia los recursos del componente (no suele ser necesario en Transform, pero está por consistencia).
     */
    void
    destroy();

    /**
     * @brief Obtiene la posición actual del objeto.
     * @return Vector3 que representa la posición.
     */
    const EngineUtilities::Vector3&
    getPosition() const { return position; }

    /**
    * @brief Establece la posición del objeto.
    * @param newPos Nuevo valor de posición.
    * @return Nueva posición asignada.
    */
    const EngineUtilities::Vector3&
    setPosition(const EngineUtilities::Vector3& newPos) { position = newPos; }

    /**
     * @brief Obtiene la rotación actual del objeto.
     * @return Vector3 que representa la rotación (en grados o radianes según implementación).
     */
    const EngineUtilities::Vector3&
    getRotation() const { return rotation; }

    /**
     * @brief Establece la rotación del objeto.
     * @param newRot Nueva rotación a asignar.
     * @return Nueva rotación asignada.
     */
    const EngineUtilities::Vector3&
    setRotation(const EngineUtilities::Vector3& newRot) { rotation = newRot; }

    /**
     * @brief Obtiene la escala actual del objeto.
     * @return Vector3 que representa la escala.
     */
    const EngineUtilities::Vector3&
    getScale() const { return scale; }

    /**
     * @brief Establece la escala del objeto.
     * @param newScale Nueva escala a asignar.
     * @return Nueva escala asignada.
     */
    const EngineUtilities::Vector3&
    setScale(const EngineUtilities::Vector3& newScale) { scale = newScale; }

    /**
     * @brief Establece de manera conjunta la posición, rotación y escala del objeto.
     * @param _position Nueva posición.
     * @param _rotation Nueva rotación.
     * @param _scale Nueva escala.
     */
    void
    setTransform(EngineUtilities::Vector3 _position, EngineUtilities::Vector3 _rotation, EngineUtilities::Vector3 _scale);

    /**
     * @brief Aplica una traslación a la posición actual del objeto.
     * @param translation Vector que indica cuánto trasladar en cada eje.
     */
    void
    translate(const EngineUtilities::Vector3& translation);

    EngineUtilities::Vector3 position; ///< Posición del objeto
    EngineUtilities::Vector3 rotation; ///< Rotación del objeto
    EngineUtilities::Vector3 scale; ///< Escala del objeto

private:


public:
    XMMATRIX matrix; ///< Matriz de transformación
};