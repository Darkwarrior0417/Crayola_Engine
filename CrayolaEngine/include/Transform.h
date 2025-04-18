#pragma once
#include "Prerequisites.h"
#include "Utilities/Vectors/Vector3.h"
#include "ECS/Component.h"

class
    Transform : public Component
{
public:
    Transform() : position(),
        rotation(),
        scale(),
        matrix(),
        Component(ComponentType::TRANSFORM) {}
    virtual
        ~Transform();

    void
        init();

    /**
     * @brief M�todo virtual puro para actualizar el componente.
     * @param deltaTime El tiempo transcurrido desde la �ltima actualizaci�n.
     */
    void
        update(float deltaTime)override;

    /**
     * @brief M�todo virtual puro para renderizar el componente.
     * @param deviceContext Contexto del dispositivo para operaciones gr�ficas.
     */
    void
        render(DeviceContext& deviceContext)override {};

    void
        destroy();

    const EngineUtilities::Vector3&
        getPosition() const { return position; }

    const EngineUtilities::Vector3&
        setPosition(const EngineUtilities::Vector3& newPos) { position = newPos; }

    const EngineUtilities::Vector3&
        getRotation() const { return rotation; }

    const EngineUtilities::Vector3&
        setRotation(const EngineUtilities::Vector3& newRot) { rotation = newRot; }

    const EngineUtilities::Vector3&
        getScale() const { return scale; }

    const EngineUtilities::Vector3&
        setScale(const EngineUtilities::Vector3& newScale) { scale = newScale; }

    void
        setTransform(EngineUtilities::Vector3 _position, EngineUtilities::Vector3 _rotation, EngineUtilities::Vector3 _scale);

    void
        translate(const EngineUtilities::Vector3& translation);

    EngineUtilities::Vector3 position; ///< Posición del objeto
    EngineUtilities::Vector3 rotation; ///< Rotación del objeto
    EngineUtilities::Vector3 scale; ///< Escala del objeto

private:


public:
    XMMATRIX matrix; ///< Matriz de transformación
};