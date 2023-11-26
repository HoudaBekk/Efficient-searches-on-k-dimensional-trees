import sys
import subprocess
import os
from concurrent.futures import ThreadPoolExecutor

def run_task(data_dir, k_dir, query_type, file):
    result_path = "results/" + k_dir + "/" + query_type
    subprocess.run(["mkdir", "-p", result_path])
    with open(os.path.join(os.path.join(data_dir, k_dir), file), 'r') as input_file, open(os.path.join(result_path, "results_" + file), "w") as output_file:
        subprocess.run(["./queryKdTree", query_type], stdin=input_file, stdout=output_file)
    return os.path.join(result_path, "results_" + file)

def main():
    if len(sys.argv) != 2:
        print(f"Uso: {sys.argv[0]}")
        sys.exit(1)

    data_dir = sys.argv[1]
    query_range = ["STANDART", "RELAX", "SQUARISH"]

    tasks = []

    for k_dir in os.listdir(data_dir):
        if os.path.isdir(os.path.join(data_dir, k_dir)):
            for query_type in query_range:
                for file in os.listdir(os.path.join(data_dir, k_dir)):
                    if os.path.isfile(os.path.join(os.path.join(data_dir, k_dir), file)):
                        tasks.append((data_dir, k_dir, query_type, file))

    with ThreadPoolExecutor() as executor:
        results = list(executor.map(lambda args: run_task(*args), tasks))

    for r in results:
        print(r)

if __name__ == "__main__":
    main()
