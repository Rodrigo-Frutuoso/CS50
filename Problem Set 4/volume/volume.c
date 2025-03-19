#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Define um tipo para um cabeçalho WAV
typedef uint8_t BYTE;
typedef int16_t SAMPLE;

const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Verificar número de argumentos
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Abrir ficheiro de entrada
    FILE *input = fopen(argv[1], "rb");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Abrir ficheiro de saída
    FILE *output = fopen(argv[2], "wb");
    if (output == NULL)
    {
        fclose(input);
        printf("Could not open file.\n");
        return 1;
    }

    // Obter fator de escala
    float factor = atof(argv[3]);

    // Ler e copiar cabeçalho
    BYTE header[HEADER_SIZE];
    fread(header, sizeof(BYTE), HEADER_SIZE, input);
    fwrite(header, sizeof(BYTE), HEADER_SIZE, output);

    // Processar amostras
    SAMPLE buffer;
    while (fread(&buffer, sizeof(SAMPLE), 1, input))
    {
        buffer *= factor;
        fwrite(&buffer, sizeof(SAMPLE), 1, output);
    }

    // Fechar ficheiros
    fclose(input);
    fclose(output);

    return 0;
}
