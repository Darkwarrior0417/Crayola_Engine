/*
 * MIT License
 *
 * Copyright (c) 2024 Roberto Charreton
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * In addition, any project or software that uses this library or class must include
 * the following acknowledgment in the credits:
 *
 * "This project uses software developed by Roberto Charreton and Attribute Overload."
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
*/
#pragma once
namespace EngineUtilities {

    // Constantes matem�ticas
    constexpr float PI = 3.14159265358979323846f;
    constexpr float E = 2.71828182845904523536f;

    /**
         * @brief Computes the square root using the Newton-Raphson method.
         *
         * @param value The value to compute the square root of.
         * @return The computed square root.
         */
    inline float sqrt(float value) {
        if (value < 0) {
            return 0; // Handle negative input gracefully.
        }
        float x = value;
        float y = 1.0f;
        float epsilon = 0.00001f; // Desired precision.
        while (x - y > epsilon) {
            x = (x + y) / 2.0f;
            y = value / x;
        }
        return x;
    }

    /**
     * @brief Calcula el cuadrado de un n�mero.
     *
     * @param value El valor del cual se desea calcular el cuadrado.
     * @return El cuadrado del valor dado.
     */
    inline float square(float value) {
        return value * value;
    }

    /**
     * @brief Calcula el cubo de un n�mero.
     *
     * @param value El valor del cual se desea calcular el cubo.
     * @return El cubo del valor dado.
     */
    inline float cube(float value) {
        return value * value * value;
    }

    /**
     * @brief Calcula la potencia de un n�mero base elevado a un exponente usando el m�todo de exponenciaci�n r�pida.
     *
     * @param base La base de la potencia.
     * @param exponent El exponente al que se eleva la base.
     * @return La base elevada al exponente.
     */
    inline float power(float base, int exponent) {
        if (exponent == 0) return 1;
        if (exponent < 0) return 1.0f / power(base, -exponent);
        float result = 1;
        while (exponent) {
            if (exponent % 2 == 1) result *= base;
            base *= base;
            exponent /= 2;
        }
        return result;
    }

    /**
     * @brief Calcula el valor absoluto de un n�mero.
     *
     * @param value El valor del cual se desea calcular el valor absoluto.
     * @return El valor absoluto del valor dado.
     */
    inline float abs(float value) {
        return (value < 0) ? -value : value;
    }

    /**
     * @brief Devuelve el valor m�ximo de dos n�meros.
     *
     * @param a El primer valor.
     * @param b El segundo valor.
     * @return El mayor de los dos valores dados.
     */
    inline float EMax(float a, float b) {
        return (a > b) ? a : b;
    }

    /**
     * @brief Devuelve el valor m�nimo de dos n�meros.
     *
     * @param a El primer valor.
     * @param b El segundo valor.
     * @return El menor de los dos valores dados.
     */
    inline float EMin(float a, float b) {
        return (a < b) ? a : b;
    }

    /**
     * @brief Redondea un n�mero al entero m�s cercano.
     *
     * @param value El valor que se desea redondear.
     * @return El valor redondeado al entero m�s cercano.
     */
    inline float round(float value) {
        return (value > 0) ? static_cast<int>(value + 0.5f) : static_cast<int>(value - 0.5f);
    }

    /**
     * @brief Trunca un n�mero a su parte entera, redondeando hacia abajo.
     *
     * @param value El valor que se desea truncar.
     * @return La parte entera del valor dado, redondeada hacia abajo.
     */
    inline float floor(float value) {
        int intValue = static_cast<int>(value);
        return (value < intValue) ? intValue - 1 : intValue;
    }

    /**
     * @brief Redondea un n�mero hacia arriba al entero m�s cercano.
     *
     * @param value El valor que se desea redondear hacia arriba.
     * @return El valor redondeado hacia arriba al entero m�s cercano.
     */
    inline float ceil(float value) {
        int intValue = static_cast<int>(value);
        return (value > intValue) ? intValue + 1 : intValue;
    }

    /**
     * Calcula el valor absoluto de un n�mero flotante.
     * @param value Valor flotante.
     * @return Valor absoluto del n�mero flotante.
     */
    inline float fabs(float value) {
        return value < 0.0f ? -value : value;
    }

    // Funciones Trigonom�tricas
    /**
     * Calcula el seno de un �ngulo en radianes.
     * @param angle �ngulo en radianes.
     * @return Valor del seno del �ngulo.
     */
    inline float sin(float angle) {
        float result = 0.0f;
        float term = angle;
        float angle_squared = angle * angle;
        int n = 1;
        while (term > 1e-6f || term < -1e-6f) {
            result += term;
            term *= -angle_squared / ((2 * n) * (2 * n + 1));
            ++n;
        }
        return result;
    }

    /**
     * Calcula el coseno de un �ngulo en radianes.
     * @param angle �ngulo en radianes.
     * @return Valor del coseno del �ngulo.
     */
    inline float cos(float angle) {
        return sin(angle + PI / 2);
    }

    /**
     * Calcula la tangente de un �ngulo en radianes.
     * @param angle �ngulo en radianes.
     * @return Valor de la tangente del �ngulo.
     */
    inline float tan(float angle) {
        float s = sin(angle);
        float c = cos(angle);
        return c != 0.0f ? s / c : 0.0f; // Evita la divisi�n por cero
    }

    /**
     * Calcula el arco seno de un valor.
     * @param value Valor en el rango [-1, 1].
     * @return �ngulo en radianes.
     */
    inline float asin(float value) {
        // Aproximaci�n con la serie de Taylor
        float x = value;
        float result = x;
        float term = x;
        for (int n = 1; n < 10; ++n) {
            term *= x * x * (2 * n - 1) / ((2 * n + 1) * (2 * n));
            result += term;
        }
        return result;
    }

    /**
     * Calcula el arco coseno de un valor.
     * @param value Valor en el rango [-1, 1].
     * @return �ngulo en radianes.
     */
    inline float acos(float value) {
        return PI / 2 - asin(value);
    }

    /**
     * Calcula el arco tangente de un valor.
     * @param value Valor.
     * @return �ngulo en radianes.
     */
    inline float atan(float value) {
        // Aproximaci�n de la funci�n arcotangente
        float result = 0.0f;
        float term = value;
        for (int n = 0; n < 10; ++n) {
            result += term / (2 * n + 1);
            term *= -value * value;
        }
        return result;
    }

    /**
     * Calcula el seno hiperb�lico de un valor.
     * @param value Valor.
     * @return Seno hiperb�lico.
     */
    inline float sinh(float value) {
        return (exp(value) - exp(-value)) / 2;
    }

    /**
     * Calcula el coseno hiperb�lico de un valor.
     * @param value Valor.
     * @return Coseno hiperb�lico.
     */
    inline float cosh(float value) {
        return (exp(value) + exp(-value)) / 2;
    }

    /**
     * Calcula la tangente hiperb�lica de un valor.
     * @param value Valor.
     * @return Tangente hiperb�lica.
     */
    inline float tanh(float value) {
        return sinh(value) / cosh(value);
    }

    // Conversi�n entre Radianes y Grados
    /**
     * Convierte grados a radianes.
     * @param degrees �ngulo en grados.
     * @return �ngulo en radianes.
     */
    inline float radians(float degrees) {
        return degrees * PI / 180.0f;
    }

    /**
     * Convierte radianes a grados.
     * @param radians �ngulo en radianes.
     * @return �ngulo en grados.
     */
    inline float degrees(float radians) {
        return radians * 180.0f / PI;
    }

    // Funciones Exponenciales y Logar�tmicas
    /**
     * Calcula la funci�n exponencial e^x.
     * @param value Exponente.
     * @return Valor de e^x.
     */
    inline float exp(float value) {
        float result = 1.0f;
        float term = 1.0f;
        for (int n = 1; n < 20; ++n) {
            term *= value / n;
            result += term;
        }
        return result;
    }

    /**
     * Calcula el logaritmo natural de un valor.
     * @param value Valor.
     * @return Logaritmo natural.
     */
    inline float log(float value) {
        // Aproximaci�n usando la serie de Taylor
        if (value <= 0) return 0;
        float x = (value - 1) / (value + 1);
        float x2 = x * x;
        float result = 0.0f;
        float term = x;
        for (int n = 1; n < 20; ++n) {
            result += term / (2 * n - 1);
            term *= x2;
        }
        return 2 * result;
    }

    /**
     * Calcula el logaritmo en base 10 de un valor.
     * @param value Valor.
     * @return Logaritmo en base 10.
     */
    inline float log10(float value) {
        return log(value) / log(10);
    }

    // Operaciones de Redondeo Avanzadas
    /**
     * Calcula el m�dulo de dos n�meros.
     * @param a Valor.
     * @param b Divisor.
     * @return M�dulo.
     */
    inline float mod(float a, float b) {
        return a - b * static_cast<int>(a / b);
    }

    // Funciones de Geometr�a
    /**
     * Calcula el �rea de un c�rculo dado su radio.
     * @param radius Radio del c�rculo.
     * @return �rea del c�rculo.
     */
    inline float circleArea(float radius) {
        return PI * radius * radius;
    }

    /**
     * Calcula la circunferencia de un c�rculo dado su radio.
     * @param radius Radio del c�rculo.
     * @return Circunferencia del c�rculo.
     */
    inline float circleCircumference(float radius) {
        return 2 * PI * radius;
    }

    /**
     * Calcula el �rea de un rect�ngulo dado su ancho y alto.
     * @param width Ancho del rect�ngulo.
     * @param height Alto del rect�ngulo.
     * @return �rea del rect�ngulo.
     */
    inline float rectangleArea(float width, float height) {
        return width * height;
    }

    /**
     * Calcula el per�metro de un rect�ngulo dado su ancho y alto.
     * @param width Ancho del rect�ngulo.
     * @param height Alto del rect�ngulo.
     * @return Per�metro del rect�ngulo.
     */
    inline float rectanglePerimeter(float width, float height) {
        return 2 * (width + height);
    }

    /**
     * Calcula el �rea de un tri�ngulo dado su base y altura.
     * @param base Base del tri�ngulo.
     * @param height Altura del tri�ngulo.
     * @return �rea del tri�ngulo.
     */
    inline float triangleArea(float base, float height) {
        return 0.5f * base * height;
    }

    /**
     * Calcula la distancia entre dos puntos en un plano bidimensional.
     * @param x1 Coordenada x del primer punto.
     * @param y1 Coordenada y del primer punto.
     * @param x2 Coordenada x del segundo punto.
     * @param y2 Coordenada y del segundo punto.
     * @return Distancia entre los dos puntos.
     */
    inline float distance(float x1, float y1, float x2, float y2) {
        float dx = x2 - x1;
        float dy = y2 - y1;
        return sqrt(dx * dx + dy * dy);
    }

    // Funciones de C�lculo Num�rico
    /**
     * Interpola linealmente entre dos valores.
     * @param a Valor inicial.
     * @param b Valor final.
     * @param t Par�metro de interpolaci�n entre 0 y 1.
     * @return Valor interpolado.
     */
    inline float lerp(float a, float b, float t) {
        return a + t * (b - a);
    }

    /**
     * Calcula el factorial de un n�mero entero.
     * @param n N�mero entero no negativo.
     * @return Factorial de n.
     */
    inline int factorial(int n) {
        int result = 1;
        for (int i = 2; i <= n; ++i) {
            result *= i;
        }
        return result;
    }

    /**
     * Verifica si dos valores flotantes son aproximadamente iguales.
     * @param a Primer valor.
     * @param b Segundo valor.
     * @param epsilon Margen de error.
     * @return Verdadero si los valores son aproximadamente iguales.
     */
    inline bool approxEqual(float a, float b, float epsilon) {
        return fabs(a - b) < epsilon;
    }

}