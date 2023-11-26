import sys
import subprocess
import numpy as np
def main():
    # Verificar que se haya proporcionado un argumento
    if len(sys.argv) != 2:
        print(f"Uso: {sys.argv[0]} K")
        sys.exit(1)

    range_i = 1
    for i in range(1000, 110000, 5000):
        N = i
        T = 100
        K = int(sys.argv[1])
        Q = 10000

        filename = f"inputs/K{sys.argv[1][0]}/kdTree_N{N}_K{K}_T{T}_Q{Q}.txt"

        # Ejecutar el comando externo y redirigir la salida al archivo
        with open(filename, "w") as output_file:
            #print(filename)
            subprocess.run(["./generadorKdTree", str(T), str(K), str(N), str(Q)], stdout=output_file)
        range_i = range_i + 1

if __name__ == "__main__":
    main()
