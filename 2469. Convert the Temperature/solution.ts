function convertTemperature(celsius: number): number[] {
    celsius = parseFloat(celsius.toFixed(2)) * 100;
    const fahrenheit = (celsius * 9 / 5) / 100 + 32;
    const kelvin = (celsius + 27315) / 100;
    return [kelvin, fahrenheit];
};
