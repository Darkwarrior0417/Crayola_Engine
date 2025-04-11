#pragma once
#include "Prerequisites.h"
#include "Utilities/Vectors/Vector3.h"
#include "Component.h"

class
	Transform : public Component {
public:
	//constructor que inicializa posicion, rotacion y escala por defecto
	Transform() : position(),
		rotation(),
		scale(),
		matrix(),
		Component(ComponentType::TRANSFORM) {}


	void
		init();

	void
		update(float deltaTime) override;

	void
		render(DeviceContext& deviceContext) override {}

	void
		destroy() {}

	//retorna la posicion actual
	const EngineUtilities::Vector3&
		getPosition() const { return position; }

	//establece una nueva rotacion
	void
		setPosition(const EngineUtilities::Vector3& newPos) { position = newPos; }

	//retorna la rotacion actual
	const EngineUtilities::Vector3&
		getRotation() const { return rotation; }

	//establece una nueva rotacion
	void
		setRotation(const EngineUtilities::Vector3& newRot) { rotation = newRot; }

	//retorna la escala actual
	const EngineUtilities::Vector3&
		getScale() const { return scale; }

	//establece una nueva escala
	void
		setScale(const EngineUtilities::Vector3& newScale) { scale = newScale; }

	void
		setTransform(const EngineUtilities::Vector3& newPos,
			const EngineUtilities::Vector3& newRot,
			const EngineUtilities::Vector3& newSca);
	//metodo para trasladar la posicion del objeto

	void
		translate(const EngineUtilities::Vector3& translation);

private:
	EngineUtilities::Vector3 position; //posicion del objeto
	EngineUtilities::Vector3 rotation; //rotacion del objeto
	EngineUtilities::Vector3 scale; //escala del objeto

public:
	XMMATRIX matrix;
};
